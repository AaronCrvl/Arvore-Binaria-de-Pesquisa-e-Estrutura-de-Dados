
Sumário:

1 – Introdução
2 – Implementação
3 – Análise de Complexidade
7 – Conclusões 
8 – Referência Bibliográficas
9 – Instruções para Compilação e Execução








1.	Introdução:

Esta documentação tem como objetivo realizar a descrição do Implemento 3, que tem a finalidade criar um sistema que dado dois 
campos distintos que representam o Nome da Pessoa e seu ID de consciência, são armazenados em uma estrutura de dado do tipo árvore binária 
para tratativa e envios posteriores, assim como, o uso da estrutura de lista para organizar os dados de cada nó.

2.	Implementação:
O programa foi desenvolvido na linguagem C++, compilada pelo compilador G++ da GNU Compiler Collection.

A-	Classe:

O código conta com 5 classes principais, sendo estas, Arquivo, ArvoreDados, ListaDados, No e Celula.


Classe Arquivo:
Esta parte fica reponsável pela leitura do arquivo e separação de suas linhas em dados para as variáveis.
1 – Variáveis:
(STRING) arquivo: Nome do arquivo para leitura.
(STRING) container: Linha lida do arquivo.
(STRING) nomeTemp: Nome/Chave da consciência a ser inserida na árvore.
(STRING) dadoTemp: Dado que deve ser inserido na lista de dados dentro do nó de mesma chave.

2 – Métodos:
(VOID) SetArquivo: Seta o nome do arquivo para leitura.
(VOID) leArquivo: Lê o arquivo.

  
Classe No:
Esta classe representa os nós que serão utilizados para a construção da árvore binária.

1 – Variáveis:
(LISTADADOS) lista: Lista de dados contida em todo Nó da árvore.
(NO*) esq: Ponteiro para o nó a direita do atual.
(NO*) dir: Ponteiro para o nó à direita do atual.
(STRING) Chave: Chave do nó.
(INT) SomaReg: Int que irá carregar a soma dos registros das posições da lista de dados.
		
2 – Métodos:
(LISTADADOS&) getLista: Retorna o ponteiro para a lista presente no nó desta árvore.
(NO*) getEsquerda: Retorna o ponteiro para o nó à esquerda do atual.
(NO*) getDireita: Retorna o ponteiro para o nó à direita do atual.
(STRING) getChave: Retorna a chave deste nó. 
(VOID) setChave: Seta a chave da classe.
(VOID) setEsquerda: Seta o ponteiro para o nó à esquerda do atual.
(VOID) addNR: Incrementa valor passada à soma geral da lista de dados.
(INT) getNr: Retorna o valor da soma dos dados da lista.


Classe ArvoreDados:

É a classe criada para representar a árvore que armazenará os dados.
1 – Variáveis:
(INT) nrRegistos: Esta é utilizada para verificação da quantidade de nós presentes em nossa árvore.
(NO*) Raiz: Representa o nó raiz da árvore. (Variável Pública)
		
2 – Métodos:
(NO*&) getRaiz: Retorna a referência para a raiz da árvore.
(NO*) BuscaIterativa: Busca um nó qualquer passada uma chave de forma iterativa.
(NO*) DeletarNo: Deleta um nó passada a raiz e sua chave respectiva.
(NO*) NoMinValor: Retorna o nó que tem o menor valor dentro do galho analisado.
(VOID) CaminhamentoCentral: Faz o caminhamento na árvore de forma in-order ou central.
(VOID) InsereNo: Insere um nó na árvore.
(VOID) PrintaEmOrdem: Caminha e print os dados de forma in-order ou central.



Classe Celula:

Esta classe fica responsável por representar os registros individuais dentro da lista de dados(info de consciências).

1 – Variáveis:
(CELULA*) prox: Ponteiro para a próxima célula.
(INT) item: Item que armazena o dado de consciência da pessoa.

2 – Métodos:
(CELULA*&) getProx: Retorna o ponteiro para a próxima celula da lista.
(INT) getItem: Retorna o dado da variável item.
(VOID) setItem: Seta um valor para a variável item.
(VOID) setProx: Seta o apontador para a próxima célula.


Classe ListaDados:

Esta classe fica responsável por representar a lista de dados de cada pessoa.
1 – Variáveis:
(INT) tamanho: Representa o tamanho da lista armazenada.
(CELULA) primeiro: Ponteiro para a primeira célula da lista.
(CELULA) ultimo: Ponteiro para a último célula da lista.

2 – Métodos:
(VOID)insereFinal: Insere um dado no final da lista de dados.
(VOID) addTamanho: Incrementa no tamanho da lista de dados.
(INT) Soma: Soma os valores de todos os dados presentes na lista.
(INT) getTamanho():Retorna o tamanho atual da lista.
(BOOL) Vazia: Retorna se a lista está vazia ou não.

 

3.	Análise de Complexidade:

Classe ArvoreDados:

Complexidade de Tempo:
Começando pela classe da árvore propriamente temos um base para os casos e complexidade conforme tipo de árvore:
Complexidade de Tempo(O)
Caso	Busca	Inserção	Remoção	Tipo
Melhor 	O(log N)	O(log N)	O(log N)	 
 Médio	O(log N)	O(log N)	O(log N)	Balanceada
Pior 	O(N)	O(N)	O(N)	Não Balanceada

A árvore também conta com métodos adicionais como:
- PrintaEmOrdem/CaminhamentoCentral: Ambos os métodos fazem o caminhamento sobre todos os nós da árvore para retornar seu resultado, geralmente utilizados para impressão.
Tem complexidade O(n) por ser feito o caminhamento completo na estrutura.
- getRaiz: O(1).
- NoMinValor: O(log N)


Complexidade de Espaço:
A árvore binária tem complexidade de espaço conforme o número de nós, logo, O(n).


Classe ListaDados:

Complexidade de Tempo:
Para as operações da Lista temos:

Complexidade de Tempo
Operação	Encadeamento
Insere Início	O(1)
Insere Final	O(1)
Insere Posição	O(n)
Pesquisa Elemento	O(n)
Exclusão Posição	O(n)



Complexidade de Espaço:
Segue linearmente o tamanho da lista, logo, O(N).





4.	Conclusões:

O objetivo deste trabalho é implementar e também analisar o funcionamento da estrutura de dados tipo árvore.
O trabalho desafia o aluno a realizar diversas operações que testam a assertividade do código quando a estrutura é modelada e posteriormente remodelada.
Após implementação e realização podemos notar a forma como a Arvore Binária e outras estruturas, em nosso contexto a lista encadeada, podem trabalhar juntos para uma funcionalidade maior.
Na montagem do código a prioridade foi sobre a forma com que a estrutura do tipo árvore pode modelar seus dados assim como, após montada, busca dados específicos em sua estrutura.

