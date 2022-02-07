//
// Created by maluc on 27/09/2021.
//

#include "Game.h"

Game::Game(unsigned width, unsigned high) : running(true) {
    this->initWindow(width, high);
    //implementa botao menu
    this->initButtons();
    //this->initMusic();

}

void Game::initButtons() {
    this->buttonJxJ = new ButtonPxP(sf::Vector2f(66, 450), sf::Vector2f(300, 70), window);
    this->buttonJxJ->setButtonColor(sf::Color(36, 54, 63,153));
    this->buttonJxJ->setTextColor(sf::Color(199, 201, 181));
    this->buttonJxJ->setOutlineThickness(1);
    this->buttonJxJ->setOutLineColor(sf::Color(199, 201, 181));
    this->buttonJxJ->setFont("../fontes/veteran typewriter.ttf");

    this->buttonPxM = new ButtonPxM(sf::Vector2f(434, 450), sf::Vector2f(300, 70), window);
    this->buttonPxM->setButtonColor(sf::Color(36, 54, 63,153));
    this->buttonPxM->setTextColor(sf::Color(199, 201, 181));
    this->buttonPxM->setOutlineThickness(1);
    this->buttonPxM->setOutLineColor(sf::Color(199, 201, 181));
    this->buttonPxM->setFont("../fontes/veteran typewriter.ttf");
}

void Game::initWindow(unsigned width, unsigned high) {
    this->icon.loadFromFile("../src/icons/gameIcon.png");
    this->titleFont.loadFromFile("../fontes/No Safety Zone.ttf");
    this->window = new sf::RenderWindow(sf::VideoMode(width, high), "Seeschlacht",
                                        sf::Style::Close | sf::Style::Titlebar);
    this->window->setIcon(this->icon.getSize().x, this->icon.getSize().y, this->icon.getPixelsPtr());
    this->window->setFramerateLimit(60);
    backGroundTexture.loadFromFile("../src/cenarioBatalhaNaval.png");
    background.setTexture(&backGroundTexture);
    background.setSize({800,600});
    title.setFont(titleFont);
    title.setString("SEESCHLACHT");
    title.setCharacterSize(100);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(1);
    title.setFillColor(sf::Color(202, 202, 202));
    title.setPosition(400-title.getGlobalBounds().width/2,20);
}

//loop do jogo
void Game::run() {
    this->menuMusic.play();
    while (this->running && this->window->isOpen()) {
        this->update();
        this->render();
    }
    this->menuMusic.stop();
}

void Game::poolEvent() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                this->running = false;
                this->menuMusic.stop();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                    this->running = false;
                    this->menuMusic.stop();
                }
                break;
            case sf::Event::MouseButtonReleased:
                this->gearSoundIcon.enableClickable();
                if(this->gearSoundIcon.isClicked()) {
                    GameSoundsFX::enableClickable();
                    GameMusics::enableClickable();
                }
                break;
            default:
                break;
        }
    }
}


void Game::updateButtonJxJ() {
    if (this->buttonJxJ->contains(this->mousePos)) {
        this->buttonJxJ->setButtonColor(sf::Color(36, 54, 63,204));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->menuMusic.stop();
            this->buttonJxJ->clickAction(this->mousePos);
            Preparation::music.stop();
            this->menuMusic.play();
            this->gearSoundIcon.setClicked(false);
        }
    } else {
        this->buttonJxJ->setButtonColor(sf::Color(36, 54, 63,153));
    }
}

void Game::updateButtonPxM() {
    if (this->buttonPxM->contains(this->mousePos)) {
        this->buttonPxM->setButtonColor(sf::Color(36, 54, 63,204));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->menuMusic.stop();
            this->buttonPxM->clickAction(this->mousePos);
            Preparation::music.stop();
            this->menuMusic.play();
            this->gearSoundIcon.setClicked(false);
        }
    } else {
        this->buttonPxM->setButtonColor(sf::Color(36, 54, 63,153));
    }
}

void Game::updateMousePos() {
    this->mousePos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Game::update() {
    this->poolEvent();
    this->updateMousePos();
    this->updateButtonPxM();
    this->updateButtonJxJ();
    this->gearSoundIcon.update(this->mousePos);
    if (this->gearSoundIcon.isClicked()) {
        GameMusics::update(this->mousePos, this->menuMusic);
        GameSoundsFX::update(this->mousePos, this->shootSfx);
    } else {
        GameMusics::update(this->menuMusic);
        GameSoundsFX::update(this->shootSfx);
    }

}

void Game::renderButtons() {
    this->buttonPxM->drawButton(*this->window);
    this->buttonJxJ->drawButton(*this->window);

}


void Game::render() {
    //limpa tela
    this->window->clear(sf::Color(9, 2, 111, 255));
    this->window->draw(background);
    this->renderButtons();
    this->window->draw(title);

    this->gearSoundIcon.render(*this->window);
    this->window->display();
}

Game::~Game() {
    delete this->window;
    delete this->buttonJxJ;
    delete this->buttonPxM;
}
