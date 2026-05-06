from src.textures import sampler
import src.renderer as renderer
import src.shaders.shadertoy_example as shader
import sys

# shader.img = sampler('assets/pumpkin.jpeg')

renderer.height = 100 #40
renderer.width = 180 #int((len(funny_shader.img.data[0]) / len(funny_shader.img.data)) * renderer.height)

sys.stdout.write("\033[?25l")
sys.stdout.flush()

while True:
    renderer.draw_with_shader(shader.shader)
