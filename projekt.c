#include <stdio.h>
#include <string.h>

//Szyfrowanie
#define N 50
int main()
{
    char text[N];
    FILE *plik;
    plik=fopen("tekst.txt","r");
    FILE *wyjscie;
    wyjscie=fopen("nik.txt","w");

    fgets(text, N, plik);
    fprintf(stdout, "%s\n", text);

    char result[N];
    int k1,k2;
    k1=3;
    k2=5; 
    
   
    int i,z=0;
    int l = strlen(text); 
   // długość tekstu 

    for(i=0;i<l;i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z'){
            result[z]=(k1*(text[i]-'A')+k2)%26+'A';
        } else if (text[i] >= 'a' && text[i] <= 'z'){
            result[z]=(k1*(text[i]-'a')+k2)%26+'a';
        } else{
            result[z] = text[i];
        }
        z++;
    }
    int m=0;
    while(m<l){
    fprintf(wyjscie,"%c", result[m]);
    m++;}

    fclose(plik);
    fclose(wyjscie);


    return 0;

   }

