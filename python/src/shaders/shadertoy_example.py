from pygame.math import Vector2, Vector3
from textures import *
from time import *
import math

##
## This shader is an example of a shadertoy shader (or glsl shader) in this ASCII renderer.
## Credit:
## https://www.shadertoy.com/view/mtyGWy
##

def palette(t:float) -> Vector3:
    a = Vector3(0.5, 0.5, 0.5)
    b = Vector3(0.5, 0.5, 0.5)
    c = Vector3(1.0, 1.0, 1.0)
    d = Vector3(0.263,0.416,0.557)

    cs = (c*t+d) * 6.28318

    return a + b * Vector3(math.cos(cs.x), math.cos(cs.y), math.cos(cs.z))

def frack(x:float) -> float:
    return x - math.floor(x)

def fract(xy:Vector2) -> Vector2:
    return Vector2(fract(xy.x), fract(xy.y))

def shader(uv:Vector2) -> Vector3:
    uuv = ((uv * Vector2(180, 100)) * 2.0 - Vector2(180, 100)) / 100
    uv0 = uuv
    finalColor = Vector3(0.0, 0.0, 0.0)

    i = 0.0
    while i < 4.0:
        uuv = fract(uuv * 1.5) - Vector2(0.5, 0.5)

        d = uuv.length() * math.exp(-uv0.length())

        d = math.sin(d*8. + time()) / 8.
        d = (d if d > 0 else -d)

        d = (0.01 / d) ** 1.2

        col = palette(uv0.length() * i*.4 + time() * .4) * d

        finalColor += col

        i += 1.0
    
    return finalColor