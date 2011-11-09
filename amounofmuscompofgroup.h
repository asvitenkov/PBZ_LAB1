#ifndef AMOUNOFMUSCOMPOFGROUP_H
#define AMOUNOFMUSCOMPOFGROUP_H

#include "ui_amounofmuscompofgroup.h"
#include <QSqlTableModel>

class AmounOfMusCompOfGroup : public QWidget
{
    Q_OBJECT

public:
    explicit AmounOfMusCompOfGroup(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AmounOfMusCompOfGroup ui;
    QStringList getAllMusGroupInDB();

private slots:
    void currentIndexChangedSlot(QString);
};

#endif // AMOUNOFMUSCOMPOFGROUP_H
