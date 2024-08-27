#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"


class StudentRegistration: public Registration
{
    Q_OBJECT
public:
    StudentRegistration(Person a, QString q);
    double calculateFee() const;
    QString toString() const;

private:
    QString mQualification;
};

#endif // STUDENTREGISTRATION_H
