// Circular Linked List Implementation
#ifndef CLL_H
#define CLL_H

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
class CLL {
    public:
        // Utilities
        CLL():size{0}, head{nullptr}{}
        ~CLL(){
            if (size == 1) {
                delete head;
            }else if (size > 1){
                ListNode<T>* curr = head->next;
                while(curr->next != head) {
                    curr = curr->next;
                }
                curr->next = nullptr;
                curr = head;
                while(curr) {
                    ListNode<T>* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                delete head;
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
inline void CLL<T>::push_back(const T& ele) {
    if(head == nullptr) {
        head = new ListNode<T>(ele);
        head->next = head;
    }else {
        ListNode<T>* curr = head;
        while(curr->next != head) {
            curr = curr->next;
        }
        curr->next = new ListNode<T>(ele,head);
    }
    size++;
}

template<typename T>
inline void CLL<T>::push_front(const T& ele) {
    if(head == nullptr) {
        head = new ListNode<T>(ele);
        head->next = head;
    }else {
        ListNode<T>* newNode = new ListNode<T>(ele,head);
        ListNode<T>* curr = head;
        while(curr->next != head) {
            curr = curr->next;
        }
        curr->next = newNode;
        head = newNode;
    }
    size++;
}

template<typename T>
void CLL<T>::add_element(const size_t index,const T& ele) {
    if(index <= 0 || index > size) {
        throw runtime_error("Error : Index out of bounds");
    }
    if(index == 1) {
        push_front(ele);
    }else if (index == size) {
        push_back(ele);
    }else {
        ListNode<T>* prev = nullptr;
        ListNode<T>* curr = head;
        for(int i = 1; i < index; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = new ListNode<T>(ele,curr);
    }
    size++;
}

template<typename T>
inline T CLL<T>::delete_element(const T& ele) {
    if(head == nullptr) {
        throw runtime_error("List in empty");
    }
    ListNode<T>* curr = head->next;
    ListNode<T>* prev = head;
    while(curr != head && curr->val != ele) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == head && curr->val != ele) {
        throw runtime_error("!! Element Not Found !!");
    }
    ListNode<T>* temp = curr;
    T delete_val = temp->val;
    if(prev->next != curr->next)
        prev->next = curr->next;
    size--;
    if(temp == head && size > 0) head = head->next;
    if(size == 0) head = nullptr;
    delete temp;
    return delete_val;
}


template<typename T>
void CLL<T>::print() const{
    if(head == nullptr) {
        throw runtime_error("!! List is empty !!");
        return;
    }
    ListNode<T>* curr = head;
    if(size == 1) {
        cout << curr->val;
    }else {
        while(curr->next != head) {            
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << curr->val;
    }
    cout << endl;
}

template<typename T>
T& CLL<T>::operator[](size_t index) const {
    if(index > 0 && index <= size && head != nullptr) {
        ListNode<T>* curr = head;
        int i;
        for(i = 1; i < index && curr->next != head; i++, curr = curr->next);
        if(i == index) {
            return curr->val;
        }else if (curr == nullptr) {
            throw runtime_error("Invalid Index");       
        }
    }
    throw runtime_error("Invalid Index");
}

template<typename T>
void CLL<T>::reverse() {
    if(head == nullptr || head->next == head) return;
    ListNode<T>* curr = head;
    ListNode<T>* prev = nullptr;
    ListNode<T>* next = nullptr;
    while(curr->next != head) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    head->next = curr;
    head = curr;
}

#endif