#include <iostream>

class Node{
public:
    int info;
    Node *next;
};

class Stack{
private:
    Node *HEAD;
public:
    Stack();
    ~Stack();

    bool isEmpty();            //checks if the stack is empty
    void push(int data);       //inserts elements into stack
    int pop();                 //removes the top element
    int top();                 //returns the top element
    void traverse();           //returns all the elements from stack
};
