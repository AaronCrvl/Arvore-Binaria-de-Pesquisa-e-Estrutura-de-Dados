#ifndef CONSCIENCIA_H
#define CONSCIENCIA_H

#include "..\tp\include\ListaDados.hpp"

#include<string>
#include<iostream>

using namespace std;

class Consciencia
{                    
    public:                
        string getChave() { return this->Chave; }
        void setChave(string chave) { this->Chave; }
        ListaDados &getListaDados(){ return lista; }

    private:    
        string Chave= "ZZZ";      
        ListaDados lista;      
};
#endif