#include "detailswidget.h"

DetailsWidget::DetailsWidget(QWidget *parent, Sessione *ses) :  QWidget(parent),
                                                                session(ses),
                                                                email(new QLabel()),
                                                                emailLabel(new QLabel()),
                                                                nameLabel(new QLabel()),
                                                                plan(new QLabel()),
                                                                planLabel(new QLabel()),
                                                                name(new QLabel()),
                                                                quit(new QPushButton()),
                                                                layout(new QVBoxLayout())
{
    setFixedSize(170, 230);

    email->setText(session->getPtr()->getEmail());
    name->setText(session->getPtr()->getNome());
    if ( session->getType() == "Free")    {
        plan->setText("Free");
    } else if ( session->getType() == "Gold" )   {
         plan->setText("Gold");
    } else if (session->getType() =="Silver" ) {
         plan->setText("Silver");
    } else  {
         plan->setText("Unknown");
    }
    emailLabel->setText("Your email:");
    nameLabel->setText("Your name");
    planLabel->setText("Your plan:");
    quit->setText("Quit");

    layout->addWidget(emailLabel);
    layout->addWidget(email);
    layout->addWidget(nameLabel);
    layout->addWidget(name);
    layout->addWidget(planLabel);
    layout->addWidget(plan);
    layout->addWidget(quit);

    setLayout(layout);

    connect ( quit, SIGNAL(clicked(bool)), this, SLOT(close()) );
}
