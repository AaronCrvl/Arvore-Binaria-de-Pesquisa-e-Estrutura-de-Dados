#include "..\tp\include\Celula.hpp"
#include "..\tp\include\Dado.hpp"

using namespace std;

Celula::Celula()
{
    item.SetChave(-1);
    prox = NULL;
}

Celula *&Celula::getProx()
{
    return this->prox;
}

Dado &Celula::getItem()
{
    return this->item;
}

void Celula::setItem(Dado item)
{
    this->item = item;
}

void Celula::setProx(Celula *p)
{
    this->prox = p;
}

// !__Celula