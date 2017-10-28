/********************************************************************************
** Form generated from reading UI file 'siftmatch.ui'
**
** Created: Thu Jul 4 21:40:03 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIFTMATCH_H
#define UI_SIFTMATCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SiftMatch
{
public:
    QPushButton *openButton;
    QPushButton *detectButton;
    QPushButton *matchButton;
    QPushButton *restartButton;
    QPushButton *mosaicButton;
    QRadioButton *radioButton_horizontal;
    QRadioButton *radioButton_vertical;
    QLabel *label;

    void setupUi(QDialog *SiftMatch)
    {
        if (SiftMatch->objectName().isEmpty())
            SiftMatch->setObjectName(QString::fromUtf8("SiftMatch"));
        SiftMatch->resize(191, 280);
        openButton = new QPushButton(SiftMatch);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(34, 60, 120, 23));
        detectButton = new QPushButton(SiftMatch);
        detectButton->setObjectName(QString::fromUtf8("detectButton"));
        detectButton->setGeometry(QRect(34, 100, 120, 23));
        matchButton = new QPushButton(SiftMatch);
        matchButton->setObjectName(QString::fromUtf8("matchButton"));
        matchButton->setGeometry(QRect(34, 170, 120, 23));
        restartButton = new QPushButton(SiftMatch);
        restartButton->setObjectName(QString::fromUtf8("restartButton"));
        restartButton->setGeometry(QRect(34, 250, 120, 23));
        mosaicButton = new QPushButton(SiftMatch);
        mosaicButton->setObjectName(QString::fromUtf8("mosaicButton"));
        mosaicButton->setGeometry(QRect(34, 210, 120, 23));
        radioButton_horizontal = new QRadioButton(SiftMatch);
        radioButton_horizontal->setObjectName(QString::fromUtf8("radioButton_horizontal"));
        radioButton_horizontal->setGeometry(QRect(50, 140, 41, 16));
        radioButton_horizontal->setChecked(true);
        radioButton_vertical = new QRadioButton(SiftMatch);
        radioButton_vertical->setObjectName(QString::fromUtf8("radioButton_vertical"));
        radioButton_vertical->setGeometry(QRect(100, 140, 41, 16));
        label = new QLabel(SiftMatch);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 191, 41));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(SiftMatch);

        QMetaObject::connectSlotsByName(SiftMatch);
    } // setupUi

    void retranslateUi(QDialog *SiftMatch)
    {
        SiftMatch->setWindowTitle(QApplication::translate("SiftMatch", "SIFT\346\213\274\346\216\245", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        SiftMatch->setWhatsThis(QApplication::translate("SiftMatch", "\350\277\231\346\230\257\344\270\200\344\270\252\345\237\272\344\272\216SIFT\347\211\271\345\276\201\347\202\271\347\232\204\345\233\276\347\211\207\345\214\271\351\205\215\345\222\214\345\205\250\346\231\257\346\213\274\346\216\245\347\250\213\345\272\217\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        openButton->setText(QApplication::translate("SiftMatch", "\346\211\223\345\274\200\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        detectButton->setText(QApplication::translate("SiftMatch", "\347\211\271\345\276\201\347\202\271\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        matchButton->setText(QApplication::translate("SiftMatch", "\347\211\271\345\276\201\345\214\271\351\205\215", 0, QApplication::UnicodeUTF8));
        restartButton->setText(QApplication::translate("SiftMatch", "\351\207\215\346\226\260\351\200\211\345\217\226", 0, QApplication::UnicodeUTF8));
        mosaicButton->setText(QApplication::translate("SiftMatch", "\345\205\250\346\231\257\346\213\274\346\216\245", 0, QApplication::UnicodeUTF8));
        radioButton_horizontal->setText(QApplication::translate("SiftMatch", "\346\250\252\346\216\222", 0, QApplication::UnicodeUTF8));
        radioButton_vertical->setText(QApplication::translate("SiftMatch", "\347\272\265\346\216\222", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SiftMatch", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#5500ff;\">\345\217\252\350\203\275\346\211\223\345\274\2002\345\274\240\345\233\276\347\211\207,\345\267\246\345\217\263\351\241\272\345\272\217\344\273\273\346\204\217</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ff0000;\">\350\267\257\345\276\204\344\270\255\344\270\215\350\203\275\346\234\211\344\270\255\346\226\207</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SiftMatch: public Ui_SiftMatch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIFTMATCH_H
