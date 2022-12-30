import math

r, s, t, l, b = map(int, input().split())

areas = {
  "Circle": math.pi * r ** 2,
  "Square": s ** 2,
  "Triangle": (math.sqrt(3) / 4) * s ** 2,
  "Rectangle": l * b
}
sorted_shapes = sorted(areas, key=areas.get, reverse=True)

for shape in sorted_shapes:
  print(shape)