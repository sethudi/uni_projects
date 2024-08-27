#ifndef PERSON_H
#define PERSON_H

#include <QString>
class Person
{
public:
    Person(QString n, QString a, QString e);
    QString getName() const;
    QString getAffiliation() const;
    QString getEmail() const;
    QString toString() const;

private:
    QString mName;
    QString mAffiliation;
    QString mEmail;

};

#endif // PERSON_H
