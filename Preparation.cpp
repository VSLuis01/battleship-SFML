
// Created by luis on 11/30/2021.
//

#include "Preparation.h"

///Atributo static
PreparationMusic Preparation::music;

/**
 * Inicia a maioria dos membros da classe
 * @param window janela para desenhar
 * @param player player que vai posicionar os barcos
 */
Preparation::Preparation(sf::RenderWindow *window, Player *player) : window(window), gameBoardPrepare(player) {
    //É meio obvio o que cada init está fazendo '-'
    this->initFonts();
    this->initVariables();
    this->initTextureAndSprite();
    this->initGameBoardPrepare();
    this->initBoatsSpritePos();
    this->initButtons();
    this->initText(player->getName());
    backGroudTexture.loadFromFile("../src/fundoBatalhaNaval.png");
    backGroud.setTexture(&backGroudTexture);
    backGroud.setSize({800,600});

}

void Preparation::initFonts() {
    this->font.loadFromFile("../fontes/veteran typewriter.ttf");
}

void Preparation::initText(const string &name) {

    this->message.setFont(this->font);
    this->playerName.setFont(this->font);
    this->playerName.setString(name);
    this->message.setString("Selecione um modo de posicionamento");
    this->message.setFillColor(sf::Color(40,40,40));
    this->message.setOutlineColor(sf::Color(0,0,0));
    this->message.setOutlineThickness(0.3);
    this->playerName.setFillColor(sf::Color(186,186,186));
    this->playerName.setPosition(this->gameBoardPrepare->getGameBoard()->getGlobalBounds().width -
                                 this->playerName.getGlobalBounds().width / 2,
                                 this->gameBoardPrepare->getGameBoard()->getGlobalBounds().top -
                                 ( 2 * this->playerName.getGlobalBounds().height + 20));
    this->message.setPosition(
            this->gameBoardPrepare->getGameBoard()->getGlobalBounds().width - this->message.getGlobalBounds().width / 2,
            this->gameBoardPrepare->getGameBoard()->getGlobalBounds().top -
            (this->message.getGlobalBounds().height + 10));
}

void Preparation::initVariables() {
    this->running = true;
    this->generateOnce = false;
    this->choosePreparation = PreparationType::Automatic; //true = RandomInit ... false = ManualInit
    this->boatSelected = -1;
    this->dropBoat = false;
    this->readyToGo = false;
    this->showConfirmResults = false;
}

void Preparation::initButtons() {

    this->randomInitButton.setPosition(612, 300);
    this->randomInitButton.setSize(175, 50);
    this->randomInitButton.setText("Automatico");
    this->randomInitButton.setFont("../fontes/veteran typewriter.ttf");
    this->randomInitButton.setTextColor(sf::Color(199, 201, 181));
    this->randomInitButton.setButtonColor(sf::Color(36, 54, 63,153));
    this->randomInitButton.setOutlineThickness(0.3);
    this->randomInitButton.setOutLineColor(sf::Color(199, 201, 181));

    this->randomConfirmButton.setPosition(612, 400);
    this->randomConfirmButton.setSize(175, 50);
    this->randomConfirmButton.setText("Confirm");
    this->randomConfirmButton.setFont("../fontes/veteran typewriter.ttf");
    this->randomConfirmButton.setTextColor(sf::Color(199, 201, 181));
    this->randomConfirmButton.setButtonColor(sf::Color(36, 54, 63,153));
    this->randomConfirmButton.setOutlineThickness(0.3);
    this->randomConfirmButton.setOutLineColor(sf::Color(199, 201, 181));

    this->manualInitButton.setPosition(612, 200);
    this->manualInitButton.setSize(175, 50);
    this->manualInitButton.setText("Manual");
    this->manualInitButton.setFont("../fontes/veteran typewriter.ttf");
    this->manualInitButton.setTextColor(sf::Color(199, 201, 181));
    this->manualInitButton.setButtonColor(sf::Color(36, 54, 63,153));
    this->manualInitButton.setOutlineThickness(0.3);
    this->manualInitButton.setOutLineColor(sf::Color(199, 201, 181));

    this->confirmButton.setPosition(12, 200);
    this->confirmButton.setSize(175, 50);
    this->confirmButton.setText("Confirmar");
    this->confirmButton.setFont("../fontes/veteran typewriter.ttf");
    this->confirmButton.setTextColor(sf::Color(199, 201, 181));
    this->confirmButton.setButtonColor(sf::Color(36, 54, 63,153));
    this->confirmButton.setOutlineThickness(0.3);
    this->confirmButton.setOutLineColor(sf::Color(199, 201, 181));

    this->resetButton.setPosition(12, 300);
    this->resetButton.setSize(175, 50);
    this->resetButton.setText("Reset");
    this->resetButton.setFont("../fontes/veteran typewriter.ttf");
    this->resetButton.setTextColor(sf::Color(199, 201, 181));
    this->resetButton.setButtonColor(sf::Color(36, 54, 63,153));
    this->resetButton.setOutlineThickness(0.3);
    this->resetButton.setOutLineColor(sf::Color(199, 201, 181));

    this->backButton.setPosition(0, 0);
    this->backButton.setSize(40, 40);
    this->backButton.setText("<");
    this->backButton.setButtonColor(sf::Color(105,105,105));

}

void Preparation::initGameBoardPrepare() {
    //this->gameBoardPrepare = new GameBoard(50, 200, 100, 8, "");
    //this->gameBoardPrepare->getGameBoard()->init();
    this->gameBoardPrepare->getGameBoard()->initCells();
}

void Preparation::initTextureAndSprite() {
    for (int i = 0; i < 6; ++i) {
        this->boatsSprite.emplace_back();
    }
    this->boatsSprite.at(0).boatTex.loadFromFile("../src/b1/b1.png");
    this->boatsSprite.at(0).tam = 1;

    this->boatsSprite.at(1).boatTex.loadFromFile("../src/b1/b1.png");
    this->boatsSprite.at(1).tam = 1;

    this->boatsSprite.at(2).boatTex.loadFromFile("../src/b2/b2.png");
    this->boatsSprite.at(2).tam = 2;

    this->boatsSprite.at(3).boatTex.loadFromFile("../src/b2/b2.png");
    this->boatsSprite.at(3).tam = 2;

    this->boatsSprite.at(4).boatTex.loadFromFile("../src/b3/b3.png");
    this->boatsSprite.at(4).tam = 3;

    this->boatsSprite.at(5).boatTex.loadFromFile("../src/b4/b4.png");
    this->boatsSprite.at(5).tam = 4;

    for (auto &i: this->boatsSprite) {
        i.boatSprite.setTexture(i.boatTex);
        i.boatSprite.setScale(0.9, 0.9);
    }
}

void Preparation::initBoatsSpritePos() {
    float y = gameBoardPrepare->getGameBoard()->getGlobalBounds().top;
    for (auto &boat: this->boatsSprite) {
        boat.boatSprite.setOrigin(boat.boatSprite.getLocalBounds().width / 2,
                                  boat.boatSprite.getLocalBounds().height / 2);
        boat.boatSprite.setPosition((float) this->window->getSize().x - 95, y);
        boat.originPos = boat.boatSprite.getPosition();
        boat.rotate = true;
        y += boat.boatSprite.getLocalBounds().height;
    }
}

/**
 * Método que contém o loop principal para o posicionamento dos barcos
 * @return true caso for posicionado corretamente, false caso contrário
 */
bool Preparation::prepare() {
    this->gearIcon.setClicked(false);
    Preparation::music.play();
    while (this->running) {
        this->update();
        this->render();
    }
    Preparation::music.pause();
    return this->readyToGo;
}

//atualiza a posicao do mouse
void Preparation::updateMousePos() {
    this->mousePos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}


void Preparation::pollEvent() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                this->running = false;
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape) { //Se clicar esq sai
                    this->window->close();
                    this->running = false;
                } else if (this->event.key.code ==
                           sf::Keyboard::R) { //Realizar a rotação do barco, quando ele estiver selecionador
                    if (this->boatSelected != -1) { //Esse if verifica se algum barco foi selecionado
                        //Verificando se o barco já está rotacionado, para rotacionar ou deixar normal
                        if (this->boatsSprite[boatSelected].rotate) {
                            //this->boatsSprite[boatSelected].boatSprite.setScale(-1.0, 1.0);
                            this->boatsSprite[boatSelected].boatSprite.setRotation(-90.0);
                            this->boatsSprite[boatSelected].rotate = false;
                        } else {
                            //this->boatsSprite[boatSelected].boatSprite.setScale(-1.0, 1.0);
                            this->boatsSprite[boatSelected].boatSprite.setRotation(0.0);
                            this->boatsSprite[boatSelected].rotate = true;
                        }

                    }
                }
                break;
            case sf::Event::MouseButtonReleased: //Verifica se soltou o botao do mouse para poder clicar nos clicaveis dnv
                                                 //Isso é necessario pq se segurar o botao do mouse em um clicavel, ele fica sendo clicado infinitamente
                this->gearIcon.enableClickable();
                if (this->gearIcon.isClicked()) {
                    GameSoundsFX::enableClickable();
                    GameMusics::enableClickable();
                }
                break;
            default:
                break;
        }
    }
}


void Preparation::updateButtonBack() {
    this->backButton.canClick(this->event); //Quando o evento de Mouse Released acontecer, o botao volta a ser clicavel
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->backButton.contains(this->mousePos)) {
            if (this->backButton.isClickable()) {
                if (this->choosePreparation == PreparationType::Automatic) { //Primeira tela: Volta para o menu inicial
                    this->running = false;
                    this->readyToGo = false;
                    this->backButton.disableClickable();
                } else { //Segunda tela, volta para a primeira tela (onde escolhe posicionar entre random e manual)
                    this->resetAll();
                    this->backButton.disableClickable();
                }
            }
        }

    }
}

/**
 * Atualização dos botoes no inicio da tela "manual" "automatico"
 */
void Preparation::updateButtonsAutoManual() {
    this->randomInitButton.canClick(this->event);
    if (this->randomInitButton.contains(this->mousePos)) {
        this->randomInitButton.setButtonColor(sf::Color(7, 22, 203));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (this->randomInitButton.isClickable()) {
                this->gameBoardPrepare->getGameBoard()->initCells();
                this->gameBoardPrepare->getGameBoard()->randomInitBoats();
                this->generateOnce = true; //Se gerou automaticamente uma vez, já pode confirmar
                this->randomInitButton.disableClickable();
            }
        }
    } else {
        this->randomInitButton.setButtonColor(sf::Color(36, 54, 63,153));
    }

    //O botão de confirmação automatica só será clicavel quando for gerado barco pelo menos uma vez
    if (this->generateOnce) {
        if (this->randomConfirmButton.contains(this->mousePos)) {
            this->randomConfirmButton.setButtonColor(sf::Color(7, 22, 203));
            if (this->event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                this->running = false;
                this->readyToGo = true;
            }
        } else {
            this->randomConfirmButton.setButtonColor(sf::Color(36, 54, 63,153));
        }
    }

    if (this->manualInitButton.contains(this->mousePos)) {
        this->manualInitButton.setButtonColor(sf::Color(7, 22, 203));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->gameBoardPrepare->getGameBoard()->initCells(); //reseta o tabuleiro para posicionar manualmente
            this->choosePreparation = PreparationType::Manual;
        }
    } else {
        this->manualInitButton.setButtonColor(sf::Color(36, 54, 63,153));
    }

}

void Preparation::spriteIntersect(const vector<Cell *> &cell1,
                                  const vector<Cell *> &cell2,
                                  vector<Cell *> &intersectCells) {
    for (auto &e: cell1) {
        for (auto &i: cell2) {
            if (e == i) { //Se uma celular intersecta a outra (tem o mexmo X e mesmo Y)
                intersectCells.push_back(e);
            }
        }
    }
}

//Verificando se a posição dos barcos é valida
bool Preparation::verifyBoatsPositions() {
    bool allBoatsAreCorrect = true; //Assume que os barcos estão posicionados corretamente

    //Busca as celulas que contem mais de um barco, caso tiver alguma
    //Isso é feito apenas para pintar a célula de vermelho
    vector<Cell *> intersectCells;
    for (int i = 0; i < this->boatsSprite.size(); ++i) {
        for (int j = i + 1; j < this->boatsSprite.size(); ++j) {
            spriteIntersect(this->boatsSprite[i].cellsSprite, this->boatsSprite[j].cellsSprite, intersectCells);
        }
    }

    for (auto &e: this->gameBoardPrepare->getGameBoard()->getCells()) {
        //Pintar todas as células que contém um barco de verde
        for (auto &j: this->boatsSprite) {
            if (!j.cellsSprite.empty()) {
                for (const auto &k: j.cellsSprite) {
                    if (e == k) {
                        e->highlight(sf::Color::Green);
                    }
                }
            } else {
                //Caso um barco não foi posicionado no tabuleiro, ele é pintado de vermelho
                allBoatsAreCorrect = false;
                j.boatSprite.setColor(sf::Color::Red);
            }
        }

        //As células que tiveram mais de um barco são pintadas de vermelho
        if (!intersectCells.empty()) {
            for (const auto &i: intersectCells) {
                if (e == i) {
                    e->highlight(sf::Color::Red);
                }
            }
            allBoatsAreCorrect = false;
        }
    }


    return allBoatsAreCorrect;
}

void Preparation::resetSprite(BoatsSpriteCells &boat) {
    boat.boatSprite.setPosition(boat.originPos);
    boat.boatSprite.setScale(0.9, 0.9);
    boat.boatSprite.setRotation(0.0);
    boat.boatSprite.setColor(sf::Color(255, 255, 255, 255));
    boat.cellsSprite.clear();
    boat.rotate = true;
}

void Preparation::resetAll() {
    for (auto &e: this->boatsSprite) {
        e.cellsSprite.clear();
        this->resetSprite(e);
    }
    this->initVariables();
}


void Preparation::updateButtonConfirmReset() {
    /*Quando confirma a posição dos barcos que foram posicionados manualmente*/
    if (this->confirmButton.contains(this->mousePos)) {
        this->confirmButton.setButtonColor(sf::Color(36, 54, 63,204));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->readyToGo = this->verifyBoatsPositions();
            //Esse atributo é utilizada em updateBoard()
            //apenas para não atualizar as celulas do tabuleiro enquanto está sendo feita a verificação da posição dos barcos
            //Pq se ficar sendo feita a atualização do tabuleiro toda hora, as células não serão pintadas de vermelho/verde como eu queria
            this->showConfirmResults = true;
        }
    } else {
        this->confirmButton.setButtonColor(sf::Color(36, 54, 63,153));
    }

    /*Reseta os barcos posicionados manualmente*/
    if (this->resetButton.contains(this->mousePos)) {
        this->resetButton.setButtonColor(sf::Color(36, 54, 63,204));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            for (auto &e: this->boatsSprite) {
                this->resetSprite(e);
            }
            this->showConfirmResults = false;
        }
    } else {
        this->resetButton.setButtonColor(sf::Color(36, 54, 63,153));
    }
}

void Preparation::updateBoard() {
    if (!this->showConfirmResults) {
        for (auto &e: this->gameBoardPrepare->getGameBoard()->getCells()) {
            //Pinta de verde as células que intersectam com o barco
            if (e->intersects(
                    this->boatsSprite[boatSelected].boatSprite.getGlobalBounds(),
                    this->boatsSprite[boatSelected].tam,
                    this->boatsSprite[boatSelected].rotate) && this->boatSelected != -1) {
                e->highlight(sf::Color::Green);
            } else {
                e->highlight(sf::Color(255, 255, 255, 255));
            }
        }
    }

    //Se todos os barcos foram posicionados corretamente, aqui é feito a linkagem do barco com as células
    if (this->readyToGo) {
        std::string src;
        std::string src_finalH[] = {"1H.png", "2H.png", "3H.png", "4H.png"};
        std::string src_finalV[] = {"1V.png", "2V.png", "3V.png", "4V.png"};
        for (auto &e: this->boatsSprite) {
            switch (e.tam) {
                case 1:
                    this->gameBoardPrepare->getGameBoard()->boats().push_back(new Boat1(e.rotate));
                    src = e.rotate ? "../src/b1/b11H.png" : "../src/b1/b11V.png";
                    break;
                case 2:
                    this->gameBoardPrepare->getGameBoard()->boats().push_back(new Boat2(e.rotate));
                    src = e.rotate ? "../src/b2/b21H.png" : "../src/b2/b21V.png";
                    break;
                case 3:
                    this->gameBoardPrepare->getGameBoard()->boats().push_back(new Boat3(e.rotate));
                    src = e.rotate ? "../src/b3/b31H.png" : "../src/b3/b31V.png";
                    break;
                case 4:
                    this->gameBoardPrepare->getGameBoard()->boats().push_back(new Boat4(e.rotate));
                    src = e.rotate ? "../src/b4/b41H.png" : "../src/b4/b41V.png";
                    break;
            }
            int j = 0;
            for (auto &i: e.cellsSprite) {
                this->gameBoardPrepare->getGameBoard()->boats().back()->addCell(i);
                i->setBarco(this->gameBoardPrepare->getGameBoard()->boats().back());
                src.replace(12, 6, e.rotate ? src_finalH[j] : src_finalV[j]);
                i->setPlayerTexture(src);
                j++;
            }
        }
        //Pinta todas as celulas com a cor padrão novamente, para não ficar com os verdes de quando são posicionadas corretamente
        for (auto &e: this->gameBoardPrepare->getGameBoard()->getCells()) {
            e->highlight(sf::Color(255, 255, 255, 255));
        }
        this->boatsSprite.clear();
        this->running = false;
    }

}

bool compareCells(Cell *a, Cell *b) { return (*a < *b); }

/*Aqui é feito o esquema de selecionar um barco com o mouse e soltar no tabuleiro*/
void Preparation::updateBoatsSprite() {
    int i = 0;

    //O barco é selecionado enquanto o botão do mouse estiver pressionado
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->event.type != sf::Event::MouseButtonReleased) {
        //boatSelected -1 quer dizer que nenhum barco está selecionado
        if (this->boatSelected == -1) {
            for (auto &e: this->boatsSprite) {
                if (e.boatSprite.getGlobalBounds().contains(this->mousePos)) {
                    this->boatSelected = i; //Salva o indice do vetor do barco selecionado
                    this->boatsSprite[boatSelected].boatSprite.setColor(sf::Color(255, 255, 255, 255));
                    this->showConfirmResults = false;
                    this->boatsSprite[boatSelected].cellsSprite.clear(); //Limpa as celulas do barco, já que vai reposicionar ele
                    break;
                }
                i++;
            }
        } else {
            //Trata da rotação do barco
            if (this->boatsSprite[boatSelected].rotate) {
                this->boatsSprite[boatSelected].boatSprite.setScale(1.0, 1.0);
            } else {
                this->boatsSprite[boatSelected].boatSprite.setScale(-1.0, 1.0);
            }
            //Move o barco junto com o mouse
            this->boatsSprite[boatSelected].boatSprite.setPosition(this->mousePos);
        }
    } else { //Quando acontece o Mouse Release e um barco estiver sido selecionado, então é dropBoat é true.
        if (this->boatSelected != -1) this->dropBoat = true;
    }

    //Caso dropBoat for true, será feito o mapeamento das celulas que ele foi "dropado" e adicionado no seu vetor de celulas
    if (this->dropBoat) {

        //MAPEANDO A POSICAO DAS CELULAS DO LUGAR ESCOLHIDO NO TABULERIO
        for (auto &e: this->gameBoardPrepare->getGameBoard()->getCells()) {
            if (e->intersects(this->boatsSprite[boatSelected].boatSprite.getGlobalBounds(),
                              this->boatsSprite[boatSelected].tam,
                              this->boatsSprite[boatSelected].rotate)) {
                this->boatsSprite[boatSelected].cellsSprite.push_back(e);
            }
        }

        //Caso a quantidade de células mapeadas não corresponder o tamanho do barco, então ele é resetado
        if (this->boatsSprite[boatSelected].cellsSprite.size() != this->boatsSprite[boatSelected].tam) {
            this->resetSprite(this->boatsSprite[boatSelected]);
            this->boatsSprite[boatSelected].cellsSprite.clear();
        } else {
            //Caso a quantidade de células for igual, entã0 elas são ordenadas para ser feito a linkagem dos boats corretamente
            std::sort(this->boatsSprite[boatSelected].cellsSprite.begin(),
                      this->boatsSprite[boatSelected].cellsSprite.end(),
                      compareCells);
            //Aqui é feito o alinhamento do barco nas células, para dar aquele efeito de ímã, quando solta o barco
            //Não ta perfeito, mas deu pro gasto, deve ter uma lógica mais precisa
            if (this->boatsSprite[boatSelected].rotate) {
                float x = (this->boatsSprite[boatSelected].cellsSprite.at(0)->getX() +
                           this->boatsSprite[boatSelected].cellsSprite.back()->getX()) / 2 + 25;

                float y = this->boatsSprite[boatSelected].cellsSprite.at(0)->getY() +
                          this->boatsSprite[boatSelected].boatSprite.getLocalBounds().height / 4;

                this->boatsSprite[boatSelected].boatSprite.setPosition(x, y);
            } else {
                float x = this->boatsSprite[boatSelected].cellsSprite.at(0)->getX() +
                          this->boatsSprite[boatSelected].boatSprite.getGlobalBounds().width / 4;

                float y = (this->boatsSprite[boatSelected].cellsSprite.at(0)->getY() +
                           this->boatsSprite[boatSelected].cellsSprite.back()->getY()) / 2 + 25;
                this->boatsSprite[boatSelected].boatSprite.setPosition(x, y);
            }

        }
        this->dropBoat = false;
        this->boatSelected = -1;
    }
}

void Preparation::updateTextPosition() {
    this->message.setPosition(
            this->gameBoardPrepare->getGameBoard()->getGlobalBounds().width - this->message.getGlobalBounds().width / 2,
            this->gameBoardPrepare->getGameBoard()->getGlobalBounds().top -
            (this->message.getGlobalBounds().height + 10));
}

void Preparation::updateText() {
    if (this->choosePreparation == PreparationType::Manual) {
        if (this->boatSelected == -1) {
            this->message.setString("Clique e segure em um barco para mover");
            this->updateTextPosition();
        } else {
            this->message.setString("Clique R para girar o barco");
            this->updateTextPosition();
        }
    } else {
        this->message.setString("Selecione um modo de posicionamento");
    }
}

void Preparation::update() {
    this->pollEvent();
    this->updateMousePos();
    if (this->choosePreparation == PreparationType::Automatic) {
        this->updateButtonsAutoManual();
    } else {
        this->updateBoatsSprite();
        this->updateButtonConfirmReset();
    }
    this->updateText();
    this->updateBoard();
    this->updateButtonBack();
    this->gearIcon.update(this->mousePos);
    if (Preparation::gearIcon.isClicked()) {
        GameMusics::update(this->mousePos, Preparation::music);
        GameSoundsFX::update(this->mousePos, this->shootSfx);
        GameSoundsFX::update(this->mousePos, this->hitSfx);
    } else {
        GameMusics::update(Preparation::music);
        GameSoundsFX::update(this->shootSfx);
        GameSoundsFX::update(this->hitSfx);
    }
}

void Preparation::renderText(sf::RenderTarget &target) {
    if (this->choosePreparation == PreparationType::Automatic) {
        target.draw(this->playerName);
    }
    target.draw(this->message);
}

void Preparation::renderPlayer() {
    this->gameBoardPrepare->getGameBoard()->desenhaPlayer(*this->window);
}

void Preparation::renderConfirmButton() {
    this->confirmButton.drawButton(*this->window);
}

void Preparation::renderResetButton() {
    this->resetButton.drawButton(*this->window);
}

void Preparation::renderBackButton() {
    this->backButton.drawButton(*this->window);
}

void Preparation::renderButtonsAutoManual() {
    this->manualInitButton.drawButton(*this->window);
    this->randomInitButton.drawButton(*this->window);
    if (this->generateOnce) {
        this->randomConfirmButton.drawButton(*this->window);
    }
}

void Preparation::renderBoatsSprites(sf::RenderTarget &target) {
    for (auto &e: this->boatsSprite) {
        target.draw(e.boatSprite);
    }
}

void Preparation::render() {
    this->window->clear(sf::Color(9, 2, 111, 255));
    window->draw(backGroud);
    this->renderPlayer();
    this->renderText(*this->window);
    if (this->choosePreparation == PreparationType::Automatic) {
        this->renderButtonsAutoManual();
    } else {
        this->renderBoatsSprites(*this->window);
        this->renderConfirmButton();
        this->renderResetButton();
    }
    this->renderBackButton();
    this->gearIcon.render(*this->window);
    this->window->display();
}

Preparation::~Preparation() {
}



