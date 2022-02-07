//
// Created by luis on 12/7/2021.
//

#include "GameMusics.h"

float GameMusics::volume = 20.f;
SpeakerIcon GameMusics::speakerIcon;

GameMusics::GameMusics() {
    GameMusics::speakerIcon.setSpeakerName("Music");
    GameMusics::speakerIcon.disableClickable();
}

void GameMusics::enableClickable() {
    GameMusics::speakerIcon.enableClickable();
}

void GameMusics::disableClickable() {
    GameMusics::speakerIcon.disableClickable();
}

sf::FloatRect GameMusics::getBounds() {
    return GameMusics::speakerIcon.getIconSpriteBounds();
}

const sf::Vector2f &GameMusics::getPosition() {
    return GameMusics::speakerIcon.getPosition();
}

void GameMusics::setPosition(sf::Vector2f pos) {
    GameMusics::speakerIcon.setPosition(pos);
}

void GameMusics::setPosition(float posX, float posY) {
    GameMusics::speakerIcon.setPosition(posX, posY);
}

void GameMusics::updateSpeakerIcon(sf::Vector2f mousePos) {
    if (GameMusics::speakerIcon.isClickable()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (GameMusics::speakerIcon.contains(mousePos)) {
                if (GameMusics::speakerIcon.getTexture() == &GameMusics::speakerIcon.iconActiveTex) {
                    GameMusics::speakerIcon.setTexture(GameMusics::speakerIcon.iconDeactivateText);
                    GameMusics::speakerIcon.disableClickable();
                    GameMusics::volume = 0.f;
                } else {
                    GameMusics::speakerIcon.setTexture(GameMusics::speakerIcon.iconActiveTex);
                    GameMusics::speakerIcon.disableClickable();
                    GameMusics::volume = 20.f;
                }
            }
        }
    }
}


void GameMusics::render(sf::RenderTarget &target) {
    GameMusics::speakerIcon.render(target);
}

void GameMusics::update(sf::Vector2f mousePos, GameMusics &musicUpdate) {
    GameMusics::updateSpeakerIcon(mousePos);
    musicUpdate.setVolume(GameMusics::volume);
}

void GameMusics::update(GameMusics &musicUpdate) {
    musicUpdate.setVolume(GameMusics::volume);
}


