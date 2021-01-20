
#include <stdio.h>
#include <string.h>

//Szyfrowanie
int cipher(char *text,char *result,int k1,int k2)
{
    int i,z=0;
    int l = strlen(text); // długość tekstu 
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
    return 0;
}

int main()
{
    char text[50]="";
    char result[50]="";
    int k1,k2;
    
    printf("Proszę wpisać tekst\n");
    scanf("%[^\n]",text);
   
        printf("Proszę wpisać klucz k1\n");
        scanf("%d",&k1);
        printf("Proszę wpisać klucz k2\n");
        scanf("%d",&k2);
        cipher(text,result,k1,k2);
        printf("Zaszyfrowany tekst jawny %s jest: %s\n",text,result);
    

    return 0;
   
    }