#include "mwdiaballik.h"
#include "ui_mwdiaballik.h"
#include "option.h"

using namespace diaballik;

MWDiaballik::MWDiaballik(QWidget *parent,bool var,unsigned taille)
    : QMainWindow(parent)
    , ui(new Ui::MWDiaballik)
{

    ui->setupUi(this);
    action_Aide = ui->menubar->addAction(tr("&Aide"));
    connexion();
    game.registerObserver(this);
    game.init(taille, var);
    setAttribute( Qt::WA_DeleteOnClose);

}

MWDiaballik::~MWDiaballik()
{
    delete ui;
    delete action_Aide;
}

void MWDiaballik::connexion(){
    connect(ui->action_Quitter, &QAction::triggered, &QCoreApplication::quit);
    connect(action_Aide, &QAction::triggered, this,&MWDiaballik::AfficheAide);
}


void  MWDiaballik::AfficheAide(){
    QDesktopServices::openUrl(QUrl("https://fr.wikipedia.org/wiki/Diaballik"));

}

void MWDiaballik::swap(){
    game.swapPlayer();
    count_=0;
    canPass_=true;
    if(game.getCurrent().getColor()==GOLD){
        ui->lbPlayer->setText("Player: GOLD");
    }else{
        ui->lbPlayer->setText("Player: BLACK");
    }
}

void MWDiaballik::fairPlay()
{
    if(game.isFairPlay()){
        QMessageBox::information(this, "anti-jeu", QString::fromStdString(game.getOpponent().toString())+ " tu triche le mino!" );
        anti_jeu_=true;
        update(&game);
    }else{
        anti_jeu_=false;
         QMessageBox::information(this, "anti-jeu", QString::fromStdString(game.getOpponent().toString())+ " n'a pas triché!" );
    }
}


void MWDiaballik::update(Subject * sdo) {

    if (sdo != &game ) return;
    try {
        if(!game.isOver() && !anti_jeu_){
            board=new BoardView(game,count_,canPass_);
            ui->graphicsView->setScene(board);
            ui->graphicsView->setFixedSize(500,500);
            if(game.getBoard().isInside(game.getSelect())){
                ui->selected->setText("Selected : "+ QString::fromStdString(game.getSelected().toString()));
            }
        }else{
            ui->graphicsView->setEnabled(false);
            GameOverWindow *over=new GameOverWindow();
            over->setGame(game);
            this->close();
    }

    } catch (exception &e) {
        qDebug()<<e.what()<<endl;
    }

}
