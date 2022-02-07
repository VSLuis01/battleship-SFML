//
// Created by luis on 11/5/2021.
//

#include "ButtonPxM.h"

ButtonPxM::ButtonPxM(const sf::Vector2f &pos, const sf::Vector2f &tam, sf::RenderWindow *window) : ButtonModel(pos,
                                                                                                               tam) {
    this->setText("Jogador X Maquina");
    this->gameModePxM = new PlayerXMachine(window);
}

void ButtonPxM::clickAction(sf::Vector2f posicaoClick) {
    this->gameModePxM->run();
}

ButtonPxM::~ButtonPxM() {
    delete gameModePxM;
}
