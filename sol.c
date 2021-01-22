#include "affine.h"
#include <stdio.h>

int main()
{
	char *text = "XZI xzi co to ja nie wiem";
	printf("%s\n", decipher(text, 7, 5));
	return 0;
}
