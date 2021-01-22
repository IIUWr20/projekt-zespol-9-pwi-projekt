#include "affine.h"
#include <stdio.h>

int main()
{
	char *text = "XZI xzi co to ja nie wiem"; // optional parameter, can be empty
	printf("%s\n", decipher(text, 7, 5)); // test function call
	return 0;
}
