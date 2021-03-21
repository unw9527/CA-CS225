
#ifndef _MULTISET_H_
#define _MULTISET_H_

template<class T> class DList;

template<class T> class node
{
    friend class DList<T>;
public:
    node(T item = 0, node<T> *pt_n = 0, node<T> *pt_p = 0);
//    virtual ~node(void);
    T getdata(void);
    node<T> *getnext(void);
    node<T> *getprevious(void);
    void setdata(T item);    
    void setnext(node<T> *pt);
    void setprevious(node<T> *pt);
private:
    T dataitem;
    node<T> *pt_next;
    node<T> *pt_previous;
};

template<class T> class DList
{
public:
    DList(void);
//    virtual ~DList();
    T operator[](int index);
    int getlength(void);
    void setitem(int index, T value);
    T getitem(int index);
    void append(T value);
    void remove(int index);
    
private:
    node<T> *dummy;
    int numitems;
    node<T> *first(void);
    node<T> *last(void);
    node<T> *locate(int index);
   
};


template<class T> class MChaining
{
public:
    MChaining(int size = 10);
    virtual ~MChaining();
    int getlength(void);
    void print_all(void);
    void pushback(DList<T> list1);
  

    void insertion(T num);
    void deletion(T num);
    int retrieval(T num);

    void setunion(MChaining<T>* set1, MChaining<T>* set2);
    void intersection(MChaining<T>* set1, MChaining<T>* set2);
    void difference(MChaining<T>* set1, MChaining<T>* set2);
    
private:
    int maxsize, minsize;
    int first, last;
    int numitems;
    DList<T> *reprarray;
    void allocate(void);
    void deallocate(void);
};


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

#endif