//
// Created by luis on 12/8/2021.
//

#include "HitSFX.h"

HitSFX::HitSFX() {
    this->soundBuffer.loadFromFile(this->path);
    this->sound.setBuffer(this->soundBuffer);
    this->sound.setVolume(GameSoundsFX::volume);
}

void HitSFX::play() {
    this->sound.play();
}

void HitSFX::pause() {
    this->sound.pause();
}

void HitSFX::stop() {
    this->sound.stop();
}

void HitSFX::setVolume(float sfxVol) {
    this->sound.setVolume(sfxVol);
}
