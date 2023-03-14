#include<iostream>
#include<queue>

using namespace std;


int main(){
    queue<int> Q;

    Q.push(10);
    Q.push(20);
    Q.push(30);


    Q.pop();
    

    cout<<"Current front element is : "<<Q.front()<<'\n';

    Q.push(40);
    Q.push(50);
    Q.push(60);


    while(!Q.empty()){
        cout<<"Current front element is : "<<Q.front()<<'\n';
        Q.pop();
    }
}

