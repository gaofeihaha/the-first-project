#include "mainwindow.h"
#include <QMenu>
#include <qmenubar.h>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>   //菜单栏
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *b = new QPushButton(this);
    b->setText("链接");
   // b->move(0,100);
    connect(b,&QPushButton::clicked,
            [=]()
            {
                b->setText("成功");
            }
            );

    //菜单栏
    QMenuBar *myBar = menuBar();
    QMenu *pFile = myBar->addMenu("文件");//添加菜单


    QAction *pNew = pFile->addAction("新建");   //为pFile菜单添加动作，出发后有一信号发射
    pFile->addSeparator();                      //多个动作之间添加分割线

    QAction *p1New = pFile->addAction("打开");




    connect(pNew,&QAction::triggered,           //为信号连接动作
            [=]()
            {
                qDebug() << "新建按钮被按下";
            }
            );

    //工具栏
    QToolBar *toolBar = addToolBar("工具栏");
    toolBar->addAction(p1New);
    toolBar->addWidget(b);

    //状栏栏
    QStatusBar *mystatusBar = statusBar();
    QLabel *mylable = new QLabel(this);
    mylable->setText("Normal text file");           //浮动窗口，核心空间


    resize(300,400);
}

MainWindow::~MainWindow()
{

}
