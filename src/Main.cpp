#include "../include/Arquivo.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// cd TP3ED\tp\src\
// g++ -o x Main.cpp Arquivo.cpp ArvoreDados.cpp Celula.cpp Dado.cpp ListaDados.cpp No.cpp

int main(int argc, char *argv[])
{
    Arquivo a;     
    a.SetArquivo(argv[1]);     
    a.leArquivo();
    return 0;
} 

// !__Main