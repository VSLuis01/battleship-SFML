//
// Created by luis on 12/10/2021.
//

#include "WonSFX.h"

WonSFX::WonSFX() {
    this->soundBufferWon.loadFromFile(this->pathWon);
    this->soundBufferClap.loadFromFile(this->pathClaps);
    this->soundWon.setBuffer(this->soundBufferWon);
    this->soundWon.setVolume(GameSoundsFX::volume);
    this->soundClap.setBuffer(this->soundBufferClap);
    this->soundClap.setVolume(GameSoundsFX::volume);
}

void WonSFX::play() {
    this->soundWon.play();
    this->soundClap.play();
}

void WonSFX::pause() {
    this->soundWon.pause();
    this->soundClap.pause();
}

void WonSFX::stop() {
    this->soundWon.stop();
    this->soundClap.stop();
}

void WonSFX::setVolume(float sfxVol) {
    this->soundWon.setVolume(sfxVol);
}