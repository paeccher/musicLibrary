#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include "sessione.h"
#include "userwindow.h"
#include "adminwindow.h"
#include "registerwidget.h"

#include <fstream>
#include <QWidget>
#include <QLineEdit>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

class LoginWidget : public QWidget
{
    Q_OBJECT
private:
    Sessione* session;
    QLabel* headphoneImage;
    QLabel* emailLabel;
    QLabel* pswLabel;
    QLineEdit* emailField;
    QLineEdit* pswField;
    QPushButton* enter;
    QPushButton* registerButton;
    QPushButton* quit;
    QCheckBox* showPsw;
    RegisterWidget* regWid;


    bool autorizzaLogin(QString, QString);

public:
    explicit LoginWidget(QWidget *parent , Sessione *ses );

protected:
    void closeEvent(QCloseEvent* );
public slots:
    void tryLogin();
    void showPassword();
    void registerUser();
    void updateUserVector();
};

#endif // LOGINWIDGET_H
