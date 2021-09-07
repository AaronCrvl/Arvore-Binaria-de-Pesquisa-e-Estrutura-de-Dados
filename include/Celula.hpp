#ifndef CELULA_H
#define CELULA_H

#include<string>
#include<iostream>

using namespace std;

class Celula
{           
    public:
        //Construtor padrão da classe
        Celula();
        //Retorna o ponteiro para a próxima celula da lista
        Celula *&getProx();
        //Retorna a variáveavl interna da classe
        int &getItem();
        //Seta a variável interna da classe
        void setItem(int item);
        //Seta o apontador para a próxima celula
        void setProx(Celula *p);
    
    private:
        Celula *prox;
        int item = 0;        

    friend class ListaEncadeada;    
};
#endif