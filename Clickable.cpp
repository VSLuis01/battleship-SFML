//
// Created by maluc on 30/09/2021.
//

#include "Clickable.h"

Clickable::Clickable() : state(true) {}

//verifica se ja foi clicado no elemento
void Clickable::enableClickable() {
    this->state = true;
}

void Clickable::disableClickable() {
    this->state = false;
}

bool Clickable::isClickable() const {
    return state;
}


void Clickable::clickAction(sf::Vector2f posicaoClick) {}

Clickable::~Clickable() {

}





