#include "../include/Dado.hpp"

using namespace std;

Dado::Dado()
{
    chave = -1; // indica um item vazio
}

Dado::Dado(TipoChave c)
{
    chave = c;
}

void Dado::SetChave(TipoChave c)
{
    chave = c;
}

TipoChave Dado::GetChave()
{
    return chave;
}

void Dado::Imprime()
{
    printf("%d ",chave);
}

// !__Dado