#include "softwaredate.h"

SoftwareDate::SoftwareDate(QString name, QDate date, bool isRecommended)
    :name(name), date(date), isRecommended(isRecommended)
{

}

QDate SoftwareDate::getDate() {
    return date;
}

QString SoftwareDate::getName(){
    return name;
}

bool SoftwareDate::getIsRecommended(){
    return isRecommended;
}

void SoftwareDate::setDate(QDate date)
{
    this->date = date;
}

void SoftwareDate::setName(QString name)
{
    this->name = name;
}

void SoftwareDate::setIsRecommended(bool isRecommended)
{
    this->isRecommended = isRecommended;
}
