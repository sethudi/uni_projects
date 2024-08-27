#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include <QFile>
#include "xmlhandler.h"


class RegistrationListReader
{
public:
    RegistrationListReader();
    QList<Registration*> read(QString path);
};

#endif // REGISTRATIONLISTREADER_H
