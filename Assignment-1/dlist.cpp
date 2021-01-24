//
//  dlist.cpp
//  
//
//  Created by KD on 16.01.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "dlist.h"
using std::cout;
using std::cin;

template<class T> node<T>::node(T item, node<T> *pt_n, node<T> *pt_p)
{
    dataitem = item;
    pt_next = pt_n;
    pt_previous = pt_p;
}

template<class T> T node<T>::getdata(void)
{
    return dataitem;
}

template<class T> node<T> *node<T>::getnext(void)
{
    return pt_next;
}

template<class T> node<T> *node<T>::getprevious(void)
{
    return pt_previous;
}

template<class T> void node<T>::setdata(T item)
{
    dataitem = item;
    return;
}

template<class T> void node<T>::setnext(node<T> *pt)
{
    pt_next = pt;
    return;
}

template<class T> void node<T>::setprevious(node<T> *pt)
{
    pt_previous = pt;
    return;
}

template<class T> DList<T>::DList(void)
{
    dummy = new node<T>;
    (*dummy).setnext(dummy);
    (*dummy).setprevious(dummy);
    numitems = 0;
}

//template<class T> DList<T>::~DList()
//{
//    delete[] reprarray;
//}

template<class T> T DList<T>::operator[](int index)
{
    T val = getitem(index);
    return val;
}

template<class T> int DList<T>::getlength(void)
{
    return numitems;
}

template<class T> node<T> *DList<T>::last(void)
{
    return (*dummy).getprevious();
}

template<class T> node<T> *DList<T>::first(void)
{
    return (*dummy).getnext();
}

template<class T> void DList<T>::append(T value)
{
    node<T> *lpt;
    lpt = last();
    node<T> *pt = new node<T>;
    (*pt).setdata(value);
    (*pt).setnext(dummy);
    (*pt).setprevious(lpt);
    (*dummy).setprevious(pt);
    (*lpt).setnext(pt);
    ++numitems;
    return;
}

template<class T> node<T> *DList<T>::locate(int index)
{
    if ((index <= 0) || (index > numitems))
    {
        cout << "Error: index out of range.\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        node<T> *pt;
        pt = (*dummy).getnext();
        for (int i = 1; i < index; ++i)
        {
            pt = (*pt).getnext();
        }
        return pt;
    }
}

template<class T> void DList<T>::setitem(int index, T value)
{
    node<T> *pt;
    pt = locate(index);
    (*pt).setdata(value);
    return;
}

template<class T> T DList<T>::getitem(int index)
{
    node<T> *pt;
    pt = locate(index);
    return (*pt).getdata();
}

template<class T> void DList<T>::insert(int index, T value)
{
    node<T> *pt_i;
    pt_i = locate(index);
    node<T> *pt_i1;
    pt_i1 = (*pt_i).getprevious();
    node<T> *pt_new = new node<T>;
    (*pt_new).setdata(value);
    (*pt_new).setnext(pt_i);
    (*pt_new).setprevious(pt_i1);
    (*pt_i).setprevious(pt_new);
    (*pt_i1).setnext(pt_new);
    numitems += 1;
    return;
}

template<class T> void DList<T>::remove(int index)
{
    node<T> *pt_i;
    pt_i = locate(index);
    node<T> *pt_i1;
    pt_i1 = (*pt_i).getprevious();
    node<T> *pt_i2;
    pt_i2 = (*pt_i).getnext();
    (*pt_i1).setnext(pt_i2);
    (*pt_i2).setprevious(pt_i1);
    numitems -= 1;
    return;
}

template<class T> void DList<T>::concat(DList<T> *dlist)
{
    int num = (*dlist).getlength();
    if (num > 0)
    {
        node<T> *lpt;
        lpt = last();
        node<T> *pt0;
        pt0 = (*dlist).dummy;
        node<T> *pt1;
        pt1 = (*pt0).getnext();
        (*pt1).setprevious(lpt);
        (*lpt).setnext(pt1);
        node<T> *pt2;
        pt2 = (*pt0).getprevious();
        (*dummy).setprevious(pt2);
        (*pt2).setnext(dummy);
        numitems += num;
    }
    return;
}

template<class T> bool DList<T>::member(T value)
{
    bool result = false;
    node<T> *pt;
    pt = (*dummy).getnext();
    for (int i = 0; i < numitems; ++i)
    {
        if ((*pt).getdata() == value)
        {
            result = true;
            break;
        }
        else
        {
            pt = (*pt).getnext();
        }
    }
    return result;
}

template<class T> bool DList<T>::equal(DList<T> *dlist)
{
    bool result = true;
    if ((*dlist).getlength() != numitems)
    {
        result = false;
    }
    else
    {
        node<T> *pt;
        pt = (*dummy).getnext();
        node<T> *pt0;
        pt0 = (*dlist).dummy;
        node<T> *pt_other;
        pt_other = (*pt0).getnext();
        for (int i = 0; i < numitems; ++i)
        {
            if ((*pt).getdata() != (*pt_other).getdata())
            {
                result = false;
                break;
            }
            else
            {
                pt = (*pt).getnext();
                pt_other = (*pt_other).getnext();
            }
        }
    }
    return result;
}

/* Function: insertionSort
 * Input: none
 * Output: none
 * Return value: none
 * Description: Use insertion sort to sort DList, and here it's in ascending order.
 */
template<class T> void DList<T>::insertionSort(void){ 	//Sort in ascending order
	node<T> *pt1;
	node<T> *pt2;	//initialize two nodes
	int l,r,mid;    //initialize some variables
	T data;		//initialize data
	for(int i=1;i<=numitems;i++){  //use for loop
		node<T> *pt=locate(i);   //initialize a pointer
		data=pt->getdata();  //let data be pt->getdata
		l=1;r=i-1;	 //let l=1;r=i-1
		while(l<=r){	 //use while loop
			mid=(l+r)/2;	 //initialize mid
			if(getitem(mid)>data)r=mid-1;  //adjust r
			else l=mid+1;   //adjust l
		}
		if(l==i)continue;  //if so, i-th is the smallest element among all the elements before it, skip it
		pt1=locate(l);
		pt->getprevious()->setnext(pt->getnext());
		pt->getnext()->setprevious(pt->getprevious());
		pt1->getprevious()->setnext(pt);
		pt->setprevious(pt1->getprevious());
		pt->setnext(pt1);
		pt1->setprevious(pt);	 //set the next and previous of these elements
	}
	
}

/* Function: bubbleSort
 * Input: none
 * Output: none
 * Return value: none
 * Description: Use bubble sort to sort DList, and here it's in ascending order.
 */
template<class T> void DList<T>::bubbleSort(void){ 	//Sort in ascending order
	node<T> *pt1;
	node<T> *pt2;	//initialize two nodes
	for(int i=1;i<=numitems-1;i++){		//use for loop to search through all the elements
		for(int j=1;j<=numitems-i;j++){		//use for loop to search through all the elements after i-th element
			if(getitem(j)>=getitem(j+1)){ 	//if the previous one is not smaller than the next one,then swap them
				pt1=locate(j);
				pt2=locate(j+1);  //initilize pt1 and pt2
				pt1->getprevious()->setnext(pt2);
				pt2->getnext()->setprevious(pt1);
				pt2->setprevious(pt1->getprevious());
				pt1->setprevious(pt2);
				pt1->setnext(pt2->getnext());
				pt2->setnext(pt1);   //set the next and previous of these elements
			}
		}
	}
}

template<class T> bool DList<T>::sublist(DList<T> *dlist)
{
    bool result = true;
    node<T> *pt;
    pt = (*dummy).getnext();
    node<T> *pt0;
    pt0 = (*dlist).dummy;
    node<T> *pt_other;
    pt_other = (*pt0).getnext();
    int numother = (*dlist).getlength();
    for (int i = 0, j = 0; (i < numother) && (j < numitems); ++i, ++j)
    {
        if ((*pt_other).getdata() == (*pt).getdata())
        {
            if ((j == numitems - 1) && (i < numother - 1))
            {
                result = false;
                break;
            }
            pt = (*pt).getnext();
            pt_other = (*pt_other).getnext();
        }
        else
        {
            if (j == numitems - 1)
            {
                result = false;
                break;
            }
            else
            {
                pt = (*pt).getnext();
                --i;
            }
        }
        
    }
    return result;
}

