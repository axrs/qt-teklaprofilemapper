#include "fileprofilemapper.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

FileProfileMapper::FileProfileMapper(QString &filePath, QObject *parent) : ProfileMapper(parent), m_filePath(filePath)
{

}

QStringList FileProfileMapper::process() const
{
    QFile file(m_filePath);
    QStringList lines;

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << file.errorString();
        return lines;
    }

    QTextStream reader(&file);
    while (!reader.atEnd()){
        lines.append(reader.readLine());
    }

    return lines;
}



