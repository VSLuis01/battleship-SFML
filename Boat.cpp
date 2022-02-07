//
// Created by maluc on 02/10/2021.
//

#include "Boat.h"
#include "Cell.h"

Boat::Boat(int tam, bool rotation) : tam(tam), hits(0), rotation(rotation) {}

bool Boat::gotShoot() {
    if (hits < tam)
        this->hits++;
    if (hits >= tam)
        return true;
    else
        return false;
}

int Boat::getTam() const {
    return tam;
}

void Boat::addCell(Cell *cell) {
    this->partesBarco.push_back(cell);
}

std::vector<Cell *> Boat::getBoatParts() {
    return partesBarco;
}

bool Boat::isRotation() const {
    return rotation;
}

void Boat::setRotation(bool rotation) {
    Boat::rotation = rotation;
}

int Boat::getBoatIndex(float x, float y) {

    for (int index = 0; index < tam; ++index) {
        if (partesBarco[index]->getX() == x && partesBarco[index]->getY() == y) {
            return index;
        }
    }
    return 0;
}

Boat::~Boat() {

}
//derivadas do boat



Boat4::Boat4(bool rotacao) : Boat(4, rotacao) {}


void Boat4::drawEnemy() {
    std::vector<Cell *> barco = getBoatParts();
    if (this->isRotation()) {
        barco[0]->setEnemyTexture("../src/b4/b41H.png");
        barco[1]->setEnemyTexture("../src/b4/b42H.png");
        barco[2]->setEnemyTexture("../src/b4/b43H.png");
        barco[3]->setEnemyTexture("../src/b4/b44H.png");

    } else {
        barco[0]->setEnemyTexture("../src/b4/b41V.png");
        barco[1]->setEnemyTexture("../src/b4/b42V.png");
        barco[2]->setEnemyTexture("../src/b4/b43V.png");
        barco[3]->setEnemyTexture("../src/b4/b44V.png");
    }
}

void Boat4::updatePlayer(float x, float y) {
    std::vector<Cell *> barco = getBoatParts();
    std::string src;
    std::string srcfinalV[] = {"1V_X.png", "2V_X.png", "3V_X.png", "4V_X.png"};
    std::string srcfinalH[] = {"1H_X.png", "2H_X.png", "3H_X.png", "4H_X.png"};
    src = "../src/b4/b41H.png";
    for (int index = 0; index < getTam(); ++index) {
        if (barco[index]->getX() == x & barco[index]->getY() == y) {
            if (isRotation()) {
                src.replace(12, 6, srcfinalH[index]);
            } else {
                src.replace(12, 6, srcfinalV[index]);
            }
            barco[index]->setPlayerTexture(src);
        }
    }

}

bool Boat4::gotShoot() {
    if (Boat::gotShoot()) {
        drawEnemy();
        return true;
    } else {
        return false;
    }

}

Boat4::~Boat4() {

}


Boat3::Boat3(bool rotacao) : Boat(3, rotacao) {

}

void Boat3::drawEnemy() {
    std::vector<Cell *> barco = getBoatParts();
    if (this->isRotation()) {
        barco[0]->setEnemyTexture("../src/b3/b31H.png");
        barco[1]->setEnemyTexture("../src/b3/b32H.png");
        barco[2]->setEnemyTexture("../src/b3/b33H.png");


    } else {
        barco[0]->setEnemyTexture("../src/b3/b31V.png");
        barco[1]->setEnemyTexture("../src/b3/b32V.png");
        barco[2]->setEnemyTexture("../src/b3/b33V.png");

    }

}

void Boat3::updatePlayer(float x, float y) {
    std::vector<Cell *> barco = getBoatParts();
    std::string src;
    std::string srcfinalV[] = {"1V_X.png", "2V_X.png", "3V_X.png"};
    std::string srcfinalH[] = {"1H_X.png", "2H_X.png", "3H_X.png"};
    src = "../src/b3/b31H.png";
    for (int index = 0; index < getTam(); ++index) {
        if (barco[index]->getX() == x & barco[index]->getY() == y) {
            if (isRotation()) {
                src.replace(12, 6, srcfinalH[index]);
            } else {
                src.replace(12, 6, srcfinalV[index]);
            }
            barco[index]->setPlayerTexture(src);
        }
    }
}

bool Boat3::gotShoot() {
    if (Boat::gotShoot()) {
        drawEnemy();
        return true;
    } else {
        return false;
    }
}

Boat3::~Boat3() {

}


Boat2::Boat2(bool rotacao) : Boat(2, rotacao) {}


void Boat2::drawEnemy() {
    std::vector<Cell *> barco = getBoatParts();
    if (this->isRotation()) {
        barco[0]->setEnemyTexture("../src/b2/b21H.png");
        barco[1]->setEnemyTexture("../src/b2/b22H.png");
    } else {
        barco[0]->setEnemyTexture("../src/b2/b21V.png");
        barco[1]->setEnemyTexture("../src/b2/b22V.png");
    }

}

void Boat2::updatePlayer(float x, float y) {
    std::vector<Cell *> barco = getBoatParts();
    std::string src;
    std::string srcfinalV[] = {"1V_X.png", "2V_X.png"};
    std::string srcfinalH[] = {"1H_X.png", "2H_X.png"};
    src = "../src/b2/b21H.png";
    for (int index = 0; index < getTam(); ++index) {
        if (barco[index]->getX() == x & barco[index]->getY() == y) {
            if (isRotation()) {
                src.replace(12, 6, srcfinalH[index]);
            } else {
                src.replace(12, 6, srcfinalV[index]);
            }
            barco[index]->setPlayerTexture(src);
        }

    }
}

bool Boat2::gotShoot() {
    if (Boat::gotShoot()) {
        drawEnemy();
        return true;
    } else {
        return false;
    }
}

Boat2::~Boat2() {

}

Boat1::Boat1(bool rotacao) : Boat(1, rotacao) {}


void Boat1::drawEnemy() {
    std::vector<Cell *> barco = getBoatParts();
    if (this->isRotation()) {
        barco[0]->setEnemyTexture("../src/b1/b11H.png");
    } else {
        barco[0]->setEnemyTexture("../src/b1/b11V.png");
    }
}

void Boat1::updatePlayer(float x, float y) {
    std::vector<Cell *> barco = getBoatParts();

    if (isRotation())
        barco[0]->setPlayerTexture("../src/b1/b11H_X.png");
    else
        barco[0]->setPlayerTexture("../src/b1/b11V_X.png");

}

bool Boat1::gotShoot() {
    if (Boat::gotShoot()) {
        drawEnemy();
        return true;
    } else {
        return false;
    }

}
Boat1::~Boat1() {

}
