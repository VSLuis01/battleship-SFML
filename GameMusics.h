//
// Created by luis on 12/7/2021.
//

#ifndef BATALHA_NAVAL_SFML_GAMEMUSICS_H
#define BATALHA_NAVAL_SFML_GAMEMUSICS_H

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SpeakerIcon.h"
#include <iostream>

/**
 * @brief Essa classe representa todas as músicas do jogo.
 *
 * Na verdade essa classe é para ser herdada por todas as músicas do jogo.
 * Possui apenas membros static para que todas as músicas estejam "conectadas".
 * Assim caso desative as músicas então todas são desativadas juntas.
 *
 * @see BattleMusic
 * @see PreparationMusic
 * @see MenuMusic
 */
class GameMusics {
protected:
    static float volume; ///<Atributo que define o volume de todas as músicas.

    virtual void setVolume(float musicVol) = 0; ///<Método abstrato para que as classes que herdam de GameMusics possam definir como alterar o volume.
private:
    static SpeakerIcon speakerIcon; ///<Ícone de Speaker estático para que seja o mesmo em todas as classes. @see SpeakerIcon
    /**
     * @brief Atualiza a texture do speakerIcon.
     *
     * Caso a textura carregada seja a do Speaker ativo, então ela é definida para Speaker mudo e vise-versa.
     * @param mousePos posição do cursos para verificar se o mouse está no Speaker.
     */
    static void updateSpeakerIcon(sf::Vector2f mousePos);
public:

    /**
     * @brief Construtor de GameMusics.
     *
     * Esse construtor define um nome para ser anexado ao speakerIcon.
     * Nesse caso o nome é "Music".
     */
    GameMusics();

    /**
     * Define que o Speaker é clicável.
     */
    static void enableClickable();

    /**
     * Define que o Speaker não é clicável.
     */
    static void disableClickable();

    /**
     * Retorna a posição do speakerIcon.
     * @return
     */
    static const sf::Vector2f& getPosition();

    /**
     * Define a posição do speakerIcon
     * @param pos
     */
    static void setPosition(sf::Vector2f pos);

    /**
     * Define a posição do speakerIcon
     * @param posX
     * @param posY
     */
    static void setPosition(float posX, float posY);

    /**
     * Retorna os bounds do speakerIcon.
     *
     * @see SpeakerIcon::getIconSpriteBounds()
     * @return
     */
    static sf::FloatRect getBounds();

    /**
     * Renderiza o speakerIcon
     * @param target janela que vai renderizar.
     */
    static void render(sf::RenderTarget &target);

    /**
     * Atualiza a textura do speakerIcon e o volume da música
     * @see updateSpeakerIcon()
     * @param mousePos posição do cursor do mouse.
     * @param musicUpdate música que terá o volume atualizado.
     */
    static void update(sf::Vector2f mousePos, GameMusics &musicUpdate);

    /**
     * Apenas atualiza o volume da música.
     * @param musicUpdate
     */
    static void update(GameMusics &musicUpdate);
};


#endif //BATALHA_NAVAL_SFML_GAMEMUSICS_H
