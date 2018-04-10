#include "newtrackwidget.h"

NewTrackWidget::NewTrackWidget(QWidget *parent) :
        QWidget(parent),
        titleLabel(new QLabel(this)),
        artistLabel(new QLabel(this)),
        albumLabel(new QLabel(this)),
        genreLabel(new QLabel(this)),
        dimensionLabel(new QLabel(this)),
        lenghtMinutesLabel(new QLabel(this)),
        lenghtSecondsLabel(new QLabel(this)),
        yearLabel(new QLabel(this)),
        titleLine(new QLineEdit(this)),
        artistLine(new QLineEdit(this)),
        albumLine(new QLineEdit(this)),
        genreLine(new QLineEdit(this)),
        dimensionLine(new QLineEdit(this)),
        lenghtMinutesLine(new QLineEdit(this)),
        lenghtSecondsLine(new QLineEdit(this)),
        yearLine(new QLineEdit(this)),
        vertLayout(new QVBoxLayout(this)),
        quit(new QPushButton(this)),
        add(new QPushButton(this))
{

    setFixedSize(300,580);


    titleLabel->setText("Inserisci titolo:");
    artistLabel->setText("Inserisci artista:");
    albumLabel->setText("Inserisci album:");
    genreLabel->setText("Inserisci genere:");
    dimensionLabel->setText("Inserisci dimensione in MB:");
    lenghtMinutesLabel->setText("Inserisci la lunghezza in minuti:");
    lenghtSecondsLabel->setText("Inserisci la lunghezza in secondi:");
    yearLabel->setText("Inserisci anno:");
    quit->setText("Esci");
    add->setText("Aggiungi!");

    vertLayout->addWidget(titleLabel);
    vertLayout->addWidget(titleLine);
    vertLayout->addWidget(artistLabel);
    vertLayout->addWidget(artistLine);
    vertLayout->addWidget(albumLabel);
    vertLayout->addWidget(albumLine);
    vertLayout->addWidget(genreLabel);
    vertLayout->addWidget(genreLine);
    vertLayout->addWidget(dimensionLabel);
    vertLayout->addWidget(dimensionLine);
    vertLayout->addWidget(lenghtMinutesLabel);
    vertLayout->addWidget(lenghtMinutesLine);
    vertLayout->addWidget(lenghtSecondsLabel);
    vertLayout->addWidget(lenghtSecondsLine);
    vertLayout->addWidget(yearLabel);
    vertLayout->addWidget(yearLine);
    vertLayout->addWidget(add);
    vertLayout->addWidget(quit);

    setLayout(vertLayout);

    connect(quit, SIGNAL(clicked(bool)), this, SLOT(closeSlot()) );
    connect(add, SIGNAL(clicked(bool)), this, SLOT(checkDataSlot()) );

}


void NewTrackWidget::closeSlot()    {
    titleLine->setText("");
    artistLine->setText("");
    genreLine->setText("");
    yearLine->setText("");
    albumLine->setText("");
    dimensionLine->setText("");
    lenghtMinutesLine->setText("");
    lenghtSecondsLine->setText("");
    this->close();
}


void NewTrackWidget::checkDataSlot()    {
    //QLocale c(QLocale::Italian);

    QString title, artist, album, genre, minutes, seconds, dimension, year;
    title=titleLine->text();
    artist=artistLine->text();
    album=albumLine->text();
    genre=genreLine->text();
    minutes=lenghtMinutesLine->text();
    seconds=lenghtSecondsLine->text();
    dimension=dimensionLine->text();
    year=yearLine->text();

    double dim=dimension.toDouble() ;
    int m=minutes.toInt();
    int s=seconds.toInt();

    if ( title=="" || artist =="" || album=="" || genre=="" || minutes=="" || seconds=="" || dimension=="" || year=="" )    {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Inserimento nuova canzone non riuscito!"), tr("Non hai riempito tutti i campi!"), QMessageBox::Ok, this);
        fail->show();
    } else if ( !dim ) {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Inserimento nuova canzone non riuscito!"), tr("Campo dimensione non valido!"), QMessageBox::Ok, this);
        fail->show();
    } else if ( !m) {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Inserimento nuova canzone non riuscito!"), tr("Campo minuti non valido!"), QMessageBox::Ok, this);
        fail->show();
    } else if ( !s ) {
        QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Inserimento nuova canzone non riuscito!"), tr("Campo secondi non valido!"), QMessageBox::Ok, this);
        fail->show();
    } else if ( title!="" || artist!="" ||album!=""||genre!=""||minutes!=""||seconds!=""||dimension!=""||year!=""){
        std::fstream io;

        std::string tit=title.toStdString();
        std::string path="tracks/";

        DIR* dir;
        struct dirent *ent;
        const char* em=tit.c_str();
        dir = opendir(path.c_str());
        bool datiValidi=true;
        if ( dir != NULL )  {
            while ( (ent = readdir(dir)) != NULL && datiValidi )  {
                if ( strcmp(ent->d_name, em) == 0 ) {
                    QMessageBox* fail = new QMessageBox(QMessageBox::Warning, tr("Inserimento canzone fallito!"), tr("Esiste una canzone con il medesimo titolo!"), QMessageBox::Ok, this);
                    fail->show();
                    datiValidi=false;
                }

            }
        }

        if ( datiValidi )   {
            path.append(tit);
            io.open(path , std::fstream::out);
            std::string titleStd, artistStd, albumStd, genreStd, minutesStd, secondStd, dimensionStd, yearStd;
            double dim=dimension.toDouble(), intp;
            double* intpart=&intp;
            dim=modf(dim, intpart);

            titleStd=title.toStdString();
            artistStd=artist.toStdString();
            albumStd=album.toStdString();
            genreStd=genre.toStdString();
            minutesStd=minutes.toStdString();
            secondStd=seconds.toStdString();
            dimensionStd=dimension.toStdString();

            yearStd=year.toStdString();

            io<<std::endl;
            io<<titleStd<<std::endl;
            io<<artistStd<<std::endl;
            io<<*intpart<<","<<dim*100<<std::endl;
            //io<<dimensionStd<<std::endl;
            io<<minutesStd<<std::endl;
            io<<secondStd<<std::endl;
            io<<genreStd<<std::endl;
            io<<yearStd<<std::endl;
            io<<albumStd;
            io<<std::endl;
            io.close();

            QMessageBox* success = new QMessageBox(QMessageBox::Information, tr("Inserimento brano completato!"), tr("L'inserimento del brano è riuscito!"), QMessageBox::Ok, this);
            success->show();
            emit updateTrackVector();

        }

    }



    titleLine->setText("");
    artistLine->setText("");
    genreLine->setText("");
    yearLine->setText("");
    albumLine->setText("");
    dimensionLine->setText("");
    lenghtMinutesLine->setText("");
    lenghtSecondsLine->setText("");

    this->close();
}



