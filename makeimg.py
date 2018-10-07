import math
import struct

from PIL import Image
from PIL.ImageColor import getrgb

WIDTH = 2048
HEIGHT = 2048

with open("out10_6.bin", "rb") as f:
    buf = f.read()

ints = struct.unpack("i" * (WIDTH * HEIGHT), buf)
#print(sorted(ints, reverse=True)[:100])
#mx = max(ints)
mx = 1500

clr_mode = "NORMAL"

im = Image.new("RGB", (WIDTH, HEIGHT))
for y in range(HEIGHT):
    for x in range(WIDTH):
        val = ints[y * WIDTH + x]
        if clr_mode == "ALT":
            hue = int(val * 360 / mx)
            clr = getrgb(f"hsv({hue}, 100%, 50%)")
        else:
            b = int(val * 255 / mx)
            clr = (0, b // 2, b)
        #clr = int(20 * math.log(val, 10) if val != 0 else 0)
        im.putpixel((x, y), clr)

im.save("out10_6.png", "PNG")
