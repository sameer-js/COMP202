#include <iostream>

class Node{
public:
  int info;
  Node *next;
};

class List{
private:
  Node *HEAD;
  Node *TAIL;
public:
  List();
  ~List();

  //insert
  bool isEmpty();
  void addtoHead(int data);
  void addtoTail(int data);
  void add(int data, Node* &predecessor);

  //remove
  void removefromHead();
  void remove(int data);

  //other functions
  bool search(int data);
  void traverse();
  bool retrieve(int data, Node* &outputPtr);
};
