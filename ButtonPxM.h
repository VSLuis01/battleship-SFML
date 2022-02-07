//
// Created by luis on 11/5/2021.
//

#ifndef TRABALHO_BUTTONPXM_H
#define TRABALHO_BUTTONPXM_H

#include "ButtonModel.h"
#include "PlayerXMachine.h"

/**
 * @brief Botão para o modo de jogo PlayerXMachine.
 *
 */
class ButtonPxM : public ButtonModel {
private:
    PlayerXMachine *gameModePxM;
public:
    /**
     * Construtor do botao
     * @param pos :posicao do botao na tela
     * @param tam :tamanho do botao
     * @param window :janela para criar o modo de jogo referente ao botao
     */
    ButtonPxM(const sf::Vector2f &pos, const sf::Vector2f &tam, sf::RenderWindow *window);

    /**
     * Faz a ação do de abrir o modo de jogo.
     * @param posicaoClick
     */
    void clickAction(sf::Vector2f posicaoClick) override;

    ~ButtonPxM() override;
};


#endif //TRABALHO_BUTTONPXM_H
