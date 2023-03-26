#ifndef DLL_H
#define DLL_h


template<typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode* prev;
    ListNode(const T val, ListNode* next = nullptr, ListNode* prev = nullptr)
        :
        val{val},next{next}, prev{prev}
        {}
};

template<typename T>
class DLL {
    public:
        DLL()
            :
            size{0}, head{nullptr}
            {}
        ~DLL() {
            ListNode<T>* curr = head;
            while(curr) {
                ListNode<T>* temp = curr;
                curr = curr->next;
                delete temp;
            }
            std::cout << "List Deleted Successfully" << std::endl;
        }

        void push_back(const T&);
        void push_front(const T&);
        void add_element(const size_t&,const T&);
        T pop(const T&);

        void reverse();
        size_t length() const;
        void print() const;

        T& operator[](const size_t&) const;
    private:
        ListNode<T>* head;
        size_t size;
};

template<typename T>
void DLL<T>::push_back(const T& val) {
    if(head == nullptr) {
        head = new ListNode<T>(val);
    }else {
        ListNode<T>* curr = head;
        while(curr->next)   curr = curr->next;
        curr->next = new ListNode<T>(val,nullptr,curr);
    }
    size++;
}

template<typename T>
void DLL<T>::push_front(const T& val) {
    if(head == nullptr) {
        head = new ListNode<T>(val);
    }else {
        ListNode<T>* newNode = new ListNode<T>(val,head);
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template<typename T>
void DLL<T>::add_element(const size_t& index,const T& val) {
    if(index > 0 && index <= size) {
        size_t i = 1;
        ListNode<T>* curr = head;
        while(i != index) {
            curr = curr->next;
            i++;
        } 
        if(curr == head) {
            ListNode<T>* newNode = new ListNode<T>(val,head);
            head->prev = newNode;
            head = newNode;
        }else {
            ListNode<T>* newNode = new ListNode<T>(val,curr,curr->prev);
            curr->prev->next = newNode;
            if(newNode->next)
                newNode->next->prev = newNode;
        }
        size++;
    }else {
        throw runtime_error("Index Out of Bounds");
    }
}

template<typename T>
T DLL<T>::pop(const T& val) {
    ListNode<T>* curr = head;
    while(curr && curr->val != val) {
        curr = curr->next;
    }
    if(curr == nullptr) {
        throw runtime_error("Element not found");
    }
    ListNode<T>* temp = curr;
    T data = temp->val;
    if(curr == head) {
        head = head->next;
        head->prev = nullptr;
    }else {
        curr->prev->next = curr->next;
        if(curr->next)
            curr->next->prev = curr->prev;
    }
    size--;
    delete temp;
    return data;
}

template<typename T>
T& DLL<T>::operator[](const size_t& index) const {
    ListNode<T>* curr = head;
    if(index > 0 && index <= size) {
        size_t i = 1;
        while(i != index) {
            curr = curr->next;
            i++;
        }
    }else {
        throw runtime_error("Invalid Index");
    }
    return curr->val;
}

template<typename T>
size_t DLL<T>::length() const {
    return this->size;
}

template<typename T>
void DLL<T>::print() const {
    for(ListNode<T>* i = head; i != nullptr; i = i->next) {
        if(i->next)
            std::cout << i->val << " -> ";
        else
            std::cout << i->val;
    }
    std::cout << std::endl;
}

template<typename T>
void DLL<T>::reverse() {
    if(head == nullptr || head->next == nullptr)    return;
    ListNode<T>* curr = head;
    while(curr->next) {
        ListNode<T>* next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
    }
    curr->next = curr->prev;
    curr->prev = nullptr;
    head = curr;
}

#endif