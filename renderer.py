import os
import numpy as np
from pygame.math import Vector2, Vector3

height = 0
width = 0

RESET = "\033[0m"

def convert_to_ansi(color:Vector3) -> str:
    return f"\033[48;2;{max(min(int(color.x * 255), 255), 0)};{max(min(int(color.y * 255), 255), 0)};{max(min(int(color.z * 255), 255), 0)}m"

def render_ascii(image:str):
    os.system('cls' if os.name == 'nt' else 'clear')
    print(image)

def draw_row(shader:callable, y:int) -> str:
    y_coord = float(y / height)
    x_coords = np.linspace(0, 1, width)
    row_output = f"  {RESET}".join([convert_to_ansi(shader(Vector2(x_coord, y_coord))) for x_coord in x_coords]) + RESET # Apply shader to all x-coordinates
    return row_output

def draw_with_shader(shader:callable):
    return "\n".join([draw_row(shader, i) for i in range(height)])
