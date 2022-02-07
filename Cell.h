//
// Created by maluc on 30/09/2021.
//
/**
 * classe responsavel por cada Cell/quadrado do GameBoard
 * cada celula é clickavel e pode guardar uma parte de um boat ou nao
 */
#ifndef TRABALHO_CELL_H
#define TRABALHO_CELL_H

#include "Cell.fwd.h"
#include "Boat.fwd.h"
#include "SFML/Graphics.hpp"
#include "Clickable.h"

/**
 * @brief Essa classe representa uma célula do tabuleiro.
 *
 * @see GameBoard
 */
class Cell : public Clickable {
private:
    //textura é um atributo pois ela tem que existir durante toda a execução da celula
    sf::Texture enemyTexture, playerTexture;
    float x, y;
    sf::RectangleShape figure;
    Boat *boat;
public:
    /**
     * Construtor celular/quadrado do tabuleiro
     * @param x :posicao em x do quadrado/celula
     * @param y :posicao em y do quadrado/celula
     * @param tam: tamanho do quadrado/celula
     */
    Cell(float x, float y, float tam);

    ~Cell() override;

    /**
     *
     * @return : retorna o ponteiro que aponta para o barco referente a este quadrado/celuula
     */
    Boat *getBarco() const;

    /**
     * define qual barco que a celula ira apontar
     * @param barco
     */
    void setBarco(Boat *barco);

    /**
     * memtodo responsavel pelo click no quadrado/celula
     * @param player :jogador que fez a acao
     * @return :retorna se acertou ou nao
     */
    bool click(bool *player, bool *shootValidation);

    /**
     * verifica se o mouse esta sobre a celula/quadrado
     * @param pos:posicao do mouse
     * @return :verdadeiro se esta sobre o objeto, falso caso nao esteja
     */
    bool contains(sf::Vector2f pos) override;

    /**
     * Verifica se algum objeto retangular (FloatRect) intersecta com uma célula.
     * Esse método não é generalizado. É utilizado apenas para verificar se as Sprites dos barcos intersectam com a célula.
     * @param rect Bounds da Sprite
     * @param tam Tamanho do barco
     * @param rotate Rotação do barco -> true: horizontal ; false: vertical
     * @return true caso há uma interseção, false caso contrário.
     */
    bool intersects(sf::FloatRect rect, int tam, bool rotate);

    void setFigureColor(sf::Color color);

    /**
     * Realça a célula com uma cor
     * @param color cor para realçar a célula
     */
    void highlight(sf::Color color);

    /**
     * diz a posicao em x do objeto
     * @return :retorna o float referente ao x
     */
    float getX() const;

    /**
     * define a posicao x do objeto
     * @param x
     */
    void setX(float x);

    /**
     * diz a posicao em y do objeto
     * @return :retorna o float referente ao y
     */
    float getY() const;

    /**
     * define a posicao y do objeto
     * @param y
     */
    void setY(float y);

    /**
     * atualiza a textura vista pelo inimigo
     * @param caminho :caminho da textura em disco
     */
    void setEnemyTexture(std::string caminho);

    /**
     * atualiza textura vista pelo jogador referente ao tabuleiro
     * @param caminho :caminho da textura em disco
     */
    void setPlayerTexture(std::string caminho);

    /**
     * carrega a textura do inimigo na figura que representa o quadrado/celula
     */
    void loadEnemyTexture();

    /**
     * carrega a textura do player na figura que representa o quadrado/celula
     */
    void loadPlayerTexture();

    /**
     * inicializa o objeto
     */
    void init();

    /**
     * retorna a figura
     * @return
     */
    const sf::RectangleShape &getFigura() const;

    bool operator<(const Cell &o) const;

    bool operator==(const Cell &o) const;
};


#endif //TRABALHO_CELL_H
