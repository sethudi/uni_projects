#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "registrationlist.h"

class QLineEdit;
class QPushButton;
class QComboBox;
class QTableWidget;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

private slots:
    void addRegistrationHelper();
    void isRegisteredHelper();
    void getTotalFee();
    void totalRegistrationsHelper();
    void saveRegistrationsHelper();

private:
    void setupGUI();
    QLineEdit *name;
    QLineEdit *affiliation;
    QLineEdit *email;
    QLineEdit *category;
    QLineEdit *qualification;
    QPushButton *addReg;
    QPushButton *isReg;
    QPushButton *totalRegs;
    QPushButton *totalFee;
    QPushButton *saveReg;
    QComboBox *comboBox;
    RegistrationList *regList;
    QTableWidget * tableWidget;

};
#endif // WIDGET_H
