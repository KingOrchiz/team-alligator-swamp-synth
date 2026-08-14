#pragma once

#include "SynthVoice.h"

class LeadVoice : public SynthVoice {
public:
    void noteOn(float frequency, float velocity) override;
    void noteOff() override;
    float renderSample(float sampleRate) override;
    void setXY(float x, float y) override;
    std::string getName() const override { return "Swamp Lead"; }

private:
    // Team task: design oscillator, envelope, and timbre parameters.
    float frequency_ = 440.0f;
    float velocity_ = 0.0f;
    float phase_ = 0.0f;
};
