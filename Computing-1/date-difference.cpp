
#include "ex1ex2.cpp"
#include "minheap.cpp"
#include<cstdio>

int date_difference(int date1, int date2){  //it's a function for calculating the difference of two dates
    if(date1>date2){    //if so, swap date1 and date 2 
        int date3=date1;
        date1=date2;
        date2=date3;
    }
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  //initialize months
    int p1=date1/1000;
    int p2=date2/1000;
    int d1=(date1%1000)/10;
    int d2=(date2%1000)/10;
    int pd=p1;
    int days=0;
    if(p2>p1){  //if so, calculete the months' dates
        for(;pd<p2;pd++){
            days=days+month[pd];
        }
        return 365-(days+d2-d1);
    } 
    return 365-(d2-d1);       //if not, just return the difference of two days
}  
