//
// Created by luis on 12/10/2021.
//

#ifndef BATALHA_NAVAL_SFML_WONSFX_H
#define BATALHA_NAVAL_SFML_WONSFX_H
#include "GameSoundsFX.h"

class WonSFX : public GameSoundsFX {
private:
    std::string pathWon = "../songs/sfx_won.wav";
    std::string pathClaps = "../songs/sfx_claps.ogg";
    sf::SoundBuffer soundBufferWon; ///<Buffer contendo o caminho para o arquivo de áudio de vitoria
    sf::SoundBuffer soundBufferClap; ///<Buffer contendo o caminho para o arquivo de palmas
    sf::Sound soundWon; ///<Som de vitoria
    sf::Sound soundClap; ///<Som de palmas
protected:
    /**
     * Define o volume do efeito sonoro de vitoria
     * @param sfxVol volume
     */
    void setVolume(float sfxVol) override;
public:
    /**
     * @brief Construtor do efeito sonoro de tiro
     *
     * Carrega o arquivo sonoro de vitoria e também define o volume do efeito sonoro.
     */
    WonSFX();
    /**
     * Inicia o som de vitoria
     */
    void play();
    /**
     * Pausa o som de vitoria
     */
    void pause();
    /**
     * Para o som de vitoria
     */
    void stop();
};


#endif //BATALHA_NAVAL_SFML_WONSFX_H
