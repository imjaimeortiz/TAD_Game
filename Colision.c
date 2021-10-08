#include "Colision.h"
#include <math.h>

int Colision (int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    double cx1=(double)x1+(double)w1/2.0;
    double cy1=(double)y1+(double)h1/2.0;
    double cx2=(double)x2+(double)w2/2;
    double cy2=(double)y2+(double)h2/2;
    double r1=(double)w1/2;
    double r2=(double)w2/2;
    return sqrt(pow(cx1-cx2,2)+pow(cy1-cy2,2))<r1+r2;
}
