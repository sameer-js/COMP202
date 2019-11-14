#include <iostream>
#include "stack.h"
using namespace std;
/**
Stack :: Stack(){
  top = -1;
}

Stack :: ~Stack(){}
**/

void Stack :: push (int element){
  if(tope >= MAX -1){
    cout << "Cannot push" << element << ". Stack is full." << endl;
  }
  else{
    tope++;
    this->elements[tope] = element;
  }
}

int Stack :: pop(){
  if(tope < 0){
    cout << "Cannot pop. Stack is empty.";
  }
  else{
    return elements[tope--];
  }
}

int Stack::top(){
    if(tope < 0){
        cout << "Cannot pop. Stack is empty.";
    }
    else{
        return elements[tope];
    }
}
bool Stack :: isEmpty(){
  if (tope < 0) return true;
  else return false;
}

void Stack::show(){
    for(int i=0; i<MAX; i++){
        cout << elements[i];
    }
}
