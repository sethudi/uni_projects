#include "guestregistration.h"


GuestRegistration::GuestRegistration(Person a, QString q)
    : Registration(a), mCategory(q)
{

}

double GuestRegistration::calculateFee() const
{
    return STANDARD_FEE *0.10;
}

QString GuestRegistration::toString() const
{
    return Registration::toString().append(", category :").append(mCategory);
}
