#include<stdio.h>
#include<stdlib.h>
//dekodowanie
int main()
{
    FILE *plik1=fopen("test.txt","w");
    char a=(char)getchar();
    fprintf(plik1,"%c",a);
    FILE *wejscie1=fopen("test.txt","r");
    while(a!='\n')
    {
        a=(char)getchar();
        fprintf(plik1,"%c",a);
    }
    fclose(plik1);
    char b;
    fscanf(wejscie1,"%c",&b);
    printf("%c",b);
    int c=0;
    while(b!='\n')
    {
        fscanf(wejscie1,"%c",&b);

        printf("%c",b);
        c++;
    }
    fclose(wejscie1);
}
