#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "hashset.cpp"
using std::cout;
using std::cin;
using std::hash;


int main(){
    int i;
    hash<int> hashfunction;
    
    // Test 1: normal case
    cout << "=============== Test 1 =====================\n";
    hashset<int> myhashtable;
    myhashtable = hashset<int>(20);
    int test_input[14] = {202,32,7,15,74,9,12,16,102,4,8,22,3,2};
    
    for (i = 0; i < 14; i ++){
        myhashtable.add(test_input[i]);
        cout << test_input[i] << "'s desired position:   " << hashfunction(test_input[i]) % 20 << "\n";
    }
    /* pay attention to 3, 2, 22's position */
    cout << "=============== my hashtable ===============\n";
    myhashtable.display();
    cout << "=============== remove 102 ===============\n";
    myhashtable.remove_modified(102);
    myhashtable.display();
    
    // Test 2: out-of-range case
    // In this case, we will have a value whose desired position is 19 but be placed at the position 1. 
    // When deleting what is originally in position 19, the number at position 1 will come there.
    cout << "\n============== Test 2 =====================\n";
    hashset<int> myhashtabletwo;
	myhashtabletwo = hashset<int>(20);
	int test_input_two[6] = {118,119,80,61,28,39};
	
	for (i = 0; i < 6; i++) {
		myhashtabletwo.add(test_input_two[i]);
		cout << test_input_two[i] << "'s desired position:  " << hashfunction(test_input_two[i]) % 20 << "\n";
	} 
    cout << "=============== my hashtable 2 ===============\n";
    myhashtabletwo.display();
    /* pay attention to 39's and 119's position*/
    cout << "=============== remove 61 ================\n";
    myhashtabletwo.remove_modified(61);
    myhashtabletwo.display();
    /* This time, a rehash happens and 39 goes to position 19.*/
    cout << "=============== remove 39 ===============\n";
    myhashtabletwo.remove_modified(39);
    myhashtabletwo.display();
    /* We can see that 119 comes back to position 19.*/
    
    return 1;
}


