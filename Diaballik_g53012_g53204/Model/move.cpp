#include "Model/move.h"

namespace diaballik{

Move::Move(Support supp, Position start, Position end, int degree):supp_(supp),start_(start),end_(end), degree_(degree){}

Position Move::getPositionEnd(){
    return end_;
}
Position Move::getPositionStart(){
    return start_;
}
Support Move::getSupport(){
    return supp_;
}

int Move::getDegree(){
    return degree_;
}
}
