/*
 * @ Author     : 
 * Lin Jiakai 
 * @ File       : 
 * 
 * @ Purpose    : 
 * 
 * @ Usage      : 
 * 
 * @ Description: 
 * 
 * @ Input      : 
 * 
 * @ Output     : 
 * 
 */
#ifndef ex1
#define ex1

#include <iostream>
#include <vector>
using namespace std;

// You may modify the decleration and definenation by yourself, add help function etc.
template <class T> class Solution {
    public:
        Solution(vector<T> input){
            data = input;
        };

        vector<T> MergeSort_k(vector<T> lst, u_int k);
        vector<T> MergeSort_t(vector<T> lst, u_int t);
        vector<T> SelfSort(vector<T> lst);
        void vec_print(vector<T> vec);
        vector<T> data;
        void test(u_int k, u_int t);
    private:
        
};

// Modify the following to finish ex1.1
template <class T> vector<T> Solution<T>::MergeSort_k(vector<T> lst, u_int k){
    return lst;
};




// Modify the following to finish ex1.2
template<class T> vector<T> Solution<T>::MergeSort_t(vector<T> lst, u_int t){
   u_int sz=lst.size();                     //let sz be the size
   if(sz<=t)return SelfSort(lst);        //it's a judgement
   u_int sub_sz=sz/2;						//it's the size for the next list
   vector<T> a(lst.begin(),lst.begin()+sub_sz);		//define vector a
   vector<T> b(lst.begin()+sub_sz,lst.end());		//define vector b
	a=MergeSort_t(a,t);			//mergesort on a
	b=MergeSort_t(b,t);			//mergesort on b
	vector<T> new_lst(lst);		//define vector new_lst
	u_int pt1=0,pt2=0,pt3=0;
	while(pt1!=a.size()&&pt2!=b.size()){	//use a while loop
		if(a[pt1]<b[pt2]){
			new_lst[pt3]=a[pt1];
			pt1++;
		}
		else{
			new_lst[pt3]=b[pt2];
			pt2++;
		}
			pt3++;		//it's the process of sort
	}
	while(pt1!=a.size()){   //it's the process of sort when b is over
		new_lst[pt3++]=a[pt1];
		pt1++;
	}
	while(pt2!=b.size()){   //it's the process of sort when a is over
		new_lst[pt3++]=b[pt2];
		pt2++;
	}
	return new_lst;		//return
}

// You could implement either bubble sort, insert sort or selection sort
template<class T> vector<T> Solution<T>::SelfSort(vector<T> lst){
    for(u_int i=1;i<lst.size();i++){		//use for loop
    	for(u_int j=0;j<lst.size()-i;j++){		//use for loop
    		T t;		//define t
    		if(lst[j]>lst[j+1]){		//use if judgement
    			t=lst[j];
    			lst[j]=lst[j+1];
    			lst[j+1]=t;		//swap two elements
			}
		}
	}
	return lst;
}

// DO NOT modify the following
// This is to view the vector
template<class T> void Solution<T>::vec_print(vector<T> vec){
    for (u_int i=0;i<vec.size();i++){
        cout << vec[i] << "  ";
    }
    cout << endl;
    return ;
}

// This is for testing.
template <class T> void Solution<T>::test(u_int k, u_int t){
    cout << "Self-implemented Sort:          ";
    vec_print(SelfSort(data));
    cout << "Merge Sort with Insertion Sort: ";
    vec_print(MergeSort_t(data, t));
}
#endif 

