//
// Created by maluc on 06/10/2021.
//

#include "PlayerXPlayer.h"

PlayerXPlayer::PlayerXPlayer(sf::RenderWindow *window) : window(window), running(true) {
    this->initButtonBack();
    this->initPlayers();
    backGroudTexture.loadFromFile("../src/fundoBatalhaNaval.png");
    backGroud.setTexture(&backGroudTexture);
    backGroud.setSize({800,600});
   // backGroud.setFillColor(sf::Color(55,71,80,255));

}

PlayerXPlayer::~PlayerXPlayer() {
    delete this->player1;
    delete this->player2;
    delete this->backButton;
}

void PlayerXPlayer::initButtonBack() {
    this->backButton = new ButtonModel(sf::Vector2f(0, 0), sf::Vector2f(40, 40));
    this->backButton->setText("<");
    this->backButton->setButtonColor(sf::Color(105,105,105,0));
}

void PlayerXPlayer::initPlayers() {
    this->player1 = new Player("Jogador 1");
    this->player2 = new Player("Jogador 2");
    shootValidation = false;
}


void PlayerXPlayer::run() {
    this->init();
    bool player1_ok;
    player1_ok = Preparation(this->window, this->player1).prepare();
    bool player2_ok;
    if (player1_ok) {
        player2_ok = Preparation(this->window, this->player2).prepare();
    }
    this->battleMusic.play();
    while (this->running && player1_ok && player2_ok) {
        this->updateAndRender();
    }
    this->battleMusic.stop();
}

void PlayerXPlayer::poolEvent() {
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
                        player1->keyboardAction(&event, window);
                    } else {
                        player2->keyboardAction(&event, window);
                    }
                }
                break;
            case sf::Event::MouseButtonReleased:
                this->player1->getGameBoard()->enableClickable();
                this->player2->getGameBoard()->enableClickable();
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

void PlayerXPlayer::updateButtonBack() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->backButton->contains(this->mousePos)) {
            this->running = false;
        }
    }
}

void PlayerXPlayer::updateMousePos() {
    this->mousePos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void PlayerXPlayer::updateCells() {
    //caso clique no GameBoard, ira acessar a celula do GameBoard correspondente ao state
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!turn) {
            if (this->player2->getGameBoard()->contains(this->mousePos) &&
                this->player2->getGameBoard()->isClickable()) {
                this->player2->getGameBoard()->disableClickable();
                if (this->player1->attack(player2->getGameBoard(), this->mousePos, &turn, &shootValidation)) {
                    player1->getGameBoard()->setBoardText("O jogador " + this->player1->getName() + " venceu!");
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
        } else {
            if (this->player1->getGameBoard()->contains(this->mousePos) &&
                this->player1->getGameBoard()->isClickable()) {
                this->player1->getGameBoard()->disableClickable();
                if (this->player2->attack(player1->getGameBoard(), this->mousePos, &turn, &shootValidation)) {
                    player2->getGameBoard()->setBoardText("O jogador " + this->player2->getName() + " venceu!");
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
                        sf::sleep(sf::seconds(0.5));
                    } else {
                        if (this->shootValidation) {
                            this->hitSfx.play();
                            this->shootValidation = false;
                        }
                    }
                }

            }

        }
    }
    this->renderGameBoard(turn);
}


void PlayerXPlayer::renderGameBoard(bool boardRender) {
    this->window->clear(sf::Color(9, 2, 111, 255));
    this->window->draw(backGroud);
    this->backButton->drawButton(*this->window);
    if (!boardRender) {
        player1->seeEnemy(*this->window, player2->getGameBoard());
    } else {
        player2->seeEnemy(*this->window, player1->getGameBoard());
    }
    this->gearIcon.render(*this->window);
    this->window->display();
}

void PlayerXPlayer::updateAndRender() {
    this->poolEvent();
    this->updateMousePos();
    //this->preparation();
    this->updateButtonBack();
    //this->gameLogic();
    this->updateCells();
    this->gearIcon.update(this->mousePos);
    if (this->gearIcon.isClicked()) {
        GameSoundsFX::update(this->mousePos, this->shootSFX);
        GameSoundsFX::update(this->mousePos, this->hitSfx);
        GameMusics::update(this->mousePos, this->battleMusic);

    } else {
        GameSoundsFX::update(this->shootSFX);
        GameSoundsFX::update(this->hitSfx);
        GameMusics::update(this->battleMusic);
    }

}

void PlayerXPlayer::init() {
    this->gearIcon.setClicked(false);
    this->running = true;
    this->turn = false;
    this->player1->reset();
    this->player2->reset();
    //this->player1->getGameBoard()->initPoints();
    //this->battleMusic.setVolume(15);
    //this->battleMusic.setLoop(true);
    //this->battleMusic.play();
}
