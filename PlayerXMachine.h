//
// Created by luis on 11/5/2021.
//

#ifndef TRABALHO_PLAYERXMACHINE_H
#define TRABALHO_PLAYERXMACHINE_H

#include "SFML/Graphics.hpp"
#include "ButtonModel.h"
#include "Player.h"
#include "BattleMusic.h"
#include "Boat.h"
#include "GameSoundsIcon.h"
#include "Preparation.h"
#include "ShootSFX.h"
#include "HitSFX.h"
#include "WonSFX.h"

/**
 * @brief Essa classe representa o modo de jogo: JogadorVsMaquina
 *
 * Nesse modo de jogo um usuário joga contra a máquina, que ataca aleatoriamente sem nenhuma inteligencia artifial.
 * @see PlayerXPlayer
 */
class PlayerXMachine {
private:
    /*Sons*/
    WonSFX wonSfx;///<Efeito sonoro de quando vence o jogo.
    ShootSFX shootSFX;///<Efeito sonoro de tiro. @see ShootSFX.
    BattleMusic battleMusic;///<Música de batalha. @see BattleMusic.
    GameSoundsIcon gearIcon; ///<Ícone da engrenagem. @see GameSoundsIcon.
    HitSFX hitSfx; ///<Efeito sonoro de hit. @see HitSFX.
    sf::Texture backGroudTexture;
    sf::RectangleShape backGroud;
    /*Boards*/
    Player *player; ///<Tabuleiro do Jogador 1. @see Player
    Player *machine; ///<Tabueliro do Jogador 2. @see Player

    /*Logic*/
    bool turn; ///<Turno do jogador: true -> player1 ; false -> player2
    bool running; ///<true enquanto estiver ocorrendo a batalha.
    bool shootValidation;///<valida o tiro:true -> tiro valido/false->tiro em area ja usada
    /*Buttons*/
    ButtonModel *backButton; ///<Botão para voltar. Pode cancelar o jogo a qualquer momento. @see ButtonModel

    /*System*/
    sf::Event event;
    sf::RenderWindow *window;
    sf::Vector2f mousePos;

    /**
     * @brief Inicia o tabuleiro dos jogadores
     * Inicializa o player e machine
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
     * Reinicia os atributos: gearIcon, running, turn, player e machine.
     */
    void init();

    /**
     * Renderiza o tabuleiro de um jogador
     * @param boardRender false é o player, true é a machine
     */
    void renderGameBoard(bool boardRender);

public:
    /**
     * @brief Construtor do modo de jogo PlayerXMachine
     * @param window janela para renderizar
     */
    explicit PlayerXMachine(sf::RenderWindow *window);

    /**
     * @brief Destrutor do modo de jogo PlayerXPlayer
     *
     * Destrói os jogadores player e machine e também o botão de voltar backButton.
     */
    virtual ~PlayerXMachine();

    /**
     * loop do modo de jogo PlayerXMachine
     */
    void run();
};


#endif //TRABALHO_PLAYERXMACHINE_H
