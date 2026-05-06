#pragma once

#include "vectors.h"

struct sampler2D {
    int width, height, channels;
    unsigned char* data;

    sampler2D() {};
    sampler2D(const char* file);
    ~sampler2D();
};

vec3 texture(const sampler2D& sampler, const vec2& uv);