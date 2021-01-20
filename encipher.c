//C program enciphering a file with Vigenère cipher  

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//function enciphering an input file 
void vigenereEncipher(char* key, const char* in, const char* out) {
    FILE *file, *encipheredFile;
    // file - input file 
    // encipheredFile - encoded input file  
    // enckey key - file with a key to encipher input file up to 100 characters
    if ((file = fopen(in, "r"))==NULL) {
        printf("Otwarcie pliku tekst.txt nie było możliwe!\n");
        exit(1);
    }

    if ((encipheredFile = fopen(out, "w"))==NULL) {
        printf("Otwarcie pliku enctekst.txt nie było możliwe!\n");
        exit(1);
    }

    char* keyptr = key; //pointer on begining of enciphering key 
    char c; // variable storing character form input file processed at the moment
    int enc;
    
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) { //checking whether char is a letter or not
            if (islower(c)) { // checking if letter is uppercase or lowercase
                enc = ((int)c-97 + (int)tolower(*keyptr)-97) % 26;
                enc += 97;
            }
            else {
                enc = ((int)c-65 + (int)toupper(*keyptr)-65) % 26;
                enc += 65;
            }

            fputc((char)enc, encipheredFile);
        }

        else 
            fputc(c, encipheredFile);
        
        if (keyptr == "\0")
            keyptr = key;

        keyptr++;
    }
    

    fclose(file);
    fclose(encipheredFile);
}


int main () {
    vigenereEncipher("LEMONLEMONLE", "tekst.txt", "enctekst.txt");
    
    return 0;
}