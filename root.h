/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ROOT_H
#define __ROOT_H
    /* for counting steps as root() can't change root() func */
extern int stepcount1, stepcount2, stepcount3;

typedef float(*function)(float);
float root(function f, function g, float a, float b, float eps1);

#endif /* __ROOT_H */
