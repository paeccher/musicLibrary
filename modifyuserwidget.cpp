#include "modifyuserwidget.h"

ModifyUserWidget::ModifyUserWidget(QWidget *parent, QItemSelectionModel* ptr) :
        QWidget(parent),
        selModel(ptr),
        newemailLabel(new QLabel("Email:", this)),
        pswLabel(new QLabel("Password:", this)),
        nameLabel(new QLabel("Nome:", this)),
        lastnameLabel(new QLabel("Cognome", this) ),

        newemailLine(new QLineEdit(this)),
        pswLine(new QLineEdit(this)),
        nameLine(new QLineEdit(this)),
        lastnameLine(new QLineEdit(this)),

        free(new QRadioButton("Free", this)),
        silver(new QRadioButton("Silver", this)),
        gold(new QRadioButton("Gold", this)),

        quit(new QPushButton( "Quit" , this)),
        save(new QPushButton("Save", this)),
        layout(new QVBoxLayout()),
        hlayout(new QHBoxLayout())

{


    hlayout->addWidget(free);
    hlayout->addWidget(silver);
    hlayout->addWidget(gold);

    setFixedSize(280,380);
    layout->addWidget(newemailLabel);
    layout->addWidget(newemailLine);
    layout->addWidget(pswLabel);
    layout->addWidget(pswLine);
    layout->addWidget(nameLabel);
    layout->addWidget(nameLine);
    layout->addWidget(lastnameLabel);
    layout->addWidget(lastnameLine);
    layout->addLayout(hlayout);

    layout->addWidget(save);
    layout->addWidget(quit);

    setLayout(layout);

    connect(quit,SIGNAL(clicked(bool)), this, SLOT(close()) );
    connect(save, SIGNAL(clicked(bool)), this, SLOT (saveSlot()));

}

void ModifyUserWidget::setTextField(QString email, QString psw, QString name, QString lastname, QString type)  {
    setOldemail(email);
    newemailLine->setText(email);
    pswLine->setText(psw);
    nameLine->setText(name);
    lastnameLine->setText(lastname);
    if ( type == "Free" )   {
        free->setChecked(true);
    } else if ( type == "Silver") {
        silver->setChecked(true);
    } else if ( type == "Gold")   {
        gold->setChecked(true);
    }
}

void ModifyUserWidget::saveSlot()   {

    QString newEmail=newemailLine->text();
    QString newPsw=pswLine->text();
    QString newName=nameLine->text();
    QString newLname=lastnameLine->text();
    QString newType;
    if ( free->isChecked() )    {
        newType="Free";
    } else if ( silver->isChecked() )   {
        newType="Silver";
    } else if ( gold->isChecked() ) {
        newType="Gold";
    }

    if ( newEmail=="" || newPsw=="" || newName==""  || newLname=="" )  {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Modifica fallita!"), tr("Riempi i campi da modificare!"), QMessageBox::Ok, this);
        fail->show();
    }


    std::string path("users/");
    std::string oldEmailPath("users/");
    std::string newEmailStd=newEmail.toStdString() ;
    std::string oldEmailStd=oldemail.toStdString();
    path.append(newEmailStd);
    oldEmailPath.append(oldEmailStd);
    std::ifstream in;
    in.open(path);
    if ( oldemail != newEmail ) {

        bool found=false;
        DIR* dir;
        struct dirent *ent;
        const char* em=newEmailStd.c_str();
        dir = opendir(path.c_str());
        if ( dir != NULL )  {
            while ( (ent = readdir(dir)) != NULL && !found )  {
                if ( strcmp(ent->d_name, em) == 0 ) {
                    QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Registrazione fallita!"), tr("Email è già associata ad un account!"), QMessageBox::Ok, this);
                    fail->show();
                    found=true;
                }
            }
        }
        if ( !found )  {
            std::ofstream out;
            std::string em=newEmail.toStdString();
            std::string psw=newPsw.toStdString();
            std::string name=newName.toStdString();
            std::string lname=newLname.toStdString();
            std::string type=newType.toStdString();

            out.open(path);

            out<<em<<std::endl;
            out<<psw<<std::endl;
            out<<type<<std::endl;
            out<<name<<std::endl;
            out<<lname;

            out.close();

            this->close();

            std::remove(oldEmailPath.c_str());

            emit updateUserVector();
        }
    }
    else  {
        std::ofstream out;
        std::string em=newEmail.toStdString();
        std::string psw=newPsw.toStdString();
        std::string name=newName.toStdString();
        std::string lname=newLname.toStdString();
        std::string type=newType.toStdString();

        out.open(path);

        out<<em<<std::endl;
        out<<psw<<std::endl;
        out<<type<<std::endl;
        out<<name<<std::endl;
        out<<lname;

        out.close();

        this->close();

        emit updateUserVector();


    }


}


void ModifyUserWidget::setOldemail(QString oe)  {
    oldemail=oe;
}
