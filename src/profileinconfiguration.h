#ifndef PROFILEINCONFIGURATIONSTRING_H
#define PROFILEINCONFIGURATIONSTRING_H

#include <QObject>
#include "profile.h"

class ProfileInConfiguration : public Profile
{
        Q_OBJECT
        Q_INTERFACES(Profile)
    public:
        explicit ProfileInConfiguration(QString configLine, QObject *parent = 0);
        virtual QString displayName() const;
    signals:

    public slots:

    private:
        QString m_configLine;
};

#endif // PROFILEINCONFIGURATIONSTRING_H
