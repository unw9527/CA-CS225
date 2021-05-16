# README

This is the guidance for users to use our medical system.

## Files

- *ex1ex2.cpp:*

  This series of file is the solution about the exercise $1$ and $2$ of CA1, with some modification used for CA2 tasks.

  In the corresponding header file, we include the definition of a new class patient and its constructor, as well as two global variables used for distributing *id*. This file includes the function implementation of the class patient and local queue. 

- *main.cpp:*

  This series of file is the solution about the exercise $4$ and $5$ of CA1, with some modification of the main function about the retrival process. 

  We have finished the required functions on the built Fibonacci heap. Also note that the main function here contains an interactive interface, which allows the operator to do what they want for the patients in the three data file.

 For CA2, we have included new global variables of hash table, B+-tree and B-tree, and add lines and operators in the main function to build these data-structures.

- *minheap.h:*

  This is the definition of minheap called **MINHEAP_H**.

- *minheap.cpp:*

  This file contains the implementation of functions in **MINHEAP_H**.

- *f.cpp:*

  This file contains functions for Fibonacci heap.

- *BPlusTree.cpp:*

  This file contains functions for B+-tree and a function to find patient with certain ID. The class declaration is in "BPlusTree.h".

- *btree.cpp:*

  This file contains class declaration and corresponding functions for B-tree.

- *hash.cpp:*

 This file contains functions for building, storing Hash Table and find patient with certain age.

## Background

We have initially constructed **3 data files(*data1.csv, data2.csv, etc*),** each containing information about people who register at three different places. The item treatment is newly appended for CA2 and all other items are shared for the two assignments.

The *timestamp* and *ddl* format for each person who register is a **5-digit integer**, with the top $2$ digits representing the month, and the following $2$ digits representing the date, and the last digit representing the time(am. for morning, pm. for afternoon).

We assume that the current year is $2021$. The patients initially contained in the *csv* files are set to registered in $2020$.

The medical system can treat **6 patients** each half day. And the system will shut down by the end of $Dec.\space 31^{th}, 2021$.

## Get Started

1. Type `make` to compile the code.

2. Type `./test` to run the program. Now you should see the interactive interface of the system.

3. There are several options available:

   - $0$: This option will just let the time pass half a day. (Eg. If the current time is $01010$, pressing $0$ will make the time $01011$; if the current time is $01011$, pressing $0$ will make the time $01020$)
   - $1$: Show the current time.
   - $2$: You can manually register through this option.
   - $3$: Withdraw an application.
   - $4$: Withdraw an application and register again.
   - $5$: If you want to quickly see the *weekly report* of our medical system, press $5$.
   - $6$: If you want to quickly see the *monthly report* of our medical system, press $6$.
   - $7$: If you want to search patient based on ID, press $7$.
   - $8$: If you want to search patient based on phone number, press $8$.
   - $9$: If you want to search patient based on age, press $9$.

4. After the time passes a week, a *weekly report* for the corresponding week will be produced to the local folder. Similar for the *monthly report*. 

   *If you quit the system and restart, the newly produced report will cover the originally produced report.*

## Important

**When you manually register(i.e. choosing option $2$), you should follow the input rule suggested by the system.** 

For instance, 

1. you should type in $6$ digits if the system asks for $6$ digits;
2. you should not add any space, when you type in your name;
3. you should always type in $1\sim3$, when you type in which *hospital* you want to register.

For CA2, Similar for the searching process: you should type in a positive integer for ID, a 8-digit positive integer for phone number, and a positive integer for age.

**Our algorithm regards *treated* and *appointed* as the same, which means that we only make appointment for a patient on the day he or she will be treated.**

## Design of the relational database schema

### Ex1.1

The information we collect includes *ID, name, profession, time* (same as REGISTRATION mentioned in the document), *status, birth and treatment*. We realize this by storing the information one by one in a class we defined call `PATIENT`, and store a pointer to `PATIENT` in an array, which is also referred to as BLOCK. These blocks are put together in an ordered sequence.

### Ex1.2

For CA1, the compare function just obeys the rule in the Programming Assignment 1. 

For CA2, for different treatments, there are different priority rules. The basic comparison rule obeys the rule in the Programming Assignment 1. Basic rule: If risk is smaller, patient has bigger priority. If prof is smaller, then priority is bigger. if aging is smaller, then priority is bigger. For the patient with smaller treatment, he or she will have higher priority. If two patients have same priority, if the treatment is 1, first compare risk, at last compare time. Then compare the profession. If the treatment is 2, first compare aging, then compare risk, at last compare time. If the treatment is 3, first compare prof, then compare aging, at last compare time. 

