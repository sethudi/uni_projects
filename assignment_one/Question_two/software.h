#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <QWidget>
#include "softwaredate.h"
#include <QList>
class QLineEdit;
class QDateEdit;
class QCheckBox;
class QPushButton;


class Software : public QWidget
{
    Q_OBJECT
public:
    explicit Software(QWidget *parent = nullptr);

private slots:
    void add();
    void view();

private:
    void setupGUI();
    QLineEdit *edtInput;
    QDateEdit *edtDate;
    QCheckBox *edtBox;
    QPushButton *btnAdd;
    QPushButton *btnDisplay;
    QList<SoftwareDate *> *list;
};

#endif // SOFTWARE_H
