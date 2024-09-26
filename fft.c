#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SMAPLE_N 8

float pi;

int main()
{
    pi = atan2f(1,1)*4;
    // printf("%.9lf\n",pi);
    // size_t n = 8;
    float in[SMAPLE_N];
    float out[SMAPLE_N];

    for (size_t i = 0; i < SMAPLE_N; i++)
    {
        float t = (float)i/SMAPLE_N;
        in[i] = sinf(2*pi*t*1) + sinf(2*pi*t*2);
    }

    for (size_t f = 0; f <SMAPLE_N; f++)
    {
        printf("%f\n",in[f]);
        out[f] = 0;
        for (size_t i = 0; i < SMAPLE_N; i++)
        {
            float t = (float)i/SMAPLE_N;
            out[f] += in[i]*sinf(2*pi*f*t);
        }
    }

    for (size_t f = 0; f < SMAPLE_N; f++)
    {
        printf("%02zu: %.2f\n",f,out[f]);
    }
    
    
    return 0;
}