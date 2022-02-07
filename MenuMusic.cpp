//
// Created by luis on 12/7/2021.
//

#include "MenuMusic.h"

MenuMusic::MenuMusic() {
    this->music.openFromFile(this->path);
    this->music.setLoop(true);
    this->music.setVolume(GameMusics::volume);
}

void MenuMusic::play() {
    this->music.play();
}

void MenuMusic::pause() {
    this->music.pause();
}

void MenuMusic::stop() {
    this->music.stop();
}

void MenuMusic::setVolume(float musicVol) {
    this->music.setVolume(musicVol);
}
