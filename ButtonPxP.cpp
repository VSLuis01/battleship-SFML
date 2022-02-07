//
// Created by maluc on 06/10/2021.
//

#include "ButtonPxP.h"

ButtonPxP::ButtonPxP(const sf::Vector2f &pos, const sf::Vector2f &tam, sf::RenderWindow *window) : ButtonModel(pos,
                                                                                                               tam) {
    this->setText("Jogador X Jogador");
    this->gameMode = new PlayerXPlayer(window);
}

void ButtonPxP::clickAction(sf::Vector2f posicaoClick) {
    this->gameMode->run();
}

ButtonPxP::~ButtonPxP() {
    delete gameMode;
}
