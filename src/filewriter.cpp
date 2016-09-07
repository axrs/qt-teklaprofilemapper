#include "filewriter.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

FileWriter::FileWriter(QStringList &data, QString &file, QObject *parent) : QObject(parent), m_data(data), m_file(file)
{

}

void FileWriter::save() const
{
    QFile outputFile(m_file);

    if(!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        qWarning() << outputFile.errorString();
    } else {

        QTextStream fileOutput(&outputFile);

        for(QString s : m_data){
            fileOutput << s << endl;
        }

        outputFile.close();
    }
}
