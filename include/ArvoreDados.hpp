#ifndef ARVOREDADOS_H
#define ARVOREDADOS_H

#include "../include/No.hpp"

#include<string>
#include<iostream>

using namespace std;
typedef string Chave;


class ArvoreDados {
  public:
    No * raiz;    
    No *&getRaiz() { return this->raiz; }
    No * insertRecursive(No *r, No *new_node);
    No * iterativeSearch(string v);
    No * recursiveSearch(No * r, string val);  
    No * deleteNode(No * r, int v);
    No * deleteNode(No * r, string v);
    No * minValueNode(No * node);
    void WalkInOrder(No * r);
    void insertNode(No * new_node);  
    void printPreorder(No * r);
    void printInorder(No *r);
    void printInorder(No * r, int tipo);
    void printPostorder(No * r);
    
  private:
    int nrRegistros = 0;
};
#endif