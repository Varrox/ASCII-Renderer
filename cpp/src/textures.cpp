#include "textures.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

sampler2D::sampler2D(const char* file){
    stbi_set_flip_vertically_on_load(false);
    data = stbi_load(file, &width, &height, &channels, 4);
}

sampler2D::~sampler2D(){
    stbi_image_free(data);
}

vec3 texture(const sampler2D& sampler, const vec2& uv){
    int u = (int)std::floor(uv.x * sampler.width) % sampler.width;
    if (u < 0) u += sampler.width;

    int v = (int)std::floor(uv.y * sampler.height) % sampler.height;
    if (v < 0) v += sampler.height;

    int index = (v * sampler.width + u) * 4;

    return vec3(sampler.data[index] / 255.0f, sampler.data[index + 1] / 255.0f, sampler.data[index + 2] / 255.0f);
}