#include "../include/Arquivo.hpp"
#include "../include/ArvoreDados.hpp"
#include "../include/No.hpp"

#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

#pragma region Funções Auxiliares

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

#pragma endregion

#pragma region Leitura de Dados

void Arquivo::leArquivo()
{
    int linhas = 0;
    fstream leitor;
    string temp = "";
    int linhasparaleitura = 0;
    string keys[1000];
    int keycount = 0;
    string NaoEnviados[1000];
    int NaoEnviadosCount = 0;
    ArvoreDados arvore;

    //Cria separador para leitura
    bool divisa = false, adnome = false, addado = false;

    //Abertura
    leitor.open(this->arquivo, ios::in);

    //Inicia leitura.
    while (getline(leitor, container)) {
        string a = container;
        if (linhas == 0) {
            linhasparaleitura = std::stoi(a);
        }
        //Monitoramento de linhas lidas
        if (linhas != linhasparaleitura) {
            temp.clear();
            for (int i = 0; i < container.size(); ++i) {
                if (container[i] != ' ' && container[i] != '1' && container[i] != '0') {
                    temp += container[i];
                }

                if (container[i] == ' ') {
                    divisa = true;
                    nomeTemp = temp;
                    adnome = true;
                    temp.clear();
                }
                else {
                    if (divisa) {
                        int ax = i;
                        addado = true;

                        while (ax < container.size()) {
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
                if (adnome == true && addado == true) {
                    //se não existir a conciencia
                    if (!arvore.BuscaIterativa(nomeTemp)) {
                        No* no = new No();
                        int ax = 0;
                        ax = binaryToDecimal(dadoTemp);
                        no->setChave(nomeTemp);
                        no->getLista().insereFinal(ax);
                        arvore.InsereNo(no);
                    }
                    else {
                        int ax = 0;
                        ax = binaryToDecimal(dadoTemp);
                        arvore.BuscaIterativa(nomeTemp)->getLista().insereFinal(ax);
                    }
                    adnome = false;
                    addado = false;
                    NaoEnviados[NaoEnviadosCount] = nomeTemp;
                    ++NaoEnviadosCount;
                    nomeTemp.clear();
                    dadoTemp.clear();
                }
                else {
                }
            }
            ++linhas;
        }
        else {
            string ax = container;
            if (ax.find('1') == std::string::npos && ax.find('0') == std::string::npos) {
                keys[keycount] = container;
                ++keycount;
            }
        }
    }

    //Saída
    arvore.PrintaEmOrdem(arvore.getRaiz());
    cout << endl;

    string resKey[keycount];
    int resSum[keycount];

    for (int i = 0; i < keycount; ++i) {
        resKey[i] = arvore.BuscaIterativa(keys[i])->getChave();
        resSum[i] = arvore.BuscaIterativa(keys[i])->getNr();
    }
    for (int a = 0; a < keycount; ++a) {
        cout << resKey[a] << " " << arvore.BuscaIterativa(resKey[a])->getLista().Soma() << endl;
    }
    for (int a = 0; a < keycount; ++a) {
        arvore.BuscaIterativa(keys[a])->~No();
    }
    arvore.PrintaEmOrdem(arvore.getRaiz());
}

#pragma endregion

// !__Arquivo