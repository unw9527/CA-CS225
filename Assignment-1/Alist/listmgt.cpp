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
    for (double i = 0.01; i < 6.08; i = i + 1.01){
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
    
    cout << "Do selection sort for a non-increasing integer list:\nThe original list contains: ";
    AList<int> listselect;
    for (int i=6; i>=0; i--) {
    	listselect.append(i); // Use this loop to build a non-increasing list.
    	cout << i << " ";
	}
	int ei1=9;
	listselect.append(ei1);
	cout << ei1 << " ";
	cout << "\n";
	listselect.selectionSort(); // Do the bubble sort using implemented function.
	numitems = listselect.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listselect[i] << " ";
	}
	cout << "\n";
	cout << "Do selection sort for a non-increasing double list:\nThe original list contains: ";
	AList<double> listselect1;
    for (double i=1.98; i>=1.82; i-=0.02) {
    	listselect1.append(i); // Use this loop to build a non-increasing list.
    	cout << i << " ";
	}
	double ed1=1.85;
	listselect1.append(ed1);
	cout << ed1 << " ";
	cout << "\n";
	listselect1.selectionSort(); // Do the bubble sort using implemented function.
	numitems = listselect1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listselect1[i] << " ";
	}
	cout << "\n";
	
	
	cout << "\n" << "Test cases for bubble sort:\n";
    
    cout << "Do bubble sort for a non-increasing integer list:\nThe original list contains: ";
    AList<int> listbubble;
    for (int i=9; i>=1; i--) {
    	listbubble.append(i); // Use this loop to build a non-increasing list.
    	cout << i << " ";
	}
	int ei2=11;
	listbubble.append(ei2);
	cout << ei2 << " ";
	cout << "\n";
	listbubble.bubbleSort(); // Do the selection sort using implemented function.
	numitems = listbubble.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble[i] << " ";
	}
	cout << "\n";
	cout << "Do bubble sort for a non-increasing double list:\nThe original list contains: ";
	AList<double> listbubble1;
    for (double i=3.5; i>=3.1; i-=0.05) {
    	listbubble1.append(i); // Use this loop to build a non-increasing list.
    	cout << i << " ";
	}
	double ed2=3.13;
	listbubble1.append(ed2);
	cout << ed2 << " ";
	cout << "\n";
	listbubble1.bubbleSort(); // Do the selection sort using implemented function.
	numitems = listbubble1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble1[i] << " ";
	}
	cout << "\n" << "\n";
    
	// Test cases for Ex.3
	int lenlist; // Added to get the length of list.
	CList<int> newlist1;
	CList<double> newlist2;
	cout << "Newly built (and thus empty) CLists should not accept pop- functions!\n";
	cout << "Test popback for empty integer and double lists:\n";
	cout << "Integer List: ";
	newlist1.popback();
	cout << "Double List: ";
	newlist2.popback();
	cout << "Test popfront for empty integer and double lists:\n";
	cout << "Integer List: ";
	newlist1.popfront();
	cout << "Double List: ";
	newlist2.popfront();
	cout << "Empty tests passed.\n\n";
	
	cout << "The original integer list is: ";
	for (int i=1;i<4;i++) {
		newlist1.pushback(i);
		cout << i << " ";
	}
	cout << "\n";
	cout << "The original double list is: ";
	for (double i=1.46;i<1.54;i+=0.02) {
		newlist2.pushback(i);
		cout << i << " ";
	}
	cout << "\n(This part of initialization is also done by pushback.)\n" << "\n";
	
	
	cout << "Test cases for pushback:\n";
    cout << "Do pushback for newlist1 (push 7 here):\n";
    newlist1.pushback(7); // Do pushback.
	lenlist = newlist1.getlength(); // Get the length of the new list.
	cout << "Pushed newlist1: ";
	for (int i=1; i<=lenlist; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do pushback for newlist2 (push 1.7 here):\n";
    newlist2.pushback(1.7); // Do pushback.
	lenlist = newlist2.getlength(); // Get the length of the new list.
	cout << "Pushed newlist2: ";
	for (int i=1; i<=lenlist; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n" << "\n";
	
	
	cout << "Test cases for pushfront:\n";
    cout << "Do pushfront for newlist1 (push 5 here):\n";
    newlist1.pushfront(5); // Do pushfront.
	lenlist = newlist1.getlength(); // Get the length of the new list.
	cout << "Pushed newlist1: ";
	for (int i=1; i<=lenlist; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do pushfront for newlist2 (push 6.4 here):\n";
    newlist2.pushfront(6.4); // Do pushfront.
	lenlist = newlist2.getlength(); // Get the length of the new list.
	cout << "Pushed newlist2: ";
	for (int i=1; i<=lenlist; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n" << "\n";
	
	
	cout << "Test cases for popback:\n";
    cout << "Do popback for newlist1 (should pop 7):\n";
    int pop_int;
    pop_int=newlist1.popback(); // Do popback.
    cout << "The poped value is: " << pop_int << "\n";
	lenlist = newlist1.getlength(); // Get the length of the new list.
	cout << "Poped newlist1: ";
	for (int i=1; i<=lenlist; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do popback for newlist2 (should pop 1.7):\n";
	double pop_double;
	pop_double=newlist2.popback(); // Do popback.
	cout << "The poped value is: " << pop_double << "\n";
	lenlist = newlist2.getlength(); // Get the length of the new list.
	cout << "Poped newlist2: ";
	for (int i=1; i<=lenlist; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n" << "\n";
	
	
	cout << "Test cases for popfront:\n";
    cout << "Do popfront for newlist1 (should pop 5):\n";
    int pop_int0;
    pop_int0=newlist1.popfront(); // Do popfront.
    cout << "The poped value is: " << pop_int0 << "\n";
	lenlist = newlist1.getlength(); // Get the length of the new list.
	cout << "Poped newlist1: ";
	for (int i=1; i<=lenlist; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do popfront for newlist2 (should pop 6.4):\n";
	double pop_double0;
	pop_double0=newlist2.popfront(); // Do popfront.
	cout << "The poped value is: " << pop_double0 << "\n";
	lenlist = newlist2.getlength(); // Get the length of the new list.
	cout << "Poped newlist2: ";
	for (int i=1; i<=lenlist; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n";
	
	
	return(0);
}
