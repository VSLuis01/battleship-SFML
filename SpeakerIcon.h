//
// Created by luis on 12/7/2021.
//

#ifndef BATALHA_NAVAL_SFML_SPEAKERICON_H
#define BATALHA_NAVAL_SFML_SPEAKERICON_H

#include "Clickable.h"
#include "SFML/Graphics.hpp"

/**
 * @brief Classe que representa o ícone speaker
 *
 * O ícone pode ter ou não um texto anexado a ele. Herda de Clickable
 * @see Clickable
 */
class SpeakerIcon : public Clickable {
private:
    sf::Sprite iconSprite;
    sf::Text iconText;
    sf::Font font;

    /**
     * @brief atualiza a posição do texto anexado ao icon
     *
     * Atualiza com base na posição da Sprite do Ícone Speaker.
     */
    void updateTextPosition();
public:
    sf::Texture iconActiveTex; ///<Textura do Speaker ativo
    sf::Texture iconDeactivateText; ///<Textura do Speaker mudo

    /**
     *
     * @return Retorna a posição da Sprite
     */
    const sf::Vector2f & getPosition();

    /**
     * Define a posição da Sprite Speaker
     * @param pos posição X/Y
     */
    void setPosition(sf::Vector2f pos);

    /**
     * Define a posição da Sprite Speaker
     * @param pos posição X/Y
     */
    void setPosition(float posX, float posY);


    /**
     * @brief Construtor do Speaker Icon
     *
     * Construtor inicia a textura e a Sprite a fonte e o texto se a Sprite não tiver uma textura.
     */
    SpeakerIcon();

    /**
     * Retorna a textura da Sprite
     * @return textura do iconSprite
     */
    const sf::Texture* getTexture();

    /**
     * @brief Essa função retorna os bounds do Speaker
     *
     * Ela faz a soma do iconSpeaker(Sprite) e iconText(Text) que é o texto anexado à Sprite.
     * @return Bounds da Sprite + Text
     */
    sf::FloatRect getIconSpriteBounds() const;

    /**
     * @brief Define a textura de Sprite.
     *
     * Há duas possibilidades iconActiveTex(Speaker com ícone ativado) e iconDeactivateText(Speaker com ícone mudo).
     * @param tex textura
     */
    void setTexture(const sf::Texture &tex);

    /**
     * @brief Define o texto anexado ao ícone
     *
     * Essa função não é obrigatória ser chamada, pois um Speaker pode aparecer sem um texto anexado também.
     * @param speakerName string anexada ao Speaker
     */
    void setSpeakerName(const std::string& speakerName);

    /**
     * Renderiza a Sprite(iconSprite) e o Text(iconText)
     * @param target janela para renderizar
     */
    void render(sf::RenderTarget &target);

    /**
     * @brief Verifica se Speaker contém o cursor do mouse.
     *
     * Essa função verifica se o iconSprite OU o iconText contém o curso do mouse.
     * @param posicao posição do cursor do mouse
     * @return true caso iconSprite OU o iconText conter o cursor do mouse, false caso contrário.
     */
    bool contains(sf::Vector2f posicao) override;
};


#endif //BATALHA_NAVAL_SFML_SPEAKERICON_H
