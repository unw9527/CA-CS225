#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

class patient {
	public:
		/* Class Members */
		// All arrays allow change in length. */
		int id;
		char name[30];
		int contact;  // 8-digit phone number.
		int prof;  // Here we use int from 1 to 8. You can let number order represent priority.
		int birth;  // 4 digit always, only the year.
		int risk;  // Here we use int from 0 to 3, as shown in the pdf.
		char time[15];  // 14 digits always, in the form yyyy-mm-dd-hh-mm-ss.
		int aging;  // Store the group that one person should be in w.r.t their age. This is essential for second priority.
		patient* prev;
		patient* next;  // Used to build fibonacci heap.
		char status[10];  // applied, waiting, allocated, completed or withdrawn. 
		
		/* Class Functions */
		patient(); 
		  //~patient();
		void age_rank(int year_now);
		
};


patient::patient(){
	this->prev=NULL;
	this->next=NULL;
}


