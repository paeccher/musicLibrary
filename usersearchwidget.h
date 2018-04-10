#ifndef USERSEARCHWIDGET_H
#define USERSEARCHWIDGET_H

#include "sessione.h"
#include "userstablemodel.h"

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class UserSearchWidget : public QWidget
{
    Q_OBJECT
public:
    UserSearchWidget(Sessione* ses, UsersTableModel* mod);
private:
    QLabel* searchNameLabel;
    QLabel* searchLastnameLabel;
    QLabel* searchEmailLabel;
    QLineEdit* searchName;
    QLineEdit* searchLastname;
    QLineEdit* searchEmail;
    QPushButton* searchButton;
    QPushButton* resetButton;
    Sessione* session;
    UsersTableModel* model;
    QVBoxLayout* vertLayout;
signals:
    void updateModel();
public slots:
    void searchSlot();
    void resetSlot();
};

#endif // USERSEARCHWIDGET_H
