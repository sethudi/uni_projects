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
