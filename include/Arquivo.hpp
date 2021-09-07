#ifndef ARQUIVO_H
#define ARQUIVO_H

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
        //Seta o nome de do arquivo para leitura
        void SetArquivo(string a){ this->arquivo = a; }
        // Lê o arquivo            
        void leArquivo();        

    private: 
        string arquivo   = "";     
        string container = "";
        string nomeTemp  = "";  
        string dadoTemp  = "";                                 
};
#endif