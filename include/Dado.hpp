#ifndef DADO_H
#define DADO_H

#include<string>
#include<iostream>

using namespace std;
typedef int TipoChave;

class Dado
{    
    public:
        Dado();
        Dado(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();
    
    private:
        TipoChave chave;
        // outros membros           
};
#endif
