from vectors import *
from textures import *
import renderer
import shader

# Multiply width by 1.3 to get accurate aspect ratios

renderer.height = 40
renderer.width = int((len(shader.img.data[0]) / len(shader.img.data)) * 1.3 * renderer.height)

while True:
    renderer.render_ascii(renderer.draw_with_shader(shader.shader))
