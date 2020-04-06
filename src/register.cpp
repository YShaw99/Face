#include "register.h"
#include "ui_register.h"
using namespace cv;
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    Init();
}


//~
Register::~Register()
{
    delete ui;
}
//x
/*
void tempfun()
{
    QSqlDatabase db=Conn();//数据库连接开启
    connect(ui->regBtn,QPushButton::clicked,[=]()
    {
        //获取值
        QString usn=ui->usnLE->text();//用户名
        QString pwd=ui->pwdLE->text();//密码

        //开始查询
        QSqlQuery sqlQuery(db);
        sqlQuery.exec(QString("Select usn from login where usn").arg(usn));//注意where后面有无引号
        sqlQuery.first();//用next也行
        int i=sqlQuery.value(0).toString().compare(usn)==0?1:0;
        if(i==1)//存在
            QMessageBox::information(this,"提示","当前用户已存在");
        else
        {
            sqlQuery.exec(QString("insert into login values(%1,%2)").arg(usn).arg(pwd));//insert语句
            QMessageBox::information(this,"提示","注册成功");
        }
    });
}*/

//拍照

void Register::on_pushButton_clicked()
{
    qDebug("1");
}
void Register::on_regBtn_clicked()
{
    //QDir *d =new QDir();
    VideoCapture cap(0);

    int i=0;
    while(i<6)
    {
        Mat frame;
        cap>>frame;
        cv::imshow("camera",frame);//arg1:窗口名 arg2:
        if(waitKey(30)=='p')//等待arg1 ms刷新一次；返回int类型 并检测键盘按键
        {
            imshow("photos",frame);
            waitKey(400);
            imwrite(QString("photos/1/%1.jpg").arg(i).toStdString(),frame);//存arg2进入相对路径arg1
            cv::destroyWindow("photos");
            i++;
        }
    }
    destroyWindow("camera");
    cap.release();
}
//处理图片
void Register::on_regBtn_2_clicked()
{
    QDir *d =new QDir();
    for(int i=1;i<2;i++)//一个人一个文件夹
        if(d->exists(QString("photos/%1").arg(i)))
            QMessageBox::information(this,"警告","文件夹已被创建");
        else
            d->mkdir(QString("photos/%1").arg(i));


    for(int i=0;i<3;i++)//n个人
        for(int j=0;j<6;j++)//一个文件夹拍n张照片
        {
            QString srcPath=QString("photos/%1/%2.jpg").arg(i).arg(j);
            QString tagPath=QString("photos/%1/d%2.jpg").arg(i).arg(j);
            detectImg(srcPath,tagPath);
        }
}
void Register::detectImg(QString srcPath,QString tagPath)
{
    CascadeClassifier faceCascade;
    if(!faceCascade.load("haarcascade_frontalface_alt.xml"))
        qDebug("xml打开失败");
    else
        qDebug("xml打开成功");

    Mat srcImg=imread(srcPath.toStdString());//原图片
    Mat tagImg;//目标图片
    std::vector<cv::Rect> faces;//存人像(截图)大小的容器

    cvtColor(srcImg,tagImg,COLOR_BGR2GRAY);//处理成灰度图
    equalizeHist(tagImg,tagImg);//对图像进行直方图均衡化处理，保存至arg2(增强对比度)
    faceCascade.detectMultiScale(tagImg,faces);//将人脸截取出来，将大小存储至faces容器

    //把原图截取，截取后的图片存至文件夹
    if(faces.size()==1)
    {
        Mat face=srcImg(faces[0]);
        cv::resize(face,face,Size(100,100));//设置固定大小
        cvtColor(face,face,COLOR_BGR2GRAY);
        imwrite(tagPath.toStdString(),face);
    }
}
//写入CSV
void Register::on_regBtn_3_clicked()
{
    QDir d("");
    QFile f("photos/user.txt");//csv文件
    if(!f.open(QIODevice::WriteOnly|QIODevice::Append))
        qDebug("open fail");
    //写入文件
    QString no="0";//可变的id号
        //同一个人可以循环写入几个

    for(int i=0;i<3;i++)
        for(int j=0;j<6;j++)
        {
            QString photoPath=d.absolutePath().append("/photos/"+QString::number(i)+"/d"+QString::number(j)+".jpg;"+QString::number(i));
            QTextStream QTS(&f);
            QTS<<photoPath<<"\n";
        }
    f.close();
}
//读取CSV处理,并进行模型训练
void Register::on_regBtn_4_clicked()
{
    std::vector<cv::Mat>imgVec;
    std::vector<int>idVec;
    readCSV("photos/user.txt",imgVec,idVec);

    if(imgVec.size()<2)
    {
        qDebug("大小不够");
        return;
    }

    Mat testImg=imgVec[imgVec.size()-1];//前n-1张用来训练 最后一张用来测试
    int testId=idVec[idVec.size()-1];

    imshow("hello",testImg);
    qDebug()<<"testID"<<testId;
    imgVec.pop_back();//测试用的pop 不参与训练
    idVec.pop_back();

    Ptr<FaceRecognizer>model=createEigenFaceRecognizer();
    model->train(imgVec,idVec);
    model->save("MyFacePCA.xml");
    int Result=model->predict(testImg);

    qDebug()<<"预测结果为:"<<Result;
}
void Register::readCSV(QString csvPath,std::vector<cv::Mat>&imgVec,std::vector<int>&idVec)
{
    QFile f(csvPath);
    if(!f.open(QIODevice::ReadOnly))
        qDebug("读取csv：打开文件失败");
    QTextStream t(&f);
    while(!t.atEnd())
    {
        QString data=t.readLine();
        QStringList list=data.split(";");
        QString imgPath=list[0];
        QString userId=list[1];
        imgVec.push_back(imread(imgPath.toStdString(),0));
        idVec.push_back(userId.toInt());
    }
    qDebug()<<imgVec.size();
}
//识别人脸
void Register::on_regBtn_5_clicked()
{
    VideoCapture cap(0);
    while(1)
    {
        std::clock_t t0=clock();
        Mat frame;
        cap>>frame;
        std::clock_t t1=clock();
        qDebug()<<"开启相机耗时："<<(t1-t0)*1000/CLOCKS_PER_SEC;

        CascadeClassifier faceCascade;
        if(!faceCascade.load("haarcascade_frontalface_alt.xml"))
        {
            qDebug("xml打开失败");
            return;
        }
        else
            qDebug("xml打开成功");

        std::clock_t t2=clock();
        qDebug()<<"打开xml耗时："<<(t2-t1)*1000/CLOCKS_PER_SEC;

        //处理镜头照片，寻找框选框大小
        std::vector<cv::Rect>Rect;
        Mat dstImg;

        cvtColor(frame,dstImg,COLOR_BGR2GRAY);
        equalizeHist(dstImg,dstImg);
        faceCascade.detectMultiScale(dstImg,Rect);

        std::clock_t t3=clock();
        qDebug()<<"处理照片耗时："<<(t3-t2)*1000/CLOCKS_PER_SEC;

        if(Rect.size()!=0)
        {
            for(int i=0;i<Rect.size();i++)
            {
                Mat face=frame(Rect[i]);//截取框选照片
                //框选处理，屏幕显示
                if(face.cols*face.rows!=10000)
                    cv::resize(face,face,Size(100,100));
                cvtColor(face,face,COLOR_BGR2GRAY);
                rectangle(frame,Rect[i],Scalar(0,255,0));

                //框选识别
                Ptr<FaceRecognizer> model=createEigenFaceRecognizer();
                model->load("MyFacePCA.xml");
                qDebug()<<"--人脸识别结果："<<model->predict(face);
            }
        }

        std::clock_t t4=clock();
        qDebug()<<"人脸识别耗时："<<(t4-t3)*1000/CLOCKS_PER_SEC;

        imshow("recognize",frame);
        if(waitKey(4)>0)//按键退出
            cv::destroyWindow("recognize");

        waitKey(1000);
        qDebug()<<"-----------------------";
    }

}




//1.灰度
//2.直方图均衡化
//3.截取放入rect
//4.resize
