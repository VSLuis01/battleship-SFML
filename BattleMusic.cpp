//
// Created by luis on 12/7/2021.
//

#include "BattleMusic.h"

BattleMusic::BattleMusic() {
    this->music.openFromFile(this->path);
    this->music.setLoop(true);
    this->music.setVolume(GameMusics::volume);
}

void BattleMusic::play() {
    this->music.play();
}

void BattleMusic::pause() {
    this->music.pause();
}

void BattleMusic::stop() {
    this->music.stop();
}

void BattleMusic::setVolume(float musicVol) {
    this->music.setVolume(musicVol);
}
