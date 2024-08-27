#include "person.h"

Person::Person(QString n, QString a, QString e)
    : mName(n), mAffiliation(a), mEmail(e)
{

}

QString Person::getName() const
{
    return mName;
}

QString Person::getAffiliation() const
{
    return mAffiliation;
}

QString Person::getEmail() const
{
    return mEmail;
}

QString Person::toString() const
{
    return QString("Name is: %1, Afilliation is: %2, Email is: %3").arg(mName).arg(mAffiliation).arg(mEmail);
}
