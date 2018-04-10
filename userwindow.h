#ifndef USERWINDOW_H
#define USERWINDOW_H

#include<QDialog>
#include<QWindow>
#include<QLabel>
#include<QTableView>
#include<QToolBar>
#include<QPushButton>
#include<QTabBar>
#include<QWidget>
#include<QSize>
#include<QGridLayout>
#include<QString>
#include<QListView>
#include<QTreeWidget>
#include <QMainWindow>

#include "tracksearchwidget.h"
#include "detailswidget.h"
#include "tabletracksview.h"
#include "sessione.h"
#include "tablemodeltracks.h"

class UserWindow : public QWidget
{
    Q_OBJECT
private:
    Sessione* session;
    TableTracksView* vista;
    TableModelTracks* tracksModel;
    QGridLayout* layout;
    QPushButton* quit;
    QPushButton* showDetails;
    TrackSearchWidget* search;
    DetailsWidget* detailsWidget;
protected:
    void  closeEvent(QCloseEvent* );

public:
    UserWindow(QWidget* parent, Sessione* ses);
private slots:
    void showDetailsSlot();
};

#endif // USERWINDOW_H
