#include <stdio.h>
#include <string.h>
#include "help.h"
#include "root.h"
#include "integral.h"

#define FUNC1 (0.6*x + 3)
#define FUNC2 ((x-2)*(x-2)*(x-2)-1)
#define FUNC3 (3/x)
#define SHIFT 6    // move all figure to one side of x axis

    /* type for passing func to func */
typedef float(*function)(float);
    /* defines accuracy of calculation */
extern float eps;
    /* read arguments from console */
extern int parseArgs(int argc, char *argv[]);
    /* calc roots of two functions (intersections) */
extern float root(function f, function g, float a, float b, float eps);
    /* calc area of figure partition */
extern float integral(function f, float a, float b, float eps);

    /* output to console */
extern void printResults(float root1, float root2, float root3,
		         float area1, float area2, float area3, float areaFull);

float func1(float x) {
    return FUNC1-SHIFT;  // move function down
}
float func2(float x) {
    return FUNC2-SHIFT;  // move function down
}
float func3(float x) {
    return FUNC3-SHIFT;  // move function down
}


int main(int argc, char *argv[]) {
        /* if wrong args: exit */
    if(parseArgs(argc, argv))
        return -1;

        /* visually found aproximate intervals */
    float points[3][2] = {{-6, -5.5},{-1, -0.1},{3.5, 4}};

        /* calculate roots of pairs of functions from left to right */
    float root1 = root(func1, func3, points[0][0], points[0][1], eps);
    float root2 = root(func2, func3, points[1][0], points[1][1], eps);
    float root3 = root(func1, func2, points[2][0], points[2][1], eps);

        /* calculate areas of fugures shifted to one side of axis */
    float area1 = integral(func1, root1, root3, eps);
    float area2 = integral(func2, root2, root3, eps);
    float area3 = integral(func3, root1, root2, eps);

        /* calculate full area: cut unwanted areas */
    float areaFull = (area1-area2-area3);

        /* print results TODO: pass vars as struct? */
    printResults(root1, root2, root3, area1, area2, area3, areaFull);

    return 0;
}
