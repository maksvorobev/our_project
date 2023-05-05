#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QSharedPointer>

class DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWindow(QWidget *parent = nullptr);
    ~DialogWindow();

private:
    QSharedPointer<QLineEdit> lineEdit;
    QSharedPointer<QPushButton> okButton;
    QSharedPointer<QPushButton> cancelButton;

signals:
    void textEntered(QString);

private slots:
    void onOkButtonClicked();
    void onCancelButtonClicked();
};

#endif // MYDIALOG_H
