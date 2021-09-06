#ifndef ARVOREDADOS_H
#define ARVOREDADOS_H

#include "../include/Consciencia.hpp"
#include "../include/No.hpp"

#include<string>
#include<iostream>

using namespace std;
typedef string Chave;


class ArvoreDados {
  public:
    No * raiz;
  ArvoreDados() {
    raiz = NULL;
    //int SPACE = 0;
  }

  No *&getRaiz() { return this->raiz; }
  void addNr() { nrRegistros += 1; }
  int getNr() { return this->nrRegistros; }

  bool isTreeEmpty() {
    if (raiz == NULL) {
      return true;
    } else {
      return false;
    }
  }

  void insertNode(No * new_node);
  No* insertRecursive(No *r, No *new_node);

  void printPreorder(No * r);
  void printInorder(No * r);
  void printInorder(No * r, int tipo);

  void printPostorder(No * r);

  No * iterativeSearch(string v);

  No * recursiveSearch(No * r, string val) {
    if (r == NULL || r ->getChave() == val)
      return r;

    else if (val < r -> getChave())
      return recursiveSearch(r -> getEsquerda(), val);

    else
      return recursiveSearch(r -> getDireita(), val);
  }

  /*
  No * deleteNode(No * r, int v) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the raiz's key, 
    // then it lies in left subtree 
    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the raiz's key, 
    // then it lies in right subtree 
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as raiz's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> left == NULL) {
        No * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        No * temp = r -> left;
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        No * temp = minValueNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> value = temp -> value;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    }
    return r;
  }*/

  private:
    int nrRegistros = 0;

};
#endif

/*
class ArvoreDados
{       
    public:
        ArvoreDados(){ raiz = NULL; } //{ this->raiz = nullptr; }
        ~ArvoreDados(){};
        ArvoreDados& insert(string val);
        bool search(string val);

    private:        
        No *raiz;         
};
#endif
*/
/*
class ArvoreDados
{       
    public:
        ArvoreDados(){} //{ this->raiz = nullptr; }
        ~ArvoreDados(){};
        void Insere(No *no);
        void Caminha(int tipo);
        No *Pesquisa(Chave chave);
        void Remove(Chave chave);
        void Limpa();
        void printInorder(No *raiz);
        No *getRaiz(){ return this->raiz; }

    private:
        void InsereRecursivo(No* &p, Consciencia c);
        void ApagaRecursivo(No* p);
        No *PesquisaRecursivo(No* p, Chave chave);
        void RemoveRecursivo(No* &p, Chave chave);
        void Antecessor(No* q, No* &r);
        void PorNivel();
        void PreOrdem(No* p);
        void InOrdem(No* p);
        void PosOrdem(No* p);
        No *raiz;         
};
#endif
*/