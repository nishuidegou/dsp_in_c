#include "math.h"
#include "dsp.h"

/*
 *
 * 
 */
void dft(double *x, double *y, double *a, double *b, int n, int sign)
{
    int i, k;
    double c, d, q, w, s;
    q = 6.28318530718/n;

    for (k = 0; k < n; k++)
    {
        w = k * q;
        a[k] =  b[k] = 0.0;
        for(i = 0; i < n; i++)
        {
            d = i * w;
            c = cos(d);
            s = sin(d) * sign;

            a[k] += c * x[i] + s * y[i];
            b[k] += c * y[i] - s * x[i];
        }
    }

    if(sign == -1)
    {
        c = 1.0/n;
        for(k = 0; k < n; k++)
        {
            a[k] = c * a[k];
            b[k] = c * b[k];
        }
    }

}