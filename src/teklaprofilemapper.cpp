#include "teklaprofilemapper.h"
#include <QDebug>
#include <QPointer>
#include <QSharedPointer>

#include "gttransformedprofile.h"
#include "profileinconfiguration.h"

TeklaProfileMapper::TeklaProfileMapper(ProfileMapper* mapper, QObject *parent) :
    TeklaProfileMapper(mapper, QString("DISPLAY_NAME"), parent)
{
}

TeklaProfileMapper::TeklaProfileMapper(ProfileMapper *mapper, QString &replacementKey, QObject *parent):
    ProfileMapper(parent), m_mapper(mapper), m_replacementKey(replacementKey)
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

        if (line.contains(m_replacementKey, Qt::CaseSensitive) && !profile.isNull()){
            //Alter the line, preserving formatting
            line = QString("%1%2%3")
                    .arg("", -8) //8 White spaces
                    .arg("\"" + m_replacementKey + "\"", -36) //UDA key to a maximum width of 36 characters surroun
                    .arg("\"" + profile->displayName() + "\""); //UDA value
        }
        result.append(line);
    }

    return result;
}
