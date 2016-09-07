#ifndef PROFILE_H
#define PROFILE_H

#include <QString>
#include <QObject>
#include <QDebug>

class Profile : public QObject
{
    public:
        Profile(QObject* parent=0) : QObject(parent){}
        virtual ~Profile(){}
        virtual QString displayName() const = 0;
};

Q_DECLARE_INTERFACE(Profile, "au.apala.tmm.Profile/1.0")


class FakeProfile : public Profile
{
        Q_OBJECT
        Q_INTERFACES(Profile)
    public:
        FakeProfile(const QString& profileType, QObject *parent=0) : Profile(parent), m_profileName(profileType){

        }
        ~FakeProfile(){}

        virtual QString displayName() const{
            return m_profileName;
        }

    private:
        const QString m_profileName;
};


#endif // PROFILE_H
