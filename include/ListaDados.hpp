#ifndef LISTADADOS_H
#define LISTADADOS_H

#include "../include/Celula.hpp"
#include "../include/Dado.hpp"

#include<string>
#include<iostream>

using namespace std;

class ListaDados
{ 
    public:
        ListaDados();
        ~ListaDados();
        Dado getDado(int pos);
        void setDado(Dado item, int pos);
        void insereInicio(Dado item);
        void insereFinal(Dado item);
        void inserePosicao(Dado item, int pos);
        Dado removeInicio();
        Dado removeFinal();
        Dado removePosicao(int pos);
        Dado Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
        int getTamanho() { return tamanho;};
        bool Vazia() { return tamanho == 0;};
        void addTamanho() { this->tamanho++; }

    private:
        int tamanho=0;
        Celula* primeiro;
        Celula* ultimo;
        Celula* Posiciona(int pos, bool antes);                   
};
#endif
