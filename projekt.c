#include <stdio.h>
#include <stdlib.h>

void szyfr_afiniczny(const char* in, const char* out)
{
FILE *plik;
FILE *wyjscie;
wyjscie=fopen(out,"w");

char text;

if ((plik = fopen("tekst.txt","r")) == NULL)
{
printf("Error opening file ");
exit(1); /* wyjście z programu w 
przypadku błędu otwarcia pliku tekst.txt*/
}

while(feof(plik)==0)
{
text = fgetc(plik); 
    
char result;
    int k1,k2;
    k1=3;
    k2=5; 
    

        if (text >= 'A' && text <= 'Z'){
            result=(k1*(text-'A')+k2)%26+'A';
        } else if (text >= 'a' && text <= 'z'){
            result=(k1*(text-'a')+k2)%26+'a';
        } else{
            result = text;
        }
    

     fprintf(wyjscie,"%c",result);
     
}

fclose(plik);
fclose(wyjscie);
}
