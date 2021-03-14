  
#include<iostream>	
#include<math.h>
#include <cstdlib>
#include <map>
#include <vector>
#include "Ex2.h"
using namespace std;
template<class T> int NumSet<T>::Check_Relation(vector<pair<int,int> > R){
    /*
    Input:
        R: The relation to be checked. Each element in R is a pair(int,int)
    Output:
        0: The binary relation R is not symmetric
        1: The binary relation R is symmetric
    */
    if (R.size()==0){
    	return 0;
	}			//for the case when the array is empty
   int max = R[0].first;
   for (int i = 0; i < R.size(); i++){
       if (max < R[i].first){
           max = R[i].first;
       }
       if (max < R[i].second){
           max = R[i].second;
       }
   } // find the max value to determine m for making unique hash value for each input
   int m = max + 1;
   int same=0,count=0,eq=0;
   vector< vector<int> > table1(m*17+m*13);
  	// 0 if two pairs share the same hash value, 1 otherwise
   for (int i = 0; i < R.size(); i++){
       if (R[i].first == R[i].second){
       		eq++;
            continue; // if the first element in a pair is the same as the second, skip it
       }
        int hashVal1 = R[i].first * 17 + R[i].second*13;
        int hashVal2 = R[i].second * 17 + R[i].first*13; // hash function
        bool flag=0;
        for(int j = 0;j<table1[hashVal1].size();j++){
        	if(R[i].first==table1[hashVal1][j]){flag=1;break;}
		}		//use for loop to finish hash function
		if(flag){same++;continue;}
		table1[hashVal1].push_back(R[i].first);
        for(int j = 0;j<table1[hashVal2].size();j++){
        	if(R[i].second==table1[hashVal2][j]){count++;break;}
		}		//use for loop to finish hash function
    }
    return R.size()==(eq+same+count*2);		//return 0 or 1 to finish it
};
int main(){
    int Set_A[10]={1,2,3,4,5,6,7,8,9,10};
    NumSet<int> S(Set_A,10);
    //Here is for Test 1
    vector<pair<int,int> > Relation_R1;
    for (int i=0; i<10; i++){
        Relation_R1.push_back(make_pair(Set_A[i],Set_A[i]));
        for (int j=0; j<10; j++){
            if (i != j)
                Relation_R1.push_back(make_pair(Set_A[i],Set_A[j]));
        }
    }
    cout << "For Test 1:"<<endl;
    cout << "The correct answer should be Yes"<<endl;
    cout << "Your answer is:" << ((S.Check_Relation(Relation_R1) == 1)?"Yes":"No")<< endl;
    //Here is for Test 2
    vector<pair<int,int> > Relation_R2;
    for (int i=0; i<10; i++){
        Relation_R2.push_back(make_pair(Set_A[i],Set_A[i]));
        for (int j=0; j<10; j++){
            if ((i != j) && (j%2 != 1))
                Relation_R2.push_back(make_pair(Set_A[i],Set_A[j]));
        }
    }
    cout << "For Test 2:"<<endl;
    cout << "The correct answer should be No"<<endl;
    cout << "Your answer is:" << ((S.Check_Relation(Relation_R2)== 1)?"Yes":"No")<< endl;

    //----------Additional tests-----------------
    vector<pair<int,int> > Relation_R3;
    for (int i=0; i<10; i++){
        Relation_R3.push_back(make_pair(Set_A[i],Set_A[i]));
    }
    cout << "For Test 3\n(Only contains pairs with the first element equals to the second):"<<endl;
    cout << "The correct answer should be Yes"<<endl;
    cout << "Your answer is:" << ((S.Check_Relation(Relation_R3)== 1)?"Yes":"No")<< endl;
    
    int Set_B[9]={19,25,73,17,55,92,78,84,92};
    NumSet<int> F(Set_B,9);
    vector<pair<int,int> > Relation_R4;
    for (int i=0; i<9; i++){
        Relation_R4.push_back(make_pair(Set_B[i],Set_B[i]));
        for (int j=0; j<9; j++){
            if (i == j+8)
                Relation_R4.push_back(make_pair(Set_B[i],Set_B[j]));
        }
    }
    cout << "For Test 4\n(Contain repeat element):"<<endl;
    cout << "The correct answer should be No"<<endl;
    cout << "Your answer is:" << ((F.Check_Relation(Relation_R4) == 1)?"Yes":"No")<< endl;
    

    int Set_D[0]={};
    NumSet<int> D(Set_D,0);
    vector<pair<int,int> > Relation_R5;

    cout << "For Test 5\n(Contain no element):"<<endl;
    cout << "The correct answer should be No"<<endl;
    cout << "Your answer is:" << ((D.Check_Relation(Relation_R5) == 1)?"Yes":"No")<< endl;
    
    return 0;
}
