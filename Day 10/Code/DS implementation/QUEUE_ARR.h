#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H

#ifndef _IOSTREAM_H
#include <iostream>
#endif

// This header file contains implementation of queue data structrure using array
template<typename T> 
class QUEUE {
    public:
        // constructors and destructor
        QUEUE()
            :
            arr{new T[INT64_MAX]},size{INT64_MAX}, front{-1}, rear{-1}
            {}
        QUEUE(size_t n)
            :
            arr{new T[n]},size{n}, front{-1}, rear{-1}
            {}        
        ~QUEUE(){
            delete arr;
            cout << "!! Queue Deleted Successfully" << endl;
        }

        // main functions
        void enqueue(const T&);
        T dequeue();
        bool isEmpty() const;
        bool isFull() const;
        const T getRear() const;
        const T getFront() const;

        // auxillary functions
        size_t length() const;
        void print() const;
    private:
        int front, rear;
        T *arr;
        size_t size;
};

template<typename T>
inline const T QUEUE<T>::getRear() const {
    return arr[rear];
}

template<typename T>
inline const T QUEUE<T>::getFront() const {
    return arr[front];
}

template<typename T>
inline bool QUEUE<T>::isEmpty() const {
    return (front == rear && rear == -1);
}

template<typename T>
inline bool QUEUE<T>::isFull() const {
    return (rear == size-1);
}

template<typename T>
inline void QUEUE<T>::enqueue(const T& ele) {
    if(!isFull()) {
        if(isEmpty()) {
            front++;
        }
        arr[++rear] = ele;
    }else {
        throw runtime_error("Queue is Full");        
    }
}

template<typename T>
inline T QUEUE<T>::dequeue() {
    if(!isEmpty()) {
        T temp = arr[front];
        if(front == rear)
            front = rear = -1;
        else 
            front++;
        return temp;
    }else {
        throw runtime_error("Queue is Empty");
    }
}

template<typename T>
inline size_t QUEUE<T>::length() const {
    return (!isEmpty() ? rear-front+1 : 0);
}

template<typename T>
void QUEUE<T>::print() const{
    if(!isEmpty()) {        
        for(size_t i = front; i <= rear; i++) {
            if(i != rear)
                cout << arr[i] << " - ";
            else 
                cout << arr[i];
        }
    }else {
        std::cout << "!! Queue is Empty !!" << endl;
    }
    cout << endl;
}

#endif