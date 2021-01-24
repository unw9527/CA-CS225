// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Test cases for Q4, selection and bubble for AList.
	int type, size, op;
    int pos, yes;
    int intitem, result1;
    int numitems; // Added.
    AList<int> mylist1;
    AList<double> mylist2;
    double doubleitem, result2;
    bool boolresult;
    cout << "Test cases for selection sort:\n";
    
    cout << "Do selection sort for an descending integer list:\nThe original list contains: ";
    AList<int> listselect;
    for (int i=6; i>=0; i--) {
    	listselect.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listselect.selectionSort(); // Do the bubble sort using implemented function.
	numitems = listselect.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listselect[i] << " ";
	}
	cout << "\n";
	cout << "Do selection sort for an descending double list:\nThe original list contains: ";
	AList<double> listselect1;
    for (double i=1.98; i>=1.82; i-=0.02) {
    	listselect1.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listselect1.selectionSort(); // Do the bubble sort using implemented function.
	numitems = listselect1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listselect1[i] << " ";
	}
	cout << "\n";
	
	
	cout << "\n" << "Test cases for bubble sort:\n";
    
    cout << "Do bubble sort for an descending integer list:\nThe original list contains: ";
    AList<int> listbubble;
    for (int i=9; i>=1; i--) {
    	listbubble.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listbubble.bubbleSort(); // Do the selection sort using implemented function.
	numitems = listbubble.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble[i] << " ";
	}
	cout << "\n";
	cout << "Do bubble sort for an descending double list:\nThe original list contains: ";
	AList<double> listbubble1;
    for (double i=3.5; i>=3.1; i-=0.05) {
    	listbubble1.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listbubble1.bubbleSort(); // Do the selection sort using implemented function.
	numitems = listbubble1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble1[i] << " ";
	}
	cout << "\n";
	
	
	return 0;

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Test cases for Q4, insertion and bubble for DList.
	int type, op;
    int pos, yes;
    int intitem, result1;
    int numitems; // Added.
    DList<int> mylist1 = DList<int>();
    DList<double> mylist2 = DList<double>();
    double doubleitem, result2;
    bool boolresult;
    cout << "Test cases for insertion sort:\n";
    
    cout << "Do insertion sort for an descending integer list:\nThe original list contains: ";
    DList<int> listinsert;
    for (int i=6; i>=0; i--) {
    	listinsert.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listinsert.insertionSort(); // Do the insertion sort using implemented function.
	numitems = listinsert.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listinsert[i] << " ";
	}
	cout << "\n";
	cout << "Do insertion sort for an descending double list:\nThe original list contains: ";
	DList<double> listinsert1;
    for (double i=1.98; i>=1.82; i-=0.02) {
    	listinsert1.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listinsert1.insertionSort(); // Do the insertion sort using implemented function.
	numitems = listinsert1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listinsert1[i] << " ";
	}
	cout << "\n";
	
	
	cout << "\n" << "Test cases for bubble sort:\n";
    
    cout << "Do bubble sort for an descending integer list:\nThe original list contains: ";
    DList<int> listbubble;
    for (int i=9; i>=1; i--) {
    	listbubble.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listbubble.bubbleSort(); // Do the bubble sort using implemented function.
	numitems = listbubble.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble[i] << " ";
	}
	cout << "\n";
	cout << "Do bubble sort for an descending double list:\nThe original list contains: ";
	DList<double> listbubble1;
    for (double i=3.5; i>=3.1; i-=0.05) {
    	listbubble1.append(i); // Use this loop to build a descending list.
    	cout << i << " ";
	}
	cout << "\n";
	listbubble1.bubbleSort(); // Do the bubble sort using implemented function.
	numitems = listbubble1.getlength(); // Get the length of the new list.
	cout << "New list:";
	for (int i=1; i<=numitems; i++) {
		cout << listbubble1[i] << " ";
	}
	cout << "\n";
	
	
	return 0;
	
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Test cases for Q3.
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

