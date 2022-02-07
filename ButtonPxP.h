//
// Created by maluc on 06/10/2021.
//
/***
 * botão do menu para a opção de Jogador contra jogador
 */
#ifndef TRABALHO_BUTTONPXP_H
#define TRABALHO_BUTTONPXP_H

#include "ButtonModel.h"
#include "PlayerXPlayer.h"
/**
 * @brief Botão do modo de jogo PlayerXPlayer
 *
 * Modo de jogo PlayerXPlayer.
 */
class ButtonPxP : public ButtonModel {
private:
    PlayerXPlayer *gameMode; ///<Modo de jogo.
public:
    /**
     * Contrutor do botao
     * @param pos :posicao do botao na tela
     * @param tam :tamanho do botao
     * @param window :janela para criar o modo de jogo referente ao botao
     */
    ButtonPxP(const sf::Vector2f &pos, const sf::Vector2f &tam, sf::RenderWindow *window);

    /**
     * Faz a ação do de abrir o modo de jogo PlayerXPlayer.
     * @param posicaoClick
     */
    void clickAction(sf::Vector2f posicaoClick) override;

    ~ButtonPxP() override;
};


#endif //TRABALHO_BUTTONPXP_H
