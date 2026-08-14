#pragma once

#include "SynthVoice.h"

class NoisePercussionVoice : public SynthVoice {
public:
    void noteOn(float frequency, float velocity) override;
    void noteOff() override;
    float renderSample(float sampleRate) override;
    void setXY(float x, float y) override;
    std::string getName() const override { return "Marsh Hit"; }

private:
    // Team task: implement safe noise generation and a short decay envelope.
    float amplitude_ = 0.0f;
    float decay_ = 0.0f;
};
