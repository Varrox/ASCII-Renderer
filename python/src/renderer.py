import sys
from pygame.math import Vector2, Vector3

height = 0
width = 0

RESET = "\033[0m"
CLEAR_ANSI = "\033[H"
CHAR = "  "

def convert_to_ansi(color:Vector3) -> str:
    return f"\033[48;2;{max(min(int(color.x * 255), 255), 0)};{max(min(int(color.y * 255), 255), 0)};{max(min(int(color.z * 255), 255), 0)}m"

def draw_row(shader:callable, y:int) -> str:
    y_coord = float(y / height)
    arr = []
    x = 0
    while x < width:
        arr.append(convert_to_ansi(shader(Vector2(float(x) / width, y_coord))))
    row_output = f"{CHAR}{RESET}".join(arr) + RESET # Apply shader to all x-coordinates
    return row_output

def draw_with_shader(shader:callable):
    output =  CLEAR_ANSI + "\n".join([draw_row(shader, i) for i in range(height)]) + "\033[?2026l"

    sys.stdout.write(output)
    sys.stdout.flush()
