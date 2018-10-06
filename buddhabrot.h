#ifndef BUDDHABROT_H
#define BUDDHANROT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>

#define HEIGHT 2048
#define WIDTH 2048
#define MAX_R 2.0
#define MAX_I 2.0
#define MIN_R -2.0
#define MIN_I -2.0
#define MAX_ITER 310
#define N_POINTS 1000000000
#define PROGRESS_BAR_LENGTH 50

#define IDX(x, y) (y * WIDTH + x)
#define RAND(min, max) ((max - min) * ((float) rand() / (float) RAND_MAX) + min)
#define POINT_I(i) ((int) (((i - MIN_I) / (MAX_I - MIN_I)) * HEIGHT))
#define POINT_R(r) ((int) (((r - MIN_R) / (MAX_R - MIN_R)) * WIDTH))

struct point {
    int x, y;
};

union bytes {
    int i;
    char chrs[4];
};

#endif /* BUDDHABROT_H */
