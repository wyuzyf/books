#-------------------------------------------------
#
# Project created by QtCreator 2012-08-16T20:46:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sift_match
TEMPLATE = app


SOURCES += main.cpp\
        siftmatch.cpp \
    utils.c \
    xform.c \
    sift.c \
    minpq.c \
    kdtree.c \
    imgfeatures.c

HEADERS  += siftmatch.h \
    utils.h \
    xform.h \
    sift.h \
    minpq.h \
    kdtree.h \
    imgfeatures.h

FORMS    += siftmatch.ui

INCLUDEPATH +=  C:\OpenCV2.4.4\opencv\build\include\
                C:\OpenCV2.4.4\opencv\build\include\opencv\
                C:\OpenCV2.4.4\opencv\build\include\opencv2

LIBS += C:\OpenCV2.4.4\opencv\build\x86\mingw\lib\libopencv_core244.dll.a\
        C:\OpenCV2.4.4\opencv\build\x86\mingw\lib\libopencv_highgui244.dll.a\
        C:\OpenCV2.4.4\opencv\build\x86\mingw\lib\libopencv_imgproc244.dll.a\
        C:\OpenCV2.4.4\opencv\build\x86\mingw\lib\libopencv_stitching244.dll.a\  #Í¼ÏñÆ´½ÓÄ£¿é
        C:\OpenCV2.4.4\opencv\build\x86\mingw\lib\libopencv_nonfree244.dll.a\     #SIFT,SURF
        C:\OpenCV2.4.4\opencv\build\x86\mingw\lib\libopencv_features2d244.dll.a   #ÌØÕ÷¼ì²â
