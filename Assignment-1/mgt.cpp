int main() {
	int numitems; // Added.
	ljk<int> newlist1;  /* ljk is a class name here, which should be later changed to Alist or a DIY name by the function programmer.*/
	ljk<double> newlist2;
	cout << "The original integer list is:";
	for (int i=1;i<4;i++) {
		newlist1.append(i);
		cout << i << " ";
	}
	cout << "\n";
	cout << "The original double list is:";
	for (double i=1.46;i<1.54;i+=0.02) {
		newlist2.append(i);
		cout << i << " ";
	}
	cout << "\n";
	
	
	cout << "Test cases for pushback:\n";
    cout << "Do pushback for newlist1 (push 7 here):\n";
    newlist1.pushback(7); // Do pushback.
	numitems = newlist1.getlength(); // Get the length of the new list.
	cout << "New list 1:";
	for (int i=1; i<=numitems; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do pushback for newlist2 (push 1.7 here):\n";
    newlist2.pushback(1.7); // Do pushback.
	numitems = newlist2.getlength(); // Get the length of the new list.
	cout << "New list 2:";
	for (int i=1; i<=numitems; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n";
	
	
	cout << "Test cases for pushhfront:\n";
    cout << "Do pushfront for newlist1 (push 5 here):\n";
    newlist1.pushfront(5); // Do pushfront.
	numitems = newlist1.getlength(); // Get the length of the new list.
	cout << "New list 1:";
	for (int i=1; i<=numitems; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do pushfront for newlist2 (push 6.4 here):\n";
    newlist2.pushfront(6.4); // Do pushfront.
	numitems = newlist2.getlength(); // Get the length of the new list.
	cout << "New list 2:";
	for (int i=1; i<=numitems; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n";
	
	
	cout << "Test cases for popback:\n";
    cout << "Do popback for newlist1 (should pop 7):\n";
    int pop_int;
    pop_int=newlist1.popback(); // Do popback.
    cout << "The poped value is:" << pop_int << "\n";
	numitems = newlist1.getlength(); // Get the length of the new list.
	cout << "New list 1:";
	for (int i=1; i<=numitems; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do popback for newlist2 (should pop 1.7):\n";
	double pop_double;
	pop_double=newlist2.popback(); // Do popback.
	cout << "The poped value is:" << pop_double << "\n";
	numitems = newlist2.getlength(); // Get the length of the new list.
	cout << "New list 2:";
	for (int i=1; i<=numitems; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n";
	
	
	cout << "Test cases for popfront:\n";
    cout << "Do popfront for newlist1 (should pop 5):\n";
    int pop_int;
    pop_int=newlist1.popfront(); // Do popfront.
    cout << "The poped value is:" << pop_int << "\n";
	numitems = newlist1.getlength(); // Get the length of the new list.
	cout << "New list 1:";
	for (int i=1; i<=numitems; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do popfront for newlist2 (should pop 6.4):\n";
	double pop_double;
	pop_double=newlist2.popfront(); // Do popfront.
	cout << "The poped value is:" << pop_double << "\n";
	numitems = newlist2.getlength(); // Get the length of the new list.
	cout << "New list 2:";
	for (int i=1; i<=numitems; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n";
	
	
	return 0;
}
