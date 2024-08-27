#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include <QList>
#include "registration.h"
#include <QMetaObject>

class RegistrationList
{
public:
    RegistrationList();
    void addRegistration(Registration *r);
    ~RegistrationList();
    bool isRegistered(QString n);
    double totalFee(QString t);
    int totalRegistrations(QString a);


private:
    QList<Registration*> mAttendeeList;
};

#endif // REGISTRATIONLIST_H
