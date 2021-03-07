/*
 * @ Author     : 
 * 
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
#include "hw2ex2.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int main(){
    vector<booking> b1({booking(1,2), booking(2,3), booking(2,4), booking(3,4)});

    // =========== Test 1 ===========
    Bookings test1 = Bookings(b1, 8);
    cout << "Test 1: " << endl;
    test1.test();
    cout << "Gold Result: Success" << endl;

    // =========== Test 2 ===========
    Bookings test2 = Bookings(b1, 1);
    cout << "\nTest 2: " << endl;
    test2.test();
    cout << "Gold Result: Fail" << endl;

    // =========== Hidden Test =========
    // You could add your own test example
    
    // Test 3
    Bookings test3 = Bookings(b1, 2);
    cout << "\nTest 3: " << endl;
    test3.test();
    cout << "Gold Result: Success" << endl;

    // Further tests on different bookings:
    // cout << endl;
    // cout << "Further tests on different bookings:" << endl;
    // vector<booking> b2({booking(1,4), booking(1,2), booking(3,4)});
    // Bookings test4 = Bookings(b2, 2);
    // cout << "\nTest 4: " << endl;
    // test4.test();
    // cout << "Gold Result: Success" << endl;

    vector<booking> b3({booking(4,5), booking(3,4), booking(1,2), booking(2,3), booking(1,15)});
    Bookings test5 = Bookings(b3, 1);
    cout << "\nTest 5: " << endl;
    test5.test();
    cout << "Gold Result: Success" << endl;
    return 0;
}