#include "../include/Arquivo.hpp"
#include "../include/ArvoreDados.hpp"

#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

#pragma region Leitura de Dados

void Arquivo::leArquivo()
{
	try
	{		
    int linhas = 0;
		fstream leitor;
		string temp = "";
		ArvoreDados *arvore = new ArvoreDados();

		//Cria separador para leitura
		bool divisa = false, adnome = false, addado = false;
	
		//Inicia leitura.
    leitor.open(this->arquivo, ios:: in);
    if( linhas <= numeroLinhas )
    {
      while (getline(leitor, container))
      {
        //Marcador de primeira linha
        if( numeroLinhas == 0 ) { numeroLinhas = stoi(container); }            
        
        temp.clear();
        for (int i = 0; i < container.size(); ++i)
        {
          if (container[i] != ' ' && container[i] != '1' && container[i] != '0')
          {
            temp += container[i];
          }

          if (container[i] == ' ')
          {
            divisa = true;
            nomeTemp = temp;
            adnome = true;
            temp.clear();
          }
          else
          {
            if (divisa)
            {
              int ax = i;
              addado = true;

              while (ax < container.size())
              {
                temp += container[ax];
                ++ax;
              }

              //Convesão do Tipo em inteiro
              dadoTemp = stoi(temp);
              divisa = false;
              temp.clear();
              break;
            }
          }


          //Atribuição de dados
          if (adnome == true && addado == true)
          {
            // Se já existe esta consciência
            if (nomeTemp == arvore->Pesquisa(nomeTemp).getChave())
            {
              Dado d;
              d.SetChave(dadoTemp);
              arvore->Pesquisa(nomeTemp).getListaDados().insereFinal(d);
            }

            // Se não existe esta consciência
            else
            {
              Consciencia c;
              c.setChave(nomeTemp);
              Dado d;
              d.SetChave(dadoTemp);

              c.getListaDados().insereFinal(d);
              arvore->Insere(c);
            }            
          }	
          ++linhas;
        }
      }
    } 
    else {} 
	}
	catch (exception e)
	{
		throw e;
	}
}

#pragma endregion

// !__Arquivo