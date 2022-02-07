//
// Created by maluc on 30/09/2021.
//
/**
 * @brief Classe que diz se algo é clicável.
 *
 * Ela diz se algo ja foi clicado uma vez e também se reporta um state
 * quem herda tem que definir a ação do state.
 */
#ifndef TRABALHO_CLICKABLE_H
#define TRABALHO_CLICKABLE_H

#include "SFML/Graphics.hpp"

class Clickable {
private:
    bool state;
public:
    /**
     * contrutor de clickavel
     */
    Clickable();

    virtual ~Clickable();

    /**
     * metodo abstrato, ele devera dizer se o mouse esta em cima do clickavel
     * @param posicao :indica posicao do mouse
     * @return true se o mouse esta em cima e false caso contrario
     */
    virtual bool contains(sf::Vector2f posicao) = 0;

    /**
     * verifica se ele esta ativado ou nao
     * @return retorna verdadeiro se ativado e falso se desativado
     */
    bool isClickable() const;

    /**
     * seta o estado como verdadeiro, ou seja, ativa o clickavel
     */
    void enableClickable();

    /**
     * seta o estado como falso, ou seja, desativa o clickavel
     */
    void disableClickable();

    /**
     * quem herda o clickavel deve implementar a acao que sera feita ao clicar
     * @param posicaoClick
     */
    virtual void clickAction(sf::Vector2f posicaoClick);


};


#endif //TRABALHO_CLICKABLE_H
