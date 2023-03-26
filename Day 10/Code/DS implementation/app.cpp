#include <iostream>
using namespace std;

#include "DCLL.h"
int main()
{
    DCLL<int> myList;
    while (true)
    {
        cout << "------------------- MENU -------------------" << endl;
        cout << "1. Push front" << endl;
        cout << "2. Push back" << endl;
        cout << "3. Push index" << endl;
        cout << "4. Delete element" << endl;
        cout << "5. Print" << endl;
        cout << "6. Get element of specific index" << endl;
        cout << "7. Size of Linkled List currently" << endl;
        cout << "8. Reverse linked list" << endl;
        cout << "0. EXIT" << endl;
        cout << "Choice --> ";
        int choice;
        cin >> choice;
        cout << "---------------------------------------------" << endl;
        switch (choice)
        {
        case 1:
        {
            int ele;
            cout << "!!! PUSH FRONT !!!" << endl;
            cout << "Element value : ";
            cin >> ele;
            myList.push_front(ele);
            break;
        }
        case 2:
        {
            int ele;
            cout << "!!! PUSH Back !!!" << endl;
            cout << "Element value : ";
            cin >> ele;
            myList.push_back(ele);
            break;
        }
        case 3:
        {
            int ele;
            size_t index;
            cout << "!!! PUSH Index !!!" << endl;
            cout << "Index value : ";
            cin >> index;
            cout << "Element value : ";
            cin >> ele;
            myList.add_element(index, ele);
            break;
        }
        case 4:
        {
            int ele;
            cout << "!!! DELETE ELEMENT !!!" << endl;
            cout << "Element value : ";
            cin >> ele;
            int deleted = myList.delete_element(ele);
            if (deleted == ele)
            {
                cout << "Element " << deleted << " deleted successfully" << endl;
            }
            else
            {
                cout << "!! Error : something went wrong deleting the element" << endl;
            }
            break;
        }
        case 5:
        {
            cout << "!!! PRINT LIST !!!" << endl;
            myList.print();
            break;
        }
        case 6:
        {
            int index;
            cout << "!!! GET ELEMENT AT specific index !!!" << endl;
            cout << "Index value : ";
            cin >> index;
            cout << "Element myList[" << index << "] = " << myList[index] << endl;
            break;
        }
        case 7:
        {
            cout << "SIZE : " << myList.length() << endl;
            break;
        }
        case 8:
        {
            cout << "!!! REVERSING LIST !!!" << endl;
            myList.reverse();
            break;
        }
        case 0:
        {
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