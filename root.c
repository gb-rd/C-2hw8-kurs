#include <stdio.h>
#include <math.h>
#include "root.h"

float root(function f, function g, float a, float b, float eps1) {

    int stepcount=0;

    while (fabs(b - a) > eps1) {

        a = b - (b - a) * (f(b) - g(b)) / (f(b) - g(b) - f(a) + g(a));
        b = a - (a - b) * (f(a) - g(a)) / (f(a) - g(a) - f(b) + g(b));
        stepcount++;
    }

        /* TODO: think how better to pass steps to print */
    if (!stepcount1)
        stepcount1 = stepcount;
    else if (!stepcount2)
        stepcount2 = stepcount;
    else if (!stepcount3)
        stepcount3 = stepcount;

    return b;
}
