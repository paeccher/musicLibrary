#ifndef TRACKSEARCHWIDGET_H
#define TRACKSEARCHWIDGET_H


#include "tablemodeltracks.h"
#include "sessione.h"

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QVBoxLayout>


class TrackSearchWidget : public QWidget
{
    Q_OBJECT
    friend class Utente;
private:
    QLabel* searchSongLabel;
    QLabel* searchArtistLabel;
    QLabel* searchAlbumLabel;
    Sessione* session;
    QLineEdit* searchSong;
    QLineEdit* searchArtist;
    QLineEdit* searchAlbum;
    QPushButton* searchButton;
    QPushButton* resetButton;
    QGridLayout* gridLayout;
    QVBoxLayout* vertLayout;
    TableModelTracks* model;
public:
    TrackSearchWidget(TableModelTracks* mod, Sessione* ses);
    void nascondi();

private slots:

    void searchSlot();
    void resetSlot();
signals:
    void updateModel();

};

#endif // TRACKSEARCHWIDGET_H
