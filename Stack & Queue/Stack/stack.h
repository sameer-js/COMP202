#ifndef STACK_H
#define STACK_H
#define MAX 100

class Stack{
private:
  int elements[MAX];
  int tope;
public:
  Stack(){tope = -1;};
  ~Stack(){};

  bool isEmpty();     //check if the stack is empty
  void push(int element); //inserts element into stack
  void show();
  int push();
  int top();
  int pop();          //remove the top element
};

#endif //STACK_H
