#include "multiset_f.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>


int main(){
    /******************* Put your own test here *******************/
    /* Your are expected to give adequate test to show the correctness of your implementation */
    /* Otherwise you may be deducted points */
    
    int input1[] = {1, 1, 1, 1, 5, 2, 3};
    // int input2[] = {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42};

    MultiSet<int> test1, test2;
    // MultiSet_chaining<int> test3, test4;

    /* Add test to your container */
    MultiSet<int> mul1;
    for(auto i: input1){
        // cout << i << endl;
        mul1.pushback(i);
    }
    for (int i = 0; i < mul1.getlength(); i++){
        mul1[i].print_pairs();
    }


    // for (auto i:input2){
    //     test2
    //     test4 
    // }


    /* Test for all required operation on both inputs, missing operation would be deducted points */
    /* Test for part(i) */
    



    /* Test for part(ii) */
    return 0;
}