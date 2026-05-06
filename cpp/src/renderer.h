#pragma once

#include "vectors.h"

#include <iostream>
#include <string>
#include <array>

#include "shader.h"

struct Renderer {
    static inline const std::string RESET = "\033[0m";
    static inline const std::string CLEAR_ANSI = "\033[H";
    static inline const std::string CHAR = "  ";

    static constexpr const int MAX_VALUE = 256;
    std::array<std::string, MAX_VALUE> num_list;

    Renderer() {
        init();
    }

    void init(){
        for(int i = 0; i < MAX_VALUE; i++){
            num_list[i] = std::to_string(i);
        }
    }

    int width, height;

    constexpr int get_value(const float& in) const{
        return CLAMP((int)(in * 255), 0, 255);
    }

    inline std::string get_ansi_from_color(const vec3& color) const{
        return "\033[48;2;" + num_list[get_value(color.x)] + ";" + num_list[get_value(color.y)] + ";" + num_list[get_value(color.z)] + 'm';
    }

    void draw_with_shader(const Shader& shader) const{
        static std::string output;
        output.clear();
        output.reserve(height * width * 20);

        output += CLEAR_ANSI;

        for(int y = 0; y < height; y++){
            float y_coord = (float)y / height;

            for(int x = 0; x < width; x++){
                vec3 color = shader.fragment(vec2((float)x / width, y_coord));
                output += get_ansi_from_color(color) + CHAR + RESET;
            }

            output += "\n";
        }

        output += "\033[?2026l";

        fwrite(output.data(), 1, output.size(), stdout);
        fflush(stdout);
    }
};