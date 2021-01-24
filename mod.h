// file containing definitions and constants
// to make use of modularity
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#ifndef AFFINE_H_INCLUDED
#define AFFINE_H_INCLUDED

#define LEN 26
#define START_UPPER 'A'
#define END_UPPER 'Z'
#define START_LOWER 'a'
#define END_LOWER 'z'

void decipher(const char* in_path, const char* out_path, int k1, int k2);
int modInverse(int a, int m);
int extendedGCD(int a, int b, int* x, int* y);
int checkRange(char c);

#endif

#ifndef PROJEKT_ZESPOL_9_PWI_PROJEKT_VIEGENERE_H
#define PROJEKT_ZESPOL_9_PWI_PROJEKT_VIEGENERE_H

void vigenere_decipher(char* key, const char* in_path, const char* out_path);
#endif //PROJEKT_ZESPOL_9_PWI_PROJEKT_VIEGENERE_H

