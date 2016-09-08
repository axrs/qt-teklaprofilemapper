#ifndef PROFILEMAPPER_H
#define PROFILEMAPPER_H
#include <QObject>
#include <QStringList>
#include <QString>

class ProfileMapper : public QObject
{
    public:
        ProfileMapper(QObject* parent=0) : QObject(parent){}
        virtual ~ProfileMapper(){}
        virtual QStringList process() const = 0;
};
Q_DECLARE_INTERFACE(ProfileMapper, "au.apala.tmm.ProfileMapper/1.0")


class FakeProfileMapper : public ProfileMapper
{
        Q_OBJECT
        Q_INTERFACES(ProfileMapper)
    public:
        FakeProfileMapper(QObject *parent=0) : FakeProfileMapper(QString("DISPLAY_NAME"), parent) {

        }
        FakeProfileMapper(QString & key, QObject *parent=0) : ProfileMapper(parent), m_key(key) {

        }
        ~FakeProfileMapper(){}

        virtual QStringList process() const{
            QStringList profileList;
            profileList <<  "PROFILE DATABASE EXPORT VERSION = 3";
            profileList <<  "";

            profileList <<  "PROFILE_NAME = \"UB150*14\";";
            profileList <<  "{";
            profileList <<  "    TYPE = 1; SUB_TYPE = 1001; COORDINATE = 0.000;";
            profileList <<  "    {";
            profileList <<  "        \"HEIGHT\"                            1.500000000E+002";
            profileList <<  "        \"WIDTH\"                             7.500000000E+001";
            profileList <<  "        \"WEB_THICKNESS\"                     5.000000000E+000";
            profileList <<  "        \"FLANGE_THICKNESS\"                  7.000000000E+000";
            //profileList:10 THIS IS THE LINE WE ARE LOOKING TO POPULATE.
            profileList << QString("%1%2%3").arg("", -8).arg("\"" + m_key + "\"", -36).arg("\"\"");
            profileList <<  "    }";
            profileList <<  "}";

            profileList <<  "PROFILE_NAME = \"CHS13.7*2.24\";";
            profileList <<  "{";
            profileList <<  "    TYPE = 1; SUB_TYPE = 1001; COORDINATE = 0.000;";
            profileList <<  "    {";
            profileList <<  "        \"DIAMETER\"                          1.370000000E+001";
            profileList <<  "        \"PLATE_THICKNESS\"                   2.240000000E+000";
            profileList <<  "        \"COVER_AREA\"                        6.690000000E+004";
            profileList <<  "        \"CROSS_SECTION_AREA\"                8.100000000E+001";
            //profileList:21 THIS IS THE LINE WE ARE LOOKING TO POPULATE.
            profileList << QString("%1%2%3").arg("", -8).arg("\"" + m_key + "\"", -36).arg("\"\"");
            profileList <<  "    }";
            profileList <<  "}";

            return profileList;
        }

    private:
        QString m_key;
};

#endif // PROFILEMAPPER_H
