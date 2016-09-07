#include "teklaprofile.h"
#include "basicprofile.h"

TeklaProfile::TeklaProfile(QString profileLineString, QObject *parent) : QObject(parent), m_profileLineString(profileLineString)
{

}


QString TeklaProfile::displayName() const
{

    // Extract values between quotations
    // Create a new profile and return it
    QString profileName;

    bool atName = false;
    for(int i = 0; i <line.length(); i++){
        if (line.at(i) == '"'){
            //Start of profile name
            atName = !atName;
        }else if (atName){
            profileName.append(line.at(i));
        }
    }


    QString profileType = "";

    for(int i = 0; i < m_profileName.length(); i++){
        if (m_profileName.at(i).isLetter()){
            profileType.append(m_profileName.at(i));
        }else{
            //Terminate the loop early as the profiles should start with alpha names only.
            break;
        }
    }


}
