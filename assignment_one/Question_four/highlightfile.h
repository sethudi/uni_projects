#ifndef HIGHLIGHTFILE_H
#define HIGHLIGHTFILE_H

#include <QWidget>
class QPushButton;
class QTextEdit;

class HighlightFile : public QWidget
{
    Q_OBJECT
public:
    explicit HighlightFile(QWidget *parent = nullptr);
    QString highlightEmail(const QRegularExpressionMatch &match);

private slots:
    void Load();
    void Process();

private:
    void setupGUI();
    QPushButton *btnLoad;
    QPushButton *btnProcess;
    QString fileContents;
    QTextEdit *textEdit;
};

#endif // HIGHLIGHTFILE_H
