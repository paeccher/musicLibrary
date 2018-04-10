#ifndef DETAILSWIDGET_H
#define DETAILSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <qpushbutton.h>
#include <sessione.h>

class DetailsWidget : public QWidget
{
    Q_OBJECT
public:
    DetailsWidget(QWidget *parent, Sessione* ses);
private:
    Sessione* session;
    QVBoxLayout* layout;
    QLabel* email;
    QLabel* emailLabel;
    QLabel* name;
    QLabel* nameLabel;
    QLabel* plan;
    QLabel* planLabel;
    QPushButton* quit;
signals:

public slots:
};

#endif // DETAILSWIDGET_H
