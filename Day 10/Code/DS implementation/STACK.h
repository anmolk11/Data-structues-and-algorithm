#ifndef STACK_H
#define STACK_H

#ifndef _IOSTREAM_H
#include <iostream>
#endif


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
class STACK {
    public:
        // Utilities
        STACK()
            :
            size{0}, top{nullptr}
            {}
        ~STACK(){
            while (top) {
                ListNode<T>* temp = top->next;
                delete top;
                top = temp;
            }
            cout << "!! Stack Deleted Successfully" << endl;
        }

        // main functions
        void push(const T&);
        T pop();
        bool isEmpty() const;
        const T getTop() const;

        // auxillary functions
        const T getMiddle() const;
        size_t length() const;
        void print() const;
        void reverse();
        void inesertBottom(T);
    private:
        ListNode<T> *top;
        size_t size;
};

template<typename T>
inline const T STACK<T>::getTop() const {
    return top->val;
}

template<typename T>
inline bool STACK<T>::isEmpty() const {
    return (top == nullptr);
}

template<typename T>
inline const T STACK<T>::getMiddle() const {
    if(!isEmpty()) {
        ListNode<T>* slow = top;
        ListNode<T>* fast = top;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->val;
    }
}

template<typename T>
inline void STACK<T>::push(const T& ele) {
    ListNode<T>* newNode = new ListNode<T>(ele,top);
    top = newNode;
    size++;
}

template<typename T>
inline T STACK<T>::pop() {
    if(!isEmpty()) {
        ListNode<T>* temp = top;
        T ele = getTop();
        top = top->next;
        delete temp;
        size--;
        return ele;
    }else {
        throw runtime_error("Stack is Empty");
    }
}

template<typename T>
inline size_t STACK<T>::length() const {
    return size;
}

template<typename T>
void STACK<T>::print() const{
    if(!isEmpty()) {
        ListNode<T>* temp = top;
        while(temp) {
            if(temp->next != nullptr)
                cout << temp->val << "->";
            else 
                cout << temp->val;
            temp = temp->next;
        }
        cout << endl;
    }else {
        std::cout << "!! Stack is Empty !!" << endl;
    }
}

template<typename T>
void STACK<T>::inesertBottom(T x) {
    if(isEmpty())
        push(x);
    else {
        T val = pop();
        inesertBottom(x);
        push(val);
    }
}

template<typename T>
void STACK<T>::reverse() {
    if(isEmpty())
        return;
    T val = pop();
    reverse();
    inesertBottom(val);
}

#endif