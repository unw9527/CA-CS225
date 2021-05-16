# README

This is the guidance for users to use our medical system.

## Files

- *ex1ex2.cpp:*

  This series of file is the solution about the exercise $1$ and $2$.

  In the corresponding header file, we include the definition of a new class patient and its constructor, as well as two global variables used for distributing *id*. This file includes the function implementation of the class patient and local queue. 

- *ex4ex5.cpp:*

  This series of file is the solution about the exercise $4$ and $5$.

  We have finished the required functions on the built Fibonacci heap. Also note that the main function here contains an interactive interface, which allows the operator to do what they want for the patients in the three data file.

- *minheap.h:*

  This is the definition of minheap called **MINHEAP_H**.

- *minheap.cpp:*

  This file contains the implementation of functions in **MINHEAP_H**.

- *f.cpp:*

  This file contains functions for Fibonacci heap.

## Background

We have initially constructed **3 data files(*data1.csv, data2.csv, etc*),** each containing information about people who register at three different places.

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

4. After the time passes a week, a *weekly report* for the corresponding week will be produced to the local folder. Similar for the *monthly report*. 

   *If you quit the system and restart, the newly produced report will cover the originally produced report.*

## Important

**When you manually register(ie. choosing option $2$), you should follow the input rule suggested by the system.** 

For instance, 

1. you should type in $6$ digits if the system asks for $6$ digits;
2. you should not add any space, when you type in your name;
3. you should always type in $1\sim3$, when you type in which *hospital* you want to register.

**Our algorithm regards *treated* and *appointed* as the same, which means that we only make appointment for a patient on the day he or she will be treated.**



