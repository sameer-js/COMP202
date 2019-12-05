#include <iostream>
#include "queue.h"

Queue :: Queue(){
  front = -1;
  rear = -1;
}

Queue :: ~Queue(){}

bool Queue :: isEmpty(){
  return front == rear;
}

bool Queue :: isFull(){
  return rear == MAX - 1;
}

void Queue :: enqueue(char data){
  if(!isFull()){
    rear = rear + 1;
    elements[rear] = data;
  }
  else{
    std::cout << "Queue Overflow" << "\n";
  }
}

char Queue :: dequeue(){
  if(!isEmpty()){
    front = front + 1;
    return elements[front];
  }
  else{
    std::cout <<"Queue Underflow" << "\n";
    return '-';
  }
}

char Queue :: peekFront(){
  if(!isEmpty()){
    return elements[front+1];
  }
  else{
    std::cout <<"Queue Underflow" << "\n";
    return '-';
  }
}

char Queue :: peekRear(){
  if(!isEmpty()){
    return elements[rear];
  }
  else{
    std::cout <<"Queue Underflow" << "\n";
    return '-';
  }
}


int main() {
  Queue Q;
  std::cout << Q.isEmpty() << '\n';
  std::cout << Q.isFull() << '\n';
  Q.enqueue('a');
  Q.enqueue('b');
  Q.enqueue('x');
  Q.enqueue('c');
  Q.enqueue('d');
  std::cout << Q.dequeue() << '\n';
  std::cout << Q.dequeue() << '\n';
  std::cout << Q.peekFront() << '\n';
  std::cout << Q.peekRear() << '\n';

  return 0;
}
