#ifndef SOFTWAREDATE_H
#define SOFTWAREDATE_H

#include <QObject>
#include <QDate>
#include <QString>
#include <QMetaObject>
#include <QMetaProperty>

class SoftwareDate : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDate date READ getDate WRITE setDate)
    Q_PROPERTY(bool isRecommended READ getIsRecommended WRITE setIsRecommended)
public:
    SoftwareDate(QString name,QDate date,bool isRecommended);
    QDate getDate();
    QString getName();
    bool getIsRecommended();
    void setDate(QDate date);
    void setName(QString name);
    void setIsRecommended(bool isRecommended);

private:
    QString name;
    QDate date;
    bool isRecommended;
};

#endif // SOFTWAREDATE_H
