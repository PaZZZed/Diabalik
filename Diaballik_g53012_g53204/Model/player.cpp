#include "Model/player.h"

namespace diaballik{
Player::Player(PlayerColor color) :color_(color){}


PlayerColor Player::getColor(){
    return color_;
}

string Player::toString()
{
    string player;
    if(color_==NONE){
        player ="No one";
    }else if(color_==GOLD){
        player = "Gold";
    }else if(color_==BLACK){
        player = "Black"
                "";
    }
    return player;
}

ostream& operator<<(ostream &strm, const Player &a) {
    if(a.color_==NONE){
        strm <<"No one";
    }else if(a.color_==GOLD){
        strm << "Gold";
    }else if(a.color_==BLACK){
        strm << "Black"
                "";
    }
    return strm;
}
}
