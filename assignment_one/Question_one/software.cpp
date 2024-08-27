#include "software.h"

#include <QDebug>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QCheckBox>

#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>

Software::Software(QWidget *parent)
    : QWidget{parent},
    edtInput(new QLineEdit),
    edtDate(new QDateEdit),
    edtBox(new QCheckBox("Recommend")),
    btnAdd(new QPushButton("Add")),
    btnDisplay(new QPushButton("Display"))
{
    setupGUI();
    setWindowTitle("Software Review");
    setMinimumSize(300, 200);

    //connect signals and slots
    connect(btnAdd, &QPushButton::clicked, this, &Software::add);
    connect(btnDisplay, &QPushButton::clicked, this, &Software::view);
}

void Software::add(){

    QString name = edtInput->text();
    bool checked = edtBox->isChecked();
    QDate selectedDate = edtDate->date();
    SoftwareDate dateCreated(name, selectedDate, checked);

    list.push_back(dateCreated);

    edtDate->setDate(QDate::currentDate());
    edtBox->setChecked(false);
    edtInput->clear();
    edtInput->setFocus();
}

void Software::view(){

    for (auto idx =list.begin(); idx < list.end(); idx ++) {
        qDebug() <<"Name of Software: " << (*idx).getName()
                 << " Date Invented: " << (*idx).getDate().toString("yyyy-MM-dd")
                 << " Is it recommended: " << (*idx).getIsRecommended();
    }

}

void Software::setupGUI(){
    edtDate->setMinimumDate(QDate(2024, 1, 1));
    edtDate->setMaximumDate(QDate(2030, 12, 31));

    QFormLayout *formLayout = new QFormLayout;
    QVBoxLayout *containerLayout = new QVBoxLayout();
    containerLayout->setContentsMargins(30, 20, 30, 20); // Set 20-pixel margins
    setLayout(containerLayout);

    QLabel *lblInput(new QLabel("name"));
    QLabel *lblHeader(new QLabel("Fill in the data and click Add"));
    QLabel *lblDisplay(new QLabel("Date"));

    formLayout->addRow(lblHeader);
    formLayout->addRow(lblInput, edtInput);
    formLayout->addRow(lblDisplay, edtDate);
    formLayout->addRow(edtBox);
    formLayout->addRow(btnAdd, btnDisplay);

    //Initialize widgets
    edtInput->setPlaceholderText("Enter Software Name ");
    edtInput->setToolTip("max 30 charactors");
    edtInput->setMaxLength(30);

    containerLayout->addLayout(formLayout);
}


