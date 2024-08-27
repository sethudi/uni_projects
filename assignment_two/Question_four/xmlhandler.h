#ifndef XMLHANDLER_H
#define XMLHANDLER_H

#include <QXmlDefaultHandler>
#include "registration.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "person.h"
#include <QList>
class XmlHandler: public QXmlDefaultHandler
{
public:
    XmlHandler();
    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
    bool characters(const QString &ch);
    QList<Registration*> getList();

private:
    QString tempString, name, email, affiliation, qualification, category, regType;
    QList<Registration*> regList;
};


#endif // XMLHANDLER_H
