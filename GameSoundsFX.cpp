//
// Created by luis on 12/7/2021.
//

#include "GameSoundsFX.h"

//Definindo os atributos static
float GameSoundsFX::volume = 30.f;
SpeakerIcon GameSoundsFX::speakerIcon;

GameSoundsFX::GameSoundsFX() {
    GameSoundsFX::speakerIcon.setSpeakerName("SoundFX");
    GameSoundsFX::speakerIcon.disableClickable();
}

void GameSoundsFX::setPosition(sf::Vector2f pos) {
    GameSoundsFX::speakerIcon.setPosition(pos);
}

void GameSoundsFX::enableClickable() {
    GameSoundsFX::speakerIcon.enableClickable();
}

void GameSoundsFX::disableClickable() {
    GameSoundsFX::speakerIcon.disableClickable();
}

void GameSoundsFX::setPosition(float posX, float posY) {
    GameSoundsFX::speakerIcon.setPosition(posX, posY);
}

sf::FloatRect GameSoundsFX::getBounds() {
    return GameSoundsFX::speakerIcon.getIconSpriteBounds();
}

/**
 * Atualizando o icone speaker
 * Se o ícone é ativo, ele é definito para mudo, caso sofra um click, e vise-versa
 * @param mousePos
 */
void GameSoundsFX::updateSpeakerIcon(sf::Vector2f mousePos) {
    if (GameSoundsFX::speakerIcon.isClickable()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (GameSoundsFX::speakerIcon.contains(mousePos)) {
                if (GameSoundsFX::speakerIcon.getTexture() == &GameSoundsFX::speakerIcon.iconActiveTex) {
                    GameSoundsFX::speakerIcon.setTexture(GameSoundsFX::speakerIcon.iconDeactivateText);
                    GameSoundsFX::speakerIcon.disableClickable();
                    GameSoundsFX::volume = 0.f; //seta o volume para zero, caso estiver mudo
                                                //Assim todos so efeitos sonoros ficam mudos
                } else {
                    GameSoundsFX::speakerIcon.setTexture(GameSoundsFX::speakerIcon.iconActiveTex);
                    GameSoundsFX::speakerIcon.disableClickable();
                    GameSoundsFX::volume = 20.f;
                }
            }
        }
    }
}

void GameSoundsFX::render(sf::RenderTarget &target) {
    GameSoundsFX::speakerIcon.render(target);
}

void GameSoundsFX::update(sf::Vector2f mousePos, GameSoundsFX &soundFX) {
    GameSoundsFX::updateSpeakerIcon(mousePos);
    soundFX.setVolume(GameSoundsFX::volume);
}

void GameSoundsFX::update(GameSoundsFX &soundFX) {
    soundFX.setVolume(GameSoundsFX::volume);
}

const sf::Vector2f &GameSoundsFX::getPosition() {
    return GameSoundsFX::speakerIcon.getPosition();
}
