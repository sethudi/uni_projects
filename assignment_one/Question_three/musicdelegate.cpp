#include "musicdelegate.h"
#include <QPainter>
#include <QDebug>

MusicDelegate::MusicDelegate() {}

void MusicDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    QString str =index.sibling(index.row(), 2).data().toString();
    str.replace(',', '.');
    double value= str.toDouble();


    if (index.column() < 3){
        if(value >= 250)
        {
            // Fill the entire row with the specified color
            painter->fillRect(option.rect, Qt::red);
        }
    }

    if (index.column() == 3)
    {

            double value = index.data().toDouble();
            int barWidth = (value / 100) * option.rect.width(); // Calculate width of bar

            QRect barRect = option.rect.adjusted(2, 2, -2, -2); // Adjust for padding
            barRect.setWidth(barWidth); // Set the width of the bar

            painter->fillRect(barRect, QColor(173, 216, 230)); // Fill the bar with a color (e.g., blue)

    }else if (index.column() == 2){
        QString str =index.data().toString();
        str.replace(',', '.');
        double v= str.toDouble();
        // return locale.toString(v, 'f', 2);
        painter->drawText(option.rect, QString::number(v, 'f', 2));
    }else {
        painter->drawText(option.rect, index.data().toString());
    }

    // QStyledItemDelegate::paint(painter, option, index);
}
