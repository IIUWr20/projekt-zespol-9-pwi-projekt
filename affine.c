#include "affine.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *decipher(char *text, int k1, int k2)
{
	int l = strlen(text), i = 0, inv = modInverse(k1, LEN); 
	// calculate inverse of modulo function of k1 modulo LEN
	char *res = (char *) malloc(l), in; // used if user also wants output on screen
	FILE *f1 = fopen("input.txt", "r"), *f2 = fopen("output.txt", "w");
	// open two files, first containing input and second output

	while ((in = getc(f1)) != EOF) // read from file
	{
		int tmp;
		char c;
		int t = checkRange(text[i]); // check if uppercase, lowercase or something else

		// decipher and write to res
		switch(t)
		{
			case 0:
				c = text[i];
				break;
			case 1:
				tmp = (int) (text[i] - START_UPPER) - k2;
				c = (char) (((inv * tmp) % LEN + LEN)) % LEN + START_UPPER;
				break;
			case 2:
				tmp = (int) (text[i] - START_LOWER) - k2;
				c = (char) (((inv * tmp) % LEN + LEN)) % LEN + START_LOWER;
				break;
			default:
				printf(u8"Jakiś błąd");
		}

		res[i] = c;

		if (i < l)
		{
			++i;
		}

		t = checkRange(in);

		// same as above but write to file
		switch(t)
		{
			case 0:
				c = in;
				break;
			case 1:
				tmp = (int) (in - START_UPPER) - k2;
				c = (char) (((inv * tmp) % LEN + LEN)) % LEN + START_UPPER;
				break;
			case 2:
				tmp = (int) (in - START_LOWER) - k2;
				c = (char) (((inv * tmp) % LEN + LEN)) % LEN + START_LOWER;
				break;
			default:
				printf(u8"Jakiś błąd \n");
		}

		putc(c, f2);
	}

	fclose(f1);
	fclose(f2);

	return res;
}

int modInverse(int a, int m) // calculate inverse of first key modulo LEN
{ 
	int x, y; 
	int g = extendedGCD(a, m, &x, &y); 
	if (g != 1) 
	{
		printf(u8"Błąd, żądana wartość nie istnieje."); 
		exit(0);
	}

	int res = (x % m + m) % m; // this instead of just x % m to
	// avoid getting negative values, same as in decipher()
	return res;
 
} 

// recursive implementation of extended Euclid's algorithm
// to get the value of gcd and x
int extendedGCD(int a, int b, int* x, int* y) 
{ 
	if (a == 0) 
	{ 
		*x = 0, *y = 1; 
		return b; 
	} 

	int x1, y1;
	int gcd = extendedGCD(b % a, a, &x1, &y1); 

	*x = y1 - (b / a) * x1; 
	*y = x1; 

	return gcd; 
} 

// helper function for better readability to 
// check if uppercase, lowercase or something else
int checkRange(char c)
{
	if (c >= START_UPPER && c <= END_UPPER)
	{
		return 1;
	}

	if (c >= START_LOWER && c <= END_LOWER)
	{
		return 2;
	}

	return 0;
}
