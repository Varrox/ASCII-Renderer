#pragma once

#include "shader.h"
#include "textures.h"
#include "time_manager.h"

class FunnyShader : public Shader {
public:
    sampler2D img;

    FunnyShader(const char* path) : img(path) {}

    vec3 fragment(const vec2& uv) const {
        return texture(img, vec2(uv.x + cos(Time::time), uv.y + sin(Time::time)));
    }
};