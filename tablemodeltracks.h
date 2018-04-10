#ifndef TABLEMODELTRACKS_H
#define TABLEMODELTRACKS_H

#include"brano.h"
#include"sessione.h"
class Sessione;


#include<QAbstractTableModel>
#include<QTreeWidget>
#include<QModelIndex>
#include<QVariant>
#include<QString>
#include <sstream>

class TableModelTracks : public QAbstractTableModel    {
    Q_OBJECT
    friend class TrackSearchWidget;
    friend class UserWindow;
    friend class AdminWindow;
    friend class UtenteFree;
    friend class UtenteSilver;
    friend class UtenteGold;
public:
private:
    Sessione* session;
    QVector<Brano*> trackVectorToShow;

    TableModelTracks(Sessione* ses, QWidget* p = nullptr);
    QString setField(int column, int row) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const ;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation = Qt::Horizontal, int role = Qt::DisplayRole) const;

public slots:
    void resetModel();
   //void showPlaylistSlot( QTreeWidgetItem* , int  );
};

#endif // TABLEMODELTRACKS_H
