#include "Model/square.h"


namespace diaballik{
Square::Square():supp_(NONE,false){}
Square::Square(PlayerColor color):supp_(color,false){}


Support& Square::getSupp(){
    return supp_;
}

bool  Square::isEmpty() {
    return supp_.getColorSupport()==NONE;
}

void Square::addSupport(Support supp){
    this->supp_=supp;
}

void Square::removeSupport(){
    supp_.setColorSupport(NONE);
}


bool Square::isMyOwn(PlayerColor color_){
    return Square::supp_.getColorSupport()==color_;
}


ostream& operator<<(ostream &strm,const Square &a)  {
    return strm<<a.supp_;
}

}
