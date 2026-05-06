from PIL import Image
from pygame.math import Vector2, Vector3

class sampler:
    def __init__(self, image_path:str):
        img = Image.open(image_path)
        pixels = list(img.getdata())
        width, height = img.size
        img.close()
        self.data = [pixels[i * width:(i + 1) * width] for i in range(height)]

def texture(image:sampler, uv:Vector2) -> Vector3:
    x, y, z = image.data[int((uv.y % 1.0) * len(image.data))][int((uv.x % 1.0) * len(image.data[0]))]
    return Vector3(x, y, z) / 255