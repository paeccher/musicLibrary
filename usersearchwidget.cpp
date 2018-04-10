#include "usersearchwidget.h"

UserSearchWidget::UserSearchWidget(Sessione* ses, UsersTableModel* mod) :
                                            session(ses),
                                            model(mod),
                                            searchEmailLabel(new QLabel(this)),
                                            searchLastnameLabel(new QLabel(this)),
                                            searchNameLabel(new QLabel(this)),
                                            searchButton(new QPushButton(this)),
                                            resetButton(new QPushButton(this)),
                                            searchEmail(new QLineEdit(this)),
                                            searchLastname(new QLineEdit(this)),
                                            searchName(new QLineEdit(this)),
                                            vertLayout(new QVBoxLayout(this))
{
    searchEmailLabel->setText("Insert email:");
    searchNameLabel->setText("Insert name:");
    searchLastnameLabel->setText("Insert lastname:");

    searchButton->setText("Search");
    resetButton->setText("Reset");

    vertLayout->setAlignment(Qt::AlignTop);

    vertLayout->addWidget(searchEmailLabel);
    vertLayout->addWidget(searchEmail);
    vertLayout->addWidget(searchNameLabel);
    vertLayout->addWidget(searchName);
    vertLayout->addWidget(searchLastnameLabel);
    vertLayout->addWidget(searchLastname);
    vertLayout->addWidget(searchButton);
    vertLayout->addWidget(resetButton);

    setLayout(vertLayout);

    connect(searchButton, SIGNAL(clicked(bool)), this, SLOT(searchSlot()) );
    connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(resetSlot()) );


}

void UserSearchWidget::searchSlot() {
    QString email, nome, cognome;
    email=searchEmail->text();
    nome=searchName->text();
    cognome=searchLastname->text();

    model->usersVectorToShow=session->cercaUtente(email, nome, cognome);

    emit updateModel();
}

void UserSearchWidget::resetSlot()  {
    model->usersVectorToShow=session->usersVector;
    emit updateModel();
}
