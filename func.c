//PWI Project
//Program using various ciphers to either encipher a file given by the user or decipher it

#include "mod.h"
#include "func.h"

//funkcja deszyfrujaca
void de_szyfr_rosnacy(const char* in, const char* out)
{
     //Łączenie się z plikiem wejściowym
    FILE *plik=fopen(in,"r");
    FILE *wyjscie=fopen(out,"w");
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
        fprintf(wyjscie,"%c",znak);
        znak = fgetc(plik);
        // Zamyka program po wpisaniu znaku "/"
        if(znak==47)
        {
            fclose(plik);
            return;
        }
    }
    fclose(plik);
    fclose(wyjscie);
}

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

// function enciphering an input file with Vigenere cipher
// key is used to encipher a file that user types in, in is input file name, out is output file name
void vigenereEncipher(char* key, const char* in, const char* out) {
    FILE *file, *encipheredFile;
    // file - input file
    // encipheredFile - cipher file
    if ((file = fopen(in, "r"))==NULL) {
        printf("Otwarcie pliku %s nie było możliwe!\n", in);
        exit(1);
    }

    if ((encipheredFile = fopen(out, "w"))==NULL) {
        printf("Otwarcie pliku %s nie było możliwe!\n", out);
        exit(1);
    }

    char* keyptr = key; //pointer to keyword
    char c; // variable storing character fromm input file processed at the moment
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

        if (keyptr == NULL)
            keyptr = key;

        keyptr++;
    }


    fclose(file);
    fclose(encipheredFile);
}

// function deciphering file ciphered with Vigenere
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

// function deciphering affine ciphered file
void decipher(const char* in_path, const char* out_path, int k1, int k2)
{
	int inv = modInverse(k1, LEN);
	// calculate inverse of modulo function of k1 modulo LEN
	FILE *f1 = fopen(in_path, "r"), *f2 = fopen(out_path, "w");
	// open two files, first containing input and second output
	char in;

	while ((in = getc(f1)) != EOF) // read from file
	{
		int tmp;
		char c;
		int t;

		t = checkRange(in);

		// write to file
		switch(t)
		{
			case 0:
				c = in;
				break;
			case 1:
				tmp = (int) (in - START_UPPER) - k2;
				c = (char) (((inv * tmp) % LEN + LEN)) % LEN + START_UPPER;
				break;
			case 2:
				tmp = (int) (in - START_LOWER) - k2;
				c = (char) (((inv * tmp) % LEN + LEN)) % LEN + START_LOWER;
				break;
			default:
				printf(u8"Jakiś błąd \n");
		}

		putc(c, f2);
	}

	fclose(f1);
	fclose(f2);

}

int modInverse(int a, int m) // calculate inverse of first key modulo LEN
{
	int x, y;
	int g = extendedGCD(a, m, &x, &y);
	if (g != 1)
	{
		printf(u8"Błąd, żądana wartość nie istnieje.");
		exit(0);
	}

	int res = (x % m + m) % m; // this instead of just x % m to
	// avoid getting negative values, same as in decipher()
	return res;

}

// recursive implementation of extended Euclid's algorithm
// to get the value of gcd and x
int extendedGCD(int a, int b, int* x, int* y)
{
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}

	int x1, y1;
	int gcd = extendedGCD(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

// helper function for better readability to
// check if uppercase, lowercase or something else
int checkRange(char c)
{
	if (c >= START_UPPER && c <= END_UPPER)
	{
		return 1;
	}

	if (c >= START_LOWER && c <= END_LOWER)
	{
		return 2;
	}

	return 0;
}


