#include "tableusersview.h"
#include <QHeaderView>

TableUsersView::TableUsersView(QWidget *par) : QTableView(par)
{

    setAlternatingRowColors(true);

    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    setShowGrid(false);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode( QAbstractItemView::SingleSelection );
}
