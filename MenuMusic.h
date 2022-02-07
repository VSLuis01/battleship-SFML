//
// Created by luis on 12/7/2021.
//

#ifndef BATALHA_NAVAL_SFML_MENUMUSIC_H
#define BATALHA_NAVAL_SFML_MENUMUSIC_H

#include "GameMusics.h"

/**
 * @brief Classe que representa a música que toca na tela inicial.
 */
class MenuMusic : public  GameMusics {
private:
    std::string path = "../songs/MenuSong.ogg";
    sf::Music music;
protected:
    void setVolume(float musicVol) override;
public:
    MenuMusic();
    void play();
    void pause();
    void stop();
};


#endif //BATALHA_NAVAL_SFML_MENUMUSIC_H
