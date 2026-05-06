from PIL import Image
from src.vectors import *

class sampler:
    def __init__(self, image_path:str):
        img = Image.open(image_path)
        pixels = list(img.getdata())
        width, height = img.size
        img.close()
        self.data = [pixels[i * width:(i + 1) * width] for i in range(height)]

def texture(image:sampler, uv:vec2) -> vec3:
    x, y, z = image.data[int((uv.y % 1.0) * len(image.data))][int((uv.x % 1.0) * len(image.data[0]))]
    return vec3(x, y, z) / 255