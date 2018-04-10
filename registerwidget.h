#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H


class LoginWidget;
#include<QPushButton>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QRadioButton>
#include<fstream>
#include<QMessageBox>
#include <dirent.h>

class RegisterWidget : public QWidget
{
    Q_OBJECT
private:
    //LoginWidget* genitore;
    QLabel* emailLabel;
    QLabel* pswLabel;
    QLabel* secondPswLabel;
    QLabel* selectPlanLabel;
    QLabel* nameLabel;
    QLabel* lastnameLabel;
    QLineEdit* emailLine;
    QLineEdit* pswLine;
    QLineEdit* secondPswLine;
    QLineEdit* nameLine;
    QLineEdit* lastnameLine;
    QRadioButton* free;
    QRadioButton* silver;
    QRadioButton* gold;
    QHBoxLayout* radioButtonLayout;
    QPushButton* reg;
    QPushButton* quit;
    QVBoxLayout* layout;
public:
    RegisterWidget(/*LoginWidget* genitore*/);

signals:
    void updateUserVector();
public slots:
    void quitSlot();
    void tryRegistrationSlot();
};

#endif // REGISTERWIDGET_H
