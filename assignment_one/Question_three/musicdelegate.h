#ifndef MUSICDELEGATE_H
#define MUSICDELEGATE_H
#include <QStyledItemDelegate>

class MusicDelegate: public QStyledItemDelegate
{
public:
    MusicDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // MUSICDELEGATE_H
