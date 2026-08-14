#pragma once

#include "SynthVoice.h"

class FMBellVoice : public SynthVoice {
public:
    void noteOn(float frequency, float velocity) override;
    void noteOff() override;
    float renderSample(float sampleRate) override;
    void setXY(float x, float y) override;
    std::string getName() const override { return "Gator Bell"; }

private:
    // Team task: implement and explain carrier/modulator behaviour.
    float carrierFrequency_ = 440.0f;
    float modulationIndex_ = 0.0f;
};
