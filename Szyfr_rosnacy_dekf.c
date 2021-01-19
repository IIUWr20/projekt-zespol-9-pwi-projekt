#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Dekodowanie na pliku działa aktualnie na pliku o nazwie "tekst.txt" który musi się znajdować w tym samym folderze co program
int main()
{
    //Łączenie się z plikiem wejściowym
    FILE *plik=fopen("tekst.txt","r");
    int wartosc = 0;
    char znak=fgetc(plik);
    while(znak!=EOF)
    {
        //Sprawdzamy czy nie powrocilismy do pierwotnej litery
        if(wartosc==27)
            wartosc = 1;
        if(znak=='\n')
            wartosc--;
        //Sprawdzamy czy nasz znak jest duza litera
        if(znak >= 65 && znak <= 90)
        {
            //Sprawdzamy czy zdeszyfrowany znak bedzie litera
            if(znak - wartosc < 65)
                znak = znak - wartosc + 26;
            else
                znak = znak - wartosc;
        }

        //Sprawdzamy czy nasz znak jest mala litera
        if(znak >= 97 && znak <= 122)
        {
            //Sprawdzamy czy zdeszyfrowany znak bedzie litera
            if(znak - wartosc < 97)
                znak = znak - wartosc + 26;
            else
                znak = znak - wartosc;
        }
// Wypisujemy na konsolę odszyfrowany teskt jeśli trzeba mogę poprawić to aby działało z plikiem tj. wypisywało odszyfrowany tekst do nowego pliku
        wartosc++;
        printf("%c",znak);
        znak = fgetc(plik);
        // Zamyka program po wpisaniu znaku "/"
        if(znak==47)
        {
            fclose(plik);
            return 0;
        }
    }
    fclose(plik);
    return 0;
}
