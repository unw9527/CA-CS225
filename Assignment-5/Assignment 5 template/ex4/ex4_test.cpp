#include <ctime>                /* For performance comparasion */
#include "hashset_f.h"
#include "hash_extend_f.h"


int main(){
    /******************* Put your own test here *******************/
    /* Your are expected to give adequate test to show the correctness of your implementation */
    /* Otherwise you may be deducted points */

    /**************************************************************/
    /* Check Point 1: Correctness */
    int input1[] = {1, 1, 1, 5, 2};
    int input2[] = {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42};
    HashSet_LCFS<int> test1,test2;
    HashSet_RH<int> test3, test4;
    /* Add test to your container */
    for(auto i: input1){
        test1.add(i);
        test3.add(i);
    }


    for (auto i:input2){
    	test2.add(i);
        test4.add(i);
    }

    /* Test on both inputs, missing operation would be deducted points */
    /* Test for LCFS Hash */
    //test case 1
//    cout<<"test1 has these elemnts.\n";
//	test1.display();
//	cout<<"Is 3 in this hashtable?\n";
//	if(test1.member(3))cout<<"no.\n";
//	else cout<<"no\n";
//	cout<<"add element 3.\n";
//	test1.add(3);
//	cout<<"Is 3 in this hashtable?\n";
//	if(test1.member(3))cout<<"yes.\n";
//	else cout<<"no\n";
//	cout<<"test1 has these elemnts.\n";
//	test1.display();
//	cout<<"add element 23.\n";
//	test1.add(23);
//	cout<<"then there would be a collison between 3 and 23.\n";
//	test1.display();
//	cout<<"add element 22.\n";
//	test1.add(22);
//	cout<<"then there would be a collison between 22 and 2.\n";
//	test1.display();
    /* Test for RH Hash */
	cout<<"test4 has these elemnts.\n";
	test4.display();
	cout<<"Is 3 in this hashtable?\n";
	if(test4.member(3))cout<<"yes.\n";
	else cout<<"no\n";
	cout<<"delete element 3.\n";
	test4.remove(3);
	cout<<"Is 3 in this hashtable?\n";
	if(test4.member(3))cout<<"yes.\n";
	else cout<<"no\n";
	cout<<"test4 has these elemnts.\n";
	test4.display();
	cout<<"add element 22.\n";
	test4.add(22);
	cout<<"then there would be a collison between 2 and 22.\n";
	test4.display();
    /**************************************************************/
    /* Check Point 2: Compare the performance with initial hashset as baseline */
    /* ctime is included for you to help */


    return 0; 
}
