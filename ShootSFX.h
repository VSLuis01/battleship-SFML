//
// Created by luis on 12/7/2021.
//

#ifndef BATALHA_NAVAL_SFML_SHOOTSFX_H
#define BATALHA_NAVAL_SFML_SHOOTSFX_H

#include "GameSoundsFX.h"

/**
 * @brief Classe que representa o efeito sonoro do tiro.
 *
 * Herda de GameSoundsFX.
 * @see GameSoundsFX
 */
class ShootSFX : public GameSoundsFX {
private:
    std::string path = "../songs/sfx_tiro.ogg";
    sf::SoundBuffer soundBuffer; ///<Buffer contendo o caminho para o arquivo de áudio do tiro
    sf::Sound sound; ///<Som do tiro
protected:
    /**
     * Define o volume do efeito sonoro do tiro
     * @param sfxVol volume
     */
    void setVolume(float sfxVol) override;
public:
    /**
     * @brief Construtor do efeito sonoro de tiro
     *
     * Carrega o arquivo sonoro do tiro e também define o volume do efeito sonoro.
     */
    ShootSFX();
    /**
     * Inicia o som do tiro
     */
    void play();
    /**
     * Pausa o som do tiro
     */
    void pause();
    /**
     * Para o som do tiro
     */
    void stop();
};


#endif //BATALHA_NAVAL_SFML_SHOOTSFX_H
