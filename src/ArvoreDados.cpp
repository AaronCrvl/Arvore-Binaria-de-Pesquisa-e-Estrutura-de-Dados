#include "../include/ArvoreDados.hpp"
#include "../include/Consciencia.hpp"
#include "../include/No.hpp"

#include <string>
#include <iostream>

using namespace std;

void ArvoreDados::insertNode(No * new_node) {
    if (raiz == NULL) {
      raiz = new_node;
      //cout << "Value Inserted as raiz node!" << endl;
    } else {
      No * temp = raiz;
      while (temp != NULL) 
        if (new_node -> getChave() == temp -> getChave()) {        
          return;
        } else if ((new_node -> getChave() < temp ->getChave()) && (temp ->getEsquerda() == NULL)) {
          temp -> setEsquerda(new_node);
          //cout << "Value Inserted to the left!" << endl;
          break;
        } else if (new_node -> getChave() < temp ->getChave()) {
          temp = temp -> getEsquerda();
        } else if ((new_node -> getChave() > temp ->getChave()) && (temp ->getDireita() == NULL)) {
          temp ->setDireita(new_node);
          //cout << "Value Inserted to the right!" << endl;
          break;
        } else {
          temp = temp -> getDireita();
        }
      }
    }

No* ArvoreDados::insertRecursive(No *r, No *new_node)
	{
		if(r==NULL)
		{
			r=new_node;
			cout <<"Insertion successful"<<endl;
			return r;
		}
	
		if(new_node->getChave() < r->getChave())
		{
			r->setEsquerda(insertRecursive(r->getEsquerda(),new_node));
		}
		else if (new_node->getChave() > r->getChave())  
		{
			r->setDireita(insertRecursive(r->getDireita(),new_node));
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r; 
		}
		return r;
	}  


void ArvoreDados::printInorder(No * r) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    printInorder(r -> getEsquerda());
    /* then print the data of node */
    cout << r -> getChave() << " " << r->getLista().Soma() << endl;
    /* now recur on right child */
    printInorder(r -> getDireita());
  }

  void ArvoreDados::WalkInOrder(No * r) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    WalkInOrder(r -> getEsquerda());
    /* then print the data of node */
    cout << r->getChave() << " ";
    /* now recur on right child */
    WalkInOrder(r -> getDireita());
  }

  void ArvoreDados::printInorder(No * r, int tipo) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    printInorder(r -> getEsquerda());
    /* then print the data of node */
    cout << r -> getChave() << " ";
    /* now recur on right child */
    printInorder(r -> getDireita());
  }


  No * ArvoreDados::iterativeSearch(string v) {
    if (raiz == NULL) {
      return raiz;
    } else {
      No * temp = raiz;
      while (temp != NULL) {
        if (v == temp -> getChave()) {
          return temp;
        } else if (v < temp -> getChave()) {
          temp = temp -> getEsquerda();
        } else {
          temp = temp -> getDireita();
        }
      }
      return NULL;
    }
  }


/*
No *ArvoreDados::Pesquisa(Chave chave) 
{
    return PesquisaRecursivo(raiz, chave);
}

No *ArvoreDados::PesquisaRecursivo(No *no, Chave chave) 
{        
    if ( no == nullptr ) 
    {        
        //return no;
    }
    cout << "Aqui" << endl;
    if (chave < no->getConsciencia().getChave())
        return PesquisaRecursivo(no->getEsquerda(), chave);
    
    else if (chave>no->getConsciencia().getChave())
        return PesquisaRecursivo(no->getDireita(), chave);    
    
    else
        return no;
}

void ArvoreDados::Insere(No *no)
{
    InsereRecursivo(raiz, no->getConsciencia() );
}

void ArvoreDados::InsereRecursivo(No* &p, Consciencia c)
{ 
    if(p == nullptr){
        p = new No();
        p->setConscienca(c);
    }
    else
    {
    if(c.getChave() < p->getConsciencia().getChave())
        InsereRecursivo(p->getEsquerda(), c);
    else
        InsereRecursivo(p->getDireita(), c);
    }
}

void ArvoreDados::Remove(Chave chave) 
{
    return RemoveRecursivo(raiz, chave);
}

void ArvoreDados::RemoveRecursivo(No* &no, Chave chave)
{
    No *aux;
    if (no == NULL) {
    throw("Item nao está presente");
    }
    if (chave < no->getConsciencia().getChave())
        return RemoveRecursivo(no->getEsquerda(), chave);
    else if (chave>no->getConsciencia().getChave())
        return RemoveRecursivo(no->getDireita(), chave);
    else 
    {
        if (no->getDireita() == NULL) {
            aux = no;
            no = no->getEsquerda();
            free(aux);
        }
        else if(no->getEsquerda() == NULL) {
            aux = no;
            no = no->getDireita();
            free(aux);
        }
        else
        Antecessor(no, no->getDireita());
    }
}

void ArvoreDados::Antecessor(No *q, No* &r){
    
    if(r->getDireita() != NULL) {
        Antecessor(q, r->getDireita());
        return;
    }
    
    q->setConscienca(r->getConsciencia());
    q = r;
    r = r->getEsquerda();
    free(q);
}

void ArvoreDados::printInorder(No *no)
{
    if (no == NULL)
        return;
    
    cout << " aqui ";    
    printInorder(no->getEsquerda());
        
    cout << no->getConsciencia().getChave();
    cout << " ";
    cout << no->getConsciencia().getListaDados().getTamanho();
    cout << endl;
     
    printInorder(no->getDireita());
}
*/

// !__ArvoreDados