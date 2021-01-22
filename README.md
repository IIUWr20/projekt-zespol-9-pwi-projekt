 Projekt PWI zespołu 9 w języku C
To repozytorium zawiera program szyfrujący lub deszyfrujący wprowadzone 
wiadomości przy użyciu jednego z trzech szyfrów (Vigenera, afinicznego 
lub placeholder) napisany w języku ANSI C w standardzie C11.

## Spis treści
- [Instalacja programu szyfrującego](#instalacja-programu-szyfrującego)
	- [Wymagania wstępne](#wymagania-wstępne)
		- [Linux](#linux)
		- [Windows](#windows)
		- [macOS](#macos)
	- [Pobieranie kodu](#pobieranie-kodu-i-instalacja)
- [Użytkowanie](#użytkowanie)
	- [Szyfrowanie](#szyfrowanie)
		- [Szyfr afiniczny](#szyfr-afiniczny)
		- [Szyfr Vigenèr'a](#szyfr-vigenèra)
	- [Deszyfrowanie](#deszyfrowanie)
- [Autorzy](#autorzy)

## Instalacja programu szyfrującego
### Wymagania wstępne
#### Linux
- git (preferowalnie) >= 2.25.0
- gcc (preferowalnie) >= 9.0.0

Ponieważ przy użyciu tych wersji technologii projekt był tworzony.
Żeby je pobrać wystarczy otworzyć terminal i wpisać:
```
sudo apt install git gcc -y
```
na Ubuntu i pochodnych oraz:
```
sudo pacman -S git gcc
```
na Archu i pochodnych
#### Windows
- git

Można go pobrać z <https://git-scm.com/download/win>
#### macOS
Program nie był testowany na macOS. Zapewne wymagałby jakiegoś 
kompilatora języka C i gita.

### Pobieranie kodu i instalacja
Pobieraie kodu wygląda tak samo na wszystkich platformach. 
Należy otworzyć terminal i wpisać poniższe komendy:
```
git clone https://github.com/IIUWr20/projekt-zespol-9-pwi-projekt
cd projekt-zespol-9-pwi-projekt
gcc -std=c11 -o program program.c affine.c itd..
```
## Użytkowanie
### Szyfrowanie
#### Szyfr afiniczny
Program przyjmuje plik z tekstem do zaszyfrowania
oraz $a, b \in \mathbb{N} \setminus \{0\}$, gdzie są to parametry 
funkcji szyfrującej $f(x) = ax + b \ \text{mod} \ m$ ($m$ to rozmiar 
alfabetu, w tym programie $m = 26$).

Więcej o szyfrze afinicznym na
<https://pl.wikipedia.org/wiki/Szyfr_afiniczny>
#### Szyfr Vigenèr'a
Więcej o szyfrze Vigenèra na
<https://pl.wikipedia.org/wiki/Szyfr_Vigen%C3%A8re%E2%80%99a>
### Deszyfrowanie
Żeby odszyfrować wiadomość należy podać programowi lokalizację pliku 
wejściowego z zaszyfrowananym tekstem oraz preferowaną lokalizację pliku wyjściowego. 
Należy także podać klucz, przy użyciu którego oryginalny tekst był
przekształcony.

## Autorzy
- Kacper Jóźwiak
- Krzysztof Rokicki
- Marcin Czapulak
- Filip Pazera
- Jana Waszkiewicz
- Igor Jarosz
