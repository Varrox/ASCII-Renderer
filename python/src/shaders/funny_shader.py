from src.vectors import *
from src.textures import *
from time import *
import math

img:sampler

def shader(uv:vec2) -> vec2:
    return texture(img, vec2(uv.x + math.cos(time()), uv.y + math.sin(time())))