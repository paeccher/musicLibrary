#include "tracksearchwidget.h"

TrackSearchWidget::TrackSearchWidget(TableModelTracks* mod, Sessione* ses) :
                                model(mod),
                                session(ses),
                                searchSongLabel(new QLabel(this)),
                                searchArtistLabel(new QLabel(this)),
                                searchAlbumLabel(new QLabel(this)),
                                searchSong(new QLineEdit(this)),
                                searchArtist(new QLineEdit(this)),
                                searchAlbum(new QLineEdit(this)),
                                searchButton(new QPushButton(this)),
                                resetButton(new QPushButton(this)),
                                vertLayout(new QVBoxLayout(this))
{
    searchSongLabel->setText("Insert title:");
    searchArtistLabel->setText("Insert artist:");
    searchAlbumLabel->setText("Insert album:");

    searchButton->setText("Search");
    resetButton->setText("Reset");

    vertLayout->setAlignment(Qt::AlignTop);

    vertLayout->addWidget(searchSongLabel);
    vertLayout->addWidget(searchSong);
    vertLayout->addWidget(searchArtistLabel);
    vertLayout->addWidget(searchArtist);
    vertLayout->addWidget(searchAlbumLabel);
    vertLayout->addWidget(searchAlbum);
    vertLayout->addWidget(searchButton);
    vertLayout->addWidget(resetButton);

    setLayout(vertLayout);

    connect(searchButton, SIGNAL(clicked(bool)), this, SLOT(searchSlot()) );
    connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(resetSlot()) );

}

void TrackSearchWidget::nascondi()    {
    if ( session->getPtr()->getTipoRicerca() == 1 )   {
        searchAlbum->setDisabled(true);
        searchArtist->setDisabled(true);
    }   else if ( session->getPtr()->getTipoRicerca() == 2 )  {
        searchAlbum->setDisabled(true);
    }
}

void TrackSearchWidget::searchSlot() {
    if ( session->getPtr()->hasInfiniteSearch() || session->getPtr()->getRicercheDisponibili() > 0 )    {
        session->getPtr()->diminuisciRicercheDisponibili();
        QString titolo, artista, album;
        titolo=searchSong->text();
        artista=searchArtist->text();
        album=searchAlbum->text();
        model->trackVectorToShow = session->cercaBrano( titolo, artista, album);
        emit updateModel();
    } else  {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Ricerca canzone non riuscita!"), tr("Hai esaurito le ricerche disponibili in una sessione!"), QMessageBox::Ok, this);
        fail->show();

    }
}

void TrackSearchWidget::resetSlot()  {
    model->trackVectorToShow=session->tracksVector;
    emit updateModel();
}
