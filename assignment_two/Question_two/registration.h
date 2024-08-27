#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"
#include <QDate>
#include <QObject>

class Registration: public QObject
{
    Q_OBJECT
public:
    const double STANDARD_FEE =100;
    Registration(Person a);
    Person getAttendee() const;
    QDate getBookingDate() const;
    virtual double calculateFee() const;
    virtual QString toString() const;
    virtual QString getCategory() const;
    virtual QString getQualification() const;

private:
    Person mAttendee;
    QDate mBooking;
};
#endif // REGISTRATION_H
