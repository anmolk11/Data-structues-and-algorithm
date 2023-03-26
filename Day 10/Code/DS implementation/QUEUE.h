#ifndef QUEUE_H
#define QUEUE_H

#ifndef _IOSTREAM_H
#include <iostream>
#endif

// This header file contains implementation of queue data structrure using Linked List
template<typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(const T val, ListNode* next = nullptr) 
        : 
        val{val}, next{next}
        {}
};

template<typename T> 
class QUEUE {
    public:
        // Utilities
        QUEUE()
            :
            size{0}, front{nullptr}, rear{nullptr}
            {}
        
        ~QUEUE(){
            while (front) {
                ListNode<T>* temp = front->next;
                delete front;
                front = temp;
            }
            cout << "!! Queue Deleted Successfully" << endl;
        }

        // main functions
        void enqueue(const T&);
        T dequeue();
        bool isEmpty() const;
        const T getRear() const;
        const T getFront() const;

        // auxillary functions
        const T getMiddle() const;
        size_t length() const;
        void print() const;
        void reverse();
        void inesertBottom(T);
    private:
        ListNode<T> *front, *nextMiddle,*rear;
        size_t size;
};

template<typename T>
inline const T QUEUE<T>::getRear() const {
    return rear->val;
}

template<typename T>
inline const T QUEUE<T>::getFront() const {
    return front->val;
}

template<typename T>
inline bool QUEUE<T>::isEmpty() const {
    return (front == rear && rear == nullptr);
}

template<typename T>
inline const T QUEUE<T>::getMiddle() const {
    if(!isEmpty()) {
        ListNode<T>* slow = front;
        ListNode<T>* fast = front;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->val;
    }else {
        throw runtime_error("Queue is Empty");
    }
}

template<typename T>
inline void QUEUE<T>::enqueue(const T& ele) {
    if(isEmpty()) {
        front = rear = new ListNode<T>(ele);
    }else {
        rear->next = new ListNode<T>(ele);
        rear = rear->next;
    }
    size++;
}

template<typename T>
inline T QUEUE<T>::dequeue() {
    if(!isEmpty()) {
        ListNode<T>* temp = front;
        T ele = getFront();
        front = front->next;
        if(front == nullptr) rear = nullptr;
        delete temp;
        size--;
        return ele;
    }else {
        throw runtime_error("Queue is Empty");
    }
}

template<typename T>
inline size_t QUEUE<T>::length() const {
    return size;
}

template<typename T>
void QUEUE<T>::print() const{
    if(!isEmpty()) {
        ListNode<T>* temp = front;
        while(temp) {
            if(temp->next != nullptr)
                cout << temp->val << "->";
            else 
                cout << temp->val;
            temp = temp->next;
        }
        cout << endl;
    }else {
        std::cout << "!! Queue is Empty !!" << endl;
    }
}

template<typename T>
void QUEUE<T>::reverse() {
    if(isEmpty())
        return;
    T val = front->val;
    dequeue();
    reverse();
    enqueue(val);
}

#endif