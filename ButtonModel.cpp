//
// Created by maluc on 06/10/2021.
//

#include "ButtonModel.h"

ButtonModel::ButtonModel(sf::Vector2f pos, sf::Vector2f tam) : Clickable() {
    this->initButton(pos, tam);
    this->initFont();
    this->initText();
    this->initVariables();

}

ButtonModel::ButtonModel() {
    this->initFont();
    this->initText();
    this->initVariables();
}

void ButtonModel::initButton(sf::Vector2f pos, sf::Vector2f tam) {
    this->button.setPosition(pos);
    this->button.setSize(tam);
}

void ButtonModel::initText() {
    this->txt.setFont(this->font);
    this->txt.setCharacterSize(30);
    this->txt.setFillColor(sf::Color::Black);//cor padrao
    this->txt.setFont(font);
}

void ButtonModel::initFont() {
    this->font.loadFromFile("../fontes/arial.ttf");//fonte padrao
}

void ButtonModel::initVariables() {
    this->clicked = false;
}

void ButtonModel::setTextColor(sf::Color color) {
    txt.setFillColor(color);
}

void ButtonModel::setTxtPosition(sf::Vector2f pos) {
    float pos_x = (pos.x + button.getGlobalBounds().width / 2.0f) -
                  (txt.getGlobalBounds().width / 2);
    float pos_y = (pos.y + button.getGlobalBounds().height / 3.0f) -
                  (txt.getGlobalBounds().height / 2);
    txt.setPosition(pos_x, pos_y);
}

void ButtonModel::setText(std::string texto) {
    sf::Vector2f pos = this->button.getPosition();
    this->txt.setString(texto);//coloca texto no botao
    setTxtPosition(pos);
}

//define tamanho do botao
void ButtonModel::setSize(sf::Vector2f tam) {
    this->button.setSize(tam);
    sf::Vector2f pos = this->button.getPosition();
    setTxtPosition(pos);
}

void ButtonModel::setSize(float tamX, float tamY) {
    this->button.setSize(sf::Vector2f(tamX, tamY));
    this->setTxtPosition(this->button.getPosition());
}

void ButtonModel::setButtonColor(sf::Color color) {
    button.setFillColor(color);
}

void ButtonModel::setOutLineColor(sf::Color color) {
    button.setOutlineColor(color);
}

void ButtonModel::setOutlineThickness(float thickness) {
    button.setOutlineThickness(thickness);
}

void ButtonModel::setPosition(sf::Vector2f pos) {
    this->button.setPosition(pos);

    setTxtPosition(pos);
}

void ButtonModel::setPosition(float posX, float posY) {
    this->button.setPosition(sf::Vector2f(posX, posY));
    this->setTxtPosition(this->button.getPosition());
}


void ButtonModel::drawButton(sf::RenderTarget &target) {
    target.draw(this->button);
    target.draw(this->txt);

}

bool ButtonModel::contains(sf::Vector2f posicao) {
    bool click = button.getGlobalBounds().contains(posicao);
    return click;
}

void ButtonModel::canClick(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonReleased) {
        this->enableClickable();
    }
}

void ButtonModel::setFont(sf::String path) {
    font.loadFromFile(path);
}

ButtonModel::~ButtonModel() {

}



