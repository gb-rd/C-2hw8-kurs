#include <stdio.h>
#include "integral.h"

float integral(function f, float a, float b, float eps2) {

    float sum = 0;
    float h = (b-a)*eps2;

    for(float x=a+h; x<b-h; x+=h) {
        sum += h/6.0*(f(x) + 4.0*f(0.5*(x+x+h)) + f(x+h));
    }

    return sum;
}
