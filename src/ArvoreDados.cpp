#include "..\tp\include\ArvoreDados.hpp"
#include "..\tp\include\Consciencia.hpp"
#include "..\tp\include\No.hpp"

#include <string>
#include <iostream>

using namespace std;

Consciencia ArvoreDados::Pesquisa(Chave chave) 
{
    return PesquisaRecursivo(raiz, chave);
}

Consciencia ArvoreDados::PesquisaRecursivo(No *no, Chave chave) 
{
    
    Consciencia aux;
    if (no == NULL) {
        aux.setChave("ZZZ"); // Flag para item não presente
        return aux;
    }

    if (chave < no->getConsciencia().getChave())
    return PesquisaRecursivo(no->getEsquerda(), chave);
    else if (chave>no->getConsciencia().getChave())
    return PesquisaRecursivo(no->getDireita(), chave);    
    else
    return no->getConsciencia();
}

void ArvoreDados::Insere(Consciencia c)
{
    InsereRecursivo(raiz,c);
}

void ArvoreDados::InsereRecursivo(No* &p, Consciencia c)
{
    
    if(p==NULL){
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

// !__ArvoreDados