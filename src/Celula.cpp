#include "../include/Celula.hpp"
#include "../include/Dado.hpp"

using namespace std;

Celula::Celula()
{
    item = -1;
    prox = NULL;
}

Celula *&Celula::getProx()
{
    return this->prox;
}

int &Celula::getItem()
{
    return this->item;
}

void Celula::setItem(int item)
{
    this->item = item;
}

void Celula::setProx(Celula *p)
{
    this->prox = p;
}

// !__Celula