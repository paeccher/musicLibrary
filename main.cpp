#include <QApplication>
#include "loginwidget.h"
#include "sessione.h"



int main( int argc, char *argv[] )
{
    QApplication a(argc, argv);

    Sessione* session=new Sessione();
    LoginWidget* login = new LoginWidget( nullptr, session);
    login->show();

    return a.exec();
}
