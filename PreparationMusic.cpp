//
// Created by luis on 12/7/2021.
//

#include "PreparationMusic.h"

PreparationMusic::PreparationMusic() {
    this->music.openFromFile(this->path);
    this->music.setLoop(true);
    this->music.setVolume(GameMusics::volume);
}

void PreparationMusic::play() {
    this->music.play();
}

void PreparationMusic::pause() {
    this->music.pause();
}

void PreparationMusic::stop() {
    this->music.stop();
}

void PreparationMusic::setVolume(float musicVol) {
    this->music.setVolume(musicVol);
}

