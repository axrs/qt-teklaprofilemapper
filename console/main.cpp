#include <QCoreApplication>
#include "teklaprofilemapper.h"
#include "fileprofilemapper.h"
#include <QTextStream>
#include <iostream>
#include <QFile>
#include <QDir>
#include "filewriter.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);

    QTextStream out(stdout, QIODevice::WriteOnly);
    out << QString("Tekla Profile Mapper") << endl;

    if (argc < 2) {
        out << QString("No input file found. Mapping has not run.") << endl;
    }else{
        out << QString("Analyzing profiles from: ") << QString(argv[1]) << endl;
        out.flush();

        QStringList result = TeklaProfileMapper(new FileProfileMapper(QString(argv[1]))).process();
        out << "\t" << result.length() << QString(" Lines Processed") << endl;

        out << QString("Exporting profiles to: ") << QDir::current().absolutePath() << endl;
        out.flush();

        FileWriter(result, QString("mapped_profiles.lis")).save();
        out << "\t" << QString("Profiles successfuly exported") << endl;
    }

    out.flush();
    system("PAUSE");
    return 0;
}
