#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QObject>
#include <QStringList>

class FileWriter : public QObject
{
        Q_OBJECT
    public:
        explicit FileWriter(QStringList &data, QString &file, QObject *parent = 0);

        void save() const;

    signals:

    public slots:

    private:
        QStringList m_data;
        QString m_file;
};

#endif // FILEWRITER_H
