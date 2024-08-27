#include "registrationfactory.h"

RegistrationFactory::RegistrationFactory() {}

Registration *RegistrationFactory::create(QString type, Person person, QString qualification, QString category)
{
    if(type == "Registration"){
        return new Registration(person);
    }else if (type == "StudentRegistration"){
        return new StudentRegistration(person, qualification);
    }else if (type == "GuestRegistration"){
        return new GuestRegistration(person, category);
    }

    return NULL;
}
