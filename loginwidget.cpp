#include "loginwidget.h"


#include <QVBoxLayout>
#include <QPixmap>
#include <QSpacerItem>


LoginWidget::LoginWidget(QWidget *parent, Sessione* ses) :
                                                         QWidget(parent),
                                                         session(ses),
                                                         headphoneImage( new QLabel(this)),
                                                         emailLabel( new QLabel(this)),
                                                         pswLabel( new QLabel(this) ),
                                                         emailField( new QLineEdit(this)),
                                                         pswField( new QLineEdit(this)),
                                                         enter( new QPushButton(this)),
                                                         registerButton(new QPushButton(this)),
                                                         quit( new QPushButton(this)),
                                                         showPsw( new QCheckBox() ),
                                                         regWid( new RegisterWidget(/*this*/))

{

    setFixedSize(550, 550);
    setWindowTitle("Login Window");

    QPixmap image(":/new/prefix1/files/headphone.png");
    headphoneImage->setPixmap(image);
    headphoneImage->setScaledContents(true);

    pswField->setEchoMode(QLineEdit::Password);

    showPsw->setText("Show password");

    emailLabel->setText("Enter email address:");
    pswLabel->setText("Enter password:");
    enter->setText("Enter");
    quit->setText("Quit");
    registerButton->setText("Register");


    QVBoxLayout* layout=new QVBoxLayout;
    layout->addWidget(headphoneImage, 0, Qt::AlignCenter);
    layout->addWidget(emailLabel);
    layout->addWidget(emailField);
    layout->addWidget(pswLabel);
    layout->addWidget(pswField);
    layout->addWidget(showPsw);
    layout->addWidget(enter);
    layout->addWidget(quit);
    layout->addWidget(registerButton);


    setLayout(layout);


    connect(quit, SIGNAL(clicked(bool)), this, SLOT( close() ) );
    connect(showPsw, SIGNAL(clicked(bool)), this, SLOT( showPassword() ));
    connect(enter, SIGNAL(clicked(bool)), this, SLOT( tryLogin()) );
    connect(registerButton, SIGNAL(clicked(bool)), this, SLOT( registerUser()) );
    connect(regWid, SIGNAL(updateUserVector()), this, SLOT(updateUserVector()) ) ;

}

void LoginWidget::updateUserVector()    {
    //memory leak?
    session->usersVector.clear();
    session->loadUsers();
    //emit updateUserModel();
}

bool LoginWidget::autorizzaLogin(QString email, QString psw)    {

    /*
    * TEMPLATE FILE UTENTE:
    * email
    * password
    * tipologia account
    * nome
    * cognome
    */
    bool found=false;

    for ( int i = 0 ; i < session->usersVector.size() && !found ; i++ )   {

        QString e = session->usersVector[i]->getEmail();
        QString p = session->usersVector[i]->getPassword();
        QString t = session->usersVector[i]->getTipologiaAbbonamento();
        if ( p==psw && e==email )    {
            found=true;
            session->setPtr(session->usersVector[i]);
            session->setType(t);
        }

    }
    return found;
}

void LoginWidget::tryLogin() {
    QString email=emailField->text();
    QString password=pswField->text();
    Utente* ptr=session->findUser(email);
    bool log=autorizzaLogin(email, password);
    if ( log ) {
        if ( ptr != 0 && dynamic_cast<UtenteAdmin*>(ptr) )  {
            AdminWindow* adminWindow=new AdminWindow( nullptr, session);
            this->close();
            adminWindow->showMaximized();
        } else if ( ptr != 0 && ( dynamic_cast<UtenteFree*>(ptr) || dynamic_cast<UtenteSilver*>(ptr) || dynamic_cast<UtenteGold*>(ptr) ) ) {
            UserWindow* userWindow=new UserWindow( 0, session );
            this->close();
            userWindow->showMaximized();
        }
    }  else {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Login failed!"), tr("Username o password non validi"), QMessageBox::Ok, this);
        fail->show();
    }
}

void  LoginWidget::closeEvent(QCloseEvent* q)   {
    close();
    regWid->close();
}


void LoginWidget::showPassword() {
    if ( pswField->echoMode()==QLineEdit::Password )  {
        pswField->setEchoMode(QLineEdit::Normal );
    }
    else    {
        pswField->setEchoMode(QLineEdit::Password);
    }
}

void LoginWidget::registerUser() {
    regWid->show();
}
