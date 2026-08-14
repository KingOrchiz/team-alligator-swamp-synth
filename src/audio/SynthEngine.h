#pragma once

#include <memory>
#include <vector>

#include "SynthVoice.h"

// Composition: the engine owns and coordinates its voice objects.
class SynthEngine {
public:
    void setup(float sampleRate);
    void selectVoice(std::size_t index);
    void noteOn(float frequency, float velocity);
    void noteOff();
    void panic();
    void setXY(float x, float y);
    float renderSample();

private:
    float sampleRate_ = 44100.0f;
    std::size_t selectedVoice_ = 0;
    std::vector<std::unique_ptr<SynthVoice>> voices_;
};
