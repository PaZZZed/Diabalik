#include "Model/position.h"

namespace diaballik{
Position::Position(){}

Position::Position(int row, int col):row_(row), col_(col){
}

int Position::getCol() {
    return col_;
}

int Position::getRow(){
    return row_;
}

void Position::next(Direction dir){

    switch (dir) {
    case UP:{
        this->col_=this->col_+1;
        break;
    }case DOWN:{
        this->col_=this->col_-1;
        break;
    } case RIGHT:{
        this->row_=this->row_+1;
        break;
    }case LEFT:{
        this->row_=this->row_-1;
        break;
    } case UR:{
        this->col_=this->col_+1;
        this->row_=this->getRow()+1;
        break;
    }case UL:{
        this->col_=this->col_+1;
        this->row_=this->getRow()-1;
        break;
    } case DR:{
        this->col_=this->col_-1;
        this->row_=this->getRow()+1;
        break;
    }case DL:{
        this->col_=this->col_-1;
        this->row_=this->getRow()-1;
        break;
    }
    }

}



ostream& operator<<(ostream &strm, const Position &a) {
    return strm<< "["<<a.row_<<","<<a.col_<<"]";
}

}
