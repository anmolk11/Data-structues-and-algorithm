#include <iostream>
#include "HEAP.h"
using namespace std;

int main() {
    Heap<int> heap;
    while(1) {
        cout << "````````````````````````````` MENU `````````````````````````````" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete any element" << endl;
        cout << "3. Extract Max" << endl;
        cout << "4. Get Max" << endl;
        cout << "5. Decrease Key" << endl;
        cout << "6. Print Heap" << endl;
        cout << "0. Exit" << endl;
        int choice;
        cout << "Choice --> ";
        cin >> choice;
        cout << "---------------------------------------------------------------------------" << endl;
        switch (choice) {
            case 1: {
                cout << "~~~~ INSERT ~~~~" << endl;
                int val;
                cout << "Enter value : ";
                cin >> val;
                if(heap.insert(val))
                    cout << val << " : Inserted successfully" << endl;
                else
                    cout << "!!! Error : either heap is full !!!" << endl;
                break;
            }
            case 2: {
                cout << "~~~~ Delete ~~~~" << endl;
                int val;
                cout << "Enter value to delete : ";
                cin >> val;
                int deleteKey = heap.delete_key(val);
                if(deleteKey != INT32_MAX) {
                    cout << deleteKey << " : successfully deleted" << endl;
                }else {
                    cout << "!!! Error : key not found !!!" << endl;
                }
                break;
            }
            case 3: {
                cout << "~~~~ Extract Max ~~~~" << endl;
                int popedKey = heap.extractMax();
                cout << "Successfully poped max : " << popedKey << endl;
                break;
            }
            case 4: {
                cout << "~~~~ Get Max ~~~~" << endl;
                cout << "Maximum : " << heap.getMax() << endl;
                break;            
            }
            case 5: {
                cout << "~~~~ Decrease Key ~~~~" << endl;
                int val,decVal;
                cout << "Enter key value to decrease : ";
                cin >> val;
                cout << "Enter new decresed value : ";
                cin >> decVal;
                if(heap.decrease_key(val,decVal)) {
                    cout << "Key Decreased successfully" << endl;
                }else {
                    cout << "!!! Error : Key not found" << endl;
                }
                break;
            }
            case 6: {
                cout << "~~~~ Print Heap ~~~~" << endl;
                heap.print();
                break;
            }
            case 0:
                return 0;
                break;
            default:
                cout << "~~~ Incorrect option ~~~" << endl;
                break;
        }
        cout << "---------------------------------------------------------------------------" << endl;
    }
    return 0;
}