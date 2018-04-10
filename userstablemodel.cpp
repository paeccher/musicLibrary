#include "userstablemodel.h"

UsersTableModel::UsersTableModel(Sessione* ses , QWidget* p) : QAbstractTableModel(p),
                                                                      session(ses)
{
    usersVectorToShow=ses->usersVector;
}



int UsersTableModel::rowCount(const QModelIndex& parent) const  {
    int row=usersVectorToShow.size();
    //return trackVectorToShow.size();
    return row;
}

int UsersTableModel::columnCount(const QModelIndex& parent) const {
    return 6;
}

QVariant UsersTableModel::data(const QModelIndex& index, int role ) const {
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole)    {
        return setField(col, row);
    }
    if ( role == Qt::BackgroundRole )    {
        if ( col==5 )   {
            Utente* ptr=0;
            int i=0;
            ptr=usersVectorToShow[row];
            if ( ptr->hasInfiniteSearch() == true ) {
                QBrush redBackground(Qt::green);
                return redBackground;
            } else  {
                QBrush redBackground(Qt::red);
                return redBackground;
            }
        }
    }
    else
            return QVariant();

}

//devo iterare lista fino alla posizione row-esima, poi in base alla column, quindi con
//uno switch seleziono il giusto campo da outputtare
QString UsersTableModel::setField(int column, int row) const {
    Utente* ptr=0;
    ptr=usersVectorToShow[row];
    switch ( column )   {
    case 0:
        return ptr->getNome();
        break;
    case 1:
        return ptr->getCognome();
        break;
    case 2:
        return ptr->getEmail();
        break;
    case 3:
        return ptr->getPassword();
        break;
    case 4:
        return ptr->getTipologiaAbbonamento();
        break;
    case 5:
        if ( ptr->hasInfiniteSearch() == true ) {
            return QString("YES");
        } else  {
            return QString("NO");
        }
    default:
        return 0;
        break;
    }


}

QVariant UsersTableModel::headerData(int section, Qt::Orientation orientation , int role ) const {
    if (role == Qt::DisplayRole)
       {
           if (orientation == Qt::Horizontal) {
               switch (section)
               {
               case 0:
                   return QString("Name");
               case 1:
                   return QString("Lastname");
               case 2:
                   return QString("Email");
               case 3:
                   return QString("Password");
               case 4:
                   return QString("Plan");
               case 5:
                   return QString("Infinite search:");

               }
           }

       }
       return QVariant();
}

void UsersTableModel::resetModel()  {
    beginResetModel();
    endResetModel();
}
