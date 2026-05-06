#pragma once

#include "vectors.h"

// Defined here so shaders can also use this.
#define CLAMP(x, min, max) (x > max ? max : (x < min ? min : x))

class Shader {
public:
    Shader(){};
    virtual vec3 fragment(const vec2& uv) const{ return vec3::ZERO; }
};