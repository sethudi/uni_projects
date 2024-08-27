#include "xmlhandler.h"

XmlHandler::XmlHandler() {
    tempString ="";
}

bool XmlHandler::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    if (localName == "registration"){
        regType = atts.value("type");
    }
    return true;
}

bool XmlHandler::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    if (localName == "name"){
        name = tempString;
    } else if (localName == "email"){
        email = tempString;
    } else if (localName == "affiliation"){
        affiliation = tempString;
    } else if (localName == "qualification"){
        qualification = tempString;
    } else if (localName == "category"){
        category =tempString;
    } else if (localName == "registration"){
        Registration* reg =NULL;
        if (regType == "Registration"){
            reg = new Registration(Person(name, affiliation, email));
        } else if (regType == "StudentRegistration"){
            reg = new StudentRegistration(Person(name, affiliation, email), qualification);
        }else if (regType == "GuestRegistration"){
            reg = new GuestRegistration(Person(name, affiliation, email), category);
        }

        if (reg != NULL){
            regList.append(reg);
        }
    }

    tempString ="";
    return true;
}

bool XmlHandler::characters(const QString &ch)
{
    tempString += ch;

    return true;
}

QList<Registration *> XmlHandler::getList()
{
    return regList;
}
