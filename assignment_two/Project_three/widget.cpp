#include "widget.h"
#include "registration.h"
#include "person.h"
#include "studentregistration.h"
#include "guestregistration.h"
#include "registrationlistwriter.h"


#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include <QComboBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget{parent},
    name{new QLineEdit},
    affiliation{new QLineEdit},
    email{new QLineEdit},
    category{new QLineEdit},
    qualification{new QLineEdit},
    comboBox{new QComboBox},
    addReg{new QPushButton("Add Registration")},
    isReg{new QPushButton("Is Registared?")},
    totalRegs{new QPushButton("Count Registrations")},
    saveReg{new QPushButton("Save Registrations")},
    readBtn{new QPushButton("Read XML")},
    totalFee{new QPushButton("total Fee")}
{
    regList = new RegistrationList();
    tableWidget = new QTableWidget(0, 6);
    setupGUI();
    connect(addReg, &QPushButton::clicked, this, &Widget::addRegistrationHelper);
    connect(isReg, &QPushButton::clicked, this, &Widget::isRegisteredHelper);
    connect(totalRegs, &QPushButton::clicked, this, &Widget::totalRegistrationsHelper);
    connect(totalFee, &QPushButton::clicked, this, &Widget::getTotalFee);
    connect(saveReg, &QPushButton::clicked, this, &Widget::saveRegistrationsHelper);
    connect(readBtn, &QPushButton::clicked, this, &Widget::readXmlHelper);
}

void Widget::addRegistrationHelper()
{
    Person person = Person(name->text(), affiliation->text(), email->text());
    Registration *registration;

    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);

    tableWidget->setItem(row, 0, new QTableWidgetItem(name->text()));
    tableWidget->setItem(row, 1, new QTableWidgetItem(affiliation->text()));
    tableWidget->setItem(row, 2, new QTableWidgetItem(email->text()));
    tableWidget->setItem(row, 3, new QTableWidgetItem(comboBox->currentText()));

    if (comboBox->currentText() == "Registration") {
        registration =new Registration(person);
        tableWidget->setItem(row, 4, new QTableWidgetItem("None"));
        tableWidget->setItem(row, 5, new QTableWidgetItem("None"));
    }else if(comboBox->currentText() == "StudentRegistration") {
        registration = new StudentRegistration(person, qualification->text());
        tableWidget->setItem(row, 4, new QTableWidgetItem("None"));
        tableWidget->setItem(row, 5, new QTableWidgetItem(qualification->text()));
    }else {
        registration = new GuestRegistration(person, category->text());
        tableWidget->setItem(row, 4, new QTableWidgetItem(category->text()));
        tableWidget->setItem(row, 5, new QTableWidgetItem("None"));
    }

    try {
        regList->addRegistration(registration);
        name->clear();
        affiliation->clear();
        email->clear();
        category->clear();
        qualification->clear();
        name->setFocus();
    }catch(QString &e) {
        tableWidget->removeRow(row);
    }

}

void Widget::isRegisteredHelper()
{
    if(regList->isRegistered(name->text())) {
        QMessageBox::information(this, "Information", QString("%1 is already registered").arg(name->text()));
    }
}

void Widget::getTotalFee()
{
    QMessageBox::information(this, "Information", QString("totalFee for %1 is %2").arg(comboBox->currentText()).arg(regList->totalFee(comboBox->currentText())));

}

void Widget::totalRegistrationsHelper()
{
    QMessageBox::information(this, "Information", QString("totalRegistrations for %1 is %2").arg(comboBox->currentText()).arg(regList->totalRegistrations(comboBox->currentText())));
}

void Widget::saveRegistrationsHelper()
{
    RegistrationListWriter regWritter;
    QString result =regWritter.serialize(regList->getList());

    // Open file dialog to select a file
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Open File", "", "Text Files (*.txt)");

    // Read contents of the selected file
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << result;
        file.close();

        QMessageBox::information(nullptr, "Save File", "Text saved to " + filePath);
    } else {
        QMessageBox::warning(nullptr, "Save File", "Could not open file for writing");
    }
}

void Widget::readXmlHelper()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Text Files (*.txt)");
    auto list = reader.read(filePath);

    foreach (Registration* r, list) {
        const QMetaObject *metaobject = r->metaObject();
        QString className =metaobject->className();

        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        tableWidget->setItem(row, 0, new QTableWidgetItem(r->getAttendee().getName().trimmed()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(r->getAttendee().getAffiliation().trimmed()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(r->getAttendee().getEmail().trimmed()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(className));

        if (className == "Registration") {
            tableWidget->setItem(row, 4, new QTableWidgetItem("None"));
            tableWidget->setItem(row, 5, new QTableWidgetItem("None"));
        }else if(className == "StudentRegistration") {
            tableWidget->setItem(row, 4, new QTableWidgetItem("None"));
            tableWidget->setItem(row, 5, new QTableWidgetItem(r->getQualification().trimmed()));
        }else {
            tableWidget->setItem(row, 4, new QTableWidgetItem(r->getCategory().trimmed()));
            tableWidget->setItem(row, 5, new QTableWidgetItem("None"));
        }

        try {
            regList->addRegistration(r);
        }catch(QString &e) {
            tableWidget->removeRow(row);
        }
    }
}

void Widget::setupGUI()
{
    QVBoxLayout *containerLayout = new QVBoxLayout();
    containerLayout->setContentsMargins(30, 20, 30, 20); // Set 20-pixel margins


    QLabel *lblName(new QLabel("Name: "));
    QLabel *lblAffiliation(new QLabel("Affiliation: "));
    QLabel *lblEmail(new QLabel("Email: "));


    QLabel *lblCategory(new QLabel("Category: "));
    QLabel *lblQualification(new QLabel("Qualification: "));

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(lblName, 0, 0);
    gridLayout->addWidget(name, 0, 1);
    gridLayout->addWidget(lblAffiliation, 0, 2);
    gridLayout->addWidget(affiliation, 0, 3);
    gridLayout->addWidget(lblEmail, 0, 4);
    gridLayout->addWidget(email, 0, 5);


    gridLayout->addWidget(lblCategory, 1, 0);
    gridLayout->addWidget(category, 1, 1);
    gridLayout->addWidget(lblQualification, 1, 2);
    gridLayout->addWidget(qualification, 1, 3);

    QLabel *labelSelect(new QLabel("Registration Type:"));
    gridLayout->addWidget(labelSelect, 2, 0);

    comboBox->addItem("Registration");
    comboBox->addItem("StudentRegistration");
    comboBox->addItem("GuestRegistration");
    gridLayout->addWidget(comboBox, 2, 1);

    //TableLayout
    QVBoxLayout *layout = new QVBoxLayout();
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Affiliation" << "Email" << "Registration_Type" << "Category" << "Qualification");
    layout->addWidget(tableWidget);

    containerLayout->addLayout(gridLayout);
    containerLayout->addLayout(layout);

    //Bottom layout
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addReg);
    buttonLayout->addWidget(saveReg);
    buttonLayout->addWidget(readBtn);
    buttonLayout->addWidget(isReg);
    buttonLayout->addWidget(totalRegs);
    buttonLayout->addWidget(totalFee);

    containerLayout->addLayout(buttonLayout);
    setLayout(containerLayout);
}
