import math
import struct
import sys

from PIL import Image

WIDTH = 2048
HEIGHT = 2048

fns = sys.argv[1:]
assert(len(fns) == 3)
imgs = []

for fn in fns:
    with open(fn, "rb") as f:
        buf = f.read()
    imgs.append(struct.unpack("i" * (WIDTH * HEIGHT), buf))
#print(sorted(ints, reverse=True)[:100])
mxs = [max(ints) for ints in imgs]

im = Image.new("RGB", (WIDTH, HEIGHT))
for y in range(HEIGHT):
    for x in range(WIDTH):
        idx = y * WIDTH + x
        #val = ints[y * WIDTH + x]
        r, g, b = [int(imgs[i][idx] * 255 / mxs[i]) for i in range(len(imgs))]
        #clr = int(val * 255 / mx)
        #clr = int(20 * math.log(val, 10) if val != 0 else 0)
        im.putpixel((x, y), (r, g, b))

im.save("out_nebula.png", "PNG")
