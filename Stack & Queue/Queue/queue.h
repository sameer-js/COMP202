#ifndef QUEUE_H
#define QUEUE_H
#define MAX 100

class Queue{
private:
  char elements[MAX];
  int front;
  int rear;
public:
  Queue();
  ~Queue();

  bool isEmpty();              //checks if the queue is empty
  bool isFull();               //checks if the queue is full
  void enqueue(char data);     //adds element into the queue
  char dequeue();              //removes element from the queue
  char peekFront();            //gives the element at the front
  char peekRear();             //gives the element at the rear
};

#endif //QUEUE_H
