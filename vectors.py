from math import *

class vec3:
    def __init__(self, x:float, y:float, z:float):
        self.x = x
        self.y = y
        self.z = z

    def __add__(self, other):
        return vec3(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return vec3(self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, scalar:float):
        return vec3(self.x * scalar, self.y * scalar, self.z * scalar)

    def __truediv__(self, scalar:float):
        return vec3(self.x / scalar, self.y / scalar, self.z / scalar)
    
class vec2:
    def __init__(self, x:float, y:float):
        self.x = x
        self.y = y

    def __add__(self, other):
        return vec2(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return vec2(self.x - other.x, self.y - other.y)

    def __mul__(self, scalar:float):
        return vec2(self.x * scalar, self.y * scalar)

    def __truediv__(self, scalar:float):
        return vec2(self.x / scalar, self.y / scalar)
    
    def length(self) -> float:
        return sqrt(self.x * self.x + self.y * self.y)
    
def wrap(value:float) -> float:
    return value % 1