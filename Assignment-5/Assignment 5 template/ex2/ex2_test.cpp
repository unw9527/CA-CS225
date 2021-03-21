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

    /* Add test to your container */
    cout << "MultiSet with explicit storage of multiplicities: " << endl;
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

    cout << "Delete 12: " << endl;
    mul2.deletion(12);
    mul2.print_pairs();

    cout << "Insert 1000: " << endl;
    mul2.insertion(1000);
    mul2.print_pairs();

    cout << "Delete 12345: " << endl;
    mul2.deletion(12345);
    mul2.print_pairs();

    double input3[] = {1.5, 1.5, 1.5, 2.1, 2.5, 3.5, 4000};
    double input4[] = {0, 2.5, 3.6, 3.6, 3.6, 3.6, 5.6, 5.5, 42};

    MultiSet<double> test3;
    MultiSet<double> test4;
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

    cout << "Retrieval from test 3:" << endl;
    test3.retrieval(1.5);
    test3.retrieval(2.1);
    test3.retrieval(4000);
    test3.retrieval(178329);

    cout << "Setunion of test 3 and test 4: " << endl;
    MultiSet<double> mul3;
    mul3.setunion(&test3, &test4);
    mul3.print_pairs();

    cout << "Intersection of test 3 and test 4: " << endl;
    MultiSet<double> mul4;
    mul4.intersection(&test3, &test4);
    mul4.print_pairs();

    cout << "Difference of test 3 and test 4: " << endl;
    MultiSet<double> mul5;
    mul5.difference(&test3, &test4);
    mul5.print_pairs();


    float input7[] = {1.4, 1.4, 1.5, 2.1, 2.5, 3.6, 4000};
    float input8[] = {0, 2.5, 3.2, 3.3, 3.6, 3.6, 5.6, 5.5, 42};

    MultiSet<float> test7;
    MultiSet<float> test8;
    for(auto i: input7){
        test7.insertion(i);
    }
    for(auto i: input8){
        test8.insertion(i);
    }
    cout << "Test 7: " << endl;
    test7.print_pairs();
    cout << "Test 8: " << endl;
    test8.print_pairs();

    cout << "Retrieval from test 7:" << endl;
    test7.retrieval(1.4);
    test7.retrieval(2.1);
    test7.retrieval(4000);
    test7.retrieval(178329);

    cout << "Setunion of test 7 and test 8: " << endl;
    MultiSet<float> mul7;
    mul7.setunion(&test7, &test8);
    mul7.print_pairs();

    cout << "Intersection of test 7 and test 8: " << endl;
    MultiSet<float> mul8;
    mul8.intersection(&test7, &test8);
    mul8.print_pairs();

    cout << "Difference of test 7 and test 8: " << endl;
    MultiSet<float> mul9;
    mul9.difference(&test7, &test8);
    mul9.print_pairs();


    /* Test for part(ii) */
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "MultiSet with Chaining: " << endl;
    MChaining<int> mc1, mc2; 
    int input5[] = {1, 1, 1, 5, 2, 3};
    int input6[] = {1, 1, 6, 2, 100};
    for (auto i: input5){
        mc1.insertion(i);
    }
    for (auto i: input6){
        mc2.insertion(i);
    }
    cout << "Test 5: " << endl;
    mc1.print_all();
    cout << "Test 6: " << endl;
    mc2.print_all();
    mc1.deletion(1);
    cout << "Delete 1: " << endl;
    mc1.print_all();
    mc1.insertion(1);
    cout << "Insert 1: " << endl;
    mc1.print_all();
    cout << "Delete 15: " << endl;
    mc1.deletion(15);
    mc1.print_all();

    cout << "Retrieval from test 5: " << endl;
    mc1.retrieval(20);
    mc1.retrieval(1);
    mc1.retrieval(2);
    MChaining<int> mc3, mc4, mc5;

    cout << "Setunion of test 5 and test 6: " << endl;
    mc3.setunion(&mc1, &mc2);
    mc3.print_all();

    cout << "Intersection of test 5 and test 6: " << endl;
    mc4.intersection(&mc1, &mc2);
    mc4.print_all();

    cout << "Difference of test 5 and test 6: " << endl;
    mc5.difference(&mc1, &mc2);
    mc5.print_all();
    return 0;
}