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
    cout << "Test cases for deleting last k elements:\n";
    cout << "Delete 1 element:\nThe original list contains: ";
    for (int i = 0; i < 6; i++){
        mylist1.append(i); // print out the original list
        cout << i << " ";
    }
    cout << "\n";
    mylist1.delete_last_k(1);
    cout << "New list: "; // print out the list with elements deleted
    int numitems = mylist1.getlength(); // get the length of the list
    for (int i = 1; i <= numitems; i++){
        cout << mylist1[i] << " ";
    }
    cout << "\n";
    cout << "Delete 2 elements:\nThe original list contains: ";
    AList<int> mylist3;
    for (int i = 0; i < 6; i++){
        mylist3.append(i); // print out the original list
        cout << i << " ";
    }
    cout << "\n";
    mylist3.delete_last_k(2);
    cout << "New list: "; // print out the list with elements deleted
    numitems = mylist3.getlength(); // get the length of the list
    for (int i = 1; i <= numitems; i++){
        cout << mylist3[i] << " ";
    }
    cout << "\n";
    cout << "Delete 3 elements:\nThe original list contains: ";
    AList<double> mylist4;
    for (int i = 0; i < 6; i++){
        mylist4.append(i); // print out the original list
        cout << i << " ";
    }
    cout << "\n";
    mylist4.delete_last_k(3);
    cout << "New list: "; // print out the list with elements deleted
    numitems = mylist4.getlength(); // get the length of the list
    for (int i = 1; i <= numitems; i++){
        cout << mylist4[i] << " ";
    }
    cout << "\n";
    cout << "Delete all elements:\nThe original list contains: ";
    AList<int> mylist5;
    for (int i = 0; i < 6; i++){
        mylist5.append(i); // print out the original list
        cout << i << " ";
    }
    cout << "\n";
    numitems = mylist5.getlength();
    mylist5.delete_last_k(numitems); // get the length of the list
    cout << "New list: "; // print out the list with elements deleted
    numitems = mylist5.getlength(); // get the length of the new list
    for (int i = 1; i <= numitems; i++){
        cout << mylist5[i] << " ";
    }
    cout << "\n";
    cout << "Delete -1 elements:\nThe original list contains: ";
    AList<int> mylist6;
    for (int i = 0; i < 6; i++){
        mylist6.append(i); // print out the original list
        cout << i << " ";
    }
    cout << "\n";
    mylist6.delete_last_k(-1);
    cout << "New list: "; // print out the list with elements deleted
    numitems = mylist6.getlength(); // get the length of the list
    for (int i = 1; i <= numitems; i++){
        cout << mylist6[i] << " ";
    }
    cout << "\n";
    cout << "Delete 100 elements (more than the length of the list):\nThe original list contains: ";
    AList<int> mylist7;
    for (int i = 0; i < 6; i++){
        mylist7.append(i); // print out the original list
        cout << i << " ";
    }
    cout << "\n";
    mylist7.delete_last_k(100);
    cout << "New list: "; // print out the list with elements deleted
    numitems = mylist7.getlength(); // get the length of the list
    for (int i = 1; i <= numitems; i++){
        cout << mylist7[i] << " ";
    }
    cout << "\n";
    cout << "\n";

    cout << "Test cases for problem 2.4: \n";
    int e;
    AList<int> mylist8;
    // mylist8.append(100);
    cout << "f(x) = x + 5 and g(x,y) = x + y\n";
    cout << "operating on mylist1:\n"; // the following tests cover cases where the list is not empty
    cout << "e = 0\nResult: ";
    cout << mylist1.src(0,f_fun,g_fun,mylist1) << "\n";
    cout << "e = -1\nResult: ";
    cout << mylist1.src(-1,f_fun,g_fun,mylist1) << "\n";
    cout << "e = 2\nResult: ";
    cout << mylist1.src(2,f_fun,g_fun,mylist1) << "\n";
    cout << "e = 1.5\nResult: ";
    cout << mylist1.src(1.5,f_fun,g_fun,mylist1) << "\n" << "\n";

    cout << "operating on an empty list:\n"; // the following tests cover cases where the list is empty 
    cout << "e = 2\nResult: ";
    cout << mylist8.src(2,f_fun,g_fun,mylist8) << "\n";
    cout << "e = 1.5\nResult: ";
    cout << mylist8.src(1.5,f_fun,g_fun,mylist8) << "\n";
    cout << "\n";


    cout << "Test cases for selection sort:\n";
    
    cout << "Do selection sort for an descending integer list:\nThe original list contains: ";
    AList<int> listselect;
    for (int i=6; i>=0; i--) {
    	listselect.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listselect.selectionSort(); // Do the bubble sort using implemented function.
	numitems = listselect.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listselect[i] << " ";
	}
	cout << "\n";
	cout << "Do selection sort for an descending double list:\nThe original list contains: ";
	AList<double> listselect1;
    for (double i=1.98; i>=1.82; i-=0.02) {
    	listselect1.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listselect1.selectionSort(); // Do the bubble sort using implemented function.
	numitems = listselect1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listselect1[i] << " ";
	}
	cout << "\n";
	
	
	cout << "\n" << "Test cases for bubble sort:\n";
    
    cout << "Do bubble sort for an descending integer list:\nThe original list contains: ";
    AList<int> listbubble;
    for (int i=9; i>=1; i--) {
    	listbubble.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listbubble.bubbleSort(); // Do the selection sort using implemented function.
	numitems = listbubble.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble[i] << " ";
	}
	cout << "\n";
	cout << "Do bubble sort for an descending double list:\nThe original list contains: ";
	AList<double> listbubble1;
    for (double i=3.5; i>=3.1; i-=0.05) {
    	listbubble1.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listbubble1.bubbleSort(); // Do the selection sort using implemented function.
	numitems = listbubble1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble1[i] << " ";
	}
	cout << "\n";
    return(0);
}
