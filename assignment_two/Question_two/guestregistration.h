#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H

#include "registration.h"
class GuestRegistration: public Registration
{
    Q_OBJECT
public:
    GuestRegistration(Person a, QString q);
    double calculateFee() const;
    QString toString() const;
    QString getCategory() const;

private:
    QString mCategory;
};
#endif // GUESTREGISTRATION_H
