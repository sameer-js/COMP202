#include <iostream>
#include "queue.h"
#define MAX 5

using std :: cout;
using std :: endl;

int count {0};

Queue :: Queue(){
    HEAD = NULL;
    TAIL = NULL;
}

Queue :: ~Queue(){}

bool Queue :: isEmpty(){
    return (HEAD == NULL);
}

void Queue :: enqueue(char data){
    if (count == MAX){
        cout << "Queue overflow!" << endl;
    }
    else{
        Node *newNode = new Node();
        newNode -> info = data;
        newNode -> next = NULL;
        if(isEmpty()){
            TAIL = newNode;         //for addition of the first element
            HEAD = TAIL;
        }
        else{
            TAIL -> next = newNode;
            TAIL = newNode;
        }
        count++;
    }
}

char Queue :: dequeue(){
    if (isEmpty()){
        cout << "Queue Underflow!" << endl;
        return '-';
    }
    else{
        Node *toDelete;
        char value;
        toDelete = HEAD;
        value = toDelete -> info;
        HEAD = toDelete -> next;
        delete toDelete;
        count--;
        return value;
    }

}

char Queue :: peekFront(){
    if (isEmpty()){
        cout << "Queue Underflow!" <<endl;
        return '-';
    }
    else{
        return (HEAD -> info);
    }
}

char Queue :: peekRear(){
    if (isEmpty()){
        cout << "Queue Overflow!" << endl;
        return '-';
    }
    else{
        return (TAIL -> info);
    }
}

void Queue :: traverse(){
    Node *temp = HEAD;
    while (temp != NULL){
        cout << temp -> info <<endl;
        temp = temp -> next;
    }
}


int main(){
    Queue Q;
    cout << Q.isEmpty() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    Q.dequeue();
    Q.enqueue('a');
    Q.enqueue('e');
    Q.enqueue('i');
    Q.enqueue('o');
    Q.enqueue('u');
    Q.traverse();
    Q.enqueue('X');
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << Q.peekFront() << endl;
    cout << Q.peekRear() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    Q.dequeue();
    Q.dequeue();
    Q.enqueue('x');
    Q.enqueue('y');
    Q.traverse();
    Q.enqueue('z');
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << Q.isEmpty() << endl;
    return 0;
}
