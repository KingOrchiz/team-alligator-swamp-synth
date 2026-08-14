#pragma once

#include <string>

// Common interface for all playable voices.
// Team task: agree thread-safety and lifetime rules before implementation.
class SynthVoice {
public:
    virtual ~SynthVoice() = default;
    virtual void noteOn(float frequency, float velocity) = 0;
    virtual void noteOff() = 0;
    virtual float renderSample(float sampleRate) = 0;
    virtual void setXY(float x, float y) = 0;
    virtual std::string getName() const = 0;
};
