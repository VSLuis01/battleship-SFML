//
// Created by luis on 12/7/2021.
//

#ifndef BATALHA_NAVAL_SFML_BATTLEMUSIC_H
#define BATALHA_NAVAL_SFML_BATTLEMUSIC_H

#include "GameMusics.h"

/**
 * @brief Essa classe representa a música da batalha.
 */
class BattleMusic : public GameMusics {
private:
    sf::Music music;
    std::string path = "../songs/BattleMusic.wav";
protected:
    void setVolume(float musicVol) override;

public:
    BattleMusic();
    void play();
    void pause();
    void stop();

};


#endif //BATALHA_NAVAL_SFML_BATTLEMUSIC_H
