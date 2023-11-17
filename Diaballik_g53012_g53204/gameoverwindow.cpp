#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"
#include "option.h"

GameOverWindow::GameOverWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::GameOverWindow)
{
    ui->setupUi(this);
     connect(ui->pbClose,&QPushButton::clicked, &QCoreApplication::quit);
}

GameOverWindow::~GameOverWindow()
{
    delete ui;
}

void GameOverWindow::setGame(Game &game)
{
     ui->label->setText("Le joueur "+QString::fromStdString(game.getWinner().toString()));
     this->show();
}

void GameOverWindow::replay()
{
    Option *w=new Option();
    w->show();
    this->close();
}

