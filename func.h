#ifndef FOO_DOT_H
#define FOO_DOT_H

void de_szyfr_rosnacy (const char* in, const char* out);
void szyfr_rosnacy(const char* in, const char* out);
void vigenereEncipher(char* key, const char* in, const char* out);
void vigenere_decipher(char* key, const char* in_path, const char* out_path);
char *decipher(const char* in_path, const char* out_path, char *text, int k1, int k2)

#endif
