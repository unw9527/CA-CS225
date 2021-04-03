#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

// below is the template for local queue
class patient;
template<class T> class localQ
{
	public:
		localQ(int size = 10);
	//    virtual ~localQ();
		T &operator[](int index);
		int getlength(void);
		bool isempty(void);
		T back(void); // get the last element 
		T front(void); // get the first element
		void pushback(T value);
		T popfront(void);
		
    
	private:
		int maxsize, minsize;
		int first, last;
		int numitems;
		T *reprarray;
		
		void allocate(void);
		void deallocate(void);
};

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


