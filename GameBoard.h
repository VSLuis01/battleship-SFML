//
// Created by maluc on 02/10/2021.
//
/**
 * tabuleiro do jogo
 * guarda os points os barcos e as celulas do tabuleiro
 */
#ifndef TRABALHO_GAMEBOARD_H
#define TRABALHO_GAMEBOARD_H

#include "Boat.h"
#include "Cell.h"
#include "vector"
#include "Clickable.h"
#include "SFML/Window/Window.hpp"
#include <random>
#include <iostream>

/**
 * @brief Classe que representa um tabuleiro com várias células.
 *
 * @see Cell
 * @see Boat
 */
class GameBoard : public sf::RectangleShape, public Clickable {
private:
    std::vector<Cell *> celulas;///<Células do tabuleiro 8x8
    std::vector<Boat *> barcos;///<Barcos em cada célula
    sf::Text boardText;///<Texto que mostra em cima do tabuleiro para identificar o jogador ou anunciar o vencedor.
    sf::Font font;
    float x, y; ///<Posição x e y onde o tabuleiro está
    int tam, ordemMatriz; ///<tamanho e ordem da matriz

    /**
     * Inicializa as fontes
     */
    void initFont();

    /**
     * Inicia o texto que fica em cima do tabuleiro
     * @param name texto que fica em cima do tabuleiro
     */
    void initText(const std::string &name);

    /**
     * Cria o tabulerio, fazendo o push no vetor de celulas.
     */
    void initBoardCells();

public:
    /**
     * @brief Construtor do tabuleiro
     * @param tam :tamanho de cada celula/quadrado do tabuleiro
     * @param x :posicao do tabuleiro em x
     * @param y :posicao do tabuleiro em y
     * @param ordemMatriz :ordem do tabuleiro
     */
    GameBoard(int tam, float x, float y, int ordemMatriz, const std::string &name);
    GameBoard();

    /**
     * Gera um barco horizontal para o tabuleiro em uma posição aleatória.
     * @param tamBarco :tamanho do barco em quadrados/celulas
     * @param engine :engine que é usada para gerar numero aleatorio
     */
    void gera_Barcos_Horizontal(int tamBarco, std::default_random_engine *engine);

    /**
     * Gera um barco vertical para o tabuleiro em uma posição aleatória.
     * @param tamBarco :tamanho do barco em quadrados/celulas
     * @param engine :engine que é usada para gerar numero aleatorio
     */
    void gera_Barcos_Vertical(int tamBarco, std::default_random_engine *engine);

    /**
     * Retorna uma célula aleatória do tabuleiro
     * @return célula aleatória do tabuleiro.
     */
    Cell getRandomCell() const;

    /**
     * Retorna todas as células do tabuleiro.
     * @return vector com a células
     */
    const std::vector<Cell *> &getCells() const;

    /**
     * Retorna todos o barcos do tabuleiro.
     * @return vector com os barcos.
     */
    const std::vector<Boat *> &getBoats() const;

    /**
     * Retorna uma referencia de todos os barco do tabuleiro.
     * @return referência vector com todos os barcos.
     */
    std::vector<Boat *> &boats();


    /**
     * Ação para caso cliquem no tabuleiro
     * @param posX :posicao x do click
     * @param posY :posicao y do click
     * @param jogador :jogador que efetuou o click
     * @return true caso o tiro tenha sido certeiro, false caso contrário OU tenha clicado em uma célula que já foi clicada.
     */
    bool click(int posX, int posY, bool *jogador, bool *shootValidation);

    /**
     * Desenha o tabuleiro do inimigo
     * @param target :janela que é usada pra desenhar o tabuleiro
     * @param enemy :tabuleiro que sera exibido
     */
    void desenhaEnemy(sf::RenderTarget &target, GameBoard *enemy);

    /**
     * Define o "nome" do tabuleiro, que é o texto que fica em cima do tabuleiro.
     * @param text
     */
    void setBoardText(const std::string &text);

    /**
     * Desenha o tabuleiro do jogador caso ele queira ver a situação dos barcos dele.
     * @param target
     */
    void desenhaPlayer(sf::RenderTarget &target);

    /**
     * Inicia as células e posiciona os barcos aleatoriamente.
     */
    void init();

    /**
     * Método para posicionar os barcos aleatoriamente.
     */
    void randomInitBoats();

    /**
     * Método para iniciar as células.
     */
    void initCells();

    bool contains(sf::Vector2f mousePos) override;



    ~GameBoard() override;
};


#endif //TRABALHO_GAMEBOARD_H
