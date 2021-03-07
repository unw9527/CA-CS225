#include "hw2ex1.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <cstdlib>

int main(){
    // ============ test 1 ==============
    int a[11]={1, 3, 2,8, 0, 10, 4, 100, 90};
    Solution<int> test1 = Solution<int>(vector<int>(a,a+9));
    cout << "Test 1:" << endl << "Input: ";
    test1.vec_print(test1.data);
    cout << "Gold Output:" << "0  1  2  3  4  8  10  90  100" << endl << endl; 
    test1.test(4, 2);

    // ============ test 2 ==============
    float b[20]={2.5, 3.4, 1.9, 7.8, 3.9, 1, 9, 0, -1.7};
   Solution<float> test2 = Solution<float>(vector<float>(b,b+9));
    cout << "\n \n Test 2:" << endl << "Input:         ";
   test2.vec_print(test2.data);
   cout << "Gold Output:        " << " -1.7  0  1  1.9  2.5  3.4  3.9  7.8  9" << endl << "--------------" << endl; 
   test2.test(4, 4);


    // You could add your own test example
    // ============ test 3 ==============
    //it's a test for double type
    float c[20]={-2.5, 3.8, 1.9, 78, 3.9, 1.5, 96, 0.2, -1.3, 2.6, 4.3, 5.9};
    Solution<double> test3 = Solution<double>(vector<double>(c,c+12));
    cout << "\n \n Test 3:" << endl << "Input:         ";
    test3.vec_print(test3.data);
    cout << "Gold Output:        " << " -2.5  -1.3  0.2  1.5  1.9  2.6  3.8  3.9  4.3  5.9  78  96" << endl << "--------------" << endl; 
    test3.test(4, 6);
    
    // ============ test 4 ==============
    //it's a test for empty array
    int d[0]={};
    Solution<int> test4 = Solution<int>(vector<int>(d,d));
    cout << "\n \n Test 4:" << endl << "Input: ";
    test4.vec_print(test4.data);
    cout << "Gold Output:" << "" << endl << endl; 
    test4.test(4, 2);

    return 0;


}
