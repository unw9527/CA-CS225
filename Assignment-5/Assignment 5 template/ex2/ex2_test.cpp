#include "multiset_f.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>


int main(){
    /******************* Put your own test here *******************/
    /* Your are expected to give adequate test to show the correctness of your implementation */
    /* Otherwise you may be deducted points */
    
    int input1[] = {1, 1, 1, 5, 2, 3};
    int input2[] = {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42};
    // MultiSet_chaining<int> test3, test4;

    /* Add test to your container */
    cout << "Test 1: {1, 1, 1, 5, 2, 3}:" << endl;
    MultiSet<int> mul1;
    for(auto i: input1){
        mul1.insertion(i);
    }
    cout << "The multiset is: ";
    mul1.print_pairs();
    
    cout << "Insert 1: " << endl;
    mul1.insertion(1);
    mul1.print_pairs();

    cout << "Insert 6: " << endl;
    mul1.insertion(6);
    mul1.print_pairs();


    cout << "Test 2: {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42}:" << endl;
    MultiSet<int> mul2;
    for(auto i: input2){
        mul2.insertion(i);
    }
    cout << "The multiset is: ";
    mul2.print_pairs();

    cout << "Insert 0: " << endl;
    mul2.insertion(0);
    mul2.print_pairs();

    cout << "Insert 3: " << endl;
    mul2.insertion(3);
    mul2.print_pairs();

    cout << "Insert 1000: " << endl;
    mul2.insertion(1000);
    mul2.print_pairs();


    // for (auto i:input2){
    //     test2
    //     test4 
    // }


    /* Test for all required operation on both inputs, missing operation would be deducted points */
    /* Test for part(i) */
    



    /* Test for part(ii) */
    return 0;
}