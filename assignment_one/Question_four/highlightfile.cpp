#include "highlightfile.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

#include <QPushButton>
#include <QTextEdit>

#include <QVBoxLayout>
#include <QHBoxLayout>

HighlightFile::HighlightFile(QWidget *parent)
    : QWidget{parent},
    btnLoad(new QPushButton("Load")),
    btnProcess(new QPushButton("Process")),
    textEdit(new QTextEdit())
{
    setupGUI();
    setWindowTitle("Search");
    setMinimumSize(400, 300);

    connect(btnLoad, &QPushButton::clicked, this, &HighlightFile::Load);
    connect(btnProcess, &QPushButton::clicked, this, &HighlightFile::Process);
}

void HighlightFile::Load()
{
    // Open file dialog to select a file
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");

    // Read contents of the selected file
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        fileContents = in.readAll();
        file.close();

        // Set the file contents as the plain text of the QTextEdit widget
        textEdit->setPlainText(fileContents);

        // Show the window with the QTextEdit widget
        // textEdit->show();
    } else {
        qDebug() << "Failed to open file:" << file.errorString();
    }
}

void HighlightFile::Process()
{ 
    // Define regular expression pattern to match email addresses
    QRegularExpression emailPattern("\\S+@\\S+|\\d{3}-\\d{3}-\\d{4}|\\d{3}-\\d{7}|\\d{10}|\\(\\d{3}\\)\\d{3}-\\d{4}|\\(\\d{3}\\)\\d{7}");

    // Replace all email addresses with highlighted versions
    static QRegularExpressionMatchIterator it = emailPattern.globalMatch(fileContents);

    while (it.hasNext()) {

        QRegularExpressionMatch match = it.next();

        QString replacement = highlightEmail(match);
        fileContents.replace(match.captured(0), replacement);
    }
    fileContents.replace("\n", "<br/>");
    textEdit->setHtml(fileContents);
}

// Function to highlight email addresses
QString HighlightFile::highlightEmail(const QRegularExpressionMatch &match) {
    QString email = match.captured(0); // Get the matched email address
    return "<span style=\"font-weight: bold; \">" + email + "</span>"; // Highlight with blue color
}


void HighlightFile::setupGUI()
{
    QVBoxLayout *containerLayout = new QVBoxLayout();
    // containerLayout->setContentsMargins(30, 20, 30, 20); // Set 20-pixel margins
    setLayout(containerLayout);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(btnLoad);
    buttonsLayout->addWidget(btnProcess);

    containerLayout->addLayout(buttonsLayout);
    containerLayout->addWidget(textEdit);
}
