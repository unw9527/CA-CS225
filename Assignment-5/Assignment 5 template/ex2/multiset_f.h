#include "multiset.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

template<class T> MultiSet<T>::MultiSet(int size)
{
    maxsize = size;
    if (size < 10)
        minsize = size;
    else
        minsize = 10;
    numitems = 0;
    first = 0;
    last = -1;
    reprarray = new pair<T>[maxsize];
}

template<class T> MultiSet<T>::~MultiSet()
{
   delete[] reprarray;
}

template<class T> pair<T> &MultiSet<T>::operator[](int index)
{
    if ((0 <= index) && (index < numitems))
    {
        int relindex = (index + first) % maxsize;
        return reprarray[relindex];
    }
    else
    {
        cout << "Error: index " << index << " out of range.\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> int MultiSet<T>::getlength(void)
{
    return numitems;
}

// template<class T> bool MultiSet<T>::isempty(void)
// {
//     if (numitems == 0)
//         return true;
//     else
//         return false;
// }

// template<class T> pair<T> MultiSet<T>::front(void)
// {
//     if (isempty() == false)
//         return reprarray[first];
//     else
//     {
//         cout << "The queue is empty.\n";
//         exit(EXIT_FAILURE);
//     }
// }

// template<class T> pair<T> MultiSet<T>::back(void)
// {
//     if (isempty() == false)
//     {
//         int relindex = (first + numitems - 1) % maxsize;
//         return reprarray[relindex];
//     }
//     else
//     {
//         cout << "The queue is empty.\n";
//         exit(EXIT_FAILURE);
//     }
// }

template<class T> void MultiSet<T>::insertion(T num)
{
    bool mark = 1;
    for (int i = 0; i < numitems; i++){
        if (reprarray[i].get_t() == num){
            int value = reprarray[i].get_n();
            reprarray[i].set_n(++value);
            mark = 0;
            break;
            
        }
    }
    if (mark){
        if (numitems == maxsize)
        allocate();
        last = last + 1;
        last = last % maxsize;
        // last = ++last % maxsize;
        pair<T> newval(num, 1);
        reprarray[last] = newval;
        ++numitems;
    }
    return;
}

template<class T> void MultiSet<T>::deletion(T num)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    bool mark = 1;
    for (int i = 0; i < numitems; i++){
        if (reprarray[i].get_t() == num){
            if (reprarray[i].get_n() > 1){
                int value = reprarray[i].get_n();
                reprarray[i].set_n(--value);
            }
            else{
                for (int j = i; j < numitems - 1; j++){
                    reprarray[j].set_t(reprarray[j+1].get_t());
                    reprarray[j].set_n(reprarray[j+1].get_n());
                }
                numitems--;
                last--;
            }
            mark = 0;
            break;
        }
    }
    if (mark){
        cout << num << " is not in the set." << endl;
    }
    return;
}

template<class T> int MultiSet<T>::retrieval(T num){
    bool mark = 1;
    for (int i = 0; i < this->getlength(); i++){
        if (num == this->reprarray[i].get_t()){
            cout << "The multiplcity of " << num << " is: " << this->reprarray[i].get_n() << endl;
            mark = 0;
            return this->reprarray[i].get_n();
        }
    }
    if (mark){
        cout << num << " is not in the set." << endl;
    }
    return 0;
}

template<class T> void MultiSet<T>::setunion(MultiSet<T>* set1, MultiSet<T>* set2){
    for (int i = 0; i < set1->getlength(); i++){
        bool mark = 1;
        pair<T> p1 = set1->reprarray[i];
        for (int j = 0; j < set2->getlength(); j++){
            pair<T> p2 = set2->reprarray[j];
            if (p1.get_t() == p2.get_t()){
                pair<T> p3;
                p3.set_t(p1.get_t());
                int n1 = p1.get_n();
                int n2 = p2.get_n();
                p3.set_n(n1 + n2);
                this->append(p3);
                mark = 0;
                break;
            }
        }
        if (mark){
            this->append(p1);
        }
    }
    for (int j = 0; j < set2->getlength(); j++){
        bool mark = 1;
        pair<T> p2 = set2->reprarray[j];
        for (int i = 0; i < set1->getlength(); i++){
            pair<T> p1 = set1->reprarray[i];
            if (p1.get_t() == p2.get_t()){
                mark = 0;
                break;
            }
        }
        if (mark){
            this->append(p2);
        }
    }
    return;
}

template<class T> void MultiSet<T>::intersection(MultiSet<T>* set1, MultiSet<T>* set2){
    for (int i = 0; i < set1->getlength(); i++){
        pair<T> p1 = set1->reprarray[i];
        for (int j = 0; j < set2->getlength(); j++){
            pair<T> p2 = set2->reprarray[j];
            if (p1.get_t() == p2.get_t()){
                pair<T> p3;
                p3.set_t(p1.get_t());
                int n1 = p1.get_n();
                int n2 = p2.get_n();
                p3.set_n(n1 < n2? n1 : n2);
                this->append(p3);
                break;
            }
        }
    }
    return;
}

template<class T> void MultiSet<T>::difference(MultiSet<T>* set1, MultiSet<T>* set2){
    for (int i = 0; i < set1->getlength(); i++){
        bool mark = 1;
        pair<T> p1 = set1->reprarray[i];
        for (int j = 0; j < set2->getlength(); j++){
            pair<T> p2 = set2->reprarray[j];
            if (p1.get_t() == p2.get_t()){
                int n1 = p1.get_n();
                int n2 = p2.get_n();
                int result = n1 - n2;
                if (0 > result){
                    result = -result;
                }
                if (0 != result){
                    pair<T> p3;
                    p3.set_t(p1.get_t());
                    p3.set_n(result);
                    this->append(p3);
                }
                mark = 0;
                break;
            }
        }
        if (mark){
            this->append(p1);
        }
    }
    for (int j = 0; j < set2->getlength(); j++){
        bool mark = 1;
        pair<T> p2 = set2->reprarray[j];
        for (int i = 0; i < set1->getlength(); i++){
            pair<T> p1 = set1->reprarray[i];
            if (p1.get_t() == p2.get_t()){
                mark = 0;
                break;
            }
        }
        if (mark){
            this->append(p2);
        }
    }
    return;
}

template<class T> void MultiSet<T>::append(pair<T> pair1){
    if (numitems == maxsize)
        allocate();
    last = last + 1;
    last = last % maxsize;
    // last = ++last % maxsize;
    reprarray[last] = pair1;
    ++numitems;
    return;
}

// template<class T> pair<T> MultiSet<T>::popfront(void)
// {
//     if ((numitems == maxsize / 4) && (maxsize > minsize))
//         deallocate();
//     if (isempty() == false)
//     {
//         pair<T> frontelement = reprarray[first];
//         first = first + 1;
//         first = first % maxsize;
//         // first = ++first % maxsize;
//         --numitems;
//         return frontelement;
//     }
//     else
//     {
//         cout << "The queue is empty.\n";
//         exit(EXIT_FAILURE);
//     }
// }

template<class T> void MultiSet<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    pair<T> *newarray = new pair<T>[newsize];
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

template<class T> void MultiSet<T>::deallocate(void)
{
    int newsize = maxsize / 2;
    pair<T> *newarray = new pair<T>[newsize];
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


template<class T> void MultiSet<T>::print_pairs(){
    for (int i = 0; i < this->getlength(); i++){
        pair<T> p1 = this->reprarray[i];
        cout << "(" << p1.get_t() << "," << p1.get_n() << ") ";
    }
    cout << endl;
    cout << endl;
}


/* Put your implementation here */
