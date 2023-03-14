#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
    int *A;
    int front;
    int rear;
    int size;

    public:
    Queue(int size){
        this->size = size;
        front = -1;
        rear = -1;
        A = new int[size];
    }
    void enqueue(int x);
    void dequeue();
    int front_();
    bool empty();

    // just for understanding purpose
    // we can not iterate over queue, because it violates the properties
    void print(){
        cout<<"\n-----------------\n";
        for(int i = front;i <= rear;i++){
            cout<<A[i]<<' ';
        }
        cout<<"\n-----------------\n";
    }
};

void Queue::enqueue(int x){
    if(rear == size - 1){
        //queue is full 
        return;
    }
    if(front == -1){
        ++front;
        ++rear;
        A[rear] = x;
    }
    else{
        ++rear;
        A[rear] = x;
    }
}

void Queue::dequeue(){
    if(empty()){       
        return;
    }
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        ++front;
    }
}

int Queue::front_(){
    if(empty()){
        return INT_MIN;
    }
    return A[front];
}

bool Queue::empty(){
    return front == -1;
}

int main(){
    Queue Q(5); // queue of size of 5

    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);

    Q.print();

    Q.dequeue();
    Q.print();

    cout<<"Current front element is : "<<Q.front_()<<'\n';

    Q.enqueue(40);
    Q.enqueue(50);
    Q.enqueue(60);


    while(!Q.empty()){
        cout<<"Current front element is : "<<Q.front_()<<'\n';
        Q.dequeue();
    }
}