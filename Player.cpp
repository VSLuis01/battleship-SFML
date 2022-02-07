//
// Created by maluc on 27/10/2021.
//

#include "Player.h"


int Player::getPoints() const {
    return points;
}

Player::operator GameBoard *() {
    return gameBoard;
}

bool Player::attack(GameBoard *board, sf::Vector2f position, bool *turn, bool *shootValidation) {
    if (board->click(position.x, position.y, turn, shootValidation)) {
        this->points++;
    }
    return this->points == this->maxPoints;
}

bool Player::randomAttack(GameBoard *board, bool *turn, bool *shootValidation) {
    Cell victim = board->getRandomCell();
    if (board->click(victim.getX(), victim.getY(), turn,shootValidation )) {
        this->points++;
    }

    return this->points == this->maxPoints;
}

GameBoard *Player::getGameBoard() {
    return gameBoard;
}

void Player::keyboardAction(sf::Event *event, sf::RenderWindow *window) {
    while (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        if (sf::Event::KeyReleased == event->type) {
            break;
        }
        this->showPlayerBoard(*window);
        window->display();
        window->pollEvent(*event);
    }
}


void Player::showPlayerBoard(sf::RenderTarget &target) {
    gameBoard->desenhaPlayer(target);
}

void Player::seeEnemy(sf::RenderTarget &target, GameBoard *enemy) {
    gameBoard->desenhaEnemy(target, enemy);
}

void Player::init() {
    gameBoard->init();
    this->points = 0;
}

void Player::reset() {
    this->gameBoard->setBoardText(name);
    this->points = 0;
}

Player::Player(const std::string &name, int tam, float x, float y, int ordemMatriz) :
        name(name), points(0), maxPoints(13),
        gameBoard(new GameBoard(tam, x, y, ordemMatriz, name)) {
}

Player::~Player() {
    delete gameBoard;
}

const std::string &Player::getName() const {
    return name;
}
