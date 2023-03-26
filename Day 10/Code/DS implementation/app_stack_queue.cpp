#include <iostream>
using namespace std;

#include "CIRCULAR_QUEUE.h"
int main() {
    int n;
    cin >> n;
    CircluarQueue<int> myQueue(n);
    while(true) {
        cout << "------------------- MENU -------------------" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print" << endl;
        cout << "4. Size" << endl;
        cout << "0. EXIT" << endl;
        cout << "Choice --> ";
        int choice;
        cin >> choice;
        cout << "---------------------------------------------" << endl;
        switch (choice) {
        case 1: {
            int ele;
            cout << "!!! PUSH FRONT !!!" << endl;
            cout << "Element value : ";
            cin >> ele;
            myQueue.enqueue(ele);
            break;
        }
        case 2: {
            int ele;
            cout << "!!! POP ELEMENT !!!" << endl;
            int deleted = myQueue.dequeue();
            cout << "Element " << deleted << " deleted successfully" << endl;
            break;
        }
        case 3: {
            cout << "!!! PRINT LIST !!!" << endl;
            myQueue.print();
            break;
        }   
        case 4: {
            cout << "SIZE : " << myQueue.getLength() << endl;
            break;
        }
        case 0: {
            return 0;
            break;
        }
        default:
            cout << "!! Incorrect Option" << endl;
            break;
        }
        cout << "---------------------------------------------" << endl;
    }

}