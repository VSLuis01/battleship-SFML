//
// Created by luis on 12/8/2021.
//

#ifndef BATALHA_NAVAL_SFML_GAMESOUNDSICON_H
#define BATALHA_NAVAL_SFML_GAMESOUNDSICON_H

#include "Clickable.h"
#include "GameSoundsFX.h"
#include "GameMusics.h"
#include "SFML/Graphics.hpp"

/**
 * @brief Classe que representa o ícone de engrenagem.
 *
 * Essa classe é um "menu" que controla a música e o efeito sonoro do jogo.
 *
 */
class GameSoundsIcon : public Clickable {
private:
    sf::RectangleShape optionsPanel; ///<Retangulo que guarda os SpeakerIcon
    sf::Texture gearIcon; ///<Textura da engrenagem.
    sf::Sprite gearSprite;///<Sprite da engrenagem.
    bool clicked;///<Verifica se a sprite gearSprite foi clicada.
                ///<true significa que o menu está aberto e false que está fechado
public:

    /**
     * @brief atualiza o ícone da engranagem.
     *
     * Caso o clicked == true então clicked = false e vise-versa.
     * @param mousePos
     */
    void update(sf::Vector2f mousePos);

    /**
     * Verifica se o ícone foi clicado
     * @return true caso o menu esteja aberto, false caso contrário
     */
    bool isClicked() const;

    /**
     * Define se o menu está aberto ou não.
     * @param clicked se true então o menu é aberto, se false não é aberto.
     */
    void setClicked(bool clicked);

    /**
     * Renderiza o ícone de engrenagem gearSprite.
     * Caso clicked == true, renderiza painel optionsPanel e os speaker GameSoundsFX e GameMusics
     * @param target
     */
    void render(sf::RenderTarget &target);

    /**
     * @brief Construtor do painel.
     *
     * ...
     */
    GameSoundsIcon();

    /**
     * Verifica se o ícone de engrenagem gearSprite contém a posição do cursor.
     * @param posicao posição cursos do mouse.
     * @return true caso gearSprite contenha a posição do cursor, false caso contrário.
     */
    bool contains(sf::Vector2f posicao) override;
};


#endif //BATALHA_NAVAL_SFML_GAMESOUNDSICON_H
