#ifndef LISTADADOS_H
#define LISTADADOS_H

#include "../include/Celula.hpp"

#include<string>
#include<iostream>

using namespace std;

class ListaDados
{ 
    public:
        //Construtor padrão da classe
        ListaDados();
        //Destrutor padrão da classe
        ~ListaDados();                
        //Inseri dado ao final de lista        
        void insereFinal(int item);
        //Incrementar o tamanho da lista        
        void addTamanho() { this->tamanho++; }
        //Soma os dados da lista
        int Soma();
        //Retorna o tamanho da lista
        int getTamanho() { return tamanho;}; 
        //Verificar se a lista está vazia       
        bool Vazia() { return tamanho == 0;};

    private:
        int tamanho=0;
        Celula* primeiro;
        Celula* ultimo;
        Celula* Posiciona(int pos, bool antes);                   
};
#endif
