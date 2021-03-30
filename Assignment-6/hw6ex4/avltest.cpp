#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "avl.cpp"
using std::cout;
using std::cin;

int main() {
	// Tests for the newly implemented Median AVL Tree
	// Preparation
	AVL<int> medianone = AVL<int>();
    AVL<double> mediantwo = AVL<double>();
	int one[8]={20,10,30,5,25,15,35,1};
	double two[16]={8.1,4.1,12.1,2.1,10.1,6.1,14.1,1.1,9.1,3.1,11.1,5.1,13.1,7.1,15.1,0.1};
	
	
	/* Test of int */
	cout << "\n|>|>|>|>|>| TEST OF INT\n";
	for (int i=0; i<8; i++) {
		medianone.insert(one[i]);
	}
	cout << "########## The current AVL<int> tree is:  ############\n";
	medianone.display();  // Here l-r=1, which satisfy median properties.
	cout << "\n";
	// Test 1
	cout << "============= Int Test 1: insert to l-r=2 ==============\n";
	cout << "~~~~~~~~~~ Insert 9: ~~~~~~~~~\n";  // This will cause the left subtree has 2 more nodes than the right one.
	medianone.insert(9);
	medianone.display();  // 15 will be the top node now.
	// Test 2
	cout << "============= Int Test 2: insert to l-r=-1 ==============\n";
	cout << "~~~~~~~~~~ Insert 21: ~~~~~~~~~\n";  // This will cause the left subtree has 1 less node than the right one.
	medianone.insert(21);
	medianone.display();  // 20 will be the top node now.
	// Test 3
	cout << "============= Int Test 3: delete to l-r=2 ==============\n";
	cout << "~~~~~~~~~~ Delete 30: ~~~~~~~~~\n";  // This will cause the left subtree has 2 more nodes than the right one.
	medianone.remove(30);
	medianone.display();  // 15 will be the top node now.
	// Test 4
	cout << "============= Int Test 4: delete to l-r=-1 ==============\n";
	cout << "~~~~~~~~~~ Delete 5: ~~~~~~~~~\n";  // This will cause the left subtree has 1 less node than the right one.
	medianone.remove(5);
	medianone.display();  // 20 will be the top node now.
	/* End of test of int */
	
	
	/* Test of double */
	cout << "\n|>|>|>|>|>| TEST OF DOUBLE\n";
	for (int i=0; i<16; i++) {
		mediantwo.insert(two[i]);
	}
	cout << "########## The current AVL<double> tree is:  ############\n";
	mediantwo.display();  // Here l-r=1, which satisfy median properties.
	cout << "\n";
	// Test 1
	cout << "============= Double Test 1: insert to l-r=2 ==============\n";
	cout << "~~~~~~~~~~ Insert 2.2: ~~~~~~~~~\n";  // This will cause the left subtree has 2 more nodes than the right one.
	mediantwo.insert(2.2);
	mediantwo.display();  // 7.1 will be the top node now.
	// Test 2
	cout << "============= Double Test 2: insert to l-r=-1 ==============\n";
	cout << "~~~~~~~~~~ Insert 8.2: ~~~~~~~~~\n";  // This will cause the left subtree has 1 less node than the right one.
	mediantwo.insert(8.2);
	mediantwo.display();  // 8.1 will be the top node now.
	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//mediantwo.insert(6.7);
	//cout << "scnb\n";
	//mediantwo.insert(14.3);
	//cout << "hzfnb\n";
	//mediantwo.display();
	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 
	// Test 3
	cout << "============= Double Test 3: delete to l-r=2 ==============\n";
	cout << "~~~~~~~~~~ Delete 14.1: ~~~~~~~~~\n";  // This will cause the left subtree has 2 more nodes than the right one.
	mediantwo.remove(14.1);
	mediantwo.display();  // 7.1 will be the top node now.
	// Test 4
	cout << "============= Double Test 4: delete to l-r=-1 ==============\n";
	cout << "~~~~~~~~~~ Delete 4.1: ~~~~~~~~~\n";  // This will cause the left subtree has 1 less node than the right one.
	mediantwo.remove(4.1);
	mediantwo.display();  // 8.1 will be the top node now.
	/* End of test of double */
	
	return 0;
} 
	

