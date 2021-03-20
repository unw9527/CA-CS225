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
    cout << "Test 1: {1, 1, 1, 5, 2, 3}" << endl;
    MultiSet<int> mul1;
    for(auto i: input1){
        mul1.insertion(i);
    }
    cout << "The multiset is: ";
    mul1.print_pairs();
    
    cout << "Insert 1: " << endl;
    mul1.insertion(1);
    mul1.print_pairs();

    // cout << "Delete 1: " << endl;
    // mul1.deletion(1);
    // mul1.print_pairs();

    cout << "Insert 6: " << endl;
    mul1.insertion(6);
    mul1.print_pairs();

    cout << "Delete 5: " << endl;
    mul1.deletion(5);
    mul1.print_pairs();

    cout << "Delete 10000: " << endl;
    mul1.deletion(10000);
    mul1.print_pairs();

    cout << "Test 2: {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42}" << endl;
    MultiSet<int> mul2;
    for(auto i: input2){
        mul2.insertion(i);
    }
    cout << "The multiset is: ";
    mul2.print_pairs();

    cout << "Insert 0: " << endl;
    mul2.insertion(0);
    mul2.print_pairs();

    cout << "Delete 0: " << endl;
    mul2.deletion(0);
    mul2.print_pairs();

    // cout << "Insert 3: " << endl;
    // mul2.insertion(3);
    // mul2.print_pairs();

    cout << "Delete 12: " << endl;
    mul2.deletion(12);
    mul2.print_pairs();

    cout << "Insert 1000: " << endl;
    mul2.insertion(1000);
    mul2.print_pairs();

    // cout << "Insert 2000: " << endl;
    // mul2.insertion(2000);
    // mul2.print_pairs();

    cout << "Delete 12345: " << endl;
    mul2.deletion(12345);
    mul2.print_pairs();

    // double input3[] = {1.0, 1.0, 1.0, 5.1, 2.3, 3.6};
    int input3[] = {1, 1, 1, 2, 2, 3, 4000};
    int input4[] = {0, 2, 3, 3, 3, 3, 5, 5, 42};

    MultiSet<int> test3, test4;
    for(auto i: input3){
        test3.insertion(i);
    }
    for(auto i: input4){
        test4.insertion(i);
    }
    cout << "Test 3: " << endl;
    test3.print_pairs();
    cout << "Test 4: " << endl;
    test4.print_pairs();

    cout << "Setunion of test 3 and test 4: " << endl;
    MultiSet<int> mul3;
    mul3.setunion(&test3, &test4);
    mul3.print_pairs();

    cout << "Intersection of test 3 and test 4: " << endl;
    MultiSet<int> mul4;
    mul4.intersection(&test3, &test4);
    mul4.print_pairs();

    cout << "Difference of test 3 and test 4: " << endl;
    MultiSet<int> mul5;
    mul5.difference(&test3, &test4);
    mul5.print_pairs();

    cout << "Retrieval from test 3:" << endl;
    test3.retrieval(1);
    test3.retrieval(2);
    test3.retrieval(4000);
    test3.retrieval(178329);

    // for (auto i:input2){
    //     test2
    //     test4 
    // }


    /* Test for all required operation on both inputs, missing operation would be deducted points */
    /* Test for part(i) */
    



    /* Test for part(ii) */
    return 0;
}