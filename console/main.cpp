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
    out << "Tekla Profile Mapper (Version: " << GIT_VERSION << ")" << endl;

    if (argc < 2) {
        out << QString("No input file found. Mapping has not run.") << endl;
        return 0;
    }

    QString udaKey;
    do{
        out << "Provide a UDA key without spaces to map to <DISPLAY_NAME>: ";
        out.flush();
        udaKey = QTextStream(stdin).readLine();

        if (udaKey.isEmpty()){
            udaKey = "DISPLAY_NAME";
        }

    }while(udaKey.contains(" "));

    out << "Using UDA Key `" << udaKey << "` for mapping profiles." << endl;
    out << "Analyzing profiles from: " << argv[1] << endl;
    out.flush();

    QStringList result = TeklaProfileMapper(new FileProfileMapper(QString(argv[1])), udaKey).process();
    out << "\t" << result.length() << QString(" Lines Processed") << endl;

    out << "Exporting profiles to: " << QDir::current().absolutePath() << endl;
    out.flush();

    FileWriter(result, QString("mapped_profiles.lis")).save();
    out << "\t" << QString("Profiles successfuly exported") << endl;

    out.flush();
    system("PAUSE");
    return 0;
}
