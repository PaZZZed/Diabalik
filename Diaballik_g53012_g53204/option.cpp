#include "option.h"
#include "ui_option.h"


Option::Option(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Option)
{
    ui->setupUi(this);
}

Option::~Option()
{
    delete ui;
    delete jeu_;

}

void Option::ouverture(){
    MWDiaballik *jeu=new MWDiaballik(this,getVariante(),getTaille());
    jeu->show();
    this->hide();
}
unsigned Option::getTaille(){
    return ui->cbTaille->currentText().toUInt();
}

bool  Option::getVariante(){
    bool check=false;
    if(ui->rbN->isChecked()){
        check= false;
    }else if(ui->rbV->isChecked()){
        check= true;
    }
    return check;
}
