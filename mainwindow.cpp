#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(600,600);

    ui->upPushButton->setShortcut(Qt::Key_Up);
    ui->downPushButton->setShortcut(Qt::Key_Down);
    ui->leftPushButton->setShortcut(Qt::Key_Left);
    ui->rightPushButton->setShortcut(Qt::Key_Right);

    setBackground();
// 不清楚原因，按理说，qrand 或者 qsrand 都可以用的。
    //已找到原因：qt 5.15 后 qsrand 和qrand 都弃用，详情参考 qt 5.15 spec
//    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    srand(QTime(0,0,0).secsTo(QTime::currentTime()));
    initGame();
    updateTableBackgroundTimer=new QTimer(this);
    connect(updateTableBackgroundTimer,&QTimer::timeout,this,&MainWindow::updateTableBackground);
    updateTableBackgroundTimer->start(10);
    
    checkGameoverTimer=new QTimer(this);
    connect(checkGameoverTimer,&QTimer::timeout,this,&MainWindow::checkGameState);
    checkGameoverTimer->start(1000);
}

MainWindow::~MainWindow()
{
    qDebug() << tr("MainWindow::~MainWindow()");
    delete ui;
}

void MainWindow::setBackground()
{
    gameSpaceWidget=new QWidget(this);
    gameSpaceWidget->setGeometry(100,30,400,400);
    gameSpaceWidget->setStyleSheet("background-color:#fff2cc;"
                                   "border:1px solid black;");
    QGridLayout *layout=new QGridLayout(gameSpaceWidget);
//    在qt 6 中，此项已经没有了，需要删除
//    layout->setMargin(0);
    layout->setSpacing(0);
    int id=0;
    for (int i=0;i<4;i++) {
        QVector<MyLabel *> list;
        for (int j=0;j<4;j++) {
            MyLabel *label=new MyLabel();
            QFont font;
            font.setPixelSize(24);
            label->setId(id++);
            label->setFont(font);
            label->setAlignment(Qt::AlignCenter);
            label->setFixedSize(100,100);
            layout->addWidget(label,i,j);
            list.push_back(label);
        }
        table.push_back(list);
    }
    
}

int MainWindow::getRandomNum()
{
    return rand()%15;
}

/**
 * @brief MainWindow::initGame
 */
void MainWindow::initGame()
{
    point=0;
    int num;
    for (int n=0;n<4;n++) {
        num=getRandomNum();
        for(int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++) {
                if(table[i][j]->getId()==num&&table[i][j]->text().isEmpty())
                {
                    table[i][j]->setNum(2);
                }
            }
        }
    }
#if 1
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++) {
            table[i][j]->clear();
        }
    }

    table[0][0]->setNum(2);
    table[0][1]->setNum(2);
    table[0][2]->setNum(4);
    table[0][3]->setNum(4);
#endif
}

void MainWindow::addNum()
{
    int num;
    for (int n=0;n<3;n++) {
        num=getRandomNum();
        for(int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++) {
                if(table[i][j]->getId()==num&&table[i][j]->text().isEmpty())
                {
                    table[i][j]->setNum(2);
                }
            }
        }
    }
}


void MainWindow::on_upPushButton_clicked()
{
    bool isAdd=false;
    bool addNum1=false;
    bool addNum2=false;
    for (int i=0;i<4;i++) {
        for (int j=1,m=0;j<4;j++) {
            isAdd=false;
            if(!table[j][i]->text().isEmpty())
            {
                m=j;
                while (m) {
                    if(table[m-1][i]->text().isEmpty())
                    {
                        table[m-1][i]->setNum(table[m][i]->text().toInt());
                        table[m][i]->clear();
                        addNum1=true;
                    }
                    else if (table[m-1][i]->text()==table[m][i]->text()&&!isAdd) {
                        point+=table[m][i]->text().toInt()*2;
                        ui->pointDataLabel->setNum(point);
                        table[m-1][i]->setNum(table[m][i]->text().toInt()*2);
                        table[m][i]->clear();
                        isAdd=true;
                        addNum2=true;
                    }
                    m--;
                }
            }
        }
    }
    if(addNum1||addNum2)
    {
        addNum();
    }
}

void MainWindow::on_leftPushButton_clicked()
{
    bool isAdd=false;
    bool addNum1=false;
    bool addNum2=false;
    for (int i=0;i<4;i++) {
        for (int j=1,m=0;j<4;j++) {
            isAdd=false;
            if(!table[i][j]->text().isEmpty())
            {
                m=j;
                while (m) {
                    if(table[i][m-1]->text().isEmpty())
                    {
                        table[i][m-1]->setNum(table[i][m]->text().toInt());
                        table[i][m]->clear();
                        addNum1=true;
                    }
                    else if (table[i][m-1]->text()==table[i][m]->text()&&!isAdd) {
                        point+=table[i][m]->text().toInt()*2;
                        ui->pointDataLabel->setNum(point);
                        table[i][m-1]->setNum(table[i][m]->text().toInt()*2);
                        table[i][m]->clear();
                        isAdd=true;
                        addNum2=true;
                    }
                    m--;
                }
            }
        }
    }
    if(addNum1||addNum2)
    {        
        addNum();
    }
}

void MainWindow::on_downPushButton_clicked()
{
    bool isAdd=false;
    bool addNum1=false;
    bool addNum2=false;
    for (int i=3;i>=0;i--) {
        for (int j=2,m=0;j>=0;j--) {
            isAdd=false;
            if(!table[j][i]->text().isEmpty())
            {
                m=j;
                while (m<3) {
                    if(table[m+1][i]->text().isEmpty())
                    {
                        table[m+1][i]->setNum(table[m][i]->text().toInt());
                        table[m][i]->clear();
                        addNum1=true;
                    }
                    else if (table[m+1][i]->text()==table[m][i]->text()&&!isAdd) {
                        point+=table[m][i]->text().toInt()*2;
                        ui->pointDataLabel->setNum(point);
                        table[m+1][i]->setNum(table[m][i]->text().toInt()*2);
                        table[m][i]->clear();
                        isAdd=true;
                        addNum2=true;
                    }
                    m++;
                }
            }
        }
    }
    if(addNum1||addNum2)
    {
        addNum();
    }
        
}

void MainWindow::on_rightPushButton_clicked()
{
    bool isAdd=false;
    bool addNum1=false;
    bool addNum2=false;
    for (int i=3;i>=0;i--) {
        for (int j=2,m=0;j>=0;j--) {
            isAdd=false;
            if(!table[i][j]->text().isEmpty())
            {
                m=j;
                while (m<3) {
                    if(table[i][m+1]->text().isEmpty())
                    {
                        table[i][m+1]->setNum(table[i][m]->text().toInt());
                        table[i][m]->clear();
                        addNum1=true;
                    }
                    else if (table[i][m+1]->text()==table[i][m]->text()&&!isAdd) {
                        point+=table[i][m]->text().toInt()*2;
                        ui->pointDataLabel->setNum(point);
                        table[i][m+1]->setNum(table[i][m]->text().toInt()*2);
                        table[i][m]->clear();
                        isAdd=true;
                        addNum2=true;
                    }
                    m++;
                }
            }
        }
    }
    if(addNum1||addNum2)
    {
        addNum();
    }
        
}

void MainWindow::updateTableBackground()
{
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++) {
            if(table[i][j]->text().toInt()==2)
            {
                table[i][j]->setStyleSheet("background-color:#fce5cd;");
            }
            else if(table[i][j]->text().toInt()==4)
            {
                table[i][j]->setStyleSheet("background-color:#ffe599;");
            }
            else if(table[i][j]->text().toInt()==8)
            {
                table[i][j]->setStyleSheet("background-color:#f4cccc;");
            }
            else if(table[i][j]->text().toInt()==16)
            {
                table[i][j]->setStyleSheet("background-color:#f9cb9c;");
            }
            else if (table[i][j]->text().toInt()==32) {
                table[i][j]->setStyleSheet("background-color:#e6b8af;");
            }
            else if (table[i][j]->text().toInt()==64) {
                table[i][j]->setStyleSheet("background-color:#ea9999;");
            }
            else if (table[i][j]->text().toInt()==128) {
                table[i][j]->setStyleSheet("background-color:#f6b26b;");
            }
            else if (table[i][j]->text().toInt()==256) {
                table[i][j]->setStyleSheet("background-color:#dd7e6b;");
            }
            else if (table[i][j]->text().toInt()==512) {
                table[i][j]->setStyleSheet("background-color:#e06666;");
            }
            else if (table[i][j]->text().toInt()==1024) {
                table[i][j]->setStyleSheet("background-color:#cc4125;");
            }
            else if (table[i][j]->text().toInt()>=2048) {
                table[i][j]->setStyleSheet("background-color:#cc0000;");
            }
            else {
                table[i][j]->setStyleSheet("background-color:#fff2cc;");
            }
        }
    }
}

void MainWindow::checkGameState()
{
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++) {
            if(table[i][j]->text().isEmpty())
            {
                return;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++) {
            if(i>0)
            {
                if(table[i][j]->text()==table[i-1][j]->text())
                {
                    return;
                }
            }
            if(i<3){
                if(table[i][j]->text()==table[i+1][j]->text())
                {
                    return;
                }
            }
            if(j>0){
                if(table[i][j]->text()==table[i][j-1]->text())
                {
                    return;
                }
            }
            if(j<3){
                if(table[i][j]->text()==table[i][j+1]->text())
                {
                    return;
                }
            }
        }
    }
    qDebug() << "game over";
    updateTableBackgroundTimer->stop();
    checkGameoverTimer->stop();
    QString strPoint="Your Point:"+QString::number(point);
    QMessageBox::information(this,"information",strPoint);
}

void MainWindow::on_actionnew_game_triggered()
{
    point=0;
    ui->pointDataLabel->clear();
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++) {
            table[i][j]->clear();
        }
    }
    initGame();
    updateTableBackgroundTimer->start();
    checkGameoverTimer->start();
}
