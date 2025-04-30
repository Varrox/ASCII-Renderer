from vectors import *
from textures import *
from time import *

img:sampler = sampler('pumpkin.jpeg')

def shader(uv:vec2) -> vec3:
    return texture(img, vec2(uv.x + cos(time()), uv.y + sin(time())))