#ifndef ARQUIVO_H
#define ARQUIVO_H

// #include "../include/Dados.hpp"

#include<string>
#include<iostream>

using namespace std;

class Arquivo
{                    
    public:        
        //Inicializa classe com nome do arquivo.
        Arquivo(){}
        //Destrutor
        ~Arquivo(){}   
        //
        void SetArquivo(string a){ this->arquivo = a; }
        // Lê o arquivo            
        void leArquivo();        
        //Inicializa as variáveis
        void Inicializa();

    private: 
        string arquivo   = "";     
        string container = "";
        string nomeTemp  = "";  
        int dadoTemp = 0;                         
};
#endif