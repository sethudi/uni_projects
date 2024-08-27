#include "musicmodelview.h"

#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QString>

#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>


MusicModelView::MusicModelView(QWidget *parent)
    : QWidget{parent},
    firstInput{new QLineEdit},
    secondInput{new QLineEdit},
    btnAdd{new QPushButton("Add")},
    btnDelete{new QPushButton("Delete")},
    spinReplacement{new QDoubleSpinBox},
    spinRating{new QSpinBox},
    model{new QStandardItemModel(0, 4, this)},
    tableView(new QTableView()),
    colorDelecate{new MusicDelegate()}
{

    // Create a model and Set the model for the table view
    model->setHorizontalHeaderLabels({ "Composer", "Album Title", "Replacement cost", "Rating" });
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(tableView->horizontalHeader()->count() - 1, QHeaderView::Stretch);

    setupGUI();

    connect(btnAdd, &QPushButton::clicked, this, &MusicModelView::addRow);
    connect(btnDelete, &QPushButton::clicked, this, MusicModelView::deleteRow);
}

void MusicModelView::addRow()
{
    QList<QStandardItem*> row;
    row.append(new QStandardItem(firstInput->text()));
    row.append(new QStandardItem(secondInput->text()));
    row.append(new QStandardItem(spinReplacement->text()) );
    row.append(new QStandardItem(spinRating->text()) );

    model->appendRow(row);
    tableView->setItemDelegateForRow(model->rowCount() -1, colorDelecate);
}

void MusicModelView::deleteRow()
{
    QModelIndexList indexList = tableView->selectionModel()->selectedRows();

    for (int i=0; i < indexList.count(); i++){
        int rowNumber;
        QModelIndex index = indexList.at(i);

        rowNumber = index.row();
        model->removeRow(rowNumber);
    }
}

void MusicModelView::setupGUI()
{

    QVBoxLayout *containerLayout = new QVBoxLayout();
    containerLayout->setContentsMargins(30, 20, 30, 20); // Set 20-pixel margins


    QLabel *lblFirstInput(new QLabel("Composer"));
    QLabel *lblSecondInput(new QLabel("Album title"));
    QLabel *lblSpinReplacement(new QLabel("Replacement Cost (R)"));
    QLabel *lblSpinRating(new QLabel("Rating"));

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(lblFirstInput, 0, 0);
    gridLayout->addWidget(lblSecondInput, 0, 1);
    gridLayout->addWidget(lblSpinReplacement, 0, 2);
    gridLayout->addWidget(lblSpinRating, 0, 3);

    gridLayout->addWidget(firstInput, 1, 0);
    gridLayout->addWidget(secondInput, 1, 1);
    gridLayout->addWidget(spinReplacement, 1, 2);
    spinReplacement->setMaximum(1000.00);
    gridLayout->addWidget(spinRating, 1, 3);
    gridLayout->addWidget(btnAdd, 1, 4);

    // Set the stretch factor for each column to ensure they're evenly sized
    gridLayout->setColumnStretch(0, 1);
    gridLayout->setColumnStretch(1, 1);
    gridLayout->setColumnStretch(2, 1);
    gridLayout->setColumnStretch(3, 1);
    gridLayout->setColumnStretch(4, 1);

    containerLayout->addLayout(gridLayout);
    containerLayout->addWidget(tableView);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(); // Add stretchable spacer
    buttonLayout->addWidget(btnDelete);
    containerLayout->addLayout(buttonLayout);

    containerLayout->addWidget(btnDelete);

    setLayout(containerLayout);
}
