import math

angle = 0.0
angleStep = math.pi / 32.0 

result = "byte sin64[] = {"

while angle < 2 * math.pi :
  x = math.sin(angle) * 127 + 127
  angle += angleStep
  result = result + str(int(x))
  if angle < 2 * math.pi :
  	result = result + ", "

result = result + "};"

print(result)