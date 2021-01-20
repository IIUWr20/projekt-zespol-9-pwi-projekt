#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 26

char *decipher(char *text, int k1, int k2);
int modInverse(int a, int m) ;
int extendedGCD(int a, int b, int* x, int* y);

int main()
{
	char *text = "XZI xzi";
	printf("%s\n", decipher(text, 7, 5));
}

char *decipher(char *text, int k1, int k2)
{
	int l = strlen(text);
	char* res = (char *) malloc(l);
	int inv = modInverse(k1, LEN);

	for (int i = 0; i < l; ++i)
	{
		if (text[i] >= 'A' && text[i] <= 'Z')
		{
			int tmp = (int) (text[i] - 'A') - k2;
			res[i] = (char) ((inv * tmp) % LEN) + 'A';
		}

		else if (text[i] >= 'a' && text[i] <= 'z')
		{
			int tmp = (int) (text[i] - 'a') - k2;
			res[i] = (char) ((inv * tmp) % LEN) + 'a';
		}
		
		else
		{
			res[i] = text[i];
		}
	}

	return res;
}

int modInverse(int a, int m) 
{ 
	int x, y; 
	int g = extendedGCD(a, m, &x, &y); 
	if (g != 1) 
	{
		printf(u8"Błąd, żądana wartość nie istnieje."); 
		exit(0);
	}

	int res = (x % m + m) % m; 
	return res;
 
} 

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
