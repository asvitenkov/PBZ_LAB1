#ifndef ADDGROUPFORM_H
#define ADDGROUPFORM_H

#include "ui_addgroupform.h"

class AddGroupForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddGroupForm(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddGroupForm ui;

private slots:
    void AddGroup();
};

#endif // ADDGROUPFORM_H
