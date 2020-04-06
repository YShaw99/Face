/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *loginBtn;
    QLineEdit *usnLE;
    QLineEdit *pwdLE;
    QPushButton *regBtn;
    QLabel *label;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(490, 411);
        loginBtn = new QPushButton(Login);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setEnabled(false);
        loginBtn->setGeometry(QRect(110, 120, 271, 51));
        usnLE = new QLineEdit(Login);
        usnLE->setObjectName(QStringLiteral("usnLE"));
        usnLE->setEnabled(false);
        usnLE->setGeometry(QRect(180, 40, 131, 31));
        pwdLE = new QLineEdit(Login);
        pwdLE->setObjectName(QStringLiteral("pwdLE"));
        pwdLE->setEnabled(false);
        pwdLE->setGeometry(QRect(180, 70, 131, 31));
        regBtn = new QPushButton(Login);
        regBtn->setObjectName(QStringLiteral("regBtn"));
        regBtn->setGeometry(QRect(140, 330, 201, 31));
        regBtn->setAutoFillBackground(false);
        regBtn->setFlat(true);
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(100, 230, 291, 101));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label->setAutoFillBackground(false);
        loginBtn->raise();
        usnLE->raise();
        pwdLE->raise();
        label->raise();
        regBtn->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("Login", "PushButton", Q_NULLPTR));
        regBtn->setText(QApplication::translate("Login", "regBtn\357\274\232\347\205\247\347\233\270\347\224\250\344\270\264\346\227\266\347\252\227\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "\351\241\271\347\233\256\346\236\204\345\273\272\344\270\255...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
