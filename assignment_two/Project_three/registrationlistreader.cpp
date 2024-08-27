#include "registrationlistreader.h"

RegistrationListReader::RegistrationListReader() {}

QList<Registration *> RegistrationListReader::read(QString path)
{
    QXmlSimpleReader reader;

    XmlHandler handler;
    reader.setContentHandler(&handler);

    QFile file(path);

    if(file.open(QFile::ReadOnly | QFile::Text)) {
        QXmlInputSource xmlSource(&file);

        if(reader.parse(xmlSource)){
            QList<Registration*> list =handler.getList();

            return list;
        }
        file.close();
    }

    return QList<Registration*>();
}
