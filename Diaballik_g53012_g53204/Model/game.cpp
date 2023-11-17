#include "Model/game.h"

namespace diaballik{


Game::Game():current_(GOLD),opponent_(BLACK), board_(0){
}


void Game::init(unsigned taille, bool variante){
    board_={taille};
    selected_=Position(0,0);
    for(unsigned i=0; i<taille;i++ ){
        if(i== taille/2){
            board_.putAt({static_cast<int>(i),0},{GOLD,true});
            board_.putAt({static_cast<int>(i),static_cast<int>(taille)-1},{BLACK,true});
        }else if(i==1 && variante){
            board_.putAt({1,0},{BLACK,false});
            board_.putAt({1,static_cast<int>(taille)-1 },{GOLD,false});
        }else if(i== taille-2 && variante){
            board_.putAt({static_cast<int>(taille-2),0},{BLACK,false});
            board_.putAt({static_cast<int>(taille-2),static_cast<int>(taille)-1 },{GOLD,false});
        }else{
            board_.putAt({static_cast<int>(i),0}, {GOLD, false});
            board_.putAt({static_cast<int>(i),static_cast<int>(taille)-1},{BLACK,false});
        }
    }
    changeSelected();//change

}


void Game::select(int row, int col){
    Position pos{row, col};
    if(!board_.isInside(pos)) {throw invalid_argument("the square is not inside the board");}

    if(board_.getSquare(pos).isEmpty()){ throw logic_error("Empty square");}

    if(!board_.getSquare(pos).isMyOwn(current_.getColor())){ throw logic_error("the chosen square doesn't belong to you!");}
    selected_=pos;
    notifierChangement();
}


Support Game::getSelected(){
    if(!board_.isInside(selected_)){
        throw std::invalid_argument("the square is not inside the board");
    }
    return board_.getSquare(selected_).getSupp();
}


Board& Game::getBoard(){
    return board_;
}


Player Game::getCurrent(){
    return current_;
}


Player Game::getOpponent(){
    return opponent_;
}

bool Game::isOver(){
    for(unsigned i=0;i<board_.getSquares().size();i++){
        if(board_.getSquare({static_cast<int>(i),0}).getSupp().getColorSupport()==BLACK && board_.getSquare({static_cast<int>(i),0}).getSupp().hasBall()){
            return true;
        }
        if(board_.getSquare({static_cast<int>(i), static_cast<int>(board_.getSquares().size()-1)}).getSupp().getColorSupport()==GOLD && board_.getSquare({ static_cast<int>(i), 4}).getSupp().hasBall()){
            return true;
        }
    }
    return false;
}

void Game::start(){
    if(isOver()){
        throw logic_error("the game does not start in good conditions");
    }
}



bool Game::isFairPlay(){
    Position pos;
    Position pos2;
    int count=0;
    bool trouver=false;
    for(unsigned i=0;i<board_.getSquares().size() && !trouver;i++){
        pos={0,static_cast<int>(i)};
        if(!board_.isFree(pos) && !board_.isMyOwn(pos, current_.getColor())){
            trouver=true;
        }
    }

    while(pos.getRow() < static_cast<int>(board_.getSquares().size()-1)  && trouver){
        trouver=false;
        for(int j=RIGHT; j<= DR && !trouver; j++){
            pos2=pos;
            pos.next(static_cast<Direction>(j));
            if(board_.isInside(pos) && !board_.isFree(pos) && !board_.isMyOwn(pos, current_.getColor())){
                if(impassable(pos)){
                    count++;
                }
                trouver=true;
            }else{
                pos=pos2;
            }
        }
    }
    if(count<3){
        trouver=false;
    }
    return trouver;
}

void Game::swapPlayer(){
    Player p(current_);
    current_=opponent_;
    opponent_=p;
    changeSelected();//change

}

bool Game::impassable(Position pos){
    bool trouver=false;
    Position pos2;
    for(int j=UP; j<= DOWN && !trouver; j++){
        pos2=pos;
        pos.next(static_cast<Direction>(j));
        if(board_.isInside(pos) && board_.isMyOwn(pos, current_.getColor())){
            trouver =true;
        }else{
            pos=pos2;
        }
    }
    return trouver;
}

void Game::notifierChangement()
{
    for (Observer * e : mesObservateurs)
    {
        e->update(this);
    }
}

void Game::removeObserver(Observer *obs)
{
    mesObservateurs.remove(obs);
}

void Game::registerObserver(Observer *obs)
{
    mesObservateurs.push_back(obs);
}

void Game::passBall(Position pos, bool &pass){
    if(!board_.isInside(selected_))throw std::invalid_argument("no selected position");
    if(selected_.getRow()==pos.getRow() &&  selected_.getCol()==pos.getCol())throw std::invalid_argument("you cannot pass ");
    if(!board_.isInside(pos)  || board_.getSquare(pos).isEmpty())  throw std::invalid_argument("the end position is not correct");
    if(!board_.getSquare(selected_).getSupp().hasBall()) throw logic_error("wrong square selected !!");

    for(int i=UP; i<= DL &&  pass; i++){
        if(checkDirection(pos,static_cast<Direction>(i))){
            board_.getSquare(selected_).getSupp().setBallSupport(false);
            board_.getSquare(pos).getSupp().setBallSupport(true);
            pass =false;
        }
    }
    if(!board_.getSquare(pos).getSupp().hasBall()){
        changeSelected();//change
        throw logic_error("no pass my friend");

    }
    changeSelected();//change

}

bool Game::checkDirection(Position pos,Direction direction){
    Position nextPosition={pos};
    bool canPass=false;

    while (board_.isInside(nextPosition) && (board_.isMyOwn(nextPosition,NONE) || board_.isMyOwn(nextPosition,current_.getColor()))) {
        if(nextPosition.getCol()==selected_.getCol() && nextPosition.getRow()==selected_.getRow()){
            canPass=true;
        }
        nextPosition.next(direction);
    }
    return canPass;
}


Player Game::getWinner(){
    if(isOver() || isFairPlay()){
        return getCurrent();
    }
    return {NONE};
}


void Game::changeSelected(){
    selected_={24,24};
    notifierChangement();//change
}


vector<Move> Game::move (int count){
    Support piece = getSelected();
    Position posi=selected_;
    vector<Move> move;
    if(!board_.getSquare(selected_).getSupp().hasBall()){
        for(unsigned i=UP;i<=DL && count < 2;i++){
            posi=selected_;
            Direction dirr=static_cast<Direction>(i);
            posi.next(dirr);
            if(board_.isInside( posi) && board_.isFree(posi) && ! board_.isMyOwn(posi,opponent_.getColor())){

                if((dirr==UP || dirr==DOWN || dirr==LEFT || dirr==RIGHT) ){
                    move.push_back(Move{piece,selected_,posi,0});
                }else if((dirr==UR || dirr==UL || dirr==DR || dirr==DL) && count !=1){
                    move.push_back(Move{piece,selected_,posi,2});
                }else if (!board_.isFree(posi)){
                    count=2;
                }
                posi.next(dirr);
            }


            if (board_.isInside(posi) && board_.isFree(posi) && (dirr==UP || dirr==DOWN || dirr==LEFT || dirr==RIGHT) && count < 1) {
                move.push_back(Move{piece,selected_,posi,2});
            }
        }
    }
    return move;
}



void Game::applyMove(Position pos, int & count){
    if(!board_.isInside(selected_)){
        throw std::invalid_argument("no selected position");
    }
    if(!board_.isInside(pos) || !board_.getSquare(pos).isEmpty()){
        throw std::invalid_argument("invalid position");
    }
    bool trouver=false;
    for(unsigned i=0; i<move(count).size() && !trouver && count <2 ; i++){
        if(pos.getCol()== move(count)[i].getPositionEnd().getCol() && pos.getRow() ==  move(count)[i].getPositionEnd().getRow() ){
            if(move(count)[i].getDegree()<2){
                count++;
            }else{
                count =2;
            }
            board_.putAt(pos, getSelected());
            board_.remove(selected_);
            trouver=true;
        }
    }
    changeSelected();//change

}

Position Game::getSelect(){
    return selected_;

}
}
