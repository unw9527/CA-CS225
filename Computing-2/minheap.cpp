//this is the definition of functions of MINHEAP_H

#include<iostream>
#include"minheap.h"
#include "f.cpp"

MinHeap::MinHeap(int size)
{
	maxsize = size;
	p = new patient*[maxsize + 1];
	if (p == nullptr) { cout << "Allocation fails!" << endl; exit(-1); }
	count = 0;
}
 
MinHeap::~MinHeap()
{
	if (p != nullptr) delete[] p;
}

void MinHeap::swap(int a, int b){
	patient* temp = p[a];  // note that here we cannot directly swap pointers because it yields no effect after swap ends
	p[a] = p[b]; 
	p[b] = temp; 
}

// below is just the classical implementation of heapify
void MinHeap::heapify(int num){ 
	int s = num;
		int l = 2 * s + 1;
		int r = 2 * s + 2;
		// the condition below based on ddl. If two ddls are the same, we further call compare defined 
		// in f.cpp to compare the priority of two nodes.
		if ((l < count) && ((p[l]->ddl < p[s]->ddl) || ((p[l]->ddl == p[s]->ddl) && compare(p[l], p[s])))){
			s = l;
		}
		if ((r < count) && ((p[r]->ddl < p[s]->ddl) || ((p[r]->ddl == p[s]->ddl) && compare(p[r], p[s])))){
			s = r;
		}
		if (s != num){
			swap(s, num);
			heapify(s);
		}
}

// below is the code to build a minheap using heapify defined above
void MinHeap::build_min_heap(){
	for (int i = count/2-1; i >= 0; i--){
		heapify(i);
	}
}

void MinHeap::Insert(patient* patient){
	count++;
	if (maxsize == count) {
		allocate(); // if we have reached the maxsize, allocate again to give a bigger size array
	} 
	p[count - 1] = patient;
}

patient* MinHeap::Delete(){
	patient* min = p[0]; // we just return the first element and remove it
	swap(0, count-1);
	count--;
	if (maxsize > count * 2) {
		deallocate(); // if the number of elements in the array is less than half of maxsize, deallocate.
	} 
	build_min_heap();
	return min;
}

int MinHeap::getnum(){
	return count;	//it's the functionfor return count
}

void MinHeap::allocate(){	//it's the allocate function for minheap
	int newsize = 2 * maxsize;
    patient **newarray = new patient*[newsize];	//initialize new array
    for (int i = 0; i < count; ++i)
    {
        newarray[i] = p[i];
    }
    delete[] p;
    p = newarray;
    maxsize = newsize;	//allocation finished
    return;
}

void MinHeap::deallocate(){	//it's the function for deallocate
	int newsize = maxsize / 2;
    patient **newarray = new patient*[newsize];	//initialize new array
    for (int i = 0; i < count; ++i)
    {
        newarray[i] = p[i];
    }
    delete[] p;
    p = newarray;
    maxsize = newsize;	//deallocation finished
    return;
}
 
 
 
