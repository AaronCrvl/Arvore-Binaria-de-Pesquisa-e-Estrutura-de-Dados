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
        int &getItem();
        void setItem(int item);
        void setProx(Celula *p);
    
    private:
        int item = 0;
        Celula *prox;

    friend class ListaEncadeada;    
};
#endif