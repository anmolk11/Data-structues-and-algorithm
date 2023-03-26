#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#ifndef _IOSTREAM_H
#include <iostream>
#endif

// This header file contains implementation of queue data structrure using array
template<typename T> 
class CircluarQueue {
    public:
        // constructors and destructor
        CircluarQueue()
            :
            arr{new T[INT8_MAX]},size{INT8_MAX}, front{-1}, rear{-1}, length{0}
            {}
        CircluarQueue(size_t n)
            :
            arr{new T[n]},size{n}, front{-1}, rear{-1}, length{0}
            {}        
        ~CircluarQueue(){
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
        size_t getLength() const;
        void print() const;
    private:
        int front, rear;
        T *arr;
        size_t size, length;
};

template<typename T>
inline const T CircluarQueue<T>::getRear() const {
    return arr[rear];
}

template<typename T>
inline const T CircluarQueue<T>::getFront() const {
    return arr[front];
}

template<typename T>
inline bool CircluarQueue<T>::isEmpty() const {
    return (front == rear && rear == -1);
}

template<typename T>
inline bool CircluarQueue<T>::isFull() const {
    return ((rear+1)%size == front);
}

template<typename T>
inline void CircluarQueue<T>::enqueue(const T& ele) {
    if(!isFull()) {
        if(isEmpty()) {
            front++;
            rear++;
        }else {
            rear = (rear+1)%size;
        }
        arr[rear] = ele;
        length++;
    }else {
        throw runtime_error("Queue is Full");        
    }
}

template<typename T>
inline T CircluarQueue<T>::dequeue() {
    if(!isEmpty()) {
        T temp = arr[front];
        if(front == rear)
            front = rear = -1;
        else 
            front = (front+1)%size;
        length--;
        return temp;
    }else {
        throw runtime_error("Queue is Empty");
    }
}

template<typename T>
inline size_t CircluarQueue<T>::getLength() const {
    return (!isEmpty() ? length : 0);
}

template<typename T>
void CircluarQueue<T>::print() const{
    if(!isEmpty()) {
        if(front <= rear) {
            for(size_t i = front; i <= rear; i++) {
                if(i != rear)
                    cout << arr[i] << " - ";
                else 
                    cout << arr[i];
            }
        }else {
            for(size_t i = front; i <= size-1; i++) {
                    cout << arr[i] << " - ";
            }
            for(size_t i = 0; i <= rear; i++) {
                if(i != rear)
                    cout << arr[i] << " - ";
                else 
                    cout << arr[i];
            }
        }        
    }else {
        std::cout << "!! Queue is Empty !!" << endl;
    }
    cout << endl;
}

#endif