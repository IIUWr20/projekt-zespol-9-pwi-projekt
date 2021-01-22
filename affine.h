#ifndef AFFINE_H_INCLUDED
#define AFFINE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 26
#define START_UPPER 'A'
#define END_UPPER 'Z'
#define START_LOWER 'a'
#define END_LOWER 'z'

char *decipher(char *text, int k1, int k2);
int modInverse(int a, int m);
int extendedGCD(int a, int b, int* x, int* y);
int checkRange(char c);

#endif
