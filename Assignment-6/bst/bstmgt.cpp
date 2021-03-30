//
//  bstmgt.cpp
//  
//
//  Created by KD on 14.03.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "bst.cpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    // int type, op;
    // BST<int> mytree1 = BST<int>();
    // BST<double> mytree2 = BST<double>();
    // bool boolresult;
    // do
    // {
    //     cout << "Choose your element type:\n";
    //     cout << "0: int  1: double\n";
    //     cin >> type ;
    //     if ((type != 0) && (type != 1))
    //         cout << "You must choose 0 or 1\n\n";
    // }
    // while ((type != 0) && (type != 1));
    // do
    // {
    //     do
    //     {
    //         cout << "Choose an operation:\n";
    //         cout << "O: quit\n";
    //         cout << "1: insert\n";
    //         cout << "2: delete\n";
    //         cout << "3: find\n";
    //         cout << "4: display\n";
    //         cin >> op ;
    //     }
    //     while ((op < 0) && (op > 4));
    //     switch(op)
    //     {
    //         case 0: return(0);
    //         case 1:
    //         {
    //             cout << "Enter a value:\n";
    //             if (type == 0)
    //             {
    //                 int intitem;
    //                 cin >> intitem;
    //                 mytree1.insert(intitem);
    //             }
    //             else
    //             {
    //                 double doubleitem;
    //                 cin >> doubleitem;
    //                 mytree2.insert(doubleitem);
    //             }
    //             break;
    //         }
    //         case 2:
    //         {
    //             cout << "Enter a value:\n";
    //             if (type == 0)
    //             {
    //                 int intitem;
    //                 cin >> intitem;
    //                 mytree1.remove(intitem);
    //             }
    //             else
    //             {
    //                 double doubleitem;
    //                 cin >> doubleitem;
    //                 mytree2.remove(doubleitem);
    //             }
    //             break;
    //         }
    //         case 3:
    //         {
    //             cout << "Enter a value:\n";
    //             if (type == 0)
    //             {
    //                 int intitem;
    //                 cin >> intitem;
    //                 boolresult = mytree1.find(intitem);
    //             }
    //             else
    //             {
    //                 double doubleitem;
    //                 cin >> doubleitem;
    //                 boolresult = mytree2.find(doubleitem);
    //             }
    //             if (boolresult == true)
    //                 cout << "The value is in the BST.\n";
    //             else
    //                 cout << "The value is not in the BST.\n";
    //             break;
    //         }
    //         case 4:
    //         {
    //             if (type == 0)
    //                 mytree1.display();
    //             else
    //                 mytree2.display();
    //         }
    //     }
    // }
    // while (op != 0);

    // Below are the tests I used for debugging.

    BST<int> mytree1 = BST<int>();
    for (int i = 1; i < 7; i++){
        mytree1.insert(i);
    }
    cout << "mytree1: " << endl;
    mytree1.display();
    cout << "Delete 3: " << endl;
    mytree1.remove(3);
    mytree1.display();
    cout << "Delete 5: " << endl;
    mytree1.remove(5);
    mytree1.display();
    cout << "Delete 1: " << endl;
    mytree1.remove(1);
    mytree1.display();
    cout << "Delete 6: " << endl;
    mytree1.remove(6);
    mytree1.display();
    cout << endl;

    BST<int> mytree2 = BST<int>();
    for (int i = 7; i > 1; i--){
        mytree2.insert(i);
    }
    cout << "mytree2: " << endl;
    mytree2.display();
    cout << "Delete 3: " << endl;
    mytree2.remove(3);
    mytree2.display();
    cout << "Delete 5: " << endl;
    mytree2.remove(5);
    mytree2.display();
    cout << "Delete 2: " << endl;
    mytree2.remove(2);
    mytree2.display();
    cout << "Insert 100: " << endl;
    mytree2.insert(100);
    mytree2.display();
    cout << "Delete 2: " << endl;
    mytree2.remove(2);
    mytree2.display();
    cout << "Delete 100: " << endl;
    mytree2.remove(100);
    mytree2.display();
    cout << "Delete 4: " << endl;
    mytree2.remove(4);
    mytree2.display();
    cout << endl;

    BST<double> mytree3 = BST<double>();
    mytree3.insert(3.1);
    mytree3.insert(6.2);
    mytree3.insert(8.3);
    mytree3.insert(10.4);
    mytree3.insert(7.5);
    mytree3.insert(5.6);
    mytree3.insert(2.7);
    mytree3.insert(9.8);
    mytree3.insert(4.9);
    mytree3.insert(13.0);
    mytree3.insert(11.6);
    cout << "mytree 3: " << endl;
    mytree3.display();
    cout << "Delete 5.6: " << endl;
    mytree3.remove(5.6);
    mytree3.display();
    cout << "Delete 2.7: " << endl;
    mytree3.remove(2.7);
    mytree3.display();
    cout << "Delete 11.6: " << endl;
    mytree3.remove(11.6);
    mytree3.display();
    cout << "Insert 66.1: " << endl;
    mytree3.insert(66.1);
    mytree3.display();
    cout << "Delete 66.1: " << endl;
    mytree3.remove(66.1);
    mytree3.display();
    cout << endl;
    return 0;
}