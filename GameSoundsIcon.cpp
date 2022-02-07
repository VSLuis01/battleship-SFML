//
// Created by luis on 12/8/2021.
//

#include "GameSoundsIcon.h"

bool GameSoundsIcon::contains(sf::Vector2f posicao) {
    return this->gearSprite.getGlobalBounds().contains(posicao);
}

GameSoundsIcon::GameSoundsIcon() : clicked(false) {
    this->gearIcon.loadFromFile("../src/icons/opcao_icon.png");
    this->gearSprite.setTexture(this->gearIcon);
    this->gearSprite.setPosition(800 - this->gearSprite.getGlobalBounds().width, 0);


    this->optionsPanel.setSize(sf::Vector2f(GameSoundsFX::getBounds().width + 20,
                                            GameSoundsFX::getBounds().height + GameMusics::getBounds().height + 5));
    this->optionsPanel.setPosition(800 - this->optionsPanel.getGlobalBounds().width,
                                   this->gearSprite.getGlobalBounds().height + 10);
    this->optionsPanel.setFillColor(sf::Color(36, 54, 63,153));


    GameMusics::setPosition(this->optionsPanel.getPosition().x + GameMusics::getBounds().width - 5,
                            this->optionsPanel.getPosition().y);

    GameSoundsFX::setPosition(this->optionsPanel.getPosition().x + GameMusics::getBounds().width - 5,
                              GameMusics::getPosition().y + GameSoundsFX::getBounds().height);
}

void GameSoundsIcon::render(sf::RenderTarget &target) {
    target.draw(this->gearSprite);
    if (this->clicked) {
        target.draw(this->optionsPanel); //renderiza o painel se a engrenagem tiver sido clicada
        GameSoundsFX::render(target);
        GameMusics::render(target);
    }
}

bool GameSoundsIcon::isClicked() const {
    return clicked;
}

/**
 * Atualiza o "painel"
 * Se o painel está ativo, então é desativado se sofreu click, e vise-versa
 * @param mousePos
 */
void GameSoundsIcon::update(sf::Vector2f mousePos) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->contains(mousePos) && this->isClickable()) {
            this->disableClickable();
            if (!this->isClicked()) {
                this->setClicked(true);
            } else {
                this->setClicked(false);
            }
        }
    }
}

void GameSoundsIcon::setClicked(bool clicked) {
    GameSoundsIcon::clicked = clicked;
}


