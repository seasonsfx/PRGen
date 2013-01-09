#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
