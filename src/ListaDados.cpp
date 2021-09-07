#include "../include/ListaDados.hpp"
#include "../include/Celula.hpp"

using namespace std;

#include <string>
#include <string.h>

#pragma region Métodos da Classe

ListaDados::ListaDados() 
{
    primeiro = new Celula();
    ultimo = primeiro;
}

ListaDados::~ListaDados()
{
    //Limpa();
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
void ListaDados::insereFinal(int item)
{        
    Celula *nova;
    nova = new Celula();
    nova->setItem(item);
    ultimo->setProx(nova);
    ultimo = nova;    
    tamanho++;  
}

int ListaDados::Soma()
{
    Celula *p;
    p = primeiro->getProx();
    int a = 0;
    while (p!=NULL)
    {
        a += p->getItem();
        p = p->getProx();
    }    

    return a;
}


#pragma endregion

// !__ListaDados