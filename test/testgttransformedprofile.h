#ifndef TESTGTTRANSFORMEDPROFILE_H
#define TESTGTTRANSFORMEDPROFILE_H

#include "autotest.h"
#include "gttransformedprofile.h"

class TestGTTransformedProfile : public QObject
{
        Q_OBJECT
    public:

    private:

    private slots:

        void testProfileTransformation()
        {
            QCOMPARE(GTTransformedProfile(new FakeProfile("SHS150*150*6.0")).displayName(), QString("150x150x6.0SHS"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("RHS150*50*6.0")).displayName(), QString("150x50x6.0RHS"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("UB150*14")).displayName(), QString("150UB14"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("UC100*15")).displayName(), QString("100UC15"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("WB700*115")).displayName(), QString("700WB115"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("WB700*115")).displayName(), QString("700WB115"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("WC350*197")).displayName(), QString("350WC197"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("TFB100*7")).displayName(), QString("100TFB7"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("PFC100*50")).displayName(), QString("100PFC"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("CHS13.7*3.02")).displayName(), QString("13.7x3.02CHS"));

            //Some profiles that shouldn't be transformed because they already confirm to the GT standard
            QCOMPARE(GTTransformedProfile(new FakeProfile("C20015")).displayName(), QString("C20015"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("Z20015")).displayName(), QString("Z20015"));

            //These profiles don't translate into the GT standard
            QCOMPARE(GTTransformedProfile(new FakeProfile("LYS-SC20012")).displayName(), QString("LYS-SC20012"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("T1-F325-MPG_275_WIDE")).displayName(), QString("T1-F325-MPG_275_WIDE"));
            QCOMPARE(GTTransformedProfile(new FakeProfile("P15(150X1200)")).displayName(), QString("P15(150X1200)"));
        }

};

DECLARE_TEST(TestGTTransformedProfile)

#endif // TESTGTTRANSFORMEDPROFILE_H
