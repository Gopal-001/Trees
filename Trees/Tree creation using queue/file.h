#include <stdio.h>
#ifndef file_h
#define file_h
using namespace std;
class Node
{
public:
    Node* left;
    int data;
    Node* right;
};
class Queue
{
    int capacity;
    int first;
    int last;
    Node** q;
public:
    Queue(){first = last = 0; capacity=10; q=new Node*[capacity];}
    Queue(int s){
        first = last = -1;
        this->capacity = s;
        q = new Node*[capacity];
    }
    bool isEmpty();
    bool isFull();
    void enqueue(Node* x);
    Node* dequeue();
    void Display();
    ~Queue();
};
bool Queue::isFull()
{
    if((last+1)%capacity == first)
        return true;
    else
        return false;
}
bool Queue::isEmpty()
{
    if(first == last)
        return true;
    return false;
}
void Queue::enqueue(Node* x)
{
    if(isFull()){
        cout<<"Queue Overflow!"<<endl;
        return ;
    }
    last = (last+1)%capacity;
    q[last] = x;
}
void Queue::Display()
{
    if(isEmpty()){
        cout<<"Queue is empty."<<endl;
        return;
    }
    cout<<*(q+first)<<" ";
    for(int i=first+1;i!=first;){
        cout<<*(q+i)<<" ";
        i = (i+1)%capacity;
    }
    cout<<endl;
}
Node* Queue::dequeue()
{
    Node* x= NULL;
    if(isEmpty()){
        cout<<"Queue Underflow!"<<endl;
        return x;
    }
    x = q[first+1];
    first = (first+1)%capacity;
    return x;
}
Queue::~Queue()
{
    for(int i=0;i<capacity;i++){
        delete(*(q+i));
    }
}
#endif
