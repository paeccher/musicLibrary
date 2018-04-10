#include "userwindow.h"

UserWindow::UserWindow(QWidget *parent, Sessione *ses) :
                            QWidget ( parent ),
                            vista( new TableTracksView(this) ),
                            session(ses),
                            tracksModel( new TableModelTracks(session, this) ),
                            layout( new QGridLayout(this) ),
                            search( new TrackSearchWidget(tracksModel, session) ),
                            showDetails( new QPushButton() ),
                            quit( new QPushButton(this) ),
                            detailsWidget( new DetailsWidget(0, session))


{


    vista->setModel(tracksModel);

    vista->setColumnWidth(0,200);
    vista->setColumnWidth(1,200);
    vista->setColumnWidth(2,100);
    vista->setColumnWidth(3,200);
    vista->setColumnWidth(4,90);
    vista->setColumnWidth(5,90);


    quit->setText("Quit");
    showDetails->setText("Show details");

    search->nascondi();


    QSizePolicy leftPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    leftPolicy.setHorizontalStretch(1);
    search->setSizePolicy(leftPolicy);


    QSizePolicy rightPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    rightPolicy.setHorizontalStretch(3);
    vista->setSizePolicy(rightPolicy);

    layout->addWidget(search,1,1,1,1);
    layout->addWidget(showDetails,2,1,1,1);
    layout->addWidget(vista,1,2,4,1);
    layout->addWidget(quit,4,1,1,1);


    connect(quit, SIGNAL(clicked(bool)), this, SLOT( close() ) );
    connect(search, SIGNAL(updateModel()), tracksModel, SLOT(resetModel()) );
    connect(showDetails, SIGNAL(clicked(bool)), this, SLOT(showDetailsSlot()) );

    setLayout(layout);
}


void  UserWindow::closeEvent(QCloseEvent* q)   {
    close();
    detailsWidget->close();
}


void UserWindow::showDetailsSlot()  {
    //DetailsWidget* detailsWidget=new DetailsWidget( 0, session);
    detailsWidget->show();
}
