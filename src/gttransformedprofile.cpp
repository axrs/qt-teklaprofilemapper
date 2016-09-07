#include "gttransformedprofile.h"
#include <QStringList>

GTTransformedProfile::GTTransformedProfile(Profile *p, QObject *parent) : Profile(parent), m_profile(p)
{
    //Take ownership of the passed in decoration
    m_profile->setParent(this);
}

QString GTTransformedProfile::displayName() const
{
    QString profileName = m_profile->displayName();
    QString profileType = "";

    for(int i = 0; i < profileName.length(); i++){
        if (profileName.at(i).isLetter()){
            profileType.append(profileName.at(i));
        }else{
            //Terminate the loop early as the profiles should start with alpha names only.
            break;
        }
    }

    QStringList profileParts =  profileName.right(profileName.length()-profileType.length()).split("*");

    switch (profileParts.length()) {
        case 0:
            return profileName;
            break;
        case 1:
            //Converts PFC200 into 200PFC
            return QString(profileParts.at(0) + profileType);
            break;
        case 2:
            //Note: String comparison here works because Qt has overloaded methods.
            //The compare method returns an integer result, where 0 is equal. This may confuse logic.

            //Converts CHS13.7*3.02 into 13.7x3.02CHS
            if (profileType == "CHS"){
                return profileParts.join('x') + profileType;
            }
            //Converts PFC250*75 into 250PFC
            else if (profileType == "PFC"){
                return profileParts.at(0) + profileType;
            } else{
                //Converts UB200*18 into 200UB18
                return profileParts.join(profileType);
            }


            break;
        default:
            return profileParts.join("x") + profileType;
    }
}
