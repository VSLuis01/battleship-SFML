//
// Created by maluc on 30/09/2021.
//

#include "Cell.h"
#include "Boat.h"

Cell::Cell(float x, float y, float tam) : Clickable(), x(x), y(y) {

    //por padrao se carrega a figure da agua
    this->init();
    this->figure.setPosition(sf::Vector2f(x, y));
    this->figure.setSize(sf::Vector2f(tam, tam));
    this->figure.setOutlineColor(sf::Color::Black);
    this->figure.setOutlineThickness(0.6);
    //por padrao nao tem boat
}

void Cell::init() {
    this->enableClickable();
    this->setEnemyTexture("../src/aqua.png");
    this->setPlayerTexture("../src/aqua.png");
    this->loadEnemyTexture();
    boat = nullptr;
}

float Cell::getX() const {
    return x;
}

void Cell::setX(float x) {
    this->x = x;
    this->figure.setPosition(x, y);
}

float Cell::getY() const {
    return y;
}

void Cell::setY(float y) {
    Cell::y = y;
    this->figure.setPosition(x, y);
}

const sf::RectangleShape &Cell::getFigura() const {
    return this->figure;
}

void Cell::setEnemyTexture(std::string caminho) {
    this->enemyTexture.loadFromFile(caminho);
}

void Cell::setPlayerTexture(std::string caminho) {
    this->playerTexture.loadFromFile(caminho);
}

void Cell::loadEnemyTexture() {
    this->figure.setTexture(&enemyTexture);
}

void Cell::loadPlayerTexture() {
    this->figure.setTexture(&playerTexture);
}

//clicou na celula do GameBoard
bool Cell::click(bool *player, bool *shootValidation) {
    if (isClickable()) {
        disableClickable();
        if (this->boat == nullptr) {
            setEnemyTexture("../src/tiroErrado.png");
            setPlayerTexture("../src/tiroErrado.png");
            this->figure.setTexture(&this->enemyTexture);
            *player = !*player;
            return false;
        } else {
            setEnemyTexture("../src/tiroCerto.png");
            this->boat->updatePlayer(this->getX(), this->getY());
            this->figure.setTexture(&this->enemyTexture);
            this->boat->gotShoot();
            *shootValidation=true;
            return true;
        }
    }
    return false;

}

Boat *Cell::getBarco() const {
    return this->boat;
}

void Cell::setBarco(Boat *barco) {
    //codição para caso esteja resetando o GameBoard
    if (barco == nullptr) {
        this->boat = barco;
        this->enemyTexture.loadFromFile("../src/aqua.png");
        this->figure.setTexture(&this->enemyTexture);
    } else {
        this->boat = barco;
    }
}

bool Cell::contains(sf::Vector2f pos) {
    return this->figure.getGlobalBounds().contains(pos);
}

bool Cell::intersects(sf::FloatRect rect, int tam, bool rotate) {
    if (rotate) {
        float fig_top = this->figure.getGlobalBounds().top;
        float fig_height = this->figure.getGlobalBounds().height;
        float fig_left = this->figure.getGlobalBounds().left;
        float fig_width = this->figure.getGlobalBounds().width;

        //ESSE AJUSTE É PQ A SPRITE É MAIOR DO QUE APARENTA SER.
        //Precisa ajustar para ocupar a quantidade certa de quadrados que o barco tem
        float spriteAdjustment;
        if (tam == 4) {
            spriteAdjustment = 58.f;
        } else if (tam == 3) {
            spriteAdjustment = 46.f;
        } else {
            spriteAdjustment = 40.f;
        }

        if ((rect.top + 30 > fig_top) && (rect.top + rect.height - 20 < fig_top + fig_height)) {
            if ((rect.left + spriteAdjustment < fig_left + fig_width) &&
                (rect.left + rect.width - spriteAdjustment > fig_left)) {
                return true;
            }
        }

    } else {
        float fig_top = this->figure.getGlobalBounds().top;
        float fig_height = this->figure.getGlobalBounds().height;
        float fig_left = this->figure.getGlobalBounds().left;
        float fig_width = this->figure.getGlobalBounds().width;

        //ESSE AJUSTE É PQ A SPRITE É MAIOR DO QUE APARENTA SER.
        //Precisa ajustar para ocupar a quantidade certa de quadrados que o barco tem
        float spriteAdjustment;
        if (tam == 4) {
            spriteAdjustment = -2.8f;
        } else if (tam == 3) {
            spriteAdjustment = 4.3f;
        } else {
            spriteAdjustment = 11.3f;
        }

        if ((rect.left - 5 < fig_left) && (rect.left + rect.width + 20 > fig_left + fig_width)) {
            if ((rect.top - spriteAdjustment < fig_top) &&
                (rect.top + rect.height + spriteAdjustment > fig_top + fig_height)) {
                return true;
            }
        }
    }

    return false;
}

void Cell::setFigureColor(sf::Color color) {
    this->figure.setFillColor(color);
}

void Cell::highlight(sf::Color color) {
    figure.setFillColor(color);
}

bool Cell::operator<(const Cell &o) const {
    return (this->x < o.x || this->y < o.y);
}

bool Cell::operator==(const Cell &o) const {
    return (this->x == o.x && this->y == o.y);
}

Cell::~Cell() {

}
