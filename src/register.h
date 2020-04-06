#ifndef REGISTER_H
#define REGISTER_H
#include"publicfun.h"
#include "opencv2/opencv.hpp"
#include<QDir>
#include <QWidget>
#include<ctime>
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    void detectImg(QString srcPath,QString tagPath);//fun图片处理 arg资源路径，目标路径
    void readCSV(QString csvPath,std::vector<cv::Mat>&imgVec,std::vector<int>&idVec);

    ~Register();

private slots:
    void on_pushButton_clicked();

    void on_regBtn_clicked();

    void on_regBtn_2_clicked();

    void on_regBtn_3_clicked();

    void on_regBtn_4_clicked();

    void on_regBtn_5_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
