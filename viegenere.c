#include "viegenere.h"
#include <stdio.h>
#include <ctype.h>

void vigenere_decipher(char* key, const char* in_path, const char* out_path)
{
    FILE* in_file = fopen(in_path, "r");
    FILE* out_file = fopen(out_path, "w");

    char* key_iter = key;

    char c;
    while ((c = getc(in_file)) != EOF)
    {
        if (c == ' ' || c == '\n') {
            putc(c, out_file);
            continue;
        }

        if (*key_iter == '\0')
            key_iter = key;

        char decipher_char = (tolower(c) - tolower(*key_iter) + 26) % 26;
        if (isupper(c))
            decipher_char += 'A';
        else
            decipher_char += 'a';

        putc(decipher_char, out_file);
        key_iter++;
    }

    fclose(out_file);
    fclose(in_file);
}