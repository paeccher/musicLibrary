#include "tabletracksview.h"
#include <iostream>
#include <QMenu>
#include<QHeaderView>
#include <QAction>

TableTracksView::TableTracksView(QWidget* par) : QTableView(par)
{

    setAlternatingRowColors(true);
    setShowGrid(false);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode( QAbstractItemView::SingleSelection );

    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}
