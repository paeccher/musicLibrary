#include "tablemodeltracks.h"



TableModelTracks::TableModelTracks(Sessione *ses, QWidget* p) : QAbstractTableModel(p),
                                                               session(ses)
{
    //trackVectorToShow=trackVector;
    trackVectorToShow=ses->tracksVector;
}



int TableModelTracks::rowCount(const QModelIndex& parent) const  {
    int row=trackVectorToShow.size();
    //return trackVectorToShow.size();
    return row;
}

int TableModelTracks::columnCount(const QModelIndex& parent) const {
    return 7;
}

QVariant TableModelTracks::data(const QModelIndex& index, int role ) const {
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole)
        return setField(col, row);
    else
            return QVariant();

}

//devo iterare lista fino alla posizione row-esima, poi in base alla column, quindi con
//uno switch seleziono il giusto campo da outputtare
QString TableModelTracks::setField(int column, int row) const {
    /* devo prendere una coppia colonna, riga e fare output del field corretto
     * colonna indica il campo ( titolo, artista....)
     * riga indica il numero della canzone
     * return setField(column, row)
     */

    Brano* ptr=0;
    if ( trackVectorToShow.size() ) {

        ptr=trackVectorToShow[row];
        if ( ptr )  {
            switch ( column )   {
            case 0:
                return ptr->getNomeBrano();
                break;
            case 1:
                return ptr->getArtista();
                break;
            case 2:
                return ptr->getDurataBrano();
                break;
            case 3:
                return ptr->getAlbumBrano();
                break;
            case 4:
                return ptr->getGenereBrano();
                break;
            case 5:
                return ptr->getAnnoBrano();
                break;
            case 6:
            {
                return QString(QString::number(ptr->getDimensioneBrano(),'f', 2));
                break;
            }
            default:
                return 0;
                break;
            }
        }
    }

}

QVariant TableModelTracks::headerData(int section, Qt::Orientation orientation , int role ) const {
    if (role == Qt::DisplayRole)
       {
           if (orientation == Qt::Horizontal) {
               switch (section)
               {
               case 0:
                   return QString("Song");
               case 1:
                   return QString("Artist");
               case 2:
                   return QString("Length");
               case 3:
                   return QString("Album");
               case 4:
                   return QString("Genre");
               case 5:
                   return QString("Year");
               case 6:
                   return QString("Dimension");

               }
           }
           /*
           if ( orientation== Qt::Vertical) {
               return section+1;
           }
           */
       }
       return QVariant();
}

void TableModelTracks::resetModel()  {
    beginResetModel();
    endResetModel();
}
/*
void TableModelTracks::showPlaylistSlot( QTreeWidgetItem* i , int  ){
    QString titoloPlay=i->child(0)->text(0);




    std::cout<<"slot azionato"<<std::endl;
}
*/
