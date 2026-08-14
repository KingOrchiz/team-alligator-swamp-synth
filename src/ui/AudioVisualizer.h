#pragma once

#include <vector>

class AudioVisualizer {
public:
    void pushSample(float sample);
    void draw(float x, float y, float width, float height) const;

private:
    std::vector<float> history_;
};
