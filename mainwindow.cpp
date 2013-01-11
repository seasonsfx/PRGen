#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *PRPageTabWidget = new QWidget;
    PRPage.setupUi(PRPageTabWidget);
    Ui::FormPRPage secondPRPage;
    QWidget *secondPRPageTabWidget = new QWidget;
    secondPRPage.setupUi(secondPRPageTabWidget);
    ui->tabWidgetPR->addTab(PRPageTabWidget,tr("第1页"));
    ui->tabWidgetPR->addTab(secondPRPageTabWidget,tr("第2页"));

//    QWidget *otherPRPageTabWidget = new QWidget[4];
    QWidget *otherPRPageTabWidget[4];
    for(int i = 0;i<4;i++)
    {
        otherPRPageTabWidget[i] = new QWidget;
    }
    Ui::FormPRPage otherPRPage[4];
    otherPRPage[0].setupUi(otherPRPageTabWidget[0]);
    ui->tabWidgetPR->addTab(otherPRPageTabWidget[0],tr("第3页"));
    ui->tabWidgetPR->addTab(otherPRPageTabWidget[1],tr("第4页"));

//    PRPagePointer->setupUi(this);
//    ui->tabWidgetPR->addTab(this,tr("第2页"));


    //用正则表达式对输入进行限制
    QRegExp totalPointsExp("[1-9]||[1-9][0-9]||[1-2][0-9]{2}");

    ui->lineEditTotalPoints->setValidator(new QRegExpValidator(totalPointsExp,this));

    //界面控件相关设置
    ui->comboBoxLineGrade->addItem(tr("一等"));
    ui->comboBoxLineGrade->addItem(tr("二等"));
    ui->comboBoxLineGrade->addItem(tr("三等"));
    ui->comboBoxLineGrade->addItem(tr("四等"));

    ui->tabWidgetPR->removeTab(2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
