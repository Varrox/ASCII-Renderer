import os
import sys
import threading
import numpy as np
from colorist import BgColorRGB
from vectors import *

height = 0
width = 0

def convert_to_ascii_color(color:vec3) -> BgColorRGB:
    return BgColorRGB(
        max(min(int(color.x * 255), 255), 0),
        max(min(int(color.y * 255), 255), 0),
        max(min(int(color.z * 255), 255), 0)
    )

def render_ascii(image:str):
    os.system('cls' if os.name == 'nt' else 'clear')
    sys.stdout.write(image)
    sys.stdout.flush()

def draw_row(shader:callable, output, y:int):
    y_coord = float(y / height)
    x_coords = np.linspace(0, 1, width)
    colors = np.array([convert_to_ascii_color(shader(vec2(x, y_coord))) for x in x_coords])  # Apply shader to all x-coordinates
    row_output = ""
    for col in colors:
        row_output += f"{col}  {col.OFF}"
    output[y] = row_output

def draw_with_shader(shader:callable):
    lines = [""] * height
    output:str = ""

    threads = []

    i = 0
    while i < height:
        threads.append(threading.Thread(target=draw_row, args=(shader, lines, i)))
        threads[-1].start()
        i += 1

    i = 0
    while i < height:
        output += lines[i] + '\n'
        threads[i].join()
        i += 1

    return output