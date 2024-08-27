#ifndef MUSICMODELVIEW_H
#define MUSICMODELVIEW_H

#include <QWidget>
#include <QList>
#include "musicdelegate.h"


class QStandardItemModel;
class QTableView;
class QLineEdit;
class QPushButton;
class QSpinBox;
class QDoubleSpinBox;

class MusicModelView : public QWidget
{
    Q_OBJECT
public:
    explicit MusicModelView(QWidget *parent = nullptr);

private slots:
    void addRow();
    void deleteRow();

private:
    void setupGUI();
    QLineEdit *firstInput;
    QLineEdit *secondInput;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QDoubleSpinBox *spinReplacement;
    QSpinBox *spinRating;
    QStandardItemModel *model;
    QTableView *tableView;
    MusicDelegate *colorDelecate;
};

#endif // MUSICMODELVIEW_H
