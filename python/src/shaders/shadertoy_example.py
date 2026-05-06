from src.vectors import *
from src.textures import *
import time
import math

##
## This shader is an example of a shadertoy shader (or glsl shader) in this ASCII renderer.
## Credit:
## https://www.shadertoy.com/view/mtyGWy
##

def palette(t:float) -> vec3:
    a:vec3 = vec3(0.5, 0.5, 0.5)
    b:vec3 = vec3(0.5, 0.5, 0.5)
    c:vec3 = vec3(1.0, 1.0, 1.0)
    d:vec3 = vec3(0.263,0.416,0.557)

    v:vec3 = (c * t + d) * 6.28318

    return a + b * vec3(math.cos(v.x), math.cos(v.y), math.cos(v.z))

def fract(v):
    if isinstance(v, vec2):
        return vec2(v.x - floor(v.x), v.y - floor(v.y))
    if isinstance(v, vec3):
        return vec3(v.x - floor(v.x), v.y - floor(v.y), v.z - floor(v.z))
    return v - floor(v)

def shader(uv:vec2) -> vec3:
    uuv:vec2 = ((vec2(uv.x * 180, uv.y * 100)) * 2.0 - vec2(180, 100)) / 100
    uv0:vec2 = uuv
    finalColor:vec3 = vec3(0.0, 0.0, 0.0)

    i:float = 0.0
    while i < 4.0:
        uuv = fract(uuv * 1.5) - vec2(0.5, 0.5)

        d:float = uuv.length() * math.exp(-uv0.length())

        d = math.sin(d*8. + time.time()) / 8.
        d = (d if d > 0 else -d)

        d = (0.01 / d) ** 1.2

        col:vec3 = palette((uv0.length()) * i * .4 + time.time() * .4) * d

        finalColor += col

        i += 1.0
    
    return finalColor