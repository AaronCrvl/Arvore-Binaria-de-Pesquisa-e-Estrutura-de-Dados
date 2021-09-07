#ifndef NO_H
#define NO_H

#include "../include/ListaDados.hpp"
#include<string>
#include<iostream>

using namespace std;

class No
{                    
    public:
        //Construtor padrão da classe
        No();
        //Destrutor padrão da classe
        ~No()
        {
            this->esq = NULL;
            this->dir = NULL;
        }
        //Retorna a referência da lista de dados presente neste Nó
        ListaDados &getLista (){ return this->lista; }        
        //Retorna a referência para o galho à esquerda
        No *&getEsquerda(){ return this->esq; }
        //Retorna a referência para o galho à esquerda
        No *&getDireita(){ return this->dir; }
        //Retorna a chave do Nó
        string getChave(){ return this->Chave; }
        //Seta valores para a chave do Nó
        void setChave(string c){ this->Chave = c; }
        //Seta o galho esquerdo
        void setEsquerda(No *esq) { this->esq = esq; }
        //Seta o galho direito
        void setDireita(No *dir) { this->dir = dir; }
        //Faz a soma dos valores da lista
        void addNr(int n) { SomaReg += n; }
        //Retorna a soma dos valores da lista
        int getNr() { return this->SomaReg; }

    private:
        ListaDados lista;
        No *esq;
        No *dir;
        string Chave = "";
        int SomaReg = 0;

    friend class ArvoreBinaria;              
};
#endif