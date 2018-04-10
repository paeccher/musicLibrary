#include "registerwidget.h"

RegisterWidget::RegisterWidget(/*LoginWidget* par*/) :
   // genitore(0),
    emailLabel(new QLabel(this)),
    pswLabel(new QLabel(this)),
    secondPswLabel(new QLabel(this)),
    selectPlanLabel(new QLabel(this)),
    nameLabel(new QLabel(this)),
    lastnameLabel(new QLabel(this)),
    emailLine(new QLineEdit(this)),
    pswLine(new QLineEdit(this)),
    secondPswLine(new QLineEdit(this)),
    nameLine(new QLineEdit(this)),
    lastnameLine(new QLineEdit(this)),
    reg(new QPushButton(this)),
    quit(new QPushButton(this)),
    free(new QRadioButton(this)),
    silver(new QRadioButton(this)),
    gold(new QRadioButton(this)),
    layout(new QVBoxLayout()),
    radioButtonLayout( new QHBoxLayout())


{
    setFixedSize(300,500);

    emailLabel->setText("Inserisci indirizzo email:");
    pswLabel->setText("Inserisci la password:");
    secondPswLabel->setText("Reinserisci la password:");
    reg->setText("Registrati");
    quit->setText("Esci");
    selectPlanLabel->setText("Seleziona piano:");
    free->setText("Free");
    silver->setText("Silver");
    gold->setText("Gold");
    nameLabel->setText("Inserisci nome:");
    lastnameLabel->setText("Inserisci cognome:");

    radioButtonLayout->addWidget(free);
    radioButtonLayout->addWidget(silver);
    radioButtonLayout->addWidget(gold);

    free->setChecked(true);

    layout->addWidget(nameLabel);
    layout->addWidget(nameLine);
    layout->addWidget(lastnameLabel);
    layout->addWidget(lastnameLine);
    layout->addWidget(emailLabel);
    layout->addWidget(emailLine);
    layout->addWidget(pswLabel);
    layout->addWidget(pswLine);
    layout->addWidget(secondPswLabel);
    layout->addWidget(secondPswLine);
    layout->addWidget(selectPlanLabel);
    layout->addLayout(radioButtonLayout);
    layout->addWidget(reg);
    layout->addWidget(quit);

    setLayout(layout);

    connect(quit, SIGNAL(clicked(bool)), this, SLOT(quitSlot()) );
    connect(reg, SIGNAL(clicked(bool)), this, SLOT(tryRegistrationSlot()) );

}

void RegisterWidget::quitSlot()  {
    nameLine->setText("");
    lastnameLine->setText("");
    pswLine->setText("");
    emailLine->setText("");
    secondPswLine->setText("");
    lastnameLine->setText("");
    free->setChecked(true);
    this->close();
}

void RegisterWidget::tryRegistrationSlot() {
    QString nome=nameLine->text();
    QString cognome=lastnameLine->text();
    QString email=emailLine->text();
    QString password=pswLine->text();
    QString secondPsw=secondPswLine->text();
    bool datiValidi=true;

    if ( email == "" || nome=="" || cognome=="" || password=="" || secondPsw=="" ) {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Registration failed!"), tr("Non hai riempito qualche campo!"), QMessageBox::Ok, this);
        fail->show();
        datiValidi=false;
    } else if ( password != secondPsw )    {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Registration failed!"), tr("Le due password non corrispondono!"), QMessageBox::Ok, this);
        fail->show();
        datiValidi=false;
    }


    std::string path("users/");
    std::string emailUtente(email.toStdString());
    std::string pswUtente(password.toStdString());
    std::string nomeUtente(nome.toStdString());
    std::string lastnameUtente(cognome.toStdString());

    std::string tipologia;
    if ( free->isChecked() ) {
        tipologia="Free";
    } else if ( silver->isChecked() ) {
        tipologia="Silver";
    } else if ( gold->isChecked() )  {
        tipologia="Gold";
    }


    DIR* dir;
    struct dirent *ent;
    const char* em=emailUtente.c_str();
    dir = opendir(path.c_str());
    if ( dir != NULL )  {
        while ( (ent = readdir(dir)) != NULL && datiValidi )  {
            if ( strcmp(ent->d_name, em) == 0 ) {
                QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Registrazione fallita!"), tr("Email è già associata ad un account!"), QMessageBox::Ok, this);
                fail->show();
                datiValidi=false;
            }

        }
    }

    path.append(em);
    if ( datiValidi )    {
        std::ofstream of;
        of.open(path, std::fstream::out);
        if ( of )   {
            of<<emailUtente<<'\n';
            of<<pswUtente<<'\n';
            of<<tipologia<<'\n';
            of<<nomeUtente<<'\n';
            of<<lastnameUtente;
            of.close();
            QMessageBox* success = new QMessageBox(QMessageBox::Information, tr("Registrazione completata!"), tr("La registrazione è stata effettuata con successo"), QMessageBox::Ok, this);
            success->show();
        }
        nameLine->setText("");
        lastnameLine->setText("");
        pswLine->setText("");
        emailLine->setText("");
        secondPswLine->setText("");
        lastnameLine->setText("");
        free->setChecked(true);

        emit updateUserVector();

        this->close();

    }

}
