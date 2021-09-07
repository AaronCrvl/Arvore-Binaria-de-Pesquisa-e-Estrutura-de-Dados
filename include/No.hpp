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
        ListaDados &getLista (){ return this->lista; }
        void setConscienca(ListaDados l){ this-> lista = l; }

        No *&getEsquerda(){ return this->esq; }
        No *&getDireita(){ return this->dir; }
        string getChave(){ return this->Chave; }
        void setChave(string c){ this->Chave = c; }
        void setEsquerda(No *esq) { this->esq = esq; }
        void setDireita(No *dir) { this->dir = dir; }
        void addNr(int n) { SomaReg += n; }
        int getNr() { return this->SomaReg; }

    private:
        string Chave = "";
        ListaDados lista;
        No *esq;
        No *dir;
        int SomaReg = 0;
        
    friend class ArvoreBinaria;              
};
#endif