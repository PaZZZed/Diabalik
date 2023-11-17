#include "Model/board.h"

namespace diaballik{


Board::Board(unsigned taille){
    unsigned cote=taille;
    squares_.resize(cote);
    for(unsigned i=0;i<cote;i++){
        Board::squares_[i].resize(cote);
        for(unsigned j=0;j<cote;j++){
            Square squa=Square();
            Board::squares_[i][j] = squa;
        }
    }
}


vector<vector<Square>> Board::getSquares(){
    return squares_;
}



void Board::putAt(Position pos,Support supp){
    squares_[static_cast<unsigned>(pos.getRow())][static_cast<unsigned>(pos.getCol())].addSupport(supp);
}



void Board::remove(Position pos){
    squares_[static_cast<unsigned>(pos.getRow())][static_cast<unsigned>(pos.getCol())].removeSupport();
}




bool Board::isInside(Position pos){
    return ((pos.getCol() >= 0 && static_cast<unsigned>(pos.getCol()) < squares_.size() )
            && static_cast<unsigned>(pos.getRow()) < squares_[0].size() && pos.getRow() >= 0);
}



Square& Board::getSquare(Position pos){
    return squares_[static_cast<unsigned>(pos.getRow())][static_cast<unsigned>(pos.getCol())];
}


bool Board::isFree(Position pos){
    return getSquare(pos).getSupp().getColorSupport()==NONE;
}


bool Board::isMyOwn(Position pos,PlayerColor color){
    return getSquare(pos).getSupp().getColorSupport()==color;
}

}

