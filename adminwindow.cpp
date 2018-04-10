#include "adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent, Sessione *ses) :
                                            tracksPanelShown(false),
                                            session(ses),
                                            tracksModel( new TableModelTracks(session, this) ),
                                            vista( new TableTracksView(this) ),
                                            vistaUsers(new TableUsersView(this)),
                                            modelUsers( new UsersTableModel(ses, this)),
                                            search( new TrackSearchWidget( tracksModel, session )),
                                            userSearch( new UserSearchWidget(ses, modelUsers)),
                                            QWidget(parent),
                                            usersButton(new QPushButton(this)),
                                            tracksButton(new QPushButton(this)),
                                            addUser(new QPushButton(this)),
                                            removeUser(new QPushButton(this)),
                                            modifyUser(new QPushButton(this)),
                                            addTrack(new QPushButton(this)),
                                            removeTrack(new QPushButton(this)),
                                            layout(new QGridLayout(this)),
                                            quit( new QPushButton(this)),
                                            regWid( new RegisterWidget()),
                                            newtrackWid( new NewTrackWidget()),
                                            modifyUserWid( new ModifyUserWidget() )



{
    newtrackWid->hide();
    modifyUserWid->hide();
    regWid->hide();

    usersButton->setText("Go to Users panel");
    tracksButton->setText("Go to Tracks panel");
    quit->setText("Quit");

    addUser->setIcon(QIcon(":/new/prefix1/files/addusericon.png"));
    addUser->setIconSize(QSize(44,44));
    modifyUser->setIcon(QIcon(":/new/prefix1/files/modifyusericon.png"));
    modifyUser->setIconSize(QSize(44,44));
    removeUser->setIcon(QIcon(":/new/prefix1/files/removeusericon.png"));
    removeUser->setIconSize(QSize(44,44));

    addTrack->setIcon(QIcon(":/new/prefix1/files/addtrackicon.png"));
    addTrack->setIconSize(QSize(44,44));
    removeTrack->setIcon(QIcon(":/new/prefix1/files/removetrackicon.png"));
    removeTrack->setIconSize(QSize(44,44));

    vista->setModel(tracksModel);
    vista->setColumnWidth(0,200);
    vista->setColumnWidth(1,200);
    vista->setColumnWidth(2,100);
    vista->setColumnWidth(3,200);
    vista->setColumnWidth(4,90);
    vista->setColumnWidth(5,90);

    vistaUsers->setModel(modelUsers);

    QSizePolicy leftTSPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    leftTSPolicy.setHorizontalStretch(1);
    search->setSizePolicy(leftTSPolicy);

    QSizePolicy rightTVPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    rightTVPolicy.setHorizontalStretch(3);
    vista->setSizePolicy(rightTVPolicy);

    QSizePolicy leftUSPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    leftUSPolicy.setHorizontalStretch(1);
    userSearch->setSizePolicy(leftUSPolicy);

    QSizePolicy rightUVPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    rightUVPolicy.setHorizontalStretch(3);
    vistaUsers->setSizePolicy(rightUVPolicy);

    QSizePolicy leftButtonsPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    leftButtonsPolicy.setHorizontalStretch(1);
    addUser->setSizePolicy(leftButtonsPolicy);
    modifyUser->setSizePolicy(leftButtonsPolicy);
    removeUser->setSizePolicy(leftButtonsPolicy);

    QHBoxLayout* userHl=new QHBoxLayout();
    userHl->addWidget(addUser);
    userHl->addWidget(modifyUser);
    userHl->addWidget(removeUser);

    QHBoxLayout* trackHl=new QHBoxLayout();
    trackHl->addWidget(addTrack);
    trackHl->addWidget(removeTrack);

    layout->addWidget(tracksButton,9,1,1,1);
    layout->addWidget(usersButton,10,1,1,1);
    layout->addLayout(userHl,2,1,1,1);
    layout->addLayout(trackHl,2,1,1,1);
    layout->addWidget(search, 1,1,1,1);
    layout->addWidget(vista, 1,2,11,1);
    layout->addWidget(userSearch,1,1,1,1);
    layout->addWidget(vistaUsers, 1,2,11,1);
    layout->addWidget(quit, 11,1,1,1);
    setLayout(layout);


    usersButton->setEnabled(false);
    search->hide();
    vista->hide();
    addTrack->hide();
    removeTrack->hide();

    connect ( quit, SIGNAL(clicked(bool)), this, SLOT(close()) );

    connect ( search, SIGNAL(updateModel()), tracksModel, SLOT(resetModel()) );
    connect ( userSearch, SIGNAL(updateModel()), modelUsers, SLOT(resetModel()) );
    connect ( usersButton, SIGNAL(clicked(bool)), this, SLOT(changeViewToUserSlot()) );
    connect ( tracksButton, SIGNAL(clicked(bool)), this, SLOT(changeViewToTracksSlot()) );
    connect ( addUser, SIGNAL(clicked(bool)), this, SLOT(addUserSlot()) );
    connect ( regWid, SIGNAL(updateUserVector()), this, SLOT(updateUserVector()) );
    connect ( modifyUserWid, SIGNAL(updateUserVector()), this, SLOT(updateUserVector()) );
    connect ( newtrackWid, SIGNAL(updateTrackVector()), this, SLOT(updateTrackVector()) );
    connect ( this, SIGNAL(updateUserModel()), modelUsers, SLOT(resetModel()) );
    connect ( this, SIGNAL(updateTrackModel()), tracksModel, SLOT(resetModel()) );
    connect ( addTrack, SIGNAL(clicked(bool)), this, SLOT(addTrackSlot()) );
    connect ( removeUser, SIGNAL(clicked(bool)), this, SLOT(removeUserSlot()) );
    connect ( newtrackWid, SIGNAL(addTrackSignal(QString, QString,QString, QString,QString, QString, QString, QString)), this, SLOT(addTrackToVectorSlot(QString, QString,QString, QString,QString, QString, QString, QString)) );
    connect ( removeTrack, SIGNAL(clicked(bool)) , this, SLOT(removeTrackSlot()) );
    connect ( modifyUser, SIGNAL(clicked(bool)), this, SLOT(modifyUserSlot()) );


}

void AdminWindow::modifyUserSlot()  {

    QItemSelectionModel* selection = vistaUsers->selectionModel();
    if ( selection->hasSelection() )    {

        QString email;
        int emailrowidx=vistaUsers->selectionModel()->currentIndex().row();
        email = modelUsers->index(emailrowidx, 2).data().toString();

        QString psw;
        int pswrowidx=vistaUsers->selectionModel()->currentIndex().row();
        psw = modelUsers->index(pswrowidx, 3).data().toString();

        QString name;
        int namerowidx=vistaUsers->selectionModel()->currentIndex().row();
        name = modelUsers->index(namerowidx, 0).data().toString();

        QString lastname;
        int lnamerowidx=vistaUsers->selectionModel()->currentIndex().row();
        lastname = modelUsers->index(lnamerowidx, 1).data().toString();

        QString type;
        int typerowidx=vistaUsers->selectionModel()->currentIndex().row();
        type = modelUsers->index(typerowidx, 4).data().toString();

        if ( ! dynamic_cast<UtenteAdmin*>(session->usersVector[ vistaUsers->selectionModel()->currentIndex().row() ]) ) {
            modifyUserWid->setTextField(email, psw, name, lastname, type);
            modifyUserWid->show();
        } else  {
            QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Modifica utente non riuscita!"), tr("L'utente che vuoi modificare è Admin!"), QMessageBox::Ok, this);
            fail->show();
        }

        emit updateUserModel();

    } else  {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Modifica utente non riuscita!"), tr("Seleziona un utente per modificarne i dati!"), QMessageBox::Ok, this);
        fail->show();

    }

}

void  AdminWindow::closeEvent(QCloseEvent* q)   {
    close();
    regWid->close();
    newtrackWid->close();
    modifyUserWid->close();
}
/*
void AdminWindow::adminWindowCloseSlot() {
    close();
    regWid->close();
    newtrackWid->close();
    modifyUserWid->close();
}
*/


void AdminWindow::addTrackToVectorSlot(QString title, QString artist, QString album, QString genre, QString minutes, QString seconds, QString dimension, QString year)    {
    session->addTrack(title, artist, album, genre, minutes, seconds, dimension, year);
    emit updateUserModel();
}

void AdminWindow::addUserSlot() {
    regWid->show();
}

void AdminWindow::addTrackSlot()    {
    newtrackWid->show();
}


void AdminWindow::changeViewToUserSlot()    {
    if ( tracksPanelShown ) {
        vista->hide();
        search->hide();
        addTrack->hide();
        removeTrack->hide();
        addUser->show();
        modifyUser->show();
        removeUser->show();
        vistaUsers->show();
        userSearch->show();
        tracksButton->setEnabled(true);
        usersButton->setEnabled(false);
        tracksPanelShown=false;
    }
}


void AdminWindow::changeViewToTracksSlot()    {
    if ( !tracksPanelShown ) {
        vistaUsers->hide();
        userSearch->hide();
        addUser->hide();
        modifyUser->hide();
        removeUser->hide();
        vista->show();
        search->show();
        addTrack->show();
        removeTrack->show();

        usersButton->setEnabled(true);
        tracksButton->setEnabled(false);
        tracksPanelShown=true;
    }
}

void AdminWindow::updateUserVector()    {
    //memory leak?
    session->usersVector.clear();
    /*
    for ( int i = 0 ; i < session->usersVector.size() ; i++ )   {
        delete session->usersVector[i];
        session->usersVector.remove(i);
    }*/
    session->loadUsers();
    modelUsers->usersVectorToShow=session->usersVector;
    emit updateUserModel();
}

void AdminWindow::updateTrackVector()   {
    //mem leak
    session->tracksVector.clear();
    session->loadTracks();
    tracksModel->trackVectorToShow=session->tracksVector;
    emit updateTrackModel();

}

void AdminWindow::removeUserSlot()  {
    QItemSelectionModel* selection = vistaUsers->selectionModel();
    if ( selection->hasSelection() )    {
        QString email, tipo;
        int rowidx=vistaUsers->selectionModel()->currentIndex().row();
        email = modelUsers->index(rowidx, 2).data().toString();
        tipo = modelUsers->index(rowidx, 4).data().toString();
        if ( email != "" )  {
            if ( tipo != "Admin" )  {
                session->removeUser(email);
                session->usersVector.clear();
                session->loadUsers();
                modelUsers->usersVectorToShow=session->usersVector;
                emit updateUserModel();
            }   else    {
                QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Rimozione utente non riuscita!"), tr("Non puoi eliminare un admin!"), QMessageBox::Ok, this);
                fail->show();
            }

        } else  {
            QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Rimozione utente non riuscita!"), tr("Errore!"), QMessageBox::Ok, this);
            fail->show();
        }
    }   else    {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Rimozione utente non riuscita!"), tr("Seleziona un utente per rimuoverlo."), QMessageBox::Ok, this);
        fail->show();
    }
}

void AdminWindow::removeTrackSlot()  {

    QItemSelectionModel* selection = vista->selectionModel();
    if ( selection->hasSelection() )    {
        QString title;
        int rowidx=vista->selectionModel()->currentIndex().row();
        title = tracksModel->trackVectorToShow[rowidx]->getNomeBrano();

        if ( title != "" )  {
            session->removeTrack(title);
            session->tracksVector.clear();
            session->loadTracks();
            tracksModel->trackVectorToShow=session->tracksVector;
            emit updateTrackModel();

        } else  {
            QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Rimozione brano non riuscita!"), tr("Errore!"), QMessageBox::Ok, this);
            fail->show();
        }
    }   else    {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Rimozione brano non riuscita!"), tr("Seleziona un brano per rimuoverlo."), QMessageBox::Ok, this);
        fail->show();
    }

}
