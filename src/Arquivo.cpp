#include "../include/Arquivo.hpp"
#include "../include/ArvoreDados.hpp"
#include "../include/No.hpp"

#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

#pragma ragion  Funções Auxiliares

void ImprimeChaves(string *chaves)
{
  while (int x = 0 < chaves->size())  
  {
    cout << chaves[x];
    cout << " ";
  }  
}

#pragma endregion

#pragma region Leitura de Dados

void Arquivo::leArquivo()
{	
    int linhas = 0;
		fstream leitor;    
		string temp = "";
    int linhasparaleitura = 0;
		ArvoreDados arvore;

		//Cria separador para leitura
		bool divisa = false, adnome = false, addado = false;
	
		//Inicia leitura.
    leitor.open(this->arquivo, ios::in);

    //Inicia leitura.
    while (getline(leitor, container))
    {
      string a = container;
      if (linhas == 0)
      {
       linhasparaleitura = std::stoi(a);      
      }            

      //Monitoramento de linhas lidas               
      if( linhas != linhasparaleitura )
      {
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
              dadoTemp = stoi(temp, 0, 2);
              divisa = false;
              temp.clear();
              break;
            }
          }
          
          //Atribuição de dados
          if (adnome == true && addado == true) 
          {            
            //se não existir a conciencia
            //arvore.Pesquisa(nomeTemp).getChave() == nomeTemp
            if( 1 == 1 )
            {
              No *no = new No();
              no->setChave(nomeTemp);                                                    
              cout << no->getChave() << endl;
              arvore.insertNode(no);
            }          
            else{}               
            adnome = false;
            addado = false;         
          } 
          else {}
        }   
        ++linhas;   
      }
      else
        { break; }
    }

    //arvore.printInorder(arvore.getRaiz());
    //Saída ================================  
    /*
    ImprimeChaves(Chaves);
    cout << "\n";
    No *r;
    r = arvore.getRaiz();
    arvore.printInorder(r); 
    */
}

#pragma endregion

// !__Arquivo

/*
leitor.open(arquivo, ios::in);
    int numeroLinhas = 0;
    getline(leitor, container);
    numeroLinhas = stoi(container);
    string Chaves[numeroLinhas];
    
    if( linhas <= numeroLinhas )
    {      
      while (getline(leitor, container))
      {
        if( linhas == 0 ){}
        else
        {                    
          temp.clear();
          for (int i = 0; i < container.size(); ++i)
          {            
            int aux = 0;
            if (container[i] != ' ' && container[i] != '1' && container[i] != '0')
            {
              temp += container[i];
            }

            if (container[i] == ' ')
            {
              divisa = true;
              Chaves[aux] = temp;
              ++aux; 
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

                //Convesão do tipo em inteiro
                dadoTemp = stoi(temp);
                divisa = false;
                temp.clear();
                break;
              }
            }
            
            //Atribuição de dados
            if (adnome == true && addado == true)
            {              
              cout << nomeTemp << endl;
              cout << dadoTemp << endl;
              cout << endl;
              /*
              // Se já existe esta consciência
              if (nomeTemp == arvore.Pesquisa(nomeTemp).getChave())
              {
                Dado d;
                d.SetChave(dadoTemp);
                arvore.Pesquisa(nomeTemp).getListaDados().insereFinal(d);
                arvore.Pesquisa(nomeTemp).getListaDados().addTamanho();              
              }

              // se não existe esta consciência
              else
              {
                Consciencia c;
                c.setChave(nomeTemp);
                Dado d;
                d.SetChave(dadoTemp);

                c.getListaDados().insereFinal(d);
                arvore.Insere(c);
              }                    
            } else{}
          }                     
        } 
        ++linhas;                        
      }
    } 
    else {} 
*/