//
//  alist.cpp
//  
//
//  Created by KD on 14.01.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "alist.h"
using std::cout;
using std::cin;

/* Function: delete_last_k
 * Input: int k
 * Output: none
 * Return value: none
 * Description: delete the last k elements from AList as required in Assignment 1.1
 */
template<class T> void AList<T>::delete_last_k(int k){
    if (k < 1){
        cout << "Invalid number of elements deleted!\n";
        return;
    }
    if (k <= numitems)
    {
        numitems -= k; // decrease the number of items if k <= numitems
    }
    else{
        numitems = 0; // set the list length to 0 if k > numitems
    }
    while ((numitems <= maxsize / 4) && (maxsize > minsize))
        deallocate(); 
}

template<class T> T &AList<T>::operator[](int index)
{
    return reprarray[index - 1];
}

template<class T> int AList<T>::getlength(void)
{
    return numitems;
}

template<class T> void AList<T>::setitem(int index, T value)
{
    if ((index > 0) && (index <= numitems))
    {
        reprarray[index - 1] = value;
        return;
    }
    else
        cout << "Index error: index out or range\n";
}

template<class T> T AList<T>::getitem(int index)
{
    if ((index > 0) && (index <= numitems))
    {
        return reprarray[index - 1];
    }
    else
    {
        cout << "Index error: index out or range\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> void AList<T>::append(T value)
{
    if (numitems == maxsize)
        allocate();
    reprarray[numitems] = value;
    ++numitems;
    return;
}

template<class T> void AList<T>::insert(int index, T value)
{
    if (numitems == maxsize)
        allocate();
    if (index < numitems)
    {
        for (int j = numitems - 1; j >= index; --j)
        {
            reprarray[j+1] = reprarray[j];
        }
        reprarray[index] = value;
        ++numitems;
        return;
    }
    else
    {
        append(value);
        return;
    }
}

template<class T> void AList<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::remove(int index)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    if (index <= numitems)
    {
        for (int j = index; j < numitems; ++j)
        {
            reprarray[j-1] = reprarray[j];
        }
        --numitems;
        return;
    }
    else
        cout << "Index error: list index out of range\n";
}

template<class T> void AList<T>::deallocate(void)
{
    int newsize = maxsize / 2;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::concat(AList<T> &list)
{
    int length = list.getlength();
    for (int i = 1; i <= length; ++i)
    {
        append(list[i]);
    }
    return;
}

template<class T> bool AList<T>::member(T value)
{
    bool result = false;
    for (int i = 0; i < numitems; ++i)
    {
        if (reprarray[i] == value)
        {
            result = true;
            break;
        }
    }
    return result;
}

template<class T> bool AList<T>::equal(AList<T> &list)
{
    bool result = true;
    if (numitems == list.getlength())
    {
        for (int i = 0; i < numitems; ++i)
        {
            if (reprarray[i] == list[i + 1])
                continue;
            else
            {
                result = false;
                break;
            }
        }
    }
    else
        result = false;
    return result;
}
template<class T> bool AList<T>::sublist(AList<T> &list)
{
    int length = list.getlength();
    bool result = true;
    for (int i = 1, j = 0; (i <= length) && (j < numitems); ++i, ++j)
    {
        if (list[i] == reprarray[j])
        {
            if ((j == numitems - 1) && (i < length))
            {
                result = false;
                break;
            }
        }
        else
            if (j == numitems - 1)
            {
                result = false;
                break;
            }
            else
                --i;
    }
    return result;
}


//Problem 2.4
/* Function: src(e,f,g,l)
 * Input: T_t e,T_t (*f)(T_t),T_t (*g)(T_t,T_t),AList<T> &list
 * Output: none
 * Return value type: T_t
 * Description: when l is empty, return e;when l has one element, return f(x);when l has more elements, return g; just as required in Assignment 2
 */
template<typename T_t>T_t f_fun(T_t x){
	return (T_t)x+5;	//here is an example of f
}
template<typename T_t>T_t g_fun(T_t x,T_t y){
	return x+y;		//here is an example of g
}
template<class T>
template<typename T_t>T_t AList<T>::src(T_t e,T_t (*f)(T_t),T_t (*g)(T_t,T_t),AList<T> &list){
	if(list.numitems==0)return e;	//when l is empty, return e
	if(list.numitems==1)return f(list.reprarray[0]);	//when l has one element, return f(x)
	AList<T> l1,l2;		//initialize l1,l2
	for(int i=0;i<list.numitems/2;i++)
		l1.append(list.reprarray[i]);	//use for loop to let l1 be a sublist of l
	for(int i=list.numitems/2;i<list.numitems;i++)
		l2.append(list.reprarray[i]);	//use for loop to let l1 be a sublist of l, and l1+l2=l
	return g(src(e,f,g,l1),src(e,f,g,l2));	//then just return g
}
/*-----------------------------------------------------------------------------*/
//Problem 3
/* Function: getlength()
 * Input: none
 * Output: none
 * Return value: numitems
 * Description: get the numitems of CList
 */
template<class T> int CList<T>::getlength(void)	  //get the numitems of CList, that's the length
{
    return numitems;
}
/* Function: operator[](int index)
 * Input: index
 * Output: none
 * Return value: reprarray[index - 1]
 * Description: get the element 
 */
template<class T> T &CList<T>::operator[](int index)	//return the element in the index of the array
{
	index+=fi_id;
    return reprarray[index - 1];
}
/* Function: allocate(void)	
 * Input: none
 * Output: none
 * Return value: none
 * Description: allocate for CList when there is no enough space
 */
template<class T> void CList<T>::allocate(void)		//it's the allocate function for CList
{
    int newsize = 2 * maxsize;
    T *newarray = new T[newsize];
    int n_fi_id=(newsize-numitems)/2;
    int n_la_id=fi_id+numitems;		//initialize some new variables
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i+fi_id] = reprarray[i];	//create the newarray to include all the elements of reprarray
    }
    delete[] reprarray;		//delete the reprarray
    reprarray = newarray;
    maxsize = newsize;
    fi_id=n_fi_id;
    la_id=n_la_id;		//set new variables
    return;
}
/* Function: deallocate(void)
 * Input: none
 * Output: none
 * Return value: none
 * Description: deallocate for CList when there is too much space
 */
template<class T> void CList<T>::deallocate(void)	//it's the deallocate function for CList
{
    int newsize = maxsize / 2;
    T *newarray = new T[newsize];
    int n_fi_id=(newsize-numitems)/2;
    int n_la_id=fi_id+numitems;		//initialize some new variables
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i+n_fi_id] = reprarray[i+fi_id];  //create the newarray to include all the elements of reprarray
    }
    delete[] reprarray;   //delete the reprarray
    reprarray = newarray;
    maxsize = newsize;
    fi_id=n_fi_id;
    la_id=n_la_id;	//set new variables
    return;
}
/* Function:pushback(T value)
 * Input: T value
 * Output: none
 * Return value: none
 * Description:  appends the element x at the end of the sequence
 */
template<class T>void CList<T>::pushback(T value){	//it's the pushback function for CList
	if (la_id == maxsize)
        allocate();		//if so, need to allocate
    reprarray[la_id] = value;	//set value
    la_id++;	//let la_id+1
	numitems++;	//let numitems+1
    return;
}
/* Function:pushback(T value)
 * Input: T value
 * Output: none
 * Return value: none
 * Description:  adds the element x at the front of the sequence
 */
template<class T>void CList<T>::pushfront(T value){		//it's the pushfront function for CList
	if (fi_id == 0)
        allocate();	//if so, need to allocate
    reprarray[--fi_id] = value;	//set value and let fi_id-1
    numitems++;		//let numitems+1
    return;
}
/* Function:popback(void)
 * Input: none
 * Output: "Index error: The list is empty!\n" if the sequence is empty, none if not
 * Return value: the last element x of the sequence
 * Description:  removes the last element x of the sequence and returns it
 */
template<class T>T CList<T>::popback(void){			//it's the popback function for CList
	if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();	//if so, need to deallocate
    if (numitems)
    {
    	la_id--;	//let la_id-1 first
    	T e = reprarray[la_id];		//take the last one as e
        numitems--;	//let numitems-1
        return e;	//return e
    }
    else
        cout << "Index error: The list is empty!\n";	//if failed, display this sentence
        return 0;	//and return 0
}
/* Function:popfront(void)
 * Input: none
 * Output: "Index error: The list is empty!\n" if the sequence is empty, none if not
 * Return value: the first element x of the sequence
 * Description:   removes the first element x of the sequence and returns it
 */
template<class T>T CList<T>::popfront(void){		//it's the popfront function for CList
	if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();	//if so, need to deallocate
    if (numitems)
    {
    	T e = reprarray[fi_id];		//take the first one as e
        fi_id++;	//let fi_id-1
        numitems--;
        return e; //return e
    }
    else
        cout << "Index error: The list is empty!\n";	//if failed, display this sentence
        return 0;	//and return 0
}

/*-----------------------------------------------------------------------------*/
/* Function: selectionSort
 * Input: none
 * Output: none
 * Return value: none
 * Description: use selection sort to sort AList, here it's in ascending order
 */
template<class T>void AList<T>::selectionSort(void){ 	//Sort in ascending order
	for(int i=0;i<numitems;i++){ 	//use for loop to search through all the elements
    	T minn=reprarray[i];
		int min_id=i;  	//initialize minn and min_id
  		for(int j=i+1;j<numitems;j++){	 //use for loop
   			if(minn>reprarray[j]){  	//if there is one element smaller than minn
    			minn=reprarray[j];	 //let minn be that element
    			min_id=j; 	//let min_id be the index
   			}
  		}
  		reprarray[min_id]=reprarray[i];  
  		reprarray[i]=minn; 	//replace the smallest element with the i-th element
 	}
} 

/* Function: bubbleSort
 * Input: none
 * Output: none
 * Return value: none
 * Description: use bubble sort to sort AList, here it's in ascending order
 */
template<class T>void AList<T>::bubbleSort(void){ 	//Sort in ascending order
	for(int i=0;i<numitems-1;i++){ 	//use for loop to search through all the elements
    	for(int j=0;j<numitems-i-1;j++){  	//use for loop to search the rest elements
       		if(reprarray[j]>=reprarray[j+1]){  	//if j-th element is bigger than the j+1-th
        	T t=reprarray[j];
        	reprarray[j]=reprarray[j+1];
        	reprarray[j+1]=t;  	//swap them 
            }
		}
 	}
}
