#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "ex1ex2.h"
using namespace std;

/* This series of file is the solution about the exercise 1 and 2.*/
/* In the corresponding header file, we include the definition of a new class patient and its constructor, 
	as well as two global variables used for distributing id. 
	This file includes the function implementation of the class patient and local queue. */


// Class Functions
void patient::age_rank() {
	int diff = 2021 - this->birth;
	if (diff <= 12) {this->aging = 12;}
	else if (diff <= 18) {this->aging = 18;}
	else if (diff <= 35) {this->aging = 35;}
	else if (diff <= 50) {this->aging = 50;}
	else if (diff <= 65) {this->aging = 65;}
	else if (diff <= 75) {this->aging = 75;}
	else if (diff > 75) {this->aging = 76;}  //we use number to represent agings 
}


// Other Funtions
// input : int i -- the number of data csv file we want to open. e.g. if input is 1, we open "data1.csv"
inline localQ<patient*> build_queue(int i) {  // Build a queue of patients from one csv file.
	localQ<patient*> palist;  // Build a new queue to store information. 
	ifstream pafile;
    char filename[30] = {0};
    sprintf(filename, "data%d.csv", i);
	pafile.open(filename,ios::in);  // Text name can be changed, or be set as a parameter.
	int item=0;  // Count for when to turn to next patient.
	int passfirstline=0;  // Used to omit the title line.
	if (!pafile.fail()) { 
		while (!pafile.eof()) {
			if (passfirstline==0) {
				char passing[256];
				pafile.getline(passing,256);
				passfirstline++;
				continue;
			}
			item=0;  // Reset item every time we need a new object of the class patient. 
			patient* ill = new patient();
			while (item>=0) {  // This loop is particularly used to initialize all information about "ill".
				char buf[64];
				pafile.getline(buf,64,',');  // Read in and stop when meeting comma (but never read this comma).
				while (buf[0]=='\n'){
					strcpy(buf, buf+1);  // Delete the "\n"(s) at the front of buf.
				}
				item++;
				switch (item) {  // You can refer to the order in the sample csv.
					case 1:
						/*ill->id=(int)strtol(buf,NULL,10);*/
						if (buf[0]=='\0') {
							delete ill;
							ill=nullptr; 
							item=-2;
							break;
						}
						ill->id=len_N;  // Set the id as the index of the array N.
						break;
					case 2:
						strcpy(ill->name,buf);
						break;
					case 3:
						ill->prof=(int)strtol(buf,NULL,10);
						break;
					case 4:
						ill->time=(int)strtol(buf,NULL,10);
						break; 
					case 5:
						ill->risk=(int)strtol(buf,NULL,10);
						break;
					case 6:
						ill->contact=(int)strtol(buf,NULL,10);
						break;
					case 7:
                        ill->ddl=(int)strtol(buf,NULL,10);
                        break; 
                    case 8:
						ill->closest=(int)strtol(buf,NULL,10);
						break;
					case 9:
						ill->treatment=(int)strtol(buf,NULL,10);
						break;
                    case 10:
                        ill->birth=(int)strtol(buf,NULL,10);
						char buf[64];
						pafile.getline(buf,64,'\n');  // This is because the end of each line in csv is still '\n' rather than ','
						while (buf[0]=='\n'){
							strcpy(buf, buf+1);  // Delete the "\n"(s) at the front of buf.
						}
						strcpy(ill->status,buf);
						item=-1;
						break;
					default:
						cout << "Wrong order!\n";
				}
				if (item==-1) {  // Set to -1 in order to jump out of the while loop and set a new patient* ill.
					ill->age_rank();
					N[len_N++]=ill; 
					palist.pushback(ill);  // This pointer to this patient is stored to the vector palist.
					continue;
				}
			}		
		}
	} else {
		cout << "File open failure!\n";
	}
	pafile.close();
	return palist;
}


// below is the implementation of local queue
template<class T> localQ<T>::localQ(int size)
{
    maxsize = size;
    if (size < 10)
        minsize = size;
    else
        minsize = 10;
    numitems = 0;
    first = 0;
    last = -1;
    reprarray = new T[maxsize];
}


template<class T> T &localQ<T>::operator[](int index)
{
    if ((0 <= index) && (index <= numitems))
    {
        int relindex = (index + first -1) % maxsize;
        return reprarray[relindex];
    }
    else
    {
        cout << "Error: index " << index << " out of range.\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> int localQ<T>::getlength(void)
{
    return numitems;
}

template<class T> bool localQ<T>::isempty(void)
{
    if (numitems == 0)
        return true;
    else
        return false;
}

template<class T> T localQ<T>::front(void)
{
    if (isempty() == false)
        return reprarray[first];
    else
    {
        cout << "The queue is empty.\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> T localQ<T>::back(void)
{
    if (isempty() == false)
    {
        int relindex = (first + numitems - 1) % maxsize;
        return reprarray[relindex];
    }
    else
    {
        cout << "The queue is empty.\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> void localQ<T>::pushback(T value)
{
    if (numitems == maxsize)
        allocate();
    last = ++last % maxsize;
    reprarray[last] = value;
    ++numitems;
    return;
}

template<class T> T localQ<T>::popfront(void)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    if (isempty() == false)
    {
        T frontelement = reprarray[first];
        first = ++first % maxsize;
        --numitems;
        return frontelement;
    }
    else
    {
        cout << "The queue is empty.\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> void localQ<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        int pos = (i + first) % maxsize;
        newarray[i] = reprarray[pos];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    first = 0;
    last = numitems -1;
    return;
}

template<class T> void localQ<T>::deallocate(void)
{
    int newsize = maxsize / 2;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        int pos = (i + first) % maxsize;
        newarray[i] = reprarray[pos];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    first = 0;
    last = numitems -1;
    return;
}





