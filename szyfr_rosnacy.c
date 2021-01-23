#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//funkcja szyfrująca
void szyfr_rosnacy(const char* in, const char* out)
{
    FILE *plik=fopen(in,"r");
    FILE *wyjscie=fopen(out,"w");
    int wartosc = 0;
    char znak=fgetc(plik);
    while(znak!=EOF){
        //Sprawdzamy czy nie powrocilismy do pierwotnej litery
        if(wartosc==27)
            wartosc = 1;
        if(znak=='\n')
        {
            wartosc--;
        }
        //Sprawdzamy czy nasz znak jest duza litera
        if(znak >= 65 && znak <= 90)
        {
            //Sprawdzamy czy zaszyfrowany znak bedzie litera
            if(znak + wartosc > 90)
                znak = znak + wartosc - 26;
            else
                znak = znak + wartosc;
        }

        //Sprawdzamy czy nasz znak jest mala litera
        if(znak >= 97 && znak <= 122)
        {
            //Sprawdzamy czy zaszyfrowany znak bedzie litera
            if(znak + wartosc > 122)
                znak = znak + wartosc - 26;
            else
                znak = znak + wartosc;
        }

        wartosc++;
        fprintf(wyjscie,"%c",znak);
        znak = getc(plik);
    }
    fclose(plik);
    fclose(wyjscie);
}

int main() {
 
    return 0;
}
