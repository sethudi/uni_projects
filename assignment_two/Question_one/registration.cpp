#include "registration.h"


Registration::Registration(Person a)
    : mAttendee(a)
{

}

Person Registration::getAttendee() const
{
    return mAttendee;
}

QDate Registration::getBookingDate() const
{
    return mBooking;
}

double Registration::calculateFee() const
{
    return STANDARD_FEE;
}

QString Registration::toString() const
{
    return QString();
}
