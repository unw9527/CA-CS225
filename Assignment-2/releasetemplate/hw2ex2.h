/*
 * @ Author     : Kunle Li (Group 1)
 * 
 * @ File       : hw2ex2.h
 * 
 * @ Purpose    : header file for ex2 hw2
 * 
 * @ Usage      : QuickSort to sort Bookings
 *     
 * @ Description: define class Bookings, booking, and methods to check whether rooms are enough for bookings during a certain period
 * 
 * @ Input      : none (this is not a simple function)
 * 
 * @ Output     : none
 * 
 */

/*
 * According to my TA, I assume that at the arrival the person will use a room,
 * and at his departure he will NOT use a room.
 * If he arrives and leaves on the same date, he does not use a room.
 */

#include <vector>
#include <iostream>
using namespace std;

class booking{
    public:
        booking(int a, int d){
            arrival = a;
            departure = d;
        };
        int arrival; 
        int departure; 
};


class Bookings{
    public:
        Bookings(vector<booking> bookings, int K){
            bks = bookings;
            k = K;
        };
        vector <booking> bks;
        int k;
        void bookings_print();
        void test();
        
        // Modify the following to solve the exercise
        // You may also add your own help function
        bool checkdemands();
        void quickSort_arr(int low, int high);
        void quickSort_dep(int low, int high);
    private:

};

void Bookings::quickSort_arr(int left, int right)
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = bks[left].arrival; // set the left number as key
	while (i < j)
	{
		while (bks[j].arrival >= base && i < j)
			j--; // decrement j until the number j points to is less than the key
		while (bks[i].arrival <= base && i < j)
			i++; // increment i until the number i points to is less than the key
		if(i < j)
		{
			temp = bks[i].arrival;
			bks[i].arrival = bks[j].arrival;
			bks[j].arrival = temp;
		}
	}
	// reset the key
	bks[left].arrival = bks[i].arrival;
	bks[i].arrival = base;
	this->quickSort_arr(left, i - 1); // recurse into the left part
	this->quickSort_arr(i + 1, right); // recurse into the right part
}

void Bookings::quickSort_dep(int left, int right)
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = bks[left].departure;  //set the number on the left as the key
	while (i < j)
	{
		while (bks[j].departure >= base && i < j)
			j--; // decrement j until the number j points to is less than the key
		while (bks[i].departure <= base && i < j)
			i++; // increment i until the number i points to is less than the key
		if(i < j)
		{
			temp = bks[i].departure;
			bks[i].departure = bks[j].departure;
			bks[j].departure = temp;
		}
	}
	// reset the key
	bks[left].departure = bks[i].departure;
	bks[i].departure = base;
	this->quickSort_dep(left, i - 1); // recurse into the left part
	this->quickSort_dep(i + 1, right); // recurse into the right part
}



// You should right the following to finish the exercise
// You may also add your own help function
bool Bookings::checkdemands(){
    this->quickSort_arr(0, bks.size()); 
    this->quickSort_dep(0, bks.size());
    int count = 0;
    int ptr = 0;
    for (long unsigned int i = 0; i < bks.size(); i++){
        
        if (count > k){
            return 0;
        }
        count++;
        if (bks[i].arrival >= bks[ptr].departure){
            count--;
            ptr++;
        }
    }
    if (count > k){
            return 0;
    }
    return 1;
};




// DO NOT modify the following 
void Bookings::bookings_print(){
    cout << "Bookings as follow:" << endl;
    for(booking i: this->bks){
        cout << "A: " << i.arrival << "  | D: " << i.departure << endl;
    }
    cout << "Max available room:" << this->k << endl;
    return ;
}

void Bookings::test(){
    bookings_print();
    cout << "Check whether satisfy the demands: " << (checkdemands()? "Success":"Fail") << endl;
}