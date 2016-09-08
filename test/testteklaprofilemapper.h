#ifndef TESTTEKLAPROFILEMAPPER_H
#define TESTTEKLAPROFILEMAPPER_H

#include "autotest.h"
#include "teklaprofilemapper.h"


class TestTeklaProfileMapper : public QObject
{
        Q_OBJECT
    public:

    private:        

    private slots:

        void testMultipleProfileProcessor()
        {
            TeklaProfileMapper processor(new FakeProfileMapper());
            QCOMPARE(processor.process().at(10), QString("        \"DISPLAY_NAME\"                      \"150UB14\""));
            QCOMPARE(processor.process().at(21), QString("        \"DISPLAY_NAME\"                      \"13.7x2.24CHS\""));
        }

        void testMultipleProfileProcessorWithReplacementKey()
        {
            QString key = "SOME_KEY";

            TeklaProfileMapper processor(new FakeProfileMapper(key), key);
            QCOMPARE(processor.process().at(10), QString("        \"SOME_KEY\"                          \"150UB14\""));
            QCOMPARE(processor.process().at(21), QString("        \"SOME_KEY\"                          \"13.7x2.24CHS\""));
        }

};

DECLARE_TEST(TestTeklaProfileMapper)

#endif // TESTTEKLAPROFILEMAPPER_H
