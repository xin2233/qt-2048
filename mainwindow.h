#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QLabel>
#include <QGridLayout>
#include <QVector>
#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyLabel : public QLabel{
    Q_OBJECT
    
public:
    MyLabel(){}
    ~MyLabel(){}
    
    int getId() const
    {
        return id;
    }
    void setId(int value)
    {
        id=value;
    }
    

private:
    int id;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    
    ~MainWindow();
    
    void setBackground();
    
    int getRandomNum();
    
    void initGame();
    
    void addNum();
    
//protected:
//    virtual void keyPressEvent(QKeyEvent *ev) override
//    {
//        if(ev->key() == Qt::Key_Up)
//        {
//            emit
//        }
//        else if(ev->key() == Qt::Key_Down)
//        {

//        }
//        else if(ev->key() == Qt::Key_Left)
//        {

//        }
//        else if(ev->key() == Qt::Key_Right)
//        {

//        }

//    }


private slots:
    void on_upPushButton_clicked();
    
    void on_leftPushButton_clicked();
    
    void on_downPushButton_clicked();
    
    void on_rightPushButton_clicked();
    
    void updateTableBackground();
    
    void checkGameState();
    
    void on_actionnew_game_triggered();
    
private:
    Ui::MainWindow *ui;
    QWidget *gameSpaceWidget;
    QVector<QVector<MyLabel*>> table;
    QTimer *updateTableBackgroundTimer;
    QTimer *checkGameoverTimer;
    int point;
};
#endif // MAINWINDOW_H
