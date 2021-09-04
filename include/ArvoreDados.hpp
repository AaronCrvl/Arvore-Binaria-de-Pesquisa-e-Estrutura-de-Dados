#ifndef DADOS_H
#define DADOS_H

#include "..\tp\include\Consciencia.hpp"
#include "..\tp\include\No.hpp"

#include<string>
#include<iostream>

using namespace std;
typedef string Chave;

class ArvoreDados
{       
    public:
        ArvoreDados(){} //{ this->raiz = nullptr; }
        ~ArvoreDados();
        void Insere(Consciencia c);
        void Caminha(int tipo);
        Consciencia Pesquisa(Chave chave);
        void Remove(Chave chave);
        void Limpa();

    private:
        void InsereRecursivo(No* &p, Consciencia c);
        void ApagaRecursivo(No* p);
        Consciencia PesquisaRecursivo(No* p, Chave chave);
        void RemoveRecursivo(No* &p, Chave chave);
        void Antecessor(No* q, No* &r);
        void PorNivel();
        void PreOrdem(No* p);
        void InOrdem(No* p);
        void PosOrdem(No* p);
        No *raiz;         
};
#endif