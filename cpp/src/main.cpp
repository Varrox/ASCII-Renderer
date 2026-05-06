#include "renderer.h"
#include "textures.h"
#include "helpers/time_manager.h"

#include "shaders/shadertoy_example.h"

bool running = true;

int main(){
    ShadertoyShader shader; // ("assets/pumpkin.jpeg")

    Renderer renderer(180, 100);

    //renderer.width = (int)(((float)shader.img.width / shader.img.height) * renderer.height);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "\033[?25l" << std::flush; // Hide cursor

    while(running) {
        Time::update_time();
        renderer.draw_with_shader(shader);
    }
    
    return 0;
}