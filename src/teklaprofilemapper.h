#ifndef TEKLAPROFILEPROCESSOR_H
#define TEKLAPROFILEPROCESSOR_H

#include <QObject>
#include "profilemapper.h"

class TeklaProfileMapper : public ProfileMapper
{
        Q_OBJECT
        Q_INTERFACES(ProfileMapper)

    public:
        explicit TeklaProfileMapper(ProfileMapper* mapper, QObject *parent = 0);
        ~TeklaProfileMapper(){
            delete m_mapper;
        }
        virtual QStringList process() const;
    signals:

    public slots:

    private:
        ProfileMapper * m_mapper;
};

#endif // TEKLAPROFILEPROCESSOR_H
