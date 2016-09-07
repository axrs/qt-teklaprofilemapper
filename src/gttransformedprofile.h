#ifndef GTTRANSFORMEDPROFILE_H
#define GTTRANSFORMEDPROFILE_H

#include <QObject>
#include <QDebug>
#include "profile.h"
#include <QScopedPointer>

class GTTransformedProfile : public Profile
{
        Q_OBJECT
        Q_INTERFACES(Profile)
    public:
        explicit GTTransformedProfile(Profile* p, QObject *parent = 0);
        ~GTTransformedProfile(){}

        virtual QString displayName() const;

    signals:

    public slots:

    private:
       Profile * m_profile;
};

#endif // GTTRANSFORMEDPROFILE_H
