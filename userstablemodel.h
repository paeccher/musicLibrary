#ifndef USERSTABLEMODEL_H
#define USERSTABLEMODEL_H

#include"utente.h"
#include"sessione.h"
class Sessione;

class UserSearchWidget;

#include<QAbstractTableModel>
#include<QTreeWidget>
#include<QModelIndex>
#include<QVariant>
#include<QString>
#include<QBrush>

class UsersTableModel : public QAbstractTableModel
{
    Q_OBJECT
    friend class AdminWindow;
    friend class UserSearchWidget;
public:
    UsersTableModel( Sessione* ses, QWidget* p=nullptr);

private:
    Sessione* session;
    QVector<Utente*> usersVectorToShow;

    QString setField(int column, int row) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const ;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation = Qt::Horizontal, int role = Qt::DisplayRole) const;

public slots:
    void resetModel();
};

#endif // USERSTABLEMODEL_H
