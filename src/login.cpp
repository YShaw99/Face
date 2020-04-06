#include "login.h"
#include "ui_login.h"
#include "opencv2/opencv.hpp"
#include<QMovie>
using namespace cv;

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);    //设置无框
  //setWindowOpacity(0.8);                      //设置透明
    ui->pwdLE->setEchoMode(QLineEdit::Password);//设置密码

    //设置gif loading
    ui->label->show();
    QMovie * m=new QMovie(":/new/prefix1/t.gif");
    ui->label->setMovie(m);
    ui->label->move(0,0);
    ui->label->resize(this->size());
    m->start();     //没有这一行，不会显示任何内容

    QSqlDatabase db=Conn();                     //数据库连接开启
    connect(ui->loginBtn,QPushButton::clicked,[=]()
    {
        //获取值
        QString usn=ui->usnLE->text();//用户名
        QString pwd=ui->pwdLE->text();//密码

        //开始查询
        QSqlQuery pwdQuery(db);
        pwdQuery.exec(QString("Select pwd from login where usn=%1").arg(usn));//注意where后面有无引号
        pwdQuery.first();//用next也行

        int i=pwdQuery.value(0).toString().compare(pwd)==0?1:0;//结果
        if(i==1)//密码正确
        {
            //关闭窗口，关闭数据库
            //db.close();
        }
    });

}


Login::~Login()
{
    delete ui;
}

void Login::on_regBtn_clicked()
{
    r.open();
}
