//
// Created by luis on 12/7/2021.
//

#include "SpeakerIcon.h"

bool SpeakerIcon::contains(sf::Vector2f posicao) {
    return this->iconSprite.getGlobalBounds().contains(posicao) || this->iconText.getGlobalBounds().contains(posicao);
}

SpeakerIcon::SpeakerIcon() {
    if (this->iconSprite.getTexture() == nullptr) {
        this->iconActiveTex.loadFromFile("../src/icons/som_ativado.png");
        this->iconDeactivateText.loadFromFile("../src/icons/som_desativado.png");

        this->iconSprite.setTexture(this->iconActiveTex);
        this->iconSprite.setColor(sf::Color(186,186,186));

        this->font.loadFromFile("../fontes/veteran typewriter.ttf");
        this->iconText.setFont(this->font);
        this->iconText.setCharacterSize(26);
        this->iconText.setFillColor(this->iconSprite.getColor());
    }
}

void SpeakerIcon::updateTextPosition() {
    this->iconText.setPosition(this->iconSprite.getPosition().x - this->iconText.getGlobalBounds().width - 10,
                               this->iconSprite.getPosition().y + this->iconText.getGlobalBounds().height - 5);
}

void SpeakerIcon::setPosition(sf::Vector2f pos) {
    this->iconSprite.setPosition(pos);
    this->updateTextPosition();
}

const sf::Vector2f &SpeakerIcon::getPosition() {
    return this->iconSprite.getPosition();
}

void SpeakerIcon::setPosition(float posX, float posY) {
    this->iconSprite.setPosition(sf::Vector2f(posX, posY));
    this->updateTextPosition();
}

const sf::Texture *SpeakerIcon::getTexture() {
    return this->iconSprite.getTexture();
}

void SpeakerIcon::setTexture(const sf::Texture &tex) {
    this->iconSprite.setTexture(tex);
}

void SpeakerIcon::setSpeakerName(const std::string &speakerName) {
    this->iconText.setString(speakerName);
    this->updateTextPosition();
    this->iconSprite.setOrigin(this->iconText.getOrigin());
}

void SpeakerIcon::render(sf::RenderTarget &target) {
    target.draw(this->iconSprite);
    target.draw(this->iconText);
}

//Isso aqui não está muito certo, mas estou muito cansado para arrumar
sf::FloatRect SpeakerIcon::getIconSpriteBounds() const {
    return {this->iconSprite.getGlobalBounds().top, this->iconSprite.getGlobalBounds().left,
                          this->iconSprite.getGlobalBounds().width + this->iconText.getGlobalBounds().width,
                          this->iconSprite.getGlobalBounds().height};
}
