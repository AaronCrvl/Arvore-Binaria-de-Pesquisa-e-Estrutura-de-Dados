#ifndef NO_H
#define NO_H

#include "../include/Consciencia.hpp"

#include<string>
#include<iostream>

using namespace std;

class No
{                    
    public:
        No();
        ~No(){}

        //Passar por referência ou não ??????
        Consciencia &getConsciencia (){ return this->consciencia; }
        void setConscienca(Consciencia c){ this-> consciencia = c; }

        No *&getEsquerda(){ return this->esq; }
        No *&getDireita(){ return this->dir; }
        string getChave(){ return this->Chave; }
        void setChave(string c){ this->Chave = c; }
        void setEsquerda(No *esq) { this->esq = esq; }
        void setDireita(No *dir) { this->dir = dir; }

    private:
        string Chave = "";
        Consciencia consciencia;
        No *esq;
        No *dir;
        
    friend class ArvoreBinaria;              
};
#endif