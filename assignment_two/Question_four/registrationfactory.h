#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H

#include "studentregistration.h"
#include "guestregistration.h"
#include "registration.h"

class RegistrationFactory
{
public:
    RegistrationFactory();
    Registration *create(QString type, Person person, QString qualification, QString category);
};

#endif // REGISTRATIONFACTORY_H
