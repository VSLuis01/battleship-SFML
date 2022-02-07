//
// Created by luis on 11/5/2021.
//

#include "PlayerXMachine.h"

PlayerXMachine::PlayerXMachine(sf::RenderWindow *window) : window(window), running(true), shootValidation(false) {
    this->initButtonBack();
    this->initPlayers();
    backGroudTexture.loadFromFile("../src/fundoBatalhaNaval.png");
    backGroud.setTexture(&backGroudTexture);
    backGroud.setSize({800,600});
}

PlayerXMachine::~PlayerXMachine() {
    delete this->player;
    delete this->machine;
    delete this->backButton;
}

void PlayerXMachine::initButtonBack() {
    this->backButton = new ButtonModel(sf::Vector2f(0, 0), sf::Vector2f(40, 40));
    this->backButton->setText("<");
    this->backButton->setButtonColor(sf::Color(105,105,105));
}

void PlayerXMachine::initPlayers() {
    this->player = new Player("Jogador");
    this->machine = new Player("Maquina");

}

void PlayerXMachine::run() {
    this->init();
    bool playerOk = Preparation(this->window, this->player).prepare();
    this->battleMusic.play();
    while (this->running && playerOk) {
        this->updateAndRender();
    }
    this->battleMusic.stop();
}

void PlayerXMachine::poolEvent() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                this->running = false;
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                    this->running = false;
                } else if (this->event.key.code == sf::Keyboard::B) {
                    if (!this->turn) {
                        player->keyboardAction(&event, window);
                    }
                }
            case sf::Event::MouseButtonReleased:
                this->machine->getGameBoard()->enableClickable();
                this->player->getGameBoard()->enableClickable();
                this->gearIcon.enableClickable();
                if (this->gearIcon.isClicked()) {
                    GameMusics::enableClickable();
                    GameSoundsFX::enableClickable();
                }
                break;
            default:
                break;
        }
    }
}

void PlayerXMachine::updateButtonBack() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->backButton->contains(this->mousePos)) {
            this->running = false;
        }
    }
}

void PlayerXMachine::updateMousePos() {
    this->mousePos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void PlayerXMachine::updateCells() {
    //caso clique no GameBoard, ira acessar a celula do GameBoard correspondente ao state
    if (!turn) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (this->machine->getGameBoard()->contains(this->mousePos) &&
                this->machine->getGameBoard()->isClickable()) {
                this->machine->getGameBoard()->disableClickable();

                if (this->player->attack(machine->getGameBoard(), this->mousePos, &turn, &shootValidation)) {
                    player->getGameBoard()->setBoardText("O jogador " + this->player->getName() + " venceu!");
                    this->renderGameBoard(turn);
                    this->battleMusic.stop();
                    this->wonSfx.play();
                    sf::sleep(sf::seconds(3));
                    this->running = false;
                }
                if (this->running) {
                    if (turn) {
                        this->shootSFX.play();
                        this->renderGameBoard(!turn);
                        sf::sleep(sf::seconds(0.5));
                    } else {
                        if (shootValidation) {
                            this->hitSfx.play();
                            shootValidation = false;
                        }
                    }
                }

            }
        }
    } else {
        sf::sleep(sf::seconds(1.0));
        if (this->machine->randomAttack(player->getGameBoard(), &turn, &shootValidation)) {
            machine->getGameBoard()->setBoardText("O jogador " + this->machine->getName() + " venceu!");
            this->renderGameBoard(turn);
            this->battleMusic.stop();
            this->wonSfx.play();
            sf::sleep(sf::seconds(3));
            this->running = false;
        }
        if (this->running) {
            if (!turn) {
                this->shootSFX.play();
                this->renderGameBoard(!turn);
                sf::sleep(sf::seconds(1.0));
            } else {
                if (shootValidation) {
                    this->hitSfx.play();
                    shootValidation = false;
                }
            }
        }

    }
    this->renderGameBoard(turn);

}


void PlayerXMachine::renderGameBoard(bool boardRender) {
    this->window->clear(sf::Color(9, 2, 111, 255));
    this->window->draw(backGroud);
    this->backButton->drawButton(*this->window);
    if (!boardRender) {
        player->seeEnemy(*this->window, machine->getGameBoard());
    } else {
        machine->seeEnemy(*this->window, player->getGameBoard());
    }
    this->gearIcon.render(*this->window);
    this->window->display();
}

void PlayerXMachine::updateAndRender() {
    this->poolEvent();
    this->updateMousePos();
    //this->preparation();
    this->updateButtonBack();
    //this->gameLogic();
    this->updateCells();
    this->gearIcon.update(this->mousePos);
    if (this->gearIcon.isClicked()) {
        GameMusics::update(this->mousePos, this->battleMusic);
        GameSoundsFX::update(this->mousePos, this->shootSFX);
        GameSoundsFX::update(this->mousePos, this->hitSfx);
    } else {
        GameMusics::update(this->battleMusic);
        GameSoundsFX::update(this->shootSFX);
        GameSoundsFX::update(this->hitSfx);
    }

}

void PlayerXMachine::init() {
    this->gearIcon.setClicked(false);
    this->running = true;
    this->turn = false;
    this->player->reset();

    this->machine->reset();
    this->machine->init();

}
