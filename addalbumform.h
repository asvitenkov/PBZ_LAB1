#ifndef ADDALBUMFORM_H
#define ADDALBUMFORM_H

#include "ui_addalbumform.h"

class AddAlbumForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddAlbumForm(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddAlbumForm ui;

private slots:
    void addAlbum();
};

#endif // ADDALBUMFORM_H
