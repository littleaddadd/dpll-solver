#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "block.h"
#include "ui_mainwindow.h"
#include "sudoku.h"
#include "gline.h"

#include <QMainWindow>
#include <QFrame>
#include <QPushButton>
#include <QLayout>
#include <QGridLayout>
#include <cstring>
#include <QMenu>
#include <QMessageBox>
#include <iostream>
#include <QApplication>


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int num[9][9];

    cnfpoint G=nullptr; //
    template <typename Edit, typename ...Args>
    void scan(Edit input, Args&&...args);
    void clear_output();
    template <typename ...Args>
    void print(Args&&...args);
    template <typename ...Args>
    void print_and_flush(Args&&...args);
    void flush();

private slots:
    void easyInitialize();
    void difficultInitialize();
    void solve();
    void blocksClear();
    void checkBlocks();
    void checkAnswers();
    void blocksReset();
    void outprint();
private:
    void createMenu();
    void createBlocks();
    void drawLine();
private:
    Ui::MainWindow *ui;
    enum{Max=9};

    Block * blocks[Max][Max]; //类指针
    QFrame *frame;
    //在程序中新建按钮
    QPushButton *easyButton;
    QPushButton *difficultButton;
    QPushButton *solveButton;
    QPushButton *outprintButton;

    QPushButton *confirmButton;
    QPushButton *clearButton;
    QPushButton *resetButton;
    QPushButton *quitButton;
    QPushButton *aboutButton;
    QPushButton *helpButton;
    QString output;

    bool flag, cflag, rflag, eflag, sflag;
    int nums[9];
    void judgeerror();
};

#endif // MAINWINDOW_H
