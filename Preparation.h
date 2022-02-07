//
// Created by luis on 11/30/2021.
//

#ifndef TRABALHO_PREPARATION_H
#define TRABALHO_PREPARATION_H

#include "SFML/Graphics.hpp"
#include "ButtonModel.h"
#include "GameBoard.h"
#include "Player.h"
#include <vector>
#include "ShootSFX.h"
#include "GameSoundsIcon.h"
#include "PreparationMusic.h"
#include "HitSFX.h"

/**
 * @brief Struct para a representação de um barco
 */
typedef struct {
    int tam; ///<tamanho do barco (em células)
    sf::Texture boatTex; ///<Textura do barco
    sf::Sprite boatSprite; ///<Sprite do barco
    std::vector<Cell *> cellsSprite; ///<Células que o barco ocupa no tabuleiro
    sf::Vector2f originPos; ///<Posição de origem (canto direito)
    bool rotate; ///<Rotação do barco
} BoatsSpriteCells;

enum PreparationType {
    Manual = 0, Automatic
};

using namespace std;

/**
 * @brief Classe para preparar os barcos no tabuleiro.
 *
 * Essa classe prepara os barcos de um determinado jogador.
 * Para isso é preciso chamar o construtor passando o Player que posicionará os barcos e depois chamar o método prepare().
 *
 * @see Player
 * @see prepare()
 */
class Preparation {
private:
    sf::RenderWindow *window;
    sf::Texture backGroudTexture;
    sf::RectangleShape backGroud;
    /*Textos*/
    sf::Text message;
    sf::Text playerName;
    sf::Font font;

    /*Musics*/
    ShootSFX shootSfx; ///<Efeito sonoro de tiro. @see ShootSFX.
    GameSoundsIcon gearIcon; ///<Ícone da engrenagem. @see GameSoundsIcon.
    HitSFX hitSfx; ///<Efeito sonoro de hit. @see HitSFX.


    /*Botões*/

    ButtonModel backButton; ///<Botão para voltar telas

    ButtonModel randomInitButton; ///<Botão para posicionar automaticamente os barcos

    ButtonModel randomConfirmButton; ///<Botão para confirmar quando os barcos forem iniciados automaticamente.

    ButtonModel manualInitButton; ///<Botão para posicionar manualmente os barcos.

    ButtonModel confirmButton; ///<Botão de confirmação dos barcos posicionados manualmente.

    ButtonModel resetButton; ///<Botão para resetar os barcos posicionados manualmente

    /*Atributos primitivos*/

    bool generateOnce; ///<Verifica se já foi gerado barco automaticamente uma vez, para poder aparecer o botão de confirmação.

    bool readyToGo; ///<Verificar se todos os barcos foram posicionados corretamente

    bool choosePreparation; ///<Escolher o tipo de preparação: true automatico; false manual

    int boatSelected; ///<Índice do barco selecionado no vector<BoatsSpriteCells> boatsSprite

    bool dropBoat; ///<Verificar se o barco selecionado foi solto em algum lugar

    bool showConfirmResults; ///<Atributo para verificar se vai apresentar a confirmação do posicionamento dos barcos ou o tabuleiro

    bool running; ///<Verificar se a classe está ativa

    /*Barcos*/

    vector<BoatsSpriteCells> boatsSprite; ///<Vetor de BoatsSpriteCells que possui cada barco.
                                            ///< A struct BoatsSpriteCells possui a Sprite do barco e as células que o barco está no tabuleiro.

    /**/

    sf::Vector2f mousePos; ///<Posição do mouse.
    sf::Event event;

    /*Tabuleiro*/

    Player *gameBoardPrepare; ///<Tabuleiro do jogador que deseja posicionar os barcos.

    /*Inicializações*/
    /**
     * Inicia as fontes
     */
    void initFonts();

    /**
     * Inicia o texto em cima do tabuleiro
     * @param name nome do jogador
     */
    void initText(const string &name);

    /**
     * Inicia atributos da classe
     */
    void initVariables();

    /**
     * Inicia todos os botões
     */
    void initButtons();

    /**
     * Inicia as textures e sprites dos barcos
     */
    void initTextureAndSprite();

    /**
     * Inicia as células do tabuleiro do jogador
     */
    void initGameBoardPrepare();

    /**
     * Inicia as posições dos barcos no canto direito da tela
     */
    void initBoatsSpritePos();

    /**
     * Reinicia um barco colocando ele de volta para o canto da tela.
     * @param boat barco a ser reiniciado
     */
    void resetSprite(BoatsSpriteCells &boat);

    /**
     * Reinicia a classe inteira, tanto os barcos quanto as variáveis.
     */
    void resetAll();


    /**
     * Verifica se duas sprites (dois barcos) se intersectam. Ou seja, um barco está em cima do outro no tabuleiro.
     * Caso tiver células com mais de uma sprite nela, essas células são guardas em intersectCells
     * @param cell1 celula da sprite
     * @param cell2 celula da sprite
     * @param intersectCells vetor com as células que possuem interseção
     */
    void spriteIntersect(const vector<Cell *> &cell1, const vector<Cell *> &cell2, vector<Cell *> &intersectCells);

    /**
     * Verifica se os barcos foram posicionados corretamente
     * @return
     */
    bool verifyBoatsPositions();

    void updateTextPosition();
    void updateText();

    ///Atualização dos botões/tabuleiros/mouse/eventos
    void updateBoard();

    void updateMousePos();

    void updateButtonBack();

    void updateButtonsAutoManual(); //BOTÕES AUTOMATICO E MANUAL
    void updateButtonConfirmReset(); // BOTÕES CONFIRM AND RESET Quando for escolhido o modo manual
    void updateBoatsSprite();

    void pollEvent();

    void update();

    ///Renderização dos botões/tabuleiro/texto/barcos
    void renderText(sf::RenderTarget &target);

    void renderPlayer();

    void renderBackButton();

    void renderButtonsAutoManual();

    void renderConfirmButton();

    void renderResetButton();

    void renderBoatsSprites(sf::RenderTarget &target);

    void render();

public:
    static PreparationMusic music; ///<Música de preparação. @see PreparationMusic.

    /**
     * @brief Construtor da classe para posicionar barcos manualmente ou automaticamente.
     *
     * @param window janela para desenhar
     * @param player jogador que posicionará os barcos.
     */
    explicit Preparation(sf::RenderWindow *window, Player *player);

    virtual ~Preparation();

    /**
     * Prepara o tabuleiro passado no construtor
     * @return true caso os barcos forem posicionados corretamente, falso caso contrário
     */
    bool prepare();
};


#endif //TRABALHO_PREPARATION_H
