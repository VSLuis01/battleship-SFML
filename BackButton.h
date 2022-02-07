//
// Created by maluc on 06/10/2021.
//

#ifndef TRABALHO_BACKBUTTON_H
#define TRABALHO_BACKBUTTON_H

#include "ButtonModel.h"

/**
 * @brief Botão de voltar.
 */
class BackButton: public ButtonModel {

public:
    /**
     *
     * @param pos posição do botão
     * @param tam tamanho do botão
     */
    BackButton(const sf::Vector2f &pos, const sf::Vector2f &tam);

};


#endif //TRABALHO_BACKBUTTON_H
