//
// Created by luis on 12/8/2021.
//

#ifndef BATALHA_NAVAL_SFML_HITSFX_H
#define BATALHA_NAVAL_SFML_HITSFX_H

#include "GameSoundsFX.h"

/**
 * @brief Classe que representa o efeito sono de um hit.
 */
class HitSFX : public GameSoundsFX {
private:
    std::string path = "../songs/sfx_hit2.wav";
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

protected:
    void setVolume(float sfxVol) override;

public:
    HitSFX();
    void play();
    void pause();
    void stop();
};


#endif //BATALHA_NAVAL_SFML_HITSFX_H
