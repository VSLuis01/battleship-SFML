//
// Created by maluc on 27/09/2021.
//
/**
 * classe responsavel pelo jogo em si.
 * guarda o loop principal, é onde a tela é definida
 * guarda o menu inicial
 */
#ifndef TRABALHO_GAME_H
#define TRABALHO_GAME_H

#include "SFML/Graphics.hpp"
#include "PlayerXPlayer.h"
#include "MenuMusic.h"
#include "GameSoundsIcon.h"
#include "ButtonPxP.h"
#include "Preparation.h"
#include "ButtonPxM.h"
#include "ShootSFX.h"

/**
 * @brief Menu principal
 *
 * Essa classe é o menu principal, onde contém os botões para os dois modos de jogo.
 */
class Game {
private:
    sf::Image icon; ///<Ícone do jogo
    sf::Font titleFont;
    sf::Text title;
    sf::RenderWindow *window;
    sf::Event event;
    sf::Texture backGroundTexture;
    sf::RectangleShape background;
    ButtonPxP* buttonJxJ;///<Botão para o modo de jogo PlayerXPlayer.

    ButtonPxM* buttonPxM;///<Botão para o modo de jogo PlayerXMachine.

    MenuMusic menuMusic;///<Música tocada no menu principal. MenuMusic
    ShootSFX shootSfx;
    GameSoundsIcon gearSoundIcon;
    bool running;///<true caso o menu princiapal esteja rodando, false caso contrário.

    sf::Vector2f mousePos;

    /**
     * Inicia as definições dos botões Player vs Player e Player vs Machine
     */
    void initButtons();
    /**
     * Inicia a janela do jogo
     * @param width comprimento
     * @param high altura
     */
    void initWindow(unsigned width, unsigned high);

    /**
     *
     */
    void poolEvent();
    /**
     * Atualizações do botão jogador vs jogador. Ex: Passar o mouse por cima, clicar no botão.
     */
    void updateButtonJxJ();
    /**
     * Atualizações do botão jogador vs máquina. Ex: Passar o mouse por cima, clicar no botão.
     */
    void updateButtonPxM();
    /**
     * Atualiza a posição do cursor em relação à window do jogo.
     */
    void updateMousePos();

    void update();

    /**
     * Renderiza os botões
     */
    void renderButtons();
    void render();
public:
    /**
     * Construtor do jogo, tem como paramemtro a resolucao da tela
     */
    Game(unsigned int , unsigned int);

    virtual ~Game();
    /**
     * Loop principal do jogo.
     */
    void run();

};



#endif //TRABALHO_GAME_H
