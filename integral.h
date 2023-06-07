/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __INTEGRAL_H
#define __INTEGRAL_H

typedef float(*function)(float);

float integral(function f, float a, float b, float eps2);

#endif /* __INTEGRAL_H */
