#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int *A;
        int top;
        int size;
    public:
        Stack(int size){
            this->size = size;
            top = -1;
            A = new int[size];
        }
        
        void push(int x);
        int pop();
        bool empty();
        int top_();

        // just for understanding purpose
        // we can not iterate over stack, because it violates the properties
        void print(){
            cout<<"\n----\n";
            for(int i = top;i >= 0;i--){
                cout<<A[i]<<'\n';
            }
            cout<<"\n----\n";
        }
        
                
        ~Stack(){
            // to avoid memory leaks
            delete[] A;
        }
};


void Stack::push(int x){
    if(top == size - 1){
        return;
    }
    ++top;
    A[top] = x;
}

int Stack::pop(){
    if(empty()){
        return INT_MIN;
    }
    int x = A[top];
    --top;
    return x;
}

bool Stack::empty(){
    return top == -1;
}

int Stack::top_(){
    if(empty()){
        return INT_MIN;
    }
    return A[top];
}

int main(){
    Stack stk(5);

    stk.push(10);
    stk.push(20);
    stk.push(30);

    // stk.print();

    // cout<<"Poped : "<<stk.pop()<<'\n';
    // stk.print();

    stk.push(40);
    // stk.print();

    while(!stk.empty()){
        stk.print();
        cout<<"Top : "<<stk.top_()<<'\n';
        stk.pop();
    }
}