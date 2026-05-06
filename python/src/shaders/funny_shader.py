from pygame.math import Vector2, Vector3
from textures import *
from time import *
import math

img:sampler

def shader(uv:Vector2) -> Vector3:
    return texture(img, Vector2(uv.x + math.cos(time()), uv.y + math.sin(time())))