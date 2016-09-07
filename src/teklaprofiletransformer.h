#ifndef TEKLAPROFILETRANSFORMER_H
#define TEKLAPROFILETRANSFORMER_H

#include <QObject>
#include <QFile>

class TeklaProfileTransformer : public QObject
{
        Q_OBJECT
    public:
        explicit TeklaProfileTransformer(QObject *parent = 0);

    signals:

    public slots:
};

#endif // TEKLAPROFILETRANSFORMER_H
