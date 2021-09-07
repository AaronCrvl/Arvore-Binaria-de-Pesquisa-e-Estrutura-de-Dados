#include "../include/ArvoreDados.hpp"
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
    cout << r -> getChave() << " ";     
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

 No * ArvoreDados::recursiveSearch(No * r, string val) {
 if (r == NULL || r ->getChave() == val)
      return r;

    else if (val < r -> getChave())
      return recursiveSearch(r -> getEsquerda(), val);

    else
      return recursiveSearch(r -> getDireita(), val);
  }

  No * ArvoreDados::deleteNode(No * r, string v) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the raiz's key, 
    // then it lies in left subtree 
    else if (v < r ->getChave()) {
      r -> setEsquerda(deleteNode(r -> getEsquerda(), v));
    }
    // If the key to be deleted is greater than the raiz's key, 
    // then it lies in right subtree 
    else if (v > r ->getChave()) {
      r -> setDireita(deleteNode(r -> getEsquerda(), v));
    }
    // if key is same as raiz's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> getEsquerda() == NULL) {
        No * temp = r -> getDireita();
        delete r;
        return temp;
      } else if (r -> getDireita() == NULL) {
        No * temp = r -> getEsquerda();
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        No * temp = minValueNode(r -> getDireita());
        // Copy the inorder successor's content to this node 
        r -> setChave(temp ->getChave());
        // Delete the inorder successor 
        r -> setDireita(deleteNode(r -> getDireita(), temp -> getChave()));
        //deleteNode(r->right, temp->value); 
      }
    }
    return r;
  }

  No * ArvoreDados::minValueNode(No * node) {
    No * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> getEsquerda() != NULL) {
      current = current -> getEsquerda();
    }
    return current;
  }

// !__ArvoreDados