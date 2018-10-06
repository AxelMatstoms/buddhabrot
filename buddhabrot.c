#include "buddhabrot.h"

int main(int argc, char **argv)
{
    char *fn = "out";
    if (argc == 2) {
	fn = argv[1];
    }
    srand(time(NULL));
    int *pixels = malloc(WIDTH * HEIGHT * sizeof(int));
    struct point *points = malloc(MAX_ITER * sizeof(struct point));
    int points_idx = 0;
    for (int i = 0; i < N_POINTS; ++i) {

	float cr = RAND(MIN_R, MAX_R);
	float ci = RAND(MIN_I, MAX_I);
	float zr = 0;
	float zi = 0;
	int itr = 0;
	points_idx = 0;
	while (zr * zr + zi * zi < 4) {
	    if (itr >= MAX_ITER) {
		break;
	    }

	    float tmp = zr;
	    zr = zr * zr - zi * zi + cr;
	    zi = 2 * tmp * zi + ci;
	    if (zr > MIN_R && zr < MAX_R && zi > MIN_R && zi < MAX_R) {
		int x = POINT_R(zr);
		int y = POINT_I(zi);
		points[points_idx].x = x;
		points[points_idx].y = y;
		++points_idx;
	    }
	    
	    ++itr;
	}

	if (itr < MAX_ITER) {
	    for (int k = 0; k < points_idx; ++k) {
		struct point p = points[k];

		pixels[IDX(p.x, p.y)]++;
	    }
	}
    }
    FILE *fp = fopen(fn, "wb");
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
	union bytes b;
	b.i = pixels[i];
	fputc(b.chrs[0], fp);
	fputc(b.chrs[1], fp);
	fputc(b.chrs[2], fp);
	fputc(b.chrs[3], fp);
    }
    free(pixels);
    fclose(fp);
}
