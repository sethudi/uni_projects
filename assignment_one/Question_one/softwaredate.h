#ifndef SOFTWAREDATE_H
#define SOFTWAREDATE_H

#include <QDate>
#include <QString>

class SoftwareDate
{
public:
    SoftwareDate(QString name,QDate date,bool isRecommended);
    QDate getDate();
    QString getName();
    bool getIsRecommended();

private:
    QString name;
    QDate date;
    bool isRecommended;
};

#endif // SOFTWAREDATE_H
