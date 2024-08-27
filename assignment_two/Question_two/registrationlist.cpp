#include "registrationlist.h"
#include <QDebug>

RegistrationList::RegistrationList() {}

void RegistrationList::addRegistration(Registration *r)
{
    foreach(Registration* a, mAttendeeList) {
        if(a->getAttendee().getEmail() == r->getAttendee().getEmail() && a->getAttendee().getName() == r->getAttendee().getName()) {
            throw QString("Something is wrong");
        }
    }

    mAttendeeList.append(r);

}

RegistrationList::~RegistrationList()
{
    qDeleteAll(mAttendeeList);
}

bool RegistrationList::isRegistered(QString n)
{
    foreach(Registration* a, mAttendeeList) {
        if(a->getAttendee().getName() == n){
            return true;
        }
    }
    return false;
}

double RegistrationList::totalFee(QString t)
{
    double total =0;
    QString type;

    foreach(Registration *a, mAttendeeList) {
        if (t =="All"){
            total += a->calculateFee();
        } else {

            const QMetaObject *metaobject = a->metaObject();
            type =metaobject->className();

            if (t == type){
                total += a->calculateFee();
            }
        }
    }

    return total;
}

int RegistrationList::totalRegistrations(QString a)
{
    int count =0;
    QString type;

    foreach(Registration *r, mAttendeeList) {
        if (a =="All"){
            count += 1;
        } else {
            //use Q's meta Object
            //Registration, StudentRegistration, GuestRegistration.
            const QMetaObject *metaobject = r->metaObject();
            type =metaobject->className();
            if (a == type){
                count += 1;
            }
        }
    }

    return count;
}

QList<Registration *> RegistrationList::getList()
{
    return mAttendeeList;
}


