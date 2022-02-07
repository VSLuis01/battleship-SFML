//
// Created by luis on 12/7/2021.
//

#ifndef BATALHA_NAVAL_SFML_GAMESOUNDSFX_H
#define BATALHA_NAVAL_SFML_GAMESOUNDSFX_H

#include "SpeakerIcon.h"
#include "SFML/Audio.hpp"

/**
 * @brief Classe que representa todos os efeitos sonoros do jogo.
 *
 * Na verdade essa classe é para ser herdada por todos os efeitos sonoros do jogo.
 * Possui apenas membros static para que todos efeitos sonoros estejam "conectados".
 * Assim caso desative os efeitos sonoros então todos são desativados juntos.
 *
 * @see HitSFX
 * @see ShootSFX
 */
class GameSoundsFX {
protected:
    static float volume;///<Atributo que define o volume de todos efeitos sonoros.
    virtual void setVolume(float sfxVol) = 0;///<Método abstrato para que as classes que herdam de GameSoundsFX possam definir como alterar o volume.
private:
    static SpeakerIcon speakerIcon;///<Ícone de Speaker estático para que seja o mesmo em todas as classes. @see SpeakerIcon
    /**
     * @brief Atualiza a texture do speakerIcon.
     *
     * Caso a textura carregada seja a do Speaker ativo, então ela é definida para Speaker mudo e vise-versa.
     * @param mousePos posição do cursos para verificar se o mouse está no Speaker.
     */
    static void updateSpeakerIcon(sf::Vector2f mousePos);
public:

    /**
     * Define que o Speaker é clicável.
     */
    static void enableClickable();

    /**
     * Define que o Speaker não é clicável.
     */
    static void disableClickable();

    /**
     * @brief Construtor de GameSoundsFX.
     *
     * Esse construtor define um nome para ser anexado ao speakerIcon.
     * Nesse caso o nome é "SoundFX".
     */
    GameSoundsFX();

    /**
     * Retorna os bounds do speakerIcon.
     *
     * @see SpeakerIcon::getIconSpriteBounds()
     * @return
     */
    static sf::FloatRect getBounds();

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
     * Renderiza o speakerIcon
     * @param target janela que vai renderizar.
     */
    static void render(sf::RenderTarget &target);

    /**
     * Atualiza a textura do speakerIcon e o volume do efeito sonoro passado.
     * @see updateSpeakerIcon()
     * @param mousePos posição do cursor do mouse.
     * @param soundFX efeito sonoro que terá o volume atualizado.
     */
    static void update(sf::Vector2f mousePos, GameSoundsFX &soundFX);

    /**
     * Apenas atualiza o volume do efeito sonoro.
     * @param soundFX
     */
    static void update(GameSoundsFX &soundFX);

};


#endif //BATALHA_NAVAL_SFML_GAMESOUNDSFX_H
