
#ifndef _MULTISET_H_
#define _MULTISET_H_
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using std::hash;



template<class T> class pair{
    public:
        pair(){
            pair_t = 0;
            pair_n = 0;
        }
        pair(T t, int n):pair_t(t), pair_n(n){}
        T get_t(){
            return pair_t;
        }
        int get_n(){
            return pair_n;
        }
        void set_t(T t){
            pair_t = t;
        }
        void set_n(int n){
            pair_n = n;
        }
        void print_pairs();
    private:
        T pair_t;
        int pair_n;
};


template<class T> class MultiSet
{
public:
    MultiSet(int size = 10);
    virtual ~MultiSet();
    pair<T> &operator[](int index);
    int getlength(void);
    void print_pairs();
    void append(pair<T> pair1);

    void insertion(T num);
    void deletion(T num);
    int retrieval(T num);

    void setunion(MultiSet<T>* set1, MultiSet<T>* set2);
    void intersection(MultiSet<T>* set1, MultiSet<T>* set2);
    void difference(MultiSet<T>* set1, MultiSet<T>* set2);
    
private:
    int maxsize, minsize;
    int first, last;
    int numitems;
    pair<T> *reprarray;
    void allocate(void);
    void deallocate(void);
};

template<class T> class Node{
    public:
        Node<T>* next;
        T key;
    private:
        
};

template<class T> class Llist{
    friend class Node<T>;
    public:
        void getlength();
    private:
        int listitems;
};

template<class T> class Mchaining{
    public:
        Mchaining(int size);
        hash<T> hashfunction;
        void insertion(T num);
        void deletion(T num);
        int retrieval(T num);

        void setunion(Mchaining<T>* set1, Mchaining<T>* set2);
        void intersection(Mchaining<T>* set1, Mchaining<T>* set2);
        void difference(Mchaining<T>* set1, Mchaining<T>* set2);

        void rehash(int newsize);
        void print_all();
    private:
        int numitems;
        int maxsize;
        Node<T>** reprarray;

};
#endif