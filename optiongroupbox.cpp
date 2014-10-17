#include "optiongroupbox.h"

OptionGroupBox::OptionGroupBox(QString title, QWidget *parent) :
    QGroupBox(parent)
{
    setTitle(title);
}

OptionGroupBox::OptionGroupBox(const OptionGroupBox &other) :
    QGroupBox()
{
    this->choixPossibles = other.choixPossibles;
}

void OptionGroupBox::addChoix(choix c){
    choixPossibles.push_back(c);
}

OptionGroupBox &OptionGroupBox::operator =(const OptionGroupBox &other){
    this->choixPossibles = other.choixPossibles;
    return *this;
}
