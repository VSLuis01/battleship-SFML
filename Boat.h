//
// Created by maluc on 02/10/2021.
//

#ifndef TRABALHO_BOAT_H
#define TRABALHO_BOAT_H


#include "Boat.fwd.h"
#include "Cell.fwd.h"
#include "vector"

/**
 * @brief Representa um barco genérico...
 */
class Boat {

    std::vector<Cell *> partesBarco;
    int tam;//tamanho do boat
    int hits;
    bool rotation;
public:
    /**
     * @return true se o barco é horizontal e false caso contrario.
     */
    bool isRotation() const;

    /**
     * Define a rotação do barco.
     * @param rotation true se o barco é horizontal e false caso contrario.
     *
     */
    void setRotation(bool rotation);

    /**
     *
     * @param tam define o tamanho em quadrados do barco.
     * @param rotation define a rotação que o barco terá.
     */
    Boat(int tam, bool rotation);

    /**
     * Funçao que é chamada sempre que o barco é acertado
     * manipula a variável de acertos no barco para saber quando o barco foi destruído
     * @return
     */
    virtual bool gotShoot();

    /**
     * função abstrata que sera implementada,ela exibe o barco ao inimigo apos ser destruido
     */
    virtual void drawEnemy() = 0;

    /**
     * @param x :posicao x da celula do barco
     * @param y :posicao y da celula do barco
     *
     * a função atualiza as imagens do barco referente ao jogador para ele saber
     * a situação dos barcos dele, é implementada pelos barcos derivados
     */
    virtual void updatePlayer(float x, float y) = 0;

    /**
     * @param x :posicao x da celula do barco
     * @param y :posicao y da celula do barco
     * @return: retorna qual o indice de uma parte do barco baseado na posicao x e y
     */
    virtual int getBoatIndex(float x, float y);

    /**
     * dada adiciona uma celula do tabuleiro como parte do barco
     */
    void addCell(Cell *);

    /**
     * @return: retorna as partes do barco
     */
    virtual std::vector<Cell *> getBoatParts();

    /**
     *
     * @return :retorna o tanho em quadrados/celulas do barco
     */
    int getTam() const;

    virtual ~Boat();


};

/**
 * @brief Derivada de Boat, representando um barco de 4 celulas/quadrados
 */
class Boat4 : public Boat {
public:
    /**
     * construtor do barco de tamanho 4
     * @param rotacao :diz se ele é vertical(false) ou horizontal(true)
     */
    Boat4(bool rotacao);

    virtual ~Boat4();

    /**
     * função registra acerto e verifica se barco foi destruido, caso seja destruido ele efetua a troca de desenho
     * @return se foi destruido ou nao
     */
    virtual bool gotShoot();

    /**
     *  funcao que se baseia na posicao de uma celula para atualizar o desenho de uma parte do barco
     *  a parte atualizada é referente ao jogador que foi acertado para quando ele for ver o proprio barco
     * @param x
     * @param y
     */
    virtual void updatePlayer(float x, float y);

    /**
     * desenha o tabuleiro para o inimigo
     */
    virtual void drawEnemy();


};

/**
 * @brief Derivada de Boat, representando um barco de 3 celulas/quadrados
 */
class Boat3 : public Boat {
public:
    /**
     * construtor do barco de tamanho 3
     * @param rotacao :diz se ele é vertical(false) ou horizontal(true)
     */
    Boat3(bool rotacao);

    virtual ~Boat3();

    /**
    * função registra acerto e verifica se barco foi destruido, caso seja destruido ele efetua a troca de desenho
    * @return se foi destruido ou nao
    */
    virtual bool gotShoot();

    /**
     *  funcao que se baseia na posicao de uma celula para atualizar o desenho de uma parte do barco
     *  a parte atualizada é referente ao jogador que foi acertado para quando ele for ver o proprio barco
     * @param x
     * @param y
     */
    virtual void updatePlayer(float x, float y);

    /**
     * desenha o tabuleiro para o inimigo
     */
    virtual void drawEnemy();
};

/**
 * @brief Derivada de Boat, representando um barco de 2 celulas/quadrados
 */
class Boat2 : public Boat {
public:
    /**
     * construtor do barco de tamanho 2
     * @param rotacao :diz se ele é vertical(false) ou horizontal(true)
     */
    Boat2(bool rotacao);

    virtual ~Boat2();


    /**
     * função registra acerto e verifica se barco foi destruido, caso seja destruido ele efetua a troca de desenho
     * @return se foi destruido ou nao
     */
    virtual bool gotShoot();


    /**
    *  funcao que se baseia na posicao de uma celula para atualizar o desenho de uma parte do barco
    *  a parte atualizada é referente ao jogador que foi acertado para quando ele for ver o proprio barco
    * @param x
    * @param y
    */
    virtual void updatePlayer(float x, float y);


    /**
     * desenha o tabuleiro para o inimigo
     */
    virtual void drawEnemy();


};

/**
 * @brief Derivada de Boat, representando um barco de 1 celula/quadrado
 */
class Boat1 : public Boat {
public:
    /**
     * construtor do barco de tamanho 2
     * @param rotacao :diz se ele é vertical(false) ou horizontal(true)
     */
    Boat1(bool rotacao);

    virtual ~Boat1();


    /**
     * função registra acerto e verifica se barco foi destruido, caso seja destruido ele efetua a troca de desenho
     * @return se foi destruido ou nao
     */
    virtual bool gotShoot();


    /**
     *  funcao que se baseia na posicao de uma celula para atualizar o desenho de uma parte do barco
     *  a parte atualizada é referente ao jogador que foi acertado para quando ele for ver o proprio barco
     * @param x
     * @param y
     */
    virtual void updatePlayer(float x, float y);

    /**
     * desenha o tabuleiro para o inimigo
     */
    virtual void drawEnemy();
};

#endif //TRABALHO_BOAT_H
