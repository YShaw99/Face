#include"publicfun.h"
QSqlDatabase Conn()
{
    //数据库连接
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("qt_face");//打开的数据库名
    db.open();
    return db;
}


void Init()
{
    //初始化创建文件及文件夹
    QDir *d=new QDir();
    QFile *f=new QFile();

    //创建照片文件夹
    if(!d->exists("photos"))
        d->mkdir("photos");

    //创建用户文件
    if(!f->exists("photos/user.txt"))
    {
        f->setFileName("photos/user.txt");//设置文件名
        f->open(QIODevice::WriteOnly);//创建并打开文件
        /*用流写内容
        //QTextStream write(f);//注意arg是地址 如果是对象需要取址
        //write<<"line1";*/
    }
}
