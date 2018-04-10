#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

#include "sessione.h"
#include "registerwidget.h"
#include "newtrackwidget.h"
#include "tracksearchwidget.h"
#include "modifyuserwidget.h"
#include "tablemodeltracks.h"
#include "tabletracksview.h"
#include "tableusersview.h"
#include "userstablemodel.h"
#include "usersearchwidget.h"

#include <fstream>
class AdminWindow : public QWidget
{
    Q_OBJECT
private:
    bool tracksPanelShown;

    Sessione* session;
    TableTracksView* vista;
    TableModelTracks* tracksModel;
    TableUsersView* vistaUsers;
    UsersTableModel* modelUsers;

    QPushButton* usersButton;
    QPushButton* tracksButton;

    QPushButton* addUser;
    QPushButton* removeUser;
    QPushButton* modifyUser;

    QPushButton* addTrack;
    QPushButton* removeTrack;

    QPushButton* quit;
    QGridLayout* layout;
    TrackSearchWidget* search;
    UserSearchWidget* userSearch;

    RegisterWidget* regWid;
    NewTrackWidget* newtrackWid;
    ModifyUserWidget* modifyUserWid;

public:
    AdminWindow(QWidget *parent , Sessione* ses);

protected:
    void  closeEvent(QCloseEvent*);

signals:
    void updateUserModel();
    void updateTrackModel();
public slots:
    void changeViewToUserSlot();
    void changeViewToTracksSlot();
    void addUserSlot();
    void updateUserVector();
    void updateTrackVector();
    void addTrackSlot();
    void addTrackToVectorSlot(QString, QString, QString, QString, QString, QString, QString, QString);
    void removeUserSlot();
    void removeTrackSlot();
    void modifyUserSlot();
   // void adminWindowCloseSlot();
};

#endif // ADMINWINDOW_H
