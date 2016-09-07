#include "teklaprofilemapper.h"
#include <QDebug>
#include <QPointer>
#include <QSharedPointer>

#include "gttransformedprofile.h"
#include "profileinconfiguration.h"

TeklaProfileMapper::TeklaProfileMapper(ProfileMapper* mapper, QObject *parent) : ProfileMapper(parent), m_mapper(mapper)
{

}

QStringList TeklaProfileMapper::process() const
{
    QStringList input = m_mapper->process();

    //Using a QSharedPointer to simplify memory management
    QSharedPointer<Profile> profile;
    QStringList result;
    QString line;


    for(int i = 0; i < input.length(); i++){
        line = input.at(i);

        if (line.startsWith("PROFILE_NAME")){
            profile = QSharedPointer<Profile>(new GTTransformedProfile(new ProfileInConfiguration(line)));
        }

        if (line.contains("DISPLAY_NAME", Qt::CaseSensitive) && !profile.isNull()){
            //Alter the line, preserving formatting
            line = "        \"DISPLAY_NAME\"                      \"" + profile->displayName() + "\"";
        }
        result.append(line);
    }

    return result;
}
