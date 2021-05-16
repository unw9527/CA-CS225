#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#ifndef ex1ex2_h
#define ex1ex2_h

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

class patient {///
	public:
		/* Class Members */
		// All arrays allow change in length. */
		int id;
		char name[30];
		int contact;  // 8-digit phone number.
		int prof;  // Here we use int from 1 to 8. You can let number order represent priority.
		int birth;  // 4 digit always, only the year.
		int risk;  // Here we use int from 0 to 3, as shown in the pdf.
		int time;  // 5 digits, in the form mm-dd-(0==am or 1==pm).
		int aging;  // Store the group that one person should be in w.r.t their age. This is essential for second priority.
		char status[10];  // applied, waiting, allocated, completed or withdrawn. 
		
		int ddl; // the time before which the patient with a priority letter must be treated
		int closest;  // indicate the closest hospital of one patient
		
		/* Class Functions */
		patient();
		patient(int nid, char nam[30], int pro, int tim, int ris, int phone, int bir, char state[10]);
		  //~patient();
		void age_rank();
		patient* left;
		patient* right;
		patient* parent;
		patient* child;
		bool marked;
		int degree;
};


// Global variables
patient* N[1000];
int len_N=0; 


patient::patient(){
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	child = nullptr;
	marked = 0;
	degree = 0;
}

patient::patient(int nid, char nam[30], int pro, int tim, int ris, int phone, int bir, char state[10]) {
	this->id=nid;
	strcpy(this->name,nam);
	this->prof=pro;
	this->time=tim;
	this->risk=ris;
	this->contact=phone;
	this->birth=bir;
	strcpy(this->status,state);
	
	N[len_N++]=this;  // Put the pointer into the global array.
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	child = nullptr;
	marked = 0;
	degree = 0;
};
#endif
/*
#ifndef f_h
#define f_h

template<class T> class F_h;


template<class T> class F_h
{
public:
    F_h(void);
    int n;
    patient *min;
    int degree;
    void insert(patient* p);
    void brother(patient* p1,patient* p2);
    void delete(patient* p);
    patient* extract_min();
    patient* parent_child(patient* p1,patient* p2);
    void consolidate();
    void decrease_key(patient* p, int k, int case);
    void cascading_cut(patient* p);
}
F_h::F_h(){
    min=new node;
    min=nullptr;
    n=0;
}

#endif

*/
