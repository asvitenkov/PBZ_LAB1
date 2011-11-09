#ifndef LISTOFALLGROUPALBUMS_H
#define LISTOFALLGROUPALBUMS_H

#include "ui_listofallgroupalbums.h"

class ListOfAllGroupAlbums : public QWidget
{
    Q_OBJECT

public:
    explicit ListOfAllGroupAlbums(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ListOfAllGroupAlbums ui;
    QStringList getAllMusGroupInDB();

private slots:
    void currentIndexChangedSlot(QString);
};

#endif // LISTOFALLGROUPALBUMS_H
