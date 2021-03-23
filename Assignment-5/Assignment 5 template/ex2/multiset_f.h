#include "multiset.h"

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
                p3.set_n(n1 + n2); // here I use the definition offered on piazza,
                // that is, the union is the sum of length from both sets rather than 
                // just take the maxium length of one set
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
                if (0 < result){
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

/* 
 * The code below is multiset implemented by hashing with chaining.
 * I have talked to Prof. Schewe personally, and he told me that I 
 * only need to implement insertion, deletion and retrieval.
 */

template<class T> Mchaining<T>::Mchaining(int size){
    maxsize = size;
    if (size < 20)
        maxsize = 20; 
    numitems = 0;
    reprarray = new Node<T>*[maxsize];
    for (int i = 0; i < maxsize; i++){
        reprarray[i] = NULL;
    }
}

template<class T> void Mchaining<T>::insertion(T num){
    int index;
    index = hashfunction(num) % maxsize;
    Node<T>* temp = reprarray[index];
    Node<T>* inserted = new Node<T>;
    inserted->next = temp; // insert the element at the entry
    inserted->key = num;
    
    reprarray[index] = inserted;
    numitems++;
    int load = 100 * numitems / maxsize;
    if (load >= 75)             // max load factor is exceeded; double the size
    {
        int newsize = 2 * numitems;
        rehash(newsize);
    }
    return;
}

template<class T> void Mchaining<T>::deletion(T num){
    bool mark = 1;
    int index;
    index = hashfunction(num) % maxsize;
    Node<T>* first = reprarray[index];
    if (NULL == first){
        cout << num << " is not in the set." << endl << endl;// if the computed index contains NULL, 
        // obviously the element we want to delete is not in the set
        return;
    }
    if (num == first->key){
        reprarray[index] = first->next; // check the first element
        --numitems;
        mark = 0;
    }
    for (Node<T>* ptr = first; NULL != ptr->next; ptr = ptr->next){
        if (ptr->next->key == num){
            mark = 0;
            ptr->next = ptr->next->next; // check the other elements
            --numitems;
            break;
        }
    }
    if (mark){
        cout << num << " is not in the set." << endl << endl; // if num is not find in the end, report the error message
    }
    int load = 100 * numitems / maxsize;
            if (load <= 25)
                // if the min load factor is undershot, we shrink the hashtable, but the size shall always be >= 20
            {
                int newsize = numitems;
                if (newsize < 20)
                    newsize = 20;
                rehash(newsize);
            }
}

template<class T> int Mchaining<T>::retrieval(T num){
    int count = 0;
    int index;
    index = hashfunction(num) % maxsize;
    Node<T>* first = reprarray[index];
    if (NULL == first){
        cout << num << " is not in the set." << endl << endl; // if the computed index contains NULL, 
        // obviously the element we want to retrieve is not in the set
        return 0;
    }
    for (Node<T>* ptr = first; NULL != ptr; ptr = ptr->next){
        if (ptr->key == num){
            count++; // increment count if we find the number
        }   
    }
    cout << "The multiplicity of " << num << " is " << count << endl << endl;
    if (!count){
        cout << num << " is not in the set." << endl << endl; // if num is not find in the end, report the error message
        return 0;
    }
    return count;
}

template<class T> void Mchaining<T>::print_all(){
    for (int i = 0; i < maxsize; i++){
        if (NULL != reprarray[i]){
            for (Node<T>* ptr = reprarray[i]; NULL != ptr; ptr = ptr->next){
                cout << ptr->key << " "; // loop through the hashset and print every element
            }
        }
    }
    cout << endl << endl;
}

template<class T> void Mchaining<T>::rehash(int newsize){
    if (newsize < 20)
        newsize = 20;
    int newnum = 0;
    Node<T> **newarray = new Node<T>*[newsize];   // allocate space for a new hashtable of the given new size
    for (int i = 0; i < newsize; i++)
    {
        newarray[i] = NULL;   // initialise the new hashtable with only null pointers
    }
    for (int i = 0; i < maxsize; i++)  // we need to copy all existing entries to the new hash table
    {
        if (reprarray[i] != NULL)
        {
            // T item = *reprarray[i];
            hash<T> hashfunction;
            int index = hashfunction(i) % newsize;
                // recompute the new hash value
            while (newarray[index] != NULL)  // find the first free place, where the entry can be stored in the new hashtable
            {
                index = (index + 1) % newsize;
            }
            newarray[index] = reprarray[i];  // do the actual copying
            ++ newnum;
        }
    }
    numitems = newnum;   // change the number of stored elements
    reprarray = newarray;   // make the new hashtable the one of the hashset object
    maxsize = newsize;   // update the size
}

