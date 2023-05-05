#include "DialogWindow.h"
#include <QVBoxLayout>

DialogWindow::DialogWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Enter Text");

    lineEdit.reset(new QLineEdit(this));
    okButton.reset(new QPushButton("OK", this));
    cancelButton.reset(new QPushButton("Cancel", this));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit.get());
    layout->addWidget(okButton.get());
    layout->addWidget(cancelButton.get());

    setLayout(layout);

    connect(okButton.get(), &QPushButton::clicked, this, &DialogWindow::onOkButtonClicked);
    connect(cancelButton.get(), &QPushButton::clicked, this, &DialogWindow::onCancelButtonClicked);
}

DialogWindow::~DialogWindow()
{
}

void DialogWindow::onOkButtonClicked()
{
    QString text = lineEdit->text();
    emit textEntered(text);
    close();
}

void DialogWindow::onCancelButtonClicked()
{
    close();
}
