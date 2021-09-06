#include "../include/ArvoreDados.hpp"
#include "../include/Consciencia.hpp"
#include "../include/No.hpp"

#include <string>
#include <iostream>

using namespace std;



/*
No *ArvoreDados::Pesquisa(Chave chave) 
{
    return PesquisaRecursivo(raiz, chave);
}

No *ArvoreDados::PesquisaRecursivo(No *no, Chave chave) 
{        
    if ( no == nullptr ) 
    {        
        //return no;
    }
    cout << "Aqui" << endl;
    if (chave < no->getConsciencia().getChave())
        return PesquisaRecursivo(no->getEsquerda(), chave);
    
    else if (chave>no->getConsciencia().getChave())
        return PesquisaRecursivo(no->getDireita(), chave);    
    
    else
        return no;
}

void ArvoreDados::Insere(No *no)
{
    InsereRecursivo(raiz, no->getConsciencia() );
}

void ArvoreDados::InsereRecursivo(No* &p, Consciencia c)
{ 
    if(p == nullptr){
        p = new No();
        p->setConscienca(c);
    }
    else
    {
    if(c.getChave() < p->getConsciencia().getChave())
        InsereRecursivo(p->getEsquerda(), c);
    else
        InsereRecursivo(p->getDireita(), c);
    }
}

void ArvoreDados::Remove(Chave chave) 
{
    return RemoveRecursivo(raiz, chave);
}

void ArvoreDados::RemoveRecursivo(No* &no, Chave chave)
{
    No *aux;
    if (no == NULL) {
    throw("Item nao está presente");
    }
    if (chave < no->getConsciencia().getChave())
        return RemoveRecursivo(no->getEsquerda(), chave);
    else if (chave>no->getConsciencia().getChave())
        return RemoveRecursivo(no->getDireita(), chave);
    else 
    {
        if (no->getDireita() == NULL) {
            aux = no;
            no = no->getEsquerda();
            free(aux);
        }
        else if(no->getEsquerda() == NULL) {
            aux = no;
            no = no->getDireita();
            free(aux);
        }
        else
        Antecessor(no, no->getDireita());
    }
}

void ArvoreDados::Antecessor(No *q, No* &r){
    
    if(r->getDireita() != NULL) {
        Antecessor(q, r->getDireita());
        return;
    }
    
    q->setConscienca(r->getConsciencia());
    q = r;
    r = r->getEsquerda();
    free(q);
}

void ArvoreDados::printInorder(No *no)
{
    if (no == NULL)
        return;
    
    cout << " aqui ";    
    printInorder(no->getEsquerda());
        
    cout << no->getConsciencia().getChave();
    cout << " ";
    cout << no->getConsciencia().getListaDados().getTamanho();
    cout << endl;
     
    printInorder(no->getDireita());
}
*/

// !__ArvoreDados