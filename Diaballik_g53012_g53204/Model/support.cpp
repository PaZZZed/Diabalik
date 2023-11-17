#include "Model/support.h"

namespace diaballik{

Support::Support(){

}

Support::Support(PlayerColor color, bool bille) :ball_(bille), color_(color){}


bool Support::hasBall(){
    return ball_;
}

PlayerColor Support::getColorSupport(){
    return color_;
}
void Support::setColorSupport(PlayerColor newColor){
    color_=newColor;
}
void Support::setBallSupport(bool val){
    ball_=val;
}

string Support::toString() const{
    string supp;
    if(color_==NONE){
        supp= "|___|";
    }else if(color_==GOLD && ball_==true){
        supp= "|xGx|";
    }else if(color_==GOLD && ball_==false){
        supp= "|_G_|";
    }else if(color_==BLACK && ball_==true){
        supp= "|xBx|";
    }else if(color_==BLACK && ball_==false){
        supp= "|_B_|";
    }
    return supp;
}

ostream& operator<<(ostream &strm, const Support &a) {
    return strm<< a.toString();
}

}
