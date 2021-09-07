#include "../include/Arquivo.hpp"
#include "../include/ArvoreDados.hpp"
#include "../include/No.hpp"

#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

#pragma region Leitura de Dados

//Conversão binário -> inteiro
int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

void Arquivo::leArquivo()
{	
    int linhas = 0;
		fstream leitor;    
		string temp = "";        
    int linhasparaleitura = 0;    
		ArvoreDados arvore;

		//Cria separador para leitura
		bool divisa = false, adnome = false, addado = false;
	
		//Abertura
    leitor.open(this->arquivo, ios::in);

    //Inicia leitura.
    while (getline(leitor, container))
    {
      string a = container;
      if (linhas == 0)
      {
       linhasparaleitura = std::stoi(a);  
       string *keys = arvore.criaEscopo(linhasparaleitura);       
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
              dadoTemp = temp;
              divisa = false;
              temp.clear();
              break;
            }
          }
          
          //Atribuição de dados
          if (adnome == true && addado == true) 
          {     
            if( nomeTemp == "" )
            {
              keys = dadoTemp;
            }  
            else{}     
            //se não existir a conciencia            
            if( !arvore.iterativeSearch(nomeTemp) )
            {
              No *no = new No();
              int ax = 0;
              ax = binaryToDecimal(dadoTemp);
              no->setChave(nomeTemp);                                                                  
              no->getLista().insereFinal(ax);            
              arvore.insertNode(no);                            
            }          
            else
            {
              int ax = 0;
              ax = binaryToDecimal(dadoTemp);
              arvore.iterativeSearch(nomeTemp)->getLista().insereFinal(ax);
            }               
            adnome = false;
            addado = false;  
            nomeTemp.clear();
            dadoTemp.clear();       
          } 
          else {}
        }   
        ++linhas;   
      }
      else
        { break; }
    }    
    
    //Saída 
    arvore.WalkInOrder(arvore.getRaiz());
    cout << endl;
    arvore.printInorder(arvore.getRaiz());
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