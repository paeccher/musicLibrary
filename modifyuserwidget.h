#ifndef MODIFYUSERWIDGET_H
#define MODIFYUSERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include<QLineEdit>
#include <QMessageBox>
#include <QItemSelectionModel>
#include <fstream>
#include <iostream>
#include <dirent.h>


class ModifyUserWidget : public QWidget
{
    Q_OBJECT
private:
    QString oldemail;
    QItemSelectionModel* selModel;
    QLabel* newemailLabel;
    QLabel* pswLabel;
    QLabel* nameLabel;
    QLabel* lastnameLabel;
    QLineEdit* newemailLine;
    QLineEdit* pswLine;
    QLineEdit* nameLine;
    QLineEdit* lastnameLine;
    QRadioButton* free;
    QRadioButton* silver;
    QRadioButton* gold;
    QPushButton* quit;
    QPushButton* save;
    QVBoxLayout* layout;
    QHBoxLayout* hlayout;


public:
    explicit ModifyUserWidget(QWidget *parent = 0, QItemSelectionModel* ptr=0);
    void setTextField(QString email, QString psw, QString name, QString lastname, QString type);
    void setOldemail(QString oe);
signals:
    void updateUserVector();
public slots:
    void saveSlot();
};

#endif // MODIFYUSERWIDGET_H
