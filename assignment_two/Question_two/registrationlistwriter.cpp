#include "registrationlistwriter.h"

RegistrationListWriter::RegistrationListWriter() {}

QString RegistrationListWriter::serialize(QList<Registration *> list)
{
    QDomDocument doc;

    QDomElement root= doc.createElement("registrationlist");
    doc.appendChild(root);

    foreach (Registration * reg, list) {
        const QMetaObject *metaobject = reg->metaObject();
        QString className =metaobject->className();

        QDomElement regElement = doc.createElement("registration");
        root.appendChild(regElement);
        regElement.setAttribute("type", className);

        QDomElement attendeeElement = doc.createElement("attendee");
        regElement.appendChild(attendeeElement);

        Person p = reg->getAttendee();
        QDomElement nameElement = doc.createElement("name");
        attendeeElement.appendChild(nameElement);

        QDomText nameText = doc.createTextNode(p.getName());
        nameElement.appendChild(nameText);

        QDomElement affiliationElement = doc.createElement("affiliation");
        attendeeElement.appendChild(affiliationElement);

        QDomText affiliationText = doc.createTextNode(p.getAffiliation());
        affiliationElement.appendChild(affiliationText);

        QDomElement emailElement = doc.createElement("email");
        attendeeElement.appendChild(emailElement);

        QDomText emailText = doc.createTextNode(p.getEmail());
        emailElement.appendChild(emailText);

        QDomElement regFeeElement = doc.createElement("registrationfee");
        regElement.appendChild(regFeeElement);

        QDomText regFeeText = doc.createTextNode(QString::number(reg->calculateFee()));
        regFeeElement.appendChild(regFeeText);

        if (className == "GuestRegistration") {
            QDomElement categoryElement = doc.createElement("category");
            regElement.appendChild(categoryElement);

            QDomText categoryText = doc.createTextNode(reg->getCategory());
            categoryElement.appendChild(categoryText);

        } else if (className == "StudentRegistration") {
            QDomElement qualificationElement = doc.createElement("qualification");
            regElement.appendChild(qualificationElement);

            QDomText qualificationText = doc.createTextNode(reg->getQualification());
            qualificationElement.appendChild(qualificationText);
        }


    }

    return doc.toString();
}
