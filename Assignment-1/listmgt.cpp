//
//  listmgt.cpp
//  
//
//  Created by KD on 14.01.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "alist.cpp"
using std::cout;
using std::cin;

int main()
{
    int type, size, op;
    int pos, yes;
    int intitem, result1;
    AList<int> mylist1;
    AList<double> mylist2;
    double doubleitem, result2;
    bool boolresult;
    int k;
    // cout << mylist1[0] << "\n";
    // cout << mylist1[1] << "\n";
    // cout << mylist1[2] << "\n";
    cout << "Test cases for deleting last k elements:\n";
    cout << "Delete 1 element:\nThe original list contains: ";
    for (int i = 0; i < 6; i++){
        mylist1.append(i);
        cout << i << " ";
    }
    cout << "\n";
    mylist1.delete_last_k(1);
    cout << "New list: ";
    int numitems = mylist1.getlength();
    for (int i = 1; i <= numitems; i++){
        cout << mylist1[i] << " ";
    }
    cout << "\n";
    cout << "Delete 2 elements:\nThe original list contains: ";
    AList<int> mylist3;
    for (int i = 0; i < 6; i++){
        mylist3.append(i);
        cout << i << " ";
    }
    cout << "\n";
    mylist3.delete_last_k(2);
    cout << "New list: ";
    numitems = mylist3.getlength();
    for (int i = 1; i <= numitems; i++){
        cout << mylist3[i] << " ";
    }
    cout << "\n";
    cout << "Delete 3 elements:\nThe original list contains: ";
    AList<double> mylist4;
    for (int i = 0; i < 6; i++){
        mylist4.append(i);
        cout << i << " ";
    }
    cout << "\n";
    mylist4.delete_last_k(3);
    cout << "New list: ";
    numitems = mylist4.getlength();
    for (int i = 1; i <= numitems; i++){
        cout << mylist4[i] << " ";
    }
    cout << "\n";
    cout << "Delete all elements:\nThe original list contains: ";
    AList<int> mylist5;
    for (int i = 0; i < 6; i++){
        mylist5.append(i);
        cout << i << " ";
    }
    cout << "\n";
    numitems = mylist5.getlength();
    mylist5.delete_last_k(numitems);
    cout << "New list: ";
    numitems = mylist5.getlength();
    for (int i = 1; i <= numitems; i++){
        cout << mylist5[i] << " ";
    }
    cout << "\n";
    cout << "Delete -1 elements:\nThe original list contains: ";
    AList<int> mylist6;
    for (int i = 0; i < 6; i++){
        mylist6.append(i);
        cout << i << " ";
    }
    cout << "\n";
    mylist6.delete_last_k(-1);
    cout << "New list: ";
    numitems = mylist6.getlength();
    for (int i = 1; i <= numitems; i++){
        cout << mylist6[i] << " ";
    }
    cout << "\n";
    cout << "Delete 100 elements (more than the length of the list):\nThe original list contains: ";
    AList<int> mylist7;
    for (int i = 0; i < 6; i++){
        mylist7.append(i);
        cout << i << " ";
    }
    cout << "\n";
    mylist7.delete_last_k(100);
    cout << "New list: ";
    numitems = mylist7.getlength();
    for (int i = 1; i <= numitems; i++){
        cout << mylist7[i] << " ";
    }
    cout << "\n";

    // cout << "Delete\nThe original list contains: ";
    // AList<int> mylist8;
    // for (int i = 0; i < 6; i++){
    //     mylist8.append(i);
    //     cout << i << " ";
    // }
    // cout << "\n";
    // numitems = mylist8.getlength();
    // mylist8.remove(5);
    // mylist8.remove(4);
    // cout << "New list: ";
    
    // for (int i = 1; i <= 10; i++){
    //     cout << mylist8[i] << " ";
    // }
    // cout << "\n";
    return(0);
}
