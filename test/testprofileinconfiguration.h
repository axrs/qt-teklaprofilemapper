#ifndef TESTPROFILEINCONFIGURATION_H
#define TESTPROFILEINCONFIGURATION_H

#include "autotest.h"
#include "profileinconfiguration.h"

class TestProfileInConfiguration : public QObject
{
        Q_OBJECT
    public:

    private:

    private slots:

        void testProfileTransformation()
        {
            QCOMPARE(ProfileInConfiguration("PROFILE_NAME = \"TFB100*7\";").displayName(), QString("TFB100*7"));
            QCOMPARE(ProfileInConfiguration("PROFILE_NAME = \"RHS50*25*2.3\";").displayName(), QString("RHS50*25*2.3"));
            QCOMPARE(ProfileInConfiguration("PROFILE_NAME = \"SHS300*300*16.0\";").displayName(), QString("SHS300*300*16.0"));
            QCOMPARE(ProfileInConfiguration("PROFILE_NAME = \"HD360*162\";").displayName(), QString("HD360*162"));
            QCOMPARE(ProfileInConfiguration("PROFILE_NAME = \"UB686*254*170\";").displayName(), QString("UB686*254*170"));
            QCOMPARE(ProfileInConfiguration("PROFILE_NAME = \"FL8*90\";").displayName(), QString("FL8*90"));
            QCOMPARE(ProfileInConfiguration("PROFILE_NAME = \"CHS13.7*2.24\";").displayName(), QString("CHS13.7*2.24"));
        }

};

DECLARE_TEST(TestProfileInConfiguration)

#endif // TESTPROFILEINCONFIGURATION_H
