//
// Created by luis on 12/7/2021.
//

#include "ShootSFX.h"

ShootSFX::ShootSFX() {
    this->soundBuffer.loadFromFile(this->path);
    this->sound.setBuffer(this->soundBuffer);
    this->sound.setVolume(GameSoundsFX::volume);
}

void ShootSFX::play() {
    this->sound.play();
}

void ShootSFX::pause() {
    this->sound.pause();
}

void ShootSFX::stop() {
    this->sound.stop();
}

void ShootSFX::setVolume(float sfxVol) {
    this->sound.setVolume(sfxVol);
}
