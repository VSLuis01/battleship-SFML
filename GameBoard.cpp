//
// Created by maluc on 02/10/2021.
//


#include "GameBoard.h"


GameBoard::GameBoard(int tam, float x, float y, int ordemMatriz, const std::string &name) :
        x(x), y(y), tam(tam), ordemMatriz(ordemMatriz),
        sf::RectangleShape(sf::Vector2f((float) (ordemMatriz * tam), (float) (ordemMatriz * tam))) {

    this->initFont();
    this->initBoardCells();
    this->initText(name);

}

GameBoard::GameBoard() : tam(50), x(200), y(100), ordemMatriz(8),
                         sf::RectangleShape(sf::Vector2f(ordemMatriz * tam, ordemMatriz * tam)) {
    this->initFont();
    this->initBoardCells();
    this->initText("");
}

void GameBoard::initFont() {
    this->font.loadFromFile("../fontes/veteran typewriter.ttf");
}

void GameBoard::initText(const std::string &name) {
    this->boardText.setFont(this->font);
    this->boardText.setFillColor(sf::Color(186,186,186));
    this->boardText.setString(name);
    this->boardText.setPosition(this->getGlobalBounds().width - this->boardText.getGlobalBounds().width / 2,
                                this->getGlobalBounds().top - (this->boardText.getGlobalBounds().height + 10));
}

void GameBoard::initBoardCells() {
    //cria GameBoard
    this->setPosition(x, y);
    for (int i = 0; i < ordemMatriz; i++) {
        for (int j = 0; j < ordemMatriz; j++) {
            this->celulas.push_back(new Cell((x + (float) (tam * j)), (y + (float) (tam * i)), (float) tam));
        }

    }
}

bool GameBoard::click(int posX, int posY, bool *jogador, bool *shootValidation) {

    int indice;
    posX = (posX - static_cast<int>(this->x)) / tam;
    posY = (posY - static_cast<int>(this->y)) / tam;
    indice = (posX) + (8 * posY);

    return celulas[indice]->click(jogador, shootValidation);
}

//responsavel por desenhar cada celula
void GameBoard::desenhaEnemy(sf::RenderTarget &target, GameBoard *enemy) {
    std::vector<Cell *> cells = enemy->celulas;
    for (auto &desenho: cells) {
        target.draw(desenho->getFigura());
    }
    target.draw(this->boardText);
}

void GameBoard::desenhaPlayer(sf::RenderTarget &target) {
    //janela->clear();
    for (auto &desenho: celulas) {
        desenho->loadPlayerTexture();
        target.draw(desenho->getFigura());
        desenho->loadEnemyTexture();
    }
}

void GameBoard::gera_Barcos_Horizontal(int tamBarco, std::default_random_engine *engine) {
    int x, y;
    bool barco_gerado;
    barco_gerado = false;
    while (!barco_gerado) {
        barco_gerado = true;
        //gera posições do boat
        x = rand() % (ordemMatriz - tamBarco);
        y = rand() % ordemMatriz;
        for (int i = x; i < x + tamBarco; ++i) {
            if (celulas[(i) + (ordemMatriz * y)]->getBarco() != nullptr) {
                barco_gerado = false;
            }
        }
    }
    std::string src;
    std::string srcfinal[] = {"1H.png", "2H.png", "3H.png", "4H.png"};
    switch (tamBarco) {
        case 1:
            barcos.push_back(new Boat1(true));
            src = "../src/b1/b11H.png";
            break;
        case 2:
            src = "../src/b2/b21H.png";
            barcos.push_back(new Boat2(true));
            break;
        case 3:
            barcos.push_back(new Boat3(true));
            src = "../src/b3/b31H.png";
            break;
        case 4:
            barcos.push_back(new Boat4(true));
            src = "../src/b4/b41H.png";
            break;
    }

    for (int i = x; i < (x + tamBarco); ++i) {
        barcos.back()->addCell(celulas[(i) + (ordemMatriz * y)]);
        celulas[(i) + (ordemMatriz * y)]->setBarco(barcos.back());
        src.replace(12, 6, srcfinal[i - x]);
        celulas[(i) + (ordemMatriz * y)]->setPlayerTexture(src);

    }

}

void GameBoard::gera_Barcos_Vertical(int tamBarco, std::default_random_engine *engine) {

    int x, y;
    bool barco_gerado;
    barco_gerado = false;
    while (!barco_gerado) {
        barco_gerado = true;
        //gera posições do boat
        std::uniform_int_distribution<int> distributionX(0, ordemMatriz);
        std::uniform_int_distribution<int> distributionY(0, ordemMatriz - tamBarco);
        x = distributionX(*engine);
        y = distributionY(*engine);

        for (int i = y; i < y + tamBarco; ++i) {
            if (celulas[(x) + (ordemMatriz * i)]->getBarco() != nullptr) {
                barco_gerado = false;
            }
        }

    }
    std::string src;
    std::string srcfinal[] = {"1V.png", "2V.png", "3V.png", "4V.png"};
    switch (tamBarco) {
        case 1:
            barcos.push_back(new Boat1(false));
            src = "../src/b1/b11V.png";
            break;
        case 2:
            barcos.push_back(new Boat2(false));
            src = "../src/b2/b21V.png";

            break;
        case 3:
            barcos.push_back(new Boat3(false));
            src = "../src/b3/b31V.png";
            break;
        case 4:
            barcos.push_back(new Boat4(false));
            src = "../src/b4/b41V.png";
            break;

    }
    for (int i = y; i < (y + tamBarco); ++i) {
        barcos.back()->addCell(celulas[(x) + (ordemMatriz * i)]);
        celulas[(x) + (ordemMatriz * i)]->setBarco(barcos.back());
        src.replace(12, 6, srcfinal[i - y]);
        celulas[(x) + (ordemMatriz * i)]->setPlayerTexture(src);

    }


}

Cell GameBoard::getRandomCell() const {
    int randIndex = static_cast<int>(rand() % this->celulas.size());
    return *this->celulas.at(randIndex);
}

GameBoard::~GameBoard() {
    if (!barcos.empty()) {
        for (auto &barco: barcos) {
            delete barco;
        }
    }
    if (!celulas.empty()) {
        for (auto &celula: celulas) {
            delete celula;
        }
    }
}

void GameBoard::randomInitBoats() {
    std::default_random_engine generator;
    rand() % 2 == 1 ? gera_Barcos_Horizontal(1, &generator) : gera_Barcos_Vertical(1, &generator);
    rand() % 2 == 1 ? gera_Barcos_Horizontal(1, &generator) : gera_Barcos_Vertical(1, &generator);
    rand() % 2 == 1 ? gera_Barcos_Horizontal(2, &generator) : gera_Barcos_Vertical(2, &generator);
    rand() % 2 == 1 ? gera_Barcos_Horizontal(2, &generator) : gera_Barcos_Vertical(2, &generator);
    rand() % 2 == 1 ? gera_Barcos_Horizontal(3, &generator) : gera_Barcos_Vertical(3, &generator);
    rand() % 2 == 1 ? gera_Barcos_Horizontal(4, &generator) : gera_Barcos_Vertical(4, &generator);
}

void GameBoard::initCells() {
    this->barcos.clear();
    for (auto &cel: this->celulas) {
        cel->init();
    }
}

void GameBoard::init() {
    //zera GameBoard
    this->initCells();
    //coloca os barcos
    this->randomInitBoats();

}

const std::vector<Cell *> &GameBoard::getCells() const {
    return celulas;
}

const std::vector<Boat *> &GameBoard::getBoats() const {
    return barcos;
}

void GameBoard::setBoardText(const std::string &text) {
    this->boardText.setString(text);
    this->boardText.setPosition(this->getGlobalBounds().width - this->boardText.getGlobalBounds().width / 2,
                                this->getGlobalBounds().top - (this->boardText.getGlobalBounds().height + 10));
}

bool GameBoard::contains(sf::Vector2f mousePos) {
    return this->getGlobalBounds().contains(mousePos);
}

std::vector<Boat *> &GameBoard::boats() {
    return this->barcos;
}
