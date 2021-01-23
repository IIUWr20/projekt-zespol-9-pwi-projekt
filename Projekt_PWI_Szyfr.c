#include<stdio.h>
#include<stdlib.h>
//dekodowanie
void dek_szyfr_rosnacy(const char* in, const char* out)
{
    FILE *plik1=fopen(in,"w");
    char a=(char)getchar();
    //fprintf(plik1,"%c",a);
    FILE *wejscie1=fopen(out,"r");
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

int main() {
    
    return 0;
}
