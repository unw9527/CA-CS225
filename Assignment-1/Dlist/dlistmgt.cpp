//
//  dlistmgt.cpp
//  
//
//  Created by KD on 14.01.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "dlist.cpp"
using std::cout;
using std::cin;

int main()
{
    int type, op;
    int pos, yes;
    int intitem, result1;
    int numitems; // Newly added.
    DList<int> mylist1 = DList<int>();
    DList<double> mylist2 = DList<double>();
    double doubleitem, result2;
    bool boolresult;
    cout << "Test cases for insertion sort:\n";
    
    cout << "Do insertion sort for an descending integer list:\nThe original list contains: ";
    DList<int> listinsert;
    for (int i=6; i>=0; i--) {
    	listinsert.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listinsert.insertionSort(); // Do the insertion sort using implemented function.
	numitems = listinsert.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listinsert[i] << " ";
	}
	cout << "\n";
	cout << "Do insertion sort for an descending double list:\nThe original list contains: ";
	DList<double> listinsert1;
    for (double i=1.98; i>=1.82; i-=0.02) {
    	listinsert1.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listinsert1.insertionSort(); // Do the insertion sort using implemented function.
	numitems = listinsert1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listinsert1[i] << " ";
	}
	cout << "\n";
	
	
	cout << "\n" << "Test cases for bubble sort:\n";
    
    cout << "Do bubble sort for an descending integer list:\nThe original list contains: ";
    DList<int> listbubble;
    for (int i=9; i>=1; i--) {
    	listbubble.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listbubble.bubbleSort(); // Do the bubble sort using implemented function.
	numitems = listbubble.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble[i] << " ";
	}
	cout << "\n";
	cout << "Do bubble sort for an descending double list:\nThe original list contains: ";
	DList<double> listbubble1;
    for (double i=3.5; i>=3.1; i-=0.05) {
    	listbubble1.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listbubble1.bubbleSort(); // Do the bubble sort using implemented function.
	numitems = listbubble1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble1[i] << " ";
	}
	cout << "\n";

    return(0);
}
