#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "publicfun.h"
#include "register.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    Register r;
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_regBtn_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
