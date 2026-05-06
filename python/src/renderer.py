import sys
from src.vectors import *

height = 0
width = 0

RESET = "\033[0m"
CLEAR_ANSI = "\033[H"
CHAR = "  "

MAX_VALUE = 255

def clamp(val, min, max):
    return max if val > max else (min if val < min else val)

def convert_to_ansi(color:vec3) -> str:
    return f"\033[48;2;{clamp(int(color.x * MAX_VALUE), 0, MAX_VALUE)};{clamp(int(color.y * MAX_VALUE), 0, MAX_VALUE)};{clamp(int(color.z * MAX_VALUE), 0, MAX_VALUE)}m"

def draw_with_shader(shader:callable):
    output:str = CLEAR_ANSI

    y:int = 0
    while y < height:
        y_coord = float(y) / height
        x:int = 0
        while x < width:
            output += convert_to_ansi(shader(vec2(float(x) / width, y_coord))) + CHAR + RESET
            x += 1
        output += "\n"
        y += 1

    output += "\033[?2026l"

    sys.stdout.write(output)
    sys.stdout.flush()
