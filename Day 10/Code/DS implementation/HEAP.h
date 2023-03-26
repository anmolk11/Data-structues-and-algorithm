#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

template <typename T>
class Heap {
    public:
        Heap()
            :
            capacity{INT32_MAX}, arr{new T[INT32_MAX]}, size{-1}
            {} 

        Heap(int n)
            :
            capacity{n}, arr{new T[n]}, size{-1}
            {} 
        T parent(const int&);
        T left(const int&);
        T right(const int&);
        void heapify_rec(const int&);
        bool insert(const T&);
        T delete_key(const T&);
        bool decrease_key(const T&,const T&);
        T getMax() const;
        T extractMax();
        void print() const;

    private:
        T *arr;
        size_t capacity;
        int size;
};

template<typename T>
T Heap<T>::parent(const int& index) {
    if(index > 0 && index <= size) 
        return arr[(index-1)/2];
    return -1;
}

template<typename T>
T Heap<T>::left(const int& index) {
    if(index >= 0 && index <= size) 
        return arr[2*index+1];
    return -1;
}

template<typename T>
T Heap<T>::right(const int& index) {
    if(index >= 0 && index <= size) 
        return arr[2*index+2];
    return -1;
}

template<typename T>
void Heap<T>::heapify_rec(const int& index) {
    int largest = index, left = 2*index+1, right = 2*index+2;
    if(left <= size && arr[left] > arr[largest]) largest = left;
    if(right <= size && arr[right] > arr[largest]) largest = right;
    if(largest != index) {
        swap(arr[index],arr[largest]);
        heapify_rec(largest);
    }
}

template<typename T>
bool Heap<T>::insert(const T& val) {
    if(size == capacity-1)
        return false;
    size++;
    arr[size] = val;
    for(int i = (size-1)/2; i >= 0; i--) {
        heapify_rec(i);
    }
    return true;
}

template<typename T>
T Heap<T>::getMax() const {
    if(size != -1)
        return arr[0];
    throw runtime_error("[Heap is Empty]");
}

template<typename T>
T Heap<T>::extractMax() {
    if(size == -1)
        throw runtime_error("[Heap is empty]");
    T maxEle = arr[0];
    swap(arr[0],arr[size]);
    size--;
    heapify_rec(0);
    return maxEle;
}

template<typename T>
T Heap<T>::delete_key(const T& val) {
    if(size == -1)
        throw runtime_error("[Heap is empty]");
    int i;
    for(i = 0; i <= size; i++)
        if(arr[i] == val)
            break;
    if(i > size)
        return INT32_MAX;
    T returnVal = arr[i];
    swap(arr[i],arr[size]);
    size--;
    heapify_rec(i);
    return returnVal;
}

template<typename T>
bool Heap<T>::decrease_key(const T& val, const T& decVal) {
    if(size == -1)
        throw runtime_error("[Heap is empty]");
    int i;
    for(i = 0; i <= size; i++)
        if(arr[i] == val)
            break;
    if(i > size)
        return false;
    arr[i] = decVal;
    heapify_rec(i);
    return true;
}

template<typename T>
void Heap<T>::print() const {
    for(int i = 0; i <= size; i++) {
        int left{2*i+1},right{2*i+2};
        cout << arr[i] << ": ";
        if(left <= size) {
            cout << "left-> " << arr[left];
        }
        if(right <= size) {
            cout << " right-> " << arr[right];
        }
        cout << endl;
    }
}
#endif