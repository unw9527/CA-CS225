//this is the head file of f.cpp

#ifndef F_H
#define F_H


#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "ex1ex2.h"
using namespace std;

//define a new class called F_h for Fibonacci heap

class F_h
{
public:
	
    F_h(void);
    int n;
    patient* min;
    int degree;
    void insert(patient* p);
    void brother(patient* p1,patient* p2);
    void delet(patient* p);
    patient* extract_min();
    patient* parent_child(patient* p1,patient* p2);
    void consolidate();
    void decrease_key(patient* p,int k,int cas);
    void cascading_cut(patient* p);
    void print_heap();
    void print_child(patient* p);
};

//it's the constructor function for F_h
F_h::F_h(){
    min=new patient;
    min=nullptr;
    n=0;
}
#endif
