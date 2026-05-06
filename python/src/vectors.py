from math import *

class vec3: # Forward Declare
    pass

class vec3:
    def __init__(self, x=0.0, y=0.0, z=0.0):
        self.x = float(x.x if hasattr(x, 'x') else x)
        self.y = float(y.y if hasattr(y, 'y') else (x.y if hasattr(x, 'y') else y))
        self.z = float(z.z if hasattr(z, 'z') else (x.z if hasattr(x, 'z') else z))

    def __add__(self, other):
        if hasattr(other, 'x') and hasattr(other, 'z'):
            return vec3(self.x + other.x, self.y + other.y, self.z + other.z)
        return vec3(self.x + other, self.y + other, self.z + other)

    def __sub__(self, other):
        if hasattr(other, 'x') and hasattr(other, 'z'):
            return vec3(self.x - other.x, self.y - other.y, self.z - other.z)
        return vec3(self.x - other, self.y - other, self.z - other)

    def __mul__(self, other):
        if hasattr(other, 'x') and hasattr(other, 'z'):
            return vec3(self.x * other.x, self.y * other.y, self.z * other.z)
        return vec3(self.x * other, self.y * other, self.z * other)

    def __rmul__(self, other):
        return self.__mul__(other)

    def __truediv__(self, other):
        if hasattr(other, 'x') and hasattr(other, 'z'):
            return vec3(self.x / other.x, self.y / other.y, self.z / other.z)
        return vec3(self.x / other, self.y / other, self.z / other)

    def length(self) -> float:
        return sqrt(self.x**2 + self.y**2 + self.z**2)

    def __repr__(self):
        return f"vec3({self.x:.2f}, {self.y:.2f}, {self.z:.2f})"

class vec2: # Forward Declare
    pass

class vec2:
    def __init__(self, x=0.0, y=0.0):
        self.x = float(x.x if hasattr(x, 'x') else x)
        self.y = float(y.y if hasattr(y, 'y') else (x.y if hasattr(x, 'y') else y))

    def __add__(self, other):
        if hasattr(other, 'x') and not hasattr(other, 'z'):
            return vec2(self.x + other.x, self.y + other.y)
        return vec2(self.x + other, self.y + other)

    def __sub__(self, other):
        if hasattr(other, 'x') and not hasattr(other, 'z'):
            return vec2(self.x - other.x, self.y - other.y)
        return vec2(self.x - other, self.y - other)

    def __mul__(self, other):
        if hasattr(other, 'x') and not hasattr(other, 'z'):
            return vec2(self.x * other.x, self.y * other.y)
        return vec2(self.x * other, self.y * other)

    def __rmul__(self, other):
        return self.__mul__(other)

    def __truediv__(self, other):
        if hasattr(other, 'x') and not hasattr(other, 'z'):
            return vec2(self.x / other.x, self.y / other.y)
        return vec2(self.x / other, self.y / other)

    def length(self) -> float:
        return sqrt(self.x**2 + self.y**2)

    def __repr__(self):
        return f"vec2({self.x:.2f}, {self.y:.2f})"

def wrap(value: float) -> float:
    return value % 1.0