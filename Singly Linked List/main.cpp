#include <iostream>
#include "singly.h"

using std::cout;
using std::endl;

List :: List(){
  HEAD = NULL;
  TAIL = NULL;
}

List :: ~List(){}

bool List :: isEmpty(){
  if (HEAD == NULL)
    return true;
  else
    return false;
}

void List :: addtoHead(int data){
  Node* newNode = new Node();
  newNode -> info = data;
  newNode -> next = HEAD;
  HEAD = newNode;
  if (TAIL == NULL)
    TAIL = HEAD;

}

void List :: addtoTail(int data){
  Node* newNode = new Node();
  newNode -> info = data;
  newNode -> next = NULL;
  TAIL -> next = newNode;
  TAIL = newNode;
}

void List :: add(int data, Node* &predecessor){
  Node* newNode = new Node();
  newNode -> info = data;
  newNode -> next = predecessor -> next;
  predecessor -> next = newNode;
}

void List :: removefromHead(){
  Node* toDelete;
  toDelete = HEAD;
  HEAD = toDelete -> next;
  delete (toDelete);
}

void List :: remove(int data){
  Node* temp;
  Node *prev;
  if(isEmpty()){
    cout << "Underflow" << endl;
  }
  else {
    if(HEAD -> info == data)
      {
      removefromHead();
      if(HEAD == NULL)
        TAIL = NULL;
      }
    else
    {
      temp = HEAD -> next;
      prev = HEAD;
      while (temp != NULL)
      {
        if(temp -> info == data)
        {
          prev -> next = temp -> next;
          delete temp;
          if(prev -> next == NULL)
            TAIL = prev;
          break;
        }
        else
        {
          prev = prev -> next;
          temp = temp -> next;
        }
      }
    }
   }
}

bool List :: search(int data){
  Node* temp;
  temp = HEAD;
  while(temp != NULL)
  {
    if( temp -> info == data)
      return true;
    else
      temp = temp -> next;
  }
  return false;
}

void List :: traverse(){
  Node* temp = HEAD;
  while(temp != NULL)
  {
    cout << temp -> info << endl;
    temp = temp -> next;
  }
}

bool List :: retrieve(int data, Node* &outputPtr){
  Node* temp;
  temp = HEAD;
  while ((temp != NULL) && (temp ->info != data))
  {
    temp = temp -> next;
  }
  if (temp == NULL)
    return false;
  else
  {
    outputPtr = temp;
    return true;
  }
}


int main(){
  Node* outputPtr;

  List linked;
  cout << linked.isEmpty() << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~"  << endl;
  linked.addtoHead(2);
  linked.addtoHead(4);
  linked.addtoHead(6);
  linked.addtoHead(8);
  linked.addtoTail(10);
  linked.traverse();
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~"  << endl;
  linked.remove(2);
  linked.remove(4);
  linked.traverse();
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~"  << endl;
  cout << linked.search(8) << endl;
  cout << linked.search(9) << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~"  << endl;
  linked.retrieve(6, outputPtr);
  cout << &outputPtr << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~"  << endl;
  linked.removefromHead();
  linked.add(44, outputPtr);
  linked.add(88, outputPtr);
  linked.traverse();
  return 0;
}
