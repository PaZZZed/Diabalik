#include "boardview.h"

BoardView::BoardView(Game &game,int &count,bool &canPass):game_(game),count_(count),canPass_(canPass)
{
    setSceneRect(0,0,500,500);
    draw();
}

void BoardView::draw()
{
    size_t taille=game_.getBoard().getSquares().size();
    for(unsigned i=0;i<game_.getBoard().getSquares().size();i++){
        for(unsigned j=0;j<game_.getBoard().getSquares()[0].size();j++){
            SquareView *c=new SquareView(game_,static_cast<int>(taille), Position(static_cast<int>(i),static_cast<int>(j)),count_,canPass_);
            addItem(c);
            if(game_.getBoard().getSquares()[i][j].getSupp().getColorSupport()==BLACK && game_.getBoard().getSquares()[i][j].getSupp().hasBall()){
                addEllipse(500/taille*i, 500/taille*j,500/taille,500/taille, QPen(Qt::black),QBrush(Qt::yellow));
            }else if(game_.getBoard().getSquares()[i][j].getSupp().getColorSupport()==GOLD && game_.getBoard().getSquares()[i][j].getSupp().hasBall()){
                addEllipse(500/taille*i, 500/taille*j,500/taille,500/taille, QPen(Qt::black),QBrush(Qt::black));
            }
            moves(Position(static_cast<int>(i),static_cast<int>(j)),c);
        }
    }

}

void BoardView::moves(Position pos,SquareView *sv)
{
    bool colo=false;
    sv->setColor(colo);
    if(sv->checkPos(pos)){
        colo=true;
        sv->setColor(colo);
    }
}
