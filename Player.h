//
// Created by maluc on 27/10/2021.
//

#ifndef TRABALHO_PLAYER_H
#define TRABALHO_PLAYER_H

#include "GameBoard.h"

/**
 * @brief Classe que representa um jogador.
 *
 * Essa classe tem nela um tabuleiro. O jogador tem um nome name que será usado para identificar o turno de qual jogador.
 */
class Player {
private:
    std::string name; ///<Nome do jogador que aparecerá em cima do tabuleiro.
    int points, maxPoints; ///<Pontos do jogador. points é a pontuação atual e maxPoints é a pontuação máxima para vencer o jogo.
    GameBoard *gameBoard; ///<Tabuleiro do jogador. @see GameBoard.
public:
    /**
     * Pega o nome do jogador
     * @return string name
     */
    const std::string &getName() const;

    /**
     * @brief Construtor do jogador
     *
     * Esse é o único construtor do Player que possui apenas o parametro name como obrigatório.
     * @param name nome do jogador
     * @param tam tamanho de alguma coisa. default 50.
     * @param x posição x na tela. default 200.
     * @param y posição y na tela. default 100.
     * @param ordemMatriz ordem da matriz de células. default 8.
     */
    explicit Player(const std::string &name, int tam = 50, float x = 200, float y = 100, int ordemMatriz = 8);

    /**
     * @brief Destrutor do jogador.
     *
     * Destrói seu tabuleiro.
     */
    virtual ~Player();

    /**
     *
     * @return points do jogador
     */
    int getPoints() const;

    /**
     * ??
     * @return ??
     */
    operator GameBoard *();

    /**
     * @brief Método para renderizar o próprio tabuleiro.
     *
     * Mostra o próprio tabuleiro caso for pressionado a tecla B
     * @param event evento para verificar se a tecla foi solta
     * @param window janela para desenhar o tabuleiro
     */
    void keyboardAction(sf::Event *event, sf::RenderWindow *window);

    /**
     * Realiza o ataque
     * @param board tabuleiro que vai receber o ataque
     * @param position posição do ataque
     * @param turn turno do jogador (que será alterado caso errar o ataque).
     * @return true caso o ataque feito resultar em uma vitória, false caso contrário.
     */
    bool attack(GameBoard *board, sf::Vector2f position, bool *turn, bool *shotValidation);

    /**
     * Realiza um ataque aleatório em um tabuleiro.
     * @param board tabuleiro que receberá o ataque
     * @param turn turno do jogador (que será alterado caso errar o ataque).
     * @return true caso o ataque feito resultar em uma vitória, false caso contrário.
     */
    bool randomAttack(GameBoard *board, bool *turn, bool *shootValidation);

    /**
     * Desenha o próprio tabuleiro.
     * @param target
     */
    void showPlayerBoard(sf::RenderTarget &target);

    /**
     * Desenha o tabuleiro do inimigo.
     * @param target
     * @param enemy tabuleiro do inimigo.
     */
    void seeEnemy(sf::RenderTarget &target, GameBoard *enemy);

    /**
     * Inicia o tabuleiro do jogador.
     */
    void init();

    /**
     * Reinicia o tabuleiro.
     */
    void reset();

    /**
     * Retorna o tabuleiro gameBoard do jogador.
     * @return tabuleiro do jogador.
     *
     * @see GameBoard
     */
    GameBoard *getGameBoard();

};


#endif //TRABALHO_PLAYER_H
