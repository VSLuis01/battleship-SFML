//
// Created by maluc on 06/10/2021.
//

#ifndef TRABALHO_PLAYERXPLAYER_H
#define TRABALHO_PLAYERXPLAYER_H

#include "SFML/Graphics.hpp"
#include "ButtonModel.h"
#include "Player.h"
#include "BattleMusic.h"
#include "GameSoundsIcon.h"
#include "Preparation.h"
#include "HitSFX.h"
#include "ShootSFX.h"
#include "WonSFX.h"

/**
 * @brief Classe representa o modo de jogo: JogadorVsJogador.
 *
 * @see PlayerXMachine
 */
class PlayerXPlayer {
private:
    sf::Texture backGroudTexture;
    sf::RectangleShape backGroud;
    /*Sons*/
    WonSFX wonSfx;///<Efeito sonoro de quando vence o jogo.
    ShootSFX shootSFX;///<Efeito sonoro de tiro. @see ShootSFX.
    BattleMusic battleMusic;///<Música de batalha. @see BattleMusic.
    GameSoundsIcon gearIcon; ///<Ícone da engrenagem. @see GameSoundsIcon.
    HitSFX hitSfx; ///<Efeito sonoro de hit. @see HitSFX.


    /*Boards*/
    Player *player1; ///<Tabuleiro do Jogador 1. @see Player
    Player *player2; ///<Tabueliro do Jogador 2. @see Player

    /*Logic*/
    bool turn; ///<Turno do jogador: true -> player1 ; false -> player2
    bool running; ///<true enquanto estiver ocorrendo a batalha.
    bool shootValidation;

    /*Buttons*/
    ButtonModel *backButton; ///<Botão para voltar. Pode cancelar o jogo a qualquer momento. @see ButtonModel

    /*System*/
    sf::Event event;
    sf::RenderWindow *window;
    sf::Vector2f mousePos;

    /**
     * @brief Inicia o tabuleiro dos jogadores
     * Inicializa o player1 e player2
     */
    void initPlayers();

    /**
     * Inicia o botão de voltar
     */
    void initButtonBack();

    void poolEvent();
    void updateButtonBack();
    /**
     * Atualiza a posição do mouse em relação à janela de jogo.
     */
    void updateMousePos();
    /**
     * @brief Atualiza as células do tabuleiro.
     *
     * Aqui é feito toda a lógica de ataque, renderização, atualização do tabuleiro, etc.
     */
    void updateCells();

    /**
     * Atualiza e renderiza os atributos da classe.
     */
    void updateAndRender();

    /**
     * @brief Inicializa alguns atributos da classe.
     *
     * Esse método reinicializa o modo de jogo.
     * Reinicia os atributos: gearIcon, running, turn, player1 e player2.
     */
    void init();

    /**
     * Renderiza o tabuleiro de um jogador
     * @param boardRender false é o player1, true é o player2
     */
    void renderGameBoard(bool boardRender);

public:
    /**
     * @brief Construtor do modo de jogo PlayerXPlayer
     * @param window janela para renderizar
     */
    explicit PlayerXPlayer(sf::RenderWindow *window);

    /**
     * @brief Destrutor do modo de jogo PlayerXPlayer
     *
     * Destrói os jogadores player1 e player2 e também o botão de voltar backButton.
     */
    virtual ~PlayerXPlayer();

    /**
     * Loop do modo de jogo PlayerXPlayer.
     */
    void run();
};



#endif //TRABALHO_PLAYERXPLAYER_H
