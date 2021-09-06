#ifndef CELULA_H
#define CELULA_H

#include "../include/Dado.hpp"

#include<string>
#include<iostream>

using namespace std;

class Celula
{           
    public:
        Celula();
        Celula *&getProx();
        Dado &getItem();
        void setItem(Dado item);
        void setProx(Celula *p);
    
    private:
        Dado item;
        Celula *prox;

    friend class ListaEncadeada;    
};
#endif