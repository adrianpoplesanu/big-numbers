# big-numbers
BigNumbers programming language

Librarie de calcul cu numere mari.

Cifrele sunt intregi dintr-un vector de cifre.
Adunare, scadere, inmultire, impartire, operatori de eglitate si ordine.

usage: 
downloadat big_numbers.h si big_numbers.cpp 
incluse fisierele in sursa C++

exemplu:

#include "big_numbers.h" 
#include "big_numbers.cpp"

BigNumber numar1, numar2, numar3;
numar1.LoadFromString("4485056798238794858723498748675689758964596");
numar2.LoadFromString("1875434579834598567495864934334678465875984");
numar3 = numar1 + numar2;
numar3.PrintNumber();

TODO: Do a programming language that uses this!

Compilare pe Windows:
D:\Documents\git-projects\personal-work\cpp\problems\big_numbers>"D:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\mingw32-make.exe"

Clean-up proiect pe Windows:
D:\Documents\git-projects\personal-work\cpp\problems\big_numbers>"D:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\mingw32-make.exe" clean-win

Unde se afla compilatorul(MinGW)
D:\Documents\git-projects\personal-work\cpp\problems\big_numbers>where g++
D:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe