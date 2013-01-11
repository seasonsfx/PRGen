#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //用正则表达式对输入进行限制
    QRegExp totalPointsExp("[1-9]||[1-9][0-9]||[1-2][0-9]{2}");

    ui->lineEditTotalPoints->setValidator(new QRegExpValidator(totalPointsExp,this));

    //界面控件相关设置
//    ui->comboBoxLineGrade->addItem(tr("一等"));
//    ui->comboBoxLineGrade->addItem(tr("二等"));
//    ui->comboBoxLineGrade->addItem(tr("三等"));
//    ui->comboBoxLineGrade->addItem(tr("四等"));

//    ui->tabWidgetPR->removeTab(2);

    connect(ui->pushButtonAddPRPages,SIGNAL(clicked()),this,SLOT(addPRPages()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPRPages()
{
    if(ui->lineEditTotalPoints->text().length()==0)
        QMessageBox::warning(this,tr("未输入页数"),tr("请输入所需添加的点之记页数"),QMessageBox::Ok);
    else{
        PRPageNum = ui->lineEditTotalPoints->text().toInt();
        int currentPageNum = 0;
        QString pageNumStr;


        QWidget *PRPagesTabWidget[PRPageNum];
        Ui::FormPRPage PRPages[PRPageNum];
        for(currentPageNum;currentPageNum<PRPageNum;currentPageNum++)
        {
            pageNumStr = QString::number(currentPageNum+1,10);
            PRPagesTabWidget[currentPageNum] = new QWidget;
            PRPages[currentPageNum].setupUi(PRPagesTabWidget[currentPageNum]);
            ui->tabWidgetPR->addTab(PRPagesTabWidget[currentPageNum],pageNumStr);
        }
        //禁用添加按钮，防止再次添加
        ui->lineEditTotalPoints->setEnabled(false);
        ui->pushButtonAddPRPages->setEnabled(false);
    }

}

