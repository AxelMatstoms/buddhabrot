import math
import struct

from PIL import Image

WIDTH = 2048
HEIGHT = 2048

with open("out.bin", "rb") as f:
    buf = f.read()

ints = struct.unpack("i" * (WIDTH * HEIGHT), buf)
#print(sorted(ints, reverse=True)[:100])
mx = max(ints)

im = Image.new("RGB", (WIDTH, HEIGHT))
for y in range(HEIGHT):
    for x in range(WIDTH):
        val = ints[y * WIDTH + x]
        clr = int(val * 255 / mx)
        #clr = int(20 * math.log(val, 10) if val != 0 else 0)
        im.putpixel((x, y), (0, clr // 2, clr))

im.save("out.png", "PNG")
