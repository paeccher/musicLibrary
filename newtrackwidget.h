#ifndef NEWTRACKWIDGET_H
#define NEWTRACKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLocale>
#include <fstream>
#include <dirent.h>
#include <math.h>


class NewTrackWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel* titleLabel;
    QLabel* artistLabel;
    QLabel* albumLabel;
    QLabel* genreLabel;
    QLabel* dimensionLabel;
    QLabel* lenghtMinutesLabel;
    QLabel* lenghtSecondsLabel;
    QLabel* yearLabel;
    QLineEdit* titleLine;
    QLineEdit* artistLine;
    QLineEdit* albumLine;
    QLineEdit* genreLine;
    QLineEdit* dimensionLine;
    QLineEdit* lenghtMinutesLine;
    QLineEdit* lenghtSecondsLine;
    QLineEdit* yearLine;
    QVBoxLayout* vertLayout;
    QPushButton* quit;
    QPushButton* add;

public:
    NewTrackWidget(QWidget *parent = 0);

signals:
    void addTrackSignal(QString, QString,QString, QString,QString, QString, QString, QString);
    void updateTrackVector();
public slots:
    void checkDataSlot();
    void closeSlot();
};

#endif // NEWTRACKWIDGET_H
