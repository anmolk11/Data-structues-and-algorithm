#ifndef LL_H
#define LL_H

#ifndef _IOSTREAM_H
#include <iostream>
#endif


template<typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(const T val, ListNode* next = nullptr) : val{val}, next{next}{}
};

template<typename T> 
class LL {
    public:
        // Utilities
        LL():size{0}, head{nullptr}{}
        ~LL(){
            while (head) {
                ListNode<T>* temp = head->next;
                delete head;
                head = temp;
            }
            cout << "!! Linked List Deleted Successfully" << endl;
        }

        // helper functions
        void push_back(const T&);
        void push_front(const T&);
        void add_element(const size_t,const T&);
        T delete_element(const T&);
        T& operator[](size_t index) const;
        size_t length() const {return size;};
        void print() const;
        void reverse();
    private:
        ListNode<T> *head;
        size_t size;
};

template<typename T>
void LL<T>::push_back(const T& ele) {
    ListNode<T>* newNode = new ListNode<T>(ele);
    if(head == nullptr) {
        head = newNode;
    }else {
        ListNode<T>* curr = head;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    size++;
}

template<typename T>
void LL<T>::push_front(const T& ele) {
    ListNode<T>* newNode = new ListNode<T>(ele,head);
    head = newNode;
    size++;
}

template<typename T>
T LL<T>::delete_element(const T& ele) {
    if(head == nullptr) {
        throw runtime_error("List in empty");
    }
    if(ele == head->val) {
        ListNode<T>* temp = head;
        T delete_val = temp->val;
        head = head->next;
        size--;
        delete temp;
        return delete_val;
    }else {
        ListNode<T>* curr = head;
        ListNode<T>* prev = NULL;
        while(curr && curr->val != ele) {
            prev = curr;
            curr = curr->next;
        }
        if(curr == nullptr) {
            throw runtime_error("!! Element Not Found !!");
        }
        ListNode<T>* temp = curr;
        T delete_val = temp->val;
        prev->next = curr->next;
        size--;
        delete temp;
        return delete_val;
    }
}

template<typename T>
void LL<T>::add_element(const size_t index,const T& ele) {
    if(index <= 0 || index > size) {
        throw runtime_error("Error : Index out of bounds");
    }
    ListNode<T>* prev = nullptr;
    ListNode<T>* curr = head;
    for(int i = 1; i < index; i++) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == head || (index == 1 && head == nullptr)) {
        ListNode<T>* newNode = new ListNode<T>(ele,head);
        head = newNode;
        size++;    
    }else {
        ListNode<T>* newNode = new ListNode<T>(ele,curr);
        prev->next = newNode;
        size++;
    }
}

template<typename T>
void LL<T>::print() const{
    if(head == nullptr) {
        throw runtime_error("!! List is empty !!");
        return;
    }
    ListNode<T>* curr = head;
    while(curr) {
        if(curr->next != nullptr)
            cout << curr->val << " -> ";
        else 
            cout << curr->val;
        curr = curr->next;
    }
    cout << endl;
}

template<typename T>
T& LL<T>::operator[](size_t index) const {
    if(index > 0 && index <= size && head != nullptr) {
        ListNode<T>* curr = head;
        int i;
        for(i = 1; i < index && curr != nullptr; i++, curr = curr->next);
        if(i == index && curr != nullptr) {
            return curr->val;
        }else if (curr == nullptr) {
            throw runtime_error("Invalid Index");       
        }
    }
    throw runtime_error("Invalid Index");
}

template<typename T>
void LL<T>::reverse() {
    if(head == nullptr || head->next == nullptr) return;
    ListNode<T>* curr = head;
    ListNode<T>* prev = nullptr;
    while(curr) {
        ListNode<T>* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

#endif