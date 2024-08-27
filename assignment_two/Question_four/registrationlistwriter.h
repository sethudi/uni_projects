#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H

#include "registration.h"
#include <QList>
#include <QDomDocument>

class RegistrationListWriter
{
public:
    RegistrationListWriter();

    QString serialize(QList<Registration*> list);
};

#endif // REGISTRATIONLISTWRITER_H
