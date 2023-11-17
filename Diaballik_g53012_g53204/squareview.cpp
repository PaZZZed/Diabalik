#include "squareview.h"


SquareView::SquareView( Game &game,int size, Position pos,int &count,bool &canPass)
    :game_(game),size_(size),pos_(pos),count_(count),canPass_(canPass){
    setPos(500/size*pos.getRow(), 500/size*pos.getCol());
}


QRectF SquareView::boundingRect() const
{
    return QRectF(0,0,500/size_,500/size_);
}

void SquareView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec=boundingRect();

    QBrush color(Qt::white);
    QPen pen(Qt::black);
    pen.setWidth(1);
    pen.setBrush(Qt::SolidPattern);
    painter->setPen(pen);

    Support s=game_.getBoard().getSquares()[static_cast<unsigned>(pos_.getRow())][static_cast<unsigned>(pos_.getCol())].getSupp();
    try {
        if((game_.getSelect().getCol()==pos_.getCol()) && (game_.getSelect().getRow()==pos_.getRow())){
            color.setColor(Qt::gray);
        }else if(s.getColorSupport()==GOLD){
            color.setColor(Qt::yellow);
            painter->setPen( QPen(Qt::white));
        }else if(s.getColorSupport()==BLACK){
            color.setColor(Qt::black);
            painter->setPen( QPen(Qt::white));
        }


        if(selected_){
            pen.setColor(Qt::green);
            pen.setWidth(4);
            painter->setPen(pen);
        }

        painter->fillRect(rec, color);
        painter->drawRect(rec);
    } catch (exception &e) {
        qDebug()<<e.what()<<endl;
    }


}

void SquareView::setColor(bool &color)
{
    selected_=color;
}

bool SquareView::checkPos(Position pos)
{
    bool trouver=false;
    try {
        for(unsigned i=0;i<game_.move(count_).size() && !trouver;i++){
            if(pos.getRow()==game_.move(count_)[i].getPositionEnd().getRow() && pos.getCol()==game_.move(count_)[i].getPositionEnd().getCol() ){
                trouver=true;
            }
        }
    }catch (exception &e) {
        qDebug()<<e.what()<<endl;
    }
    return trouver;
}

void SquareView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    try {
        if(!game_.getBoard().isInside(game_.getSelect())){
             game_.select(pos_.getRow(), pos_.getCol());
        } //change
        if(game_.getSelected().hasBall() && game_.getCurrent().getColor()==game_.getSelected().getColorSupport() && canPass_){
            game_.passBall(pos_,canPass_);
        }else if(!checkPos(pos_)){
             game_.select(pos_.getRow(), pos_.getCol());
        } else{
            game_.applyMove(pos_,count_);
        }
        selected_=true;
        QGraphicsItem::mousePressEvent(event);
    } catch (exception &e) {
        qDebug()<<e.what()<<endl;
    }


}

