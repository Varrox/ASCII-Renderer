#pragma once

#include "vectors.h"

#include <cstring>
#include <iostream>
#include <string>

#include "shader.h"

struct Renderer {
    static inline const std::string RESET = "\033[0m";
    static inline const std::string CLEAR_ANSI = "\033[H";
    static inline const std::string SYNC_START = "\033[?2026h";
    static inline const std::string SYNC_END = "\033[?2026l";

    static constexpr const int MAX_VALUE = 256;
    char num_strings[256][4];

    char* buffer;

    Renderer(int w, int h) : width(w), height(h) {
        init();
    }

    ~Renderer(){
        std::cout << "\033[0m\033[?25h" << std::endl;
        delete [] buffer;
    }

    void init(){
        for(int i = 0; i < MAX_VALUE; i++){
            sprintf(num_strings[i], "%d", i);
        }

        size_t buffer_size = (size_t)height * (width * 30) + 1024;
        buffer = new char[buffer_size];
    }

    int width, height;

    constexpr int get_value(const float& in) const{ 
        int val = (int)(in * 255.0f);
        if (val < 0) return 0;
        if (val > 255) return 255;
        return val;
    }

    inline void add_ansi_from_color(int& offset, const vec3& color) const{
        const int r_idx = get_value(color.x);
        const int g_idx = get_value(color.y);
        const int b_idx = get_value(color.z);

        const char* r_str = num_strings[r_idx];
        const char* g_str = num_strings[g_idx];
        const char* b_str = num_strings[b_idx];

        memcpy(buffer + offset, "\033[48;2;", 7);
        offset += 7;

        while (*r_str) buffer[offset++] = *r_str++;
        buffer[offset++] = ';';

        while (*g_str) buffer[offset++] = *g_str++;
        buffer[offset++] = ';';

        while (*b_str) buffer[offset++] = *b_str++;
        buffer[offset++] = 'm';

        buffer[offset++] = ' ';
        buffer[offset++] = ' ';
    }

    void draw_with_shader(const Shader& shader) const{
        int offset = 0;

        memcpy(buffer + offset, SYNC_START.c_str(), SYNC_START.size());
        offset += SYNC_START.size();
        memcpy(buffer + offset, CLEAR_ANSI.c_str(), CLEAR_ANSI.size());
        offset += CLEAR_ANSI.size();

        for(int y = 0; y < height; y++){
            float y_coord = (float)y / height;

            for(int x = 0; x < width; x++){
                vec3 color = shader.fragment(vec2((float)x / width, y_coord));
                add_ansi_from_color(offset, color);
            }

            memcpy(buffer + offset, RESET.c_str(), RESET.size());
            offset += RESET.size();
            buffer[offset++] = '\n';
        }

        memcpy(buffer + offset, SYNC_END.c_str(), SYNC_END.size());
        offset += SYNC_END.size();
        buffer[offset] = '\0';

        fwrite(buffer, 1, offset, stdout);
        fflush(stdout);
    }
};