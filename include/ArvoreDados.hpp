#ifndef ARVOREDADOS_H
#define ARVOREDADOS_H

#include "../include/No.hpp"

#include<string>
#include<iostream>

using namespace std;
typedef string Chave;


class ArvoreDados {
  
  public:
    //Objeto que representa a raiz da árvore
    No * raiz;    
    //Retorna a referência para a raiz da árvore
    No *&getRaiz() { return this->raiz; }        
    //Busca um Nó de forma iterativa.
    No * BuscaIterativa(string v);
    //Deleta um Nó    
    No * DeletarNo(No * r, string v);
    //Pega o Nó de menor valor
    No * NoMinValor(No * node);
    //Caminhamento em ordem pela árvore
    void CaminhamentoCentral(No * r);
    //Inserir Nó
    void InsereNo(No * new_node);      
    //Caminhamento em ordem pela árvore 2
    void PrintaEmOrdem(No *r);      
    
  private:
    int nrRegistros = 0;
};
#endif