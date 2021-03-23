#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "hash_extend.h"
using std::cout;
using std::cin;
using std::hash;
/* Put your implementation here */
/* This defines a constructor */
template<class T> HashSet_LCFS<T>::HashSet_LCFS(int size)
{
    maxsize = size;
    if (size < 20)
        maxsize = 20; // default size is 20; no smaller hashtables are considered
    numitems = 0; // initially, the hashtable is empty
    reprarray = new T*[maxsize];  // allocate space for the array of pointers
    // the for loop initialises all table entries to be undefined
    for (int i = 0; i < maxsize; i++)
    {
        reprarray[i] = 0;
    }
    T *pt0 = new T;  // This defines the fixed placeholder pointer
    *pt0 = 0;
    pt_nil = pt0;
}

template<class T> T & HashSet_LCFS<T>::operator[](int index)
{
    if (index <= 0 || index > maxsize)
    {
        cout << "Index error: index out of range\n";
        exit(EXIT_FAILURE);
    }
    if (reprarray[index - 1] != 0 && reprarray[index - 1] != pt_nil)
        return *reprarray[index - 1];
    else
    {
        cout << "Index not used in hashtable";
        return 0;
    }
}
template<class T> void HashSet_LCFS<T>::add(T item)
{
    hash<T> hashfunction; // use the predefined hashfunction to get "key" values
    int index;
    index = hashfunction(item) % maxsize; // First determine the position index in the hash table, where the new value is stored, if free.
    int location = -1;  // used to distinguish between undefined entries (null pointer) and placeholders
    while (reprarray[index] != 0) // We first check, if the item is already in the hashtable
    {
        if (reprarray[index] != pt_nil && *reprarray[index] == item)
            return;   // item found; no insertion
        if (location < 0 && reprarray[index] == pt_nil) // a placeholder object is found; i.e. if the item is not in the hashtable, this will be the place for the insertion
            {location = index;break;}
        T ch=item;
        item=*reprarray[index];
        *reprarray[index]=ch;
        index = (index + 1) % maxsize;
    }
    // after leaving the while loop we either have location < 1, i.e. we store the item at the last examined index (which contains a null pointer),
    // otherwise, if location >= 0 holds, we found a placeholder, so the item will be stored at the location of this placeholder
    if (location < 0)
        location = index;
    T *pt = new T;
    *pt = item;
    reprarray[location] = pt;   // store item in the hashtable
    ++ numitems;
    int load = 100 * numitems / maxsize;
    if (load >= 75)             // max load factor is exceeded; double the size
    {
        int newsize = 2 * numitems;
        rehash(newsize);
    }
    return;
}
template<class T> void HashSet_LCFS<T>::remove(T item)
{
    hash<T> hashfunction;  // use again the predefined hashfunction
    int index;
    index = hashfunction(item) % maxsize;
    while (reprarray[index] != 0)  // same as for add we search for item in the hashtable; the search starts at the designated hash value, and stops when we find a null pointer
    {
        if (reprarray[index] != pt_nil && *reprarray[index] == item)
                    // item found
        {
            int nextindex = (index + 1) % maxsize;
            /* check the next entry, if it is a null pointer; if yes, we can overwrite item by a null pointer; otherwise we use a placeholder, i.e. the pointer pt_nil */
            if (reprarray[nextindex] == 0)
                reprarray[index] = 0;
            else
                reprarray[index] = pt_nil;
            --numitems;
            int load = 100 * numitems / maxsize;
            if (load <= 25)
                // if the min load factor is undershot, we shrink the hashtable, but the size shall always be >= 20
            {
                int newsize = numitems;
                if (newsize < 20)
                    newsize = 20;
                rehash(newsize);
            }
            return;
        }
        index = (index + 1) % maxsize;
    }
    cout << item << " is not in the hashtable.\n";
    return;
}

template<class T> bool HashSet_LCFS<T>::member(T item)
{
    hash<T> hashfunction;  // use the "key" function for the type T (if defined)
    int index;
    index = hashfunction(item) % maxsize;
    while (reprarray[index] != 0) // again we search for item starting from the index position until we find a null pointer
    {
        if (reprarray[index] != pt_nil && *reprarray[index] == item)
            return true;  // item was found
        index = (index + 1) % maxsize;
    }
    return false;  // a null pointer was found, so item is not in the hashtable
}
template<class T> void HashSet_LCFS<T>::rehash(int newsize)
{
    if (newsize < 20)
        newsize = 20;
    int newnum = 0;
    T **newarray = new T*[newsize];   // allocate space for a new hashtable of the given new size
    for (int i = 0; i < newsize; i++)
    {
        newarray[i] = 0;   // initialise the new hashtable with only null pointers
    }
    for (int i = 0; i < maxsize; i++)  // we need to copy all existing entries to the new hash table
    {
        if (reprarray[i] != 0 && reprarray[i] != pt_nil)
        {
            T item = *reprarray[i];
            hash<T> hashfunction;
            int index = hashfunction(item) % newsize;
                // recompute the new hash value
            while (newarray[index] != 0)  // find the first free place, where the entry can be stored in the new hashtable
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

template<class T> void HashSet_LCFS<T>::display(void) // only for test purposes
{
    cout << "The size of the hashtable is: " << maxsize << "\n";
    cout << "The number of elements in the hashtable is: " << numitems << "\n";
    for (int i = 0; i < maxsize; ++i)
    {
        if (reprarray[i] == 0)
            cout << "The entry " << i + 1 << " is undefined.\n";
        else if (reprarray[i] == pt_nil)
            cout << "The entry " << i + 1 << " is free.\n";
        else
            cout << "The entry " << i + 1 << " is " << *reprarray[i] << " .\n";
    }
    return;
}
/*---------------------------------------------------------*/
//below are the functions of HashSet_RH;
template<class T> HashSet_RH<T>::HashSet_RH(int size)
{
    maxsize = size;
    if (size < 20)
        maxsize = 20; // default size is 20; no smaller hashtables are considered
    numitems = 0; // initially, the hashtable is empty
    del_num=0;
	reprarray = new T*[maxsize];  // allocate space for the array of pointers
    del =new bool[maxsize];
    dib = new int[maxsize];
	// the for loop initialises all table entries to be undefined
    for (int i = 0; i < maxsize; i++)
    {
        reprarray[i] = 0;
        del[i]=false;
        dib[i]=0;
    }
}

template<class T> T & HashSet_RH<T>::operator[](int index)
{
    if (index <= 0 || index > maxsize)
    {
        cout << "Index error: index out of range\n";
        exit(EXIT_FAILURE);
    }
    if (reprarray[index - 1] != 0 && !del[index - 1])
        return *reprarray[index - 1];
    else
    {
        cout << "Index not used in hashtable";
        return 0;
    }
}

template<class T> void HashSet_RH<T>::add(T item)
{
    hash<T> hashfunction; // use the predefined hashfunction to get "key" values
    int index,dis=0;
    index = hashfunction(item) % maxsize; // First determine the position index in the hash table, where the new value is stored, if free.
	int location = -1;  // used to distinguish between undefined entries (null pointer) and placeholders
    while (reprarray[index] != 0) // We first check, if the item is already in the hashtable
    {
    	
        if (!del[index] && *reprarray[index] == item)
		    return;   // item found; no insertion
        if (dib[index]<dis){
        	if(item==22){
        		cout<<"------"<<*reprarray[index]<<dib[index]<<"\n";
			}
        	if(del[index]){
        		del[index]=false;
        		del_num--;numitems--;
        		break;
			}
        	T ch=item;
        	item=*reprarray[index];
        	*reprarray[index]=ch;
        	int temp_dis=dib[index];
        	dib[index]=dis;
        	dis=temp_dis;
		}
        index = (index + 1) % maxsize;
        dis++;
    }
    // after leaving the while loop we either have location < 1, i.e. we store the item at the last examined index (which contains a null pointer),
    // otherwise, if location >= 0 holds, we found a placeholder, so the item will be stored at the location of this placeholder
	location = index;
    del[location]=false;
    T *pt = new T;
    *pt = item;
    reprarray[location] = pt;   // store item in the hashtable
    dib[location]=dis;
	++ numitems;
    int load = 100 * numitems / maxsize;
    if (load >= 75)             // max load factor is exceeded; double the size
    {
        int newsize = 2 * numitems;
        rehash(newsize);
    }
    return;
}

template<class T> void HashSet_RH<T>::remove(T item)
{
    hash<T> hashfunction;  // use again the predefined hashfunction
    int index,dis=0;
    index = hashfunction(item) % maxsize;
    while (reprarray[index] != 0&&dib[index]>=dis)  // same as for add we search for item in the hashtable; the search starts at the designated hash value, and stops when we find a null pointer
    {
        if (!del[index] && *reprarray[index] == item)
                    // item found
        {
            /* check the next entry, if it is a null pointer; if yes, we can overwrite item by a null pointer; otherwise we use a placeholder, i.e. the pointer pt_nil */
            del[index]=true;
            del_num++;
            int load = 100 * numitems / maxsize;
            if (load <= 25)
                // if the min load factor is undershot, we shrink the hashtable, but the size shall always be >= 20
            {
                int newsize = numitems;
                if (newsize < 20)
                    newsize = 20;
                rehash(newsize);
            }
            return;
        }
        index = (index + 1) % maxsize;
        dis++;
    }
    cout << item << " is not in the hashtable.\n";
    return;
}

template<class T> bool HashSet_RH<T>::member(T item)
{
    hash<T> hashfunction;  // use the "key" function for the type T (if defined)
    int index;
    index = hashfunction(item) % maxsize;
    int dis=0;
    while (reprarray[index] != 0&&dib[index]>=dis) // again we search for item starting from the index position until we find a null pointer
    {
        if (reprarray[index] != 0 && !del[index] && *reprarray[index] == item)
            return true;  // item was found
        index = (index + 1) % maxsize;
        dis++;
    }
    return false;  // a null pointer was found, so item is not in the hashtable
}

template<class T> void HashSet_RH<T>::rehash(int newsize)
{
    if (newsize < 20)
        newsize = 20;
    int newnum = 0;
    T **newarray = new T*[newsize];   // allocate space for a new hashtable of the given new size
    T *temp=new T[newsize];
    for(int i=0;i<newsize;i++)newarray[i]=0;
    for (int i = 0; i < maxsize; i++)  // we need to copy all existing entries to the new hash table
    {
        if (reprarray[i] != 0 &&!del[i])
        {
            temp[newnum++] = *reprarray[i];  // do the actual copying
        }
    }
    numitems = newnum;   // change the number of stored elements
    reprarray = newarray;   // make the new hashtable the one of the hashset object
    maxsize = newsize;   // update the size
    for(int i=0;i<newnum;i++)add(temp[i]);
}

template<class T> void HashSet_RH<T>::display(void) // only for test purposes
{
    cout << "The size of the hashtable is: " << maxsize << "\n";
    cout << "The number of elements in the hashtable is: " << numitems-del_num << "\n";
    for (int i = 0; i < maxsize; ++i)
    {
        if (reprarray[i] == 0)
            cout << "The entry " << i + 1 << " is undefined.\n";
        else if (del[i])
            cout << "---------The entry " << i + 1 << " is deleted.\n"<<dib[i]<<"\n";
        else
            cout << "The entry " << i + 1 << " is " << *reprarray[i] << " .\n";
    }\
    return;
}

