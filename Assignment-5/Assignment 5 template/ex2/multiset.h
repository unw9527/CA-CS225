
#ifndef _MULTISET_H_
#define _MULTISET_H_


template<class T> class MultiSet_Chaining{
    public:
        MultiSet_Chaining();
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
    void remove_all(MultiSet<T>* set);
    void append(pair<T> pair1);
    // bool isempty(void);
    // pair<T> back(void);
    // pair<T> front(void);
    // pair<T> popfront(void);

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