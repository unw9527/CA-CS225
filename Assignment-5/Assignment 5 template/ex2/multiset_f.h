#include "multiset.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;


// Below is the code for MultiSet with explicit storage of multiplicities.
// Please note that some functions and structures like pair were written by Prof. 
// I just take them to use (maybe I change the name of the class). So I did not make no comments on these functions. Thanks!
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

template<class T> void MultiSet<T>::insertion(T num)
{
    bool mark = 1; // to mark whether num is already in the set. 1 for not be in the set. 0 otherwise.
    for (int i = 0; i < numitems; i++){
        if (reprarray[i].get_t() == num){
            int value = reprarray[i].get_n();
            reprarray[i].set_n(++value); // if num is in the set, increment its multiplicity
            mark = 0;
            break;
            
        }
    }
    if (mark){
        pair<T> newval(num, 1); // otherwise, add (num, 1) to the set
        this->append(newval);
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
                reprarray[i].set_n(--value); // if num appears more than once in the set, decrement its multiplicity
            }
            else{
                for (int j = i; j < numitems - 1; j++){
                    reprarray[j].set_t(reprarray[j+1].get_t()); // if num appears only once in the set, remove it
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
        cout << num << " is not in the set." << endl; // if num is not in the set, report error
    }
    return;
}

template<class T> int MultiSet<T>::retrieval(T num){
    bool mark = 1;
    for (int i = 0; i < this->getlength(); i++){
        if (num == this->reprarray[i].get_t()){
            cout << "The multiplcity of " << num << " is: " << this->reprarray[i].get_n() << endl;
            mark = 0;
            cout << endl;
            return this->reprarray[i].get_n(); // return the multipilicity of num if num is in the set
        }
    }
    if (mark){
        cout << num << " is not in the set." << endl; // report error otherwise
        cout << endl;
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
                break; // if both sets contain a certain num, combine their lengths and append the new pair to the union set
            }
        }
        if (mark){
            this->append(p1); // if a pair in set1 is not in set2, append it to the union set
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
            this->append(p2); // if a pair in set2 is not in set1, append it to the union set
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
                p3.set_n(n1 < n2? n1 : n2); // if a pair is both in set1 and set2, the one we append to the intersection union has the smaller length of the two
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
                    p3.set_n(result); // if a pair is both in set1 and set2, 
                    // the one we append to the difference union has the absolute value of the difference of lengths of the two
                    this->append(p3);
                }
                mark = 0;
                break;
            }
        }
        if (mark){
            this->append(p1); // if a pair in set1 is not in set2, append it to the union set
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
            this->append(p2); // if a pair in set2 is not in set1, append it to the union set
        }
    }
    return;
}

template<class T> void MultiSet<T>::append(pair<T> pair1){
    if (numitems == maxsize)
        allocate();
    last = last + 1;
    last = last % maxsize;
    reprarray[last] = pair1;
    ++numitems;
    return;
}

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

// the three functions above were written by Prof. I take them to use.

template<class T> void MultiSet<T>::print_pairs(){
    for (int i = 0; i < this->getlength(); i++){
        pair<T> p1 = this->reprarray[i];
        cout << "(" << p1.get_t() << "," << p1.get_n() << ") "; // print pairs
    }
    cout << endl;
    cout << endl;
}


/* Put your implementation here */

// Below is the code for MultiSet with chaining.
// Please note that some functions and structures like node and DList were written by Prof. 
// I just take them to use(maybe I change the name of the class). So I did not make no comments on these functions. Thanks!

template<class T> node<T>::node(T item, node<T> *pt_n, node<T> *pt_p)
{
    dataitem = item;
    pt_next = pt_n;
    pt_previous = pt_p;
}

/* 
 * input: none.
 * output: the current item you're trying to deal with.
 * side-effects: none.
 * overall-functionality: get the item.
 */
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
    // make dummy to point to a new node. 
    // notice. now dummy can use anything defined in the class node. 
    dummy = new node<T>;

    // these lines are to initialize the linked list.
    (*dummy).setnext(dummy);
    (*dummy).setprevious(dummy);

    // numitems is a variable under DList, not node.
    numitems = 0;
}

// template<class T> DList<T>::~DList()
// {
//    delete[] reprarray;
// }

template<class T> T DList<T>::operator[](int index)
{
    T val = getitem(index);
    return val;
}

template<class T> int DList<T>::getlength(void)
{
    return numitems;
}

// notice. the last of the linked list is just the previous element of
//  the header ptr.
template<class T> node<T> *DList<T>::last(void)
{
    return (*dummy).getprevious();
}

// notice. the first element in the linked list is just the NEXT element of
//  the header ptr.
template<class T> node<T> *DList<T>::first(void)
{
    return (*dummy).getnext();
}

// to append something is equi. to get another node appended at last.
template<class T> void DList<T>::append(T value)
{
    // lpt == the pointer pointing to the last element
    node<T> *lpt;
    lpt = last();

    // initialize the new pointer & element.
    node<T> *pt = new node<T>;
    (*pt).setdata(value);
    (*pt).setnext(dummy);
    (*pt).setprevious(lpt);
    (*dummy).setprevious(pt);

    // set the next-pointer for the element *lpt to be the new ptr.
    (*lpt).setnext(pt);
    ++numitems;
    return;
}

// this function is designed to find the pointer of the given index.
template<class T> node<T> *DList<T>::locate(int index)
{
    if ((index < 0) || (index >= numitems))
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

template<class T> MChaining<T>::MChaining(int size)
{
    maxsize = size;
    if (size < 10)
        minsize = size;
    else
        minsize = 10;
    numitems = 0;
    first = 0;
    last = -1;
    reprarray = new DList<T>[maxsize];
}

template<class T> MChaining<T>::~MChaining()
{
   delete[] reprarray;
}

template<class T> void MChaining<T>::insertion(T num)
{
    bool mark = 1;
    for (int i = 0; i < numitems; i++){
        if (reprarray[i].getitem(0) == num){
            reprarray[i].append(num); // if num is in the set, append it to the linked list
            mark = 0;
            break;
            
        }
    }
    if (mark){
        DList<T> d3;
        d3.append(num);
        this->pushback(d3); // else, push it to the set
    }
    return;
}

template<class T> void MChaining<T>::deletion(T num)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    bool mark = 1;
    for (int i = 0; i < numitems; i++){
        if (reprarray[i].getitem(0) == num){
            int l1 = reprarray[i].getlength();
            if (l1 > 1){
                reprarray[i].remove(l1 - 1); // if num appears more than once in the set, decrement the length of linked list
            }
            else{
                for (int j = i; j < numitems - 1; j++){
                    reprarray[j] = reprarray[j+1]; // if num appears only once in the set, remove the linked list from the set
                }
                numitems--;
                last--;
            }
            mark = 0;
            break;
        }
    }
    if (mark){
        cout << num << " is not in the set." << endl; // report error if num is not in the set
    }
    return;
}

template<class T> int MChaining<T>::retrieval(T num){
    bool mark = 1;
    for (int i = 0; i < this->getlength(); i++){
        if (num == this->reprarray[i].getitem(0)){
            cout << "The multiplcity of " << num << " is: " << this->reprarray[i].getlength() << endl;
            mark = 0;
            cout << endl;
            return this->reprarray[i].getlength(); // return the length of the corresponding linked list
        }
    }
    if (mark){
        cout << num << " is not in the set." << endl; // report error if num is not in the set
        cout << endl;
    }
    return 0;
}

template<class T> void MChaining<T>::setunion(MChaining<T>* set1, MChaining<T>* set2){
    for (int i = 0; i < set1->getlength(); i++){
        bool mark = 1;
        DList<T> p1 = set1->reprarray[i];
        for (int j = 0; j < set2->getlength(); j++){
            DList<T> p2 = set2->reprarray[j];
            if (p1.getitem(0) == p2.getitem(0)){
                DList<T> p3;
                int length1 = p1.getlength();
                int length2 = p2.getlength();
                for (int k = 0; k < length1+length2; k++){ // combine the length if both sets contain that number
                    p3.append(p1.getitem(0));
                }
                this->pushback(p3);
                mark = 0;
                break;
            }
        }
        if (mark){
            this->pushback(p1); // push p1 if that number is not in p2
        }
    }
    for (int j = 0; j < set2->getlength(); j++){
        bool mark = 1;
        DList<T> p2 = set2->reprarray[j];
        for (int i = 0; i < set1->getlength(); i++){
            DList<T> p1 = set1->reprarray[i];
            if (p1.getitem(0) == p2.getitem(0)){
                mark = 0;
                break;
            }
        }
        if (mark){
            this->pushback(p2); // push p2 if that number is not in p1
        }
    }
    return;
}

template<class T> void MChaining<T>::intersection(MChaining<T>* set1, MChaining<T>* set2){
    for (int i = 0; i < set1->getlength(); i++){
        DList<T> p1 = set1->reprarray[i];
        for (int j = 0; j < set2->getlength(); j++){
            DList<T> p2 = set2->reprarray[j];
            if (p1.getitem(0) == p2.getitem(0)){
                DList<T> p3;
                int smaller = p1.getlength() < p2.getlength()? p1.getlength() : p2.getlength(); // the intersected length is the smaller one of the original two
                for (int k = 0; k < smaller; k++){
                    p3.append(p1.getitem(0));
                }
                this->pushback(p3);
                break;
            }
        }
    }
    return;
}

template<class T> void MChaining<T>::difference(MChaining<T>* set1, MChaining<T>* set2){
    for (int i = 0; i < set1->getlength(); i++){
        bool mark = 1;
        DList<T> p1 = set1->reprarray[i];
        for (int j = 0; j < set2->getlength(); j++){
            DList<T> p2 = set2->reprarray[j];
            if (p1.getitem(0) == p2.getitem(0)){
                int n1 = p1.getlength();
                int n2 = p2.getlength();
                int result = n1 - n2;
                if (0 > result){
                    result = -result; // take the absolute value of the difference of lengths
                }
                if (0 != result){
                    DList<T> p3;
                    for (int k = 0; k < result; k++){
                        p3.append(p1.getitem(0)); // build p3 with the length equal to the difference of the original two
                    }
                    this->pushback(p3);
                }
                mark = 0;
                break;
            }
        }
        if (mark){
            this->pushback(p1); // push p1 if that number is not in p2
        }
    }
    for (int j = 0; j < set2->getlength(); j++){
        bool mark = 1;
        DList<T> p2 = set2->reprarray[j];
        for (int i = 0; i < set1->getlength(); i++){
            DList<T> p1 = set1->reprarray[i];
            if (p1.getitem(0) == p2.getitem(0)){
                mark = 0;
                break;
            }
        }
        if (mark){
            this->pushback(p2); // push p2 if that number is not in p1
        }
    }
    return;
}

template<class T> int MChaining<T>::getlength(void)
{
    return numitems;
}

template<class T> void MChaining<T>::pushback(DList<T> list1){
    if (numitems == maxsize)
        allocate();
    last = last + 1;
    last = last % maxsize;
    reprarray[last] = list1;
    ++numitems;
    return;
}

template<class T> void MChaining<T>::print_all(){
    for (int i = 0; i < this->getlength(); i++){
        for (int j = 0; j < reprarray[i].getlength(); j++){
            cout << reprarray[i].getitem(j) << " ";
        }
    } //this function simply prints all elements in the set
    cout << endl << endl;
}

template<class T> void MChaining<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    DList<T> *newarray = new DList<T>[newsize];
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

template<class T> void MChaining<T>::deallocate(void)
{
    int newsize = maxsize / 2;
    DList<T> *newarray = new DList<T>[newsize];
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