#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QObject>
#include <QString>
#include "profilemapper.h"

class FileProfileMapper : public ProfileMapper
{
        Q_OBJECT
        Q_INTERFACES(ProfileMapper)
    public:
        explicit FileProfileMapper(QString & filePath, QObject *parent = 0);
        virtual QStringList process() const;

    signals:

    public slots:


    private:
        QString m_filePath;
};

#endif // FILEPROCESSOR_H
