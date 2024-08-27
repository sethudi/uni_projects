#include "studentregistration.h"



StudentRegistration::StudentRegistration(Person a, QString q)
    : mQualification(q), Registration(a)
{

}

double StudentRegistration::calculateFee() const
{
    return STANDARD_FEE /2;
}

QString StudentRegistration::toString() const
{
    return Registration::toString().append((", Qualification: ")).append(mQualification);
}

QString StudentRegistration::getQualification() const
{
    return mQualification;
}
