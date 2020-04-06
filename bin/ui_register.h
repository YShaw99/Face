/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLineEdit *usnLE;
    QLineEdit *pwdLE;
    QPushButton *regBtn;
    QPushButton *regBtn_2;
    QPushButton *regBtn_3;
    QPushButton *regBtn_4;
    QPushButton *regBtn_5;
    QPushButton *pushButton;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(356, 350);
        usnLE = new QLineEdit(Register);
        usnLE->setObjectName(QStringLiteral("usnLE"));
        usnLE->setEnabled(false);
        usnLE->setGeometry(QRect(10, 20, 131, 31));
        pwdLE = new QLineEdit(Register);
        pwdLE->setObjectName(QStringLiteral("pwdLE"));
        pwdLE->setEnabled(false);
        pwdLE->setGeometry(QRect(10, 50, 131, 31));
        regBtn = new QPushButton(Register);
        regBtn->setObjectName(QStringLiteral("regBtn"));
        regBtn->setGeometry(QRect(210, 30, 121, 41));
        regBtn_2 = new QPushButton(Register);
        regBtn_2->setObjectName(QStringLiteral("regBtn_2"));
        regBtn_2->setGeometry(QRect(210, 90, 121, 41));
        regBtn_3 = new QPushButton(Register);
        regBtn_3->setObjectName(QStringLiteral("regBtn_3"));
        regBtn_3->setGeometry(QRect(210, 150, 121, 41));
        regBtn_4 = new QPushButton(Register);
        regBtn_4->setObjectName(QStringLiteral("regBtn_4"));
        regBtn_4->setGeometry(QRect(210, 210, 121, 41));
        regBtn_5 = new QPushButton(Register);
        regBtn_5->setObjectName(QStringLiteral("regBtn_5"));
        regBtn_5->setGeometry(QRect(210, 270, 121, 41));
        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 230, 75, 23));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", Q_NULLPTR));
        regBtn->setText(QApplication::translate("Register", "\346\213\215\347\205\247", Q_NULLPTR));
        regBtn_2->setText(QApplication::translate("Register", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR));
        regBtn_3->setText(QApplication::translate("Register", "CSV\345\206\231\345\205\245", Q_NULLPTR));
        regBtn_4->setText(QApplication::translate("Register", "CSV\350\257\273\345\217\226|\346\250\241\345\236\213\350\256\255\347\273\203", Q_NULLPTR));
        regBtn_5->setText(QApplication::translate("Register", "\344\272\272\350\204\270\350\257\206\345\210\253", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Register", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
