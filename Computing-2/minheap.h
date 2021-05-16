//this is the definition of minheap called MINHEAP_H

#ifndef MINHEAP_H
#define MINHEAP_H

#include "ex1ex2.h"

#define MY_INFINITY   99999

class MinHeap
{
public:
	MinHeap(int size);
	~MinHeap();
	void Insert(patient* patient);  // insert an element to minheap
	patient* Delete(); // delete the smallest element from the heap, and return that element
	void swap(int a, int b);
	void heapify(int num);
	void build_min_heap();
    void allocate();
    void deallocate();
    int getnum();
 
private:
	patient** p; // a pointer to an array consisting of pointers to class patient
	int count; // the number of elements currently in the heap
	int maxsize; // the maxsize of elements in the heap
};

#endif // !MINHEAP_H