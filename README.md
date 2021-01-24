# Projekt PWI zespołu 9 w języku C
To repozytorium zawiera program szyfrujący lub deszyfrujący wprowadzone 
wiadomości przy użyciu jednego z trzech szyfrów (Vigenère'a, afinicznego 
lub rosnącego) napisany w języku ANSI C w standardzie C11.

## Spis treści
- [Instalacja programu szyfrującego](#instalacja-programu-szyfrującego)
	- [Wymagania wstępne](#wymagania-wstępne)
		- [Linux](#linux)
		- [Windows](#windows)
		- [macOS](#macos)
	- [Pobieranie kodu i instalacja](#pobieranie-kodu-i-instalacja)
- [Użytkowanie](#użytkowanie)
	- [Szyfrowanie](#szyfrowanie)
		- [Szyfr afiniczny](#szyfr-afiniczny)
		- [Szyfr Vigenère'a](#szyfr-vigenèrea)
		- [Szyfr rosnący](#szyfr-rosnacy)
	- [Deszyfrowanie](#deszyfrowanie)
- [Autorzy](#autorzy)

## Instalacja programu szyfrującego
### Wymagania wstępne
#### Linux
- git >= 2.25.0
- gcc >= 9.0.0
- gtk >= 3.0

Ponieważ przy użyciu tych wersji technologii projekt był tworzony.
Żeby je pobrać wystarczy otworzyć terminal i wpisać:
```
sudo apt install git gcc libgtk-3-dev -y
```
na Ubuntu i pochodnych oraz:
```
sudo pacman -S git gcc gtk3
```
na Archu i pochodnych
#### Windows
- git >= 2.25.0
- gtk >= 3.0

Gita można pobrać z <https://git-scm.com/download/win>

A GTK z <https://www.gtk.org/docs/installations/windows/>
#### macOS
Program nie był testowany na macOS. Zapewne wymagałby jakiegoś 
kompilatora języka C i gita.

### Pobieranie kodu i instalacja
Pobieraie kodu wygląda tak samo na wszystkich platformach. 
Należy otworzyć terminal i wpisać poniższe komendy:
```
git clone https://github.com/IIUWr20/projekt-zespol-9-pwi-projekt
cd projekt-zespol-9-pwi-projekt
gcc gui.c mod.h func.c func.h `pkg-config --cflags --libs gtk+-3.0` -o program.out
```
## Użytkowanie
### Szyfrowanie
Program przyjmuje dwa pliki (należy wskazać ich lokalizację w interefejsie graficznym) i w zależności od wybranego szyfru odpowiednie
dodatkowe parametry. Operuje on na na alfabecie angielskim (52 różne znaki), wszystkie
znaki spoza tego zbioru nie będą szyfrowane tylko zostaną przepisane
do pliku wyjściowego.
#### Szyfr afiniczny
Żeby szyfrowanie zadziałało poprawnie należy dodatkowo podać dwie dodatnie liczby naturalne, z którym pierwsza nie może mieć żadnych 
dzielników wspólnych z 26, będące wartościami kluczy szyfrujących.

Więcej o szyfrze afinicznym na
<https://pl.wikipedia.org/wiki/Szyfr_afiniczny>
#### Szyfr Vigenère'a
Program przyjmuje klucz (będący ciągiem znaków alfabetu angielskiego). Ten sam klucz należy podać przy deszyfrowaniu.
Więcej o szyfrze Vigenère'a na
<https://pl.wikipedia.org/wiki/Szyfr_Vigen%C3%A8re%E2%80%99a>
#### Szyfr rosnący
Program przesuwa znak, jeśli jest to litera o n (początkowo n = 0) miejsc w kierunku rosnących liter. Jeśli przekroczy ostatnią literę alfabetu
to reszta przesunięcia dokonywana jest od pierwszej litery. Po każdym przesunięciu n jest inkrementowane o jeden. Jeśli n = 27, to z powrotem n = 0.
### Deszyfrowanie
Analogicznie jak w przypadku szyfrowania. Należy pamiętać o tym, by podać
odpowiednie parametry, przy użyciu których oryginalny tekst był zaszyfrowany.

## Autorzy
- Kacper Jóźwiak
- Krzysztof Rokicki
- Marcin Czapulak
- Filip Pazera
- Jana Waszkiewicz
- Igor Jarosz
