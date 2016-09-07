#include "profileinconfiguration.h"

ProfileInConfiguration::ProfileInConfiguration(QString configLine, QObject *parent) : Profile(parent), m_configLine(configLine)
{

}

QString ProfileInConfiguration::displayName() const
{

    // Extract values between quotations
    // Create a new profile and return it
    QString profileName;

    bool atName = false;
    for(int i = 0; i <m_configLine.length(); i++){
        if (m_configLine.at(i) == '"'){
            //Start of profile name
            atName = !atName;
        }else if (atName){
            profileName.append(m_configLine.at(i));
        }
    }

    return profileName;
}
