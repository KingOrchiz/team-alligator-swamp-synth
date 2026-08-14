#pragma once

class InputMapper {
public:
    // Returns a frequency for a mapped musical key, or 0 when unmapped.
    float frequencyForKey(int key) const;
};
