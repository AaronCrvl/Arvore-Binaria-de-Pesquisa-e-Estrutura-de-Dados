#include "../include/ListaDados.hpp"
#include "../include/Celula.hpp"
#include "../include/Dado.hpp"

using namespace std;

ListaDados::ListaDados() 
{
    primeiro = new Celula();
    ultimo = primeiro;
}

ListaDados::~ListaDados()
{
    Limpa();
    delete primeiro;
}

Celula* ListaDados::Posiciona(int pos, bool antes=false)
{
    Celula *p; int i;
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";
    // Posiciona na célula anterior a desejada
    p = primeiro;
    for(i=1; i<pos; i++)
    {
        p = p->getProx();
    }
    // vai para a próxima
    // se antes for false
    if(!antes)
    p = p->getProx();
    return p;
}

Dado ListaDados::getDado(int pos){
    Celula *p;
    p = Posiciona(pos);
    return p->getItem();
}

void ListaDados::setDado(Dado item, int pos){
    Celula *p;
    p = Posiciona(pos);
    p->setItem(item);
}

void ListaDados::insereInicio(Dado item)
{
    Celula *nova;
    nova = new Celula();
    nova->setItem(item);
    nova->setProx(primeiro->getProx());
    primeiro->setProx(nova);
    tamanho++;
    
    if(nova->getProx() == NULL)
        ultimo = nova;
}

void ListaDados::insereFinal(Dado item)
{    
    Celula *nova;
    nova = new Celula();
    nova->setItem(item);
    ultimo->setProx(nova);
    ultimo = nova;    
    tamanho++;
}

void ListaDados::inserePosicao(Dado item, int pos) {
    
    Celula *p, *nova;
    p = Posiciona(pos,true); // posiciona na célula anterior
    nova = new Celula();
    nova->setItem(item);
    nova->setProx(p->getProx());
    p->setProx(nova);
    tamanho++;

    if(nova->getProx() == NULL)
        ultimo = nova;
}

Dado ListaDados::removeInicio() {
    Dado aux;
    Celula *p;
    
    if (tamanho == 0)
    throw "ERRO: Lista vazia!";
    p = primeiro->getProx();
    primeiro->setProx(p->getProx());
    tamanho--;
    if(primeiro->getProx() == NULL)
        ultimo = primeiro;

    aux = p->getItem();
    delete p;
    return aux;
}

Dado ListaDados::removeFinal() {
    Dado aux;
    Celula *p;
    if (tamanho == 0)
    throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);
    p->setProx(NULL);
    tamanho--;
    aux = ultimo->getItem();
    delete ultimo;
    ultimo = p;
    return aux;
}

Dado ListaDados::removePosicao(int pos) {;
    Dado aux;
    Celula *p, *q;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->getProx();
    p->setProx(q->getProx());
    tamanho--;
    aux = q->getItem();
    delete q;

    if(p->getProx() == NULL)
        ultimo = p;

    return aux;
}

Dado ListaDados::Pesquisa(TipoChave c) {
    Dado aux;
    Celula *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    p = primeiro->getProx();
    aux.SetChave(-1);

    while (p!=NULL) 
    {
        if (p->getItem().GetChave() == c) 
        {
            aux = p->getItem();
            break;
        }
        
        p = p->getProx();
    }
    return aux;
}

void ListaDados::Imprime()
{
    Celula *p;
    p = primeiro->getProx();
    while (p!=NULL)
    {
        p->getItem().Imprime();
        p = p->getProx();
    }
    //printf("\n");
}

void ListaDados::Limpa() 
{
    Celula *p;
    p = primeiro->getProx();

    while (p!=NULL) 
    {
        primeiro->setProx(p->getProx());
        delete p;
        p = primeiro->getProx();
    }
    
    ultimo = primeiro;
    tamanho = 0;
}

// !__ListaDados