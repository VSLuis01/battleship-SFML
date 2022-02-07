//
// Created by luis on 12/7/2021.
//

#ifndef BATALHA_NAVAL_SFML_PREPARATIONMUSIC_H
#define BATALHA_NAVAL_SFML_PREPARATIONMUSIC_H

#include "GameMusics.h"

/**
 * @brief Classe que representa a música da tela de preparação.
 *
 * Herda de GameMusics.
 * @see GameMusics
 */
class PreparationMusic : public GameMusics {
private:
    std::string path = "../songs/PreparationMusic.ogg";
    sf::Music music;
protected:
    /**
     * Define o volume da música de preparação.
     * @param musicVol volume
     */
    void setVolume(float musicVol) override;
public:

    /**
     * @brief Construtor da música de preparação.
     *
     * Carrega o arquivo da música e define seu volume.
     */
    PreparationMusic();

    /**
     * Inicia a música de preparação.
     */
    void play();

    /**
     * Pausa a música de preparação
     */
    void pause();

    /**
     * Para a música de preparação.
     */
    void stop();
};


#endif //BATALHA_NAVAL_SFML_PREPARATIONMUSIC_H
