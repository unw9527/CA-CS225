#include "ex1ex2.cpp"
#include "minheap.cpp"
#include <cstdio>
#include "stdlib.h"
#include <fstream>
#include <iostream>
using namespace std;


/* This series of file is the solution about the exercise 4 and 5.*/
/* We have finished the required functions on the built Fibonacci heap. 
	Also note that the main function here contains an interactive interface, 
	which allows the operator to do what they want for the patients in the three data.csv files.*/


int month=1,day=1,am=0,week=0,now=0;//now is the latest person who hasn't been put into the heap. 
MinHeap* h_ddl;
F_h* a_heap;
patient* temp;
int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  //initialize months
localQ<patient*> palist[4];
int num_re=0,num_ap=0,num_wa=0,num_wi=0,num_time=0;
int week_num = 1; // count which week we are in
int can_do[4]={0,3,2,1};//That means i-th hospital can operate can_do[i] per morning/afternoon.
struct week_data{
	int treated_id[200][2];
	int num_t;
}we;
int date_difference(int date1, int date2){  //it's a function for calculating the difference of two dates
    if(date1>date2){    //if so, swap date1 and date 2 
        int date3=date1;
        date1=date2;
        date2=date3;
    }
    int p1=date1/1000;
    int p2=date2/1000;
    int d1=(date1%1000)/10;
    int d2=(date2%1000)/10;
    int pd=p1;
    int days=0;
    if(p2>p1){  //if so, calculete the months' dates
        for(;pd<p2;pd++){
            days=days+months[pd];
        }
        return days+d2-d1;
    } 
    return d2-d1;       //if not, just return the difference of two days
}  
void print_month(){
	char filename[30] = {0};
	sprintf(filename, "month%d-report.csv", month);
	ofstream outfile(filename,ios::out);
	if(!outfile){
        cout << "Open the file failure...\n";
        exit(0);
    }
    printf("\n****The month report has been produced to month %d-report.csv****\n\n",month);
	outfile << "Now there is the report of Month " << month << ":\n";
	outfile << "1.There are " << num_re << " people who have registered:\n";
	outfile << "2.There are " << num_ap << " people who have been treated:\n";
	outfile << "3.There are " << num_wa << " people who are still waiting:\n";
	outfile << "4.There are " << num_wi << " people who have withdrawn:\n";
	if(!num_ap) {
		outfile << "5.No average waiting time this month because nobody has been treated." <<endl;
	}
	else outfile << "5.People who have been treated has the average time of waiting: " << (double)1.0*num_time/num_ap << " (unit: day)" <<endl;
	outfile.close();
	num_re=0;num_ap=0;num_wi=0;num_time=0;
}

void print_week(){
	int tp_id;
	char filename[30] = {0};
    sprintf(filename, "week%d-report.csv", week_num);
    ofstream outfile(filename,ios::out);
    if(!outfile){
        cout << "Open the file failure...\n";
        exit(0);
    }
	cout << endl << "Weekly report has been produced to week" << week_num << "-report.csv" << endl << endl;
    outfile << "Weekly Report for Week " << week_num << endl;
    outfile << "ID,NAME,PROF,AGE,RISK,WAITING TIME\n";
    outfile << "There are " << we.num_t << " people who have been treated: " << endl;
	for(int i=0;i<we.num_t;i++){
		tp_id=we.treated_id[i][0];
		int dif=date_difference(N[tp_id]->time,we.treated_id[i][1]);
		num_time+=dif;
		outfile << tp_id << ',' << N[tp_id]->name <<','<<  N[tp_id]->prof << ',' << N[tp_id]->aging << ',' << N[tp_id]->risk << ',' << dif<< endl;
	}
	outfile << "These people are still waiting:\n";// print the people that are still waiting.
	for(int i=0;i<len_N;i++){
		if(N[i]->marked)continue;// skip if the person with id i is marked. 
        outfile << N[i]->id << ',' << N[i]->name << ',' << N[i]->prof << "," << N[i]->aging << ',' << N[i]->risk <<',' << date_difference(N[i]->time,month*1000+day*10) << endl;
	}
    outfile.close();
	we.num_t=0;
	week_num++;
}

void record(patient* tp){

	num_wa--;
	tp->marked=1;	
	we.treated_id[we.num_t++][0]=tp->id;// make the record of the id.
	int nowaday=month*1000+day*10;
	we.treated_id[we.num_t][1]=nowaday;
}
void appoint(){
	int pp=0;
	for(int i=1;i<=3;i++){			// loop over palist1 to palist3 
		while(!palist[i].isempty()){	// First judge if palist[i] is not empty. 
			num_wa++;
			temp=palist[i].popfront();
			a_heap->insert(temp);pp++;
			if(temp->ddl)h_ddl->Insert(temp);// if meet the ddl, then insert it into temp.
		}
	}
	int count[4]={0,3,2,1},count_all=6;// build a new array and a new int for counting.
	
	while(h_ddl->getnum()){
		patient* ddl_now=h_ddl->Delete();
		int d_day=ddl_now->ddl;
		if(d_day/1000!=month||(d_day%1000)/10!=day){
			h_ddl->Insert(ddl_now);
			break;
		}


		if(!ddl_now->marked){// if it is not marked, do the following
			num_ap++;
			int des=ddl_now->closest;
			if(count[des]){// if count[des] is not 0
				record(ddl_now);
				count[des]--;
			}
			else{
				for(int i=1;i<=3;i++){
					if(!count[i])continue;
					record(ddl_now);
					count[i]--;
				}
			}
			count_all--;
		}
	} 
	while(count_all){
		temp=a_heap->extract_min();//Get the min node of the heap
		if(temp==nullptr){break; }
//		printf("%d\n",temp->id);

		if(!temp->marked){// if temp variable is not marked 
			num_ap++;
			int des=temp->closest;
			record(temp);
			count_all--;
		}
	}	
}
char tp_name[30],tp_state[10],choice[3];//build a few char arrays about the info of temp
int tp_prof,tp_id,tp_am,tp_month,tp_day;  
int tp_birth,tp_phone;  
int tp_risk;  
int tp_time;  
bool flag=0;
void op0(){
	appoint();// Begin appoint
	if(!am){am=1;return;} 
	if(day==28){
		if(month==2){
			print_month();
			month++;day=0;
		}
	}
	else if(day==30){
		if(month==4||month==6||month==9||month==11){
			print_month();
			month++;day=0;
		}
	}
	else if(day==31){
		print_month();
		month++;day=0;
	}
	day++;am=0;
	week++;
	if(week==7){
		print_week();
		week=0;
	}
} 
void op2(){
	num_re++;		//num of register plus 1
	printf("Your ID is: %d, please remember.\n",len_N);
	printf("What's your name without surname?\n");
	scanf("%s",tp_name);
	printf("What's your phone number?\n");
	flag=scanf("%d",&tp_phone);
	while(flag!=1){
		printf("Error! Please enter number!(8)\n");	
		flag=scanf("%d",&tp_phone);
		getchar();
//				flushall();
//				setbuff(stdin,NULL); 
	}
	printf("What's the number of your profession?(1~8)\n");
	flag=scanf("%d",&tp_prof);
	while(flag!=1){
		printf("Error! Please enter number(1~8)!\n");	
		flag=scanf("%d",&tp_prof);
		getchar();
	}
	printf("What's your birth year?\n");
	flag=scanf("%d",&tp_birth);
	while(flag!=1){
		printf("Error! Please enter number!\n");	
		flag=scanf("%d",&tp_birth);
		getchar();
	}
	printf("What's the risk status of you?\n");
	flag=scanf("%d",&tp_risk);
	while(flag!=1){
		printf("Error! Please enter number!\n");	
		flag=scanf("%d",&tp_risk);
		getchar();
	}
	tp_time=month*1000+day*10+am;//calculate the tp_time based on month, date and am/pm. 
	strcpy(tp_state,"applied");
	N[len_N]=new patient(len_N,tp_name,tp_prof,tp_time,tp_risk,tp_phone,tp_birth,tp_state);
	N[len_N-1]->age_rank();
	printf("What's the closest hospital for you?(1~3)\n");//Ask the closest hospital  
	scanf("%d",&N[len_N-1]->closest);
	palist[N[len_N-1]->closest].pushback(N[len_N-1]);
	printf("Do you have ddl for treatment?(y/n))\n");//Ask if this patient has a ddl 
	scanf("%s",choice);
	if(choice[0]=='y'){
		printf("What's the deadline of you?(month day am(1)/pm(0)))\n");
		scanf("%d %d %d",&tp_month,&tp_day,&tp_am);
		N[len_N-1]->ddl=tp_month*1000+tp_day*10+tp_am;
	}
	else N[len_N-1]->ddl=0;
	printf("Register successfully! Your ID is %d.\n",len_N-1);
		
}
void op3(){
	printf("Now you are going to withdraw an application, please enter your ID:\n");
	flag=scanf("%d",&tp_id);
	while(flag!=1){
		printf("Error! Please enter number!\n");	
		flag=scanf("%d",&tp_id);
		getchar();
	}
	if(tp_id>=len_N){printf("Illegal id!\n");return;}
	N[tp_id]->marked=1;num_wa--;
	strcpy(N[tp_id]->status,"withdrawn");
	printf("Withdraw successfully!\n\n");
	num_wi++;
}
int main(){
	a_heap=new F_h;
	h_ddl=new MinHeap(100);
	len_N=0;
    palist[1] = build_queue(1);
    palist[2] = build_queue(2);
    palist[3] = build_queue(3);
    we.num_t=0;
	int op;
	
	while(month<=12&&day<=31){
		printf("****Welcome to the medical treatment system, what do you want to do?****\n");
		printf("Enter the number from 0 to 6:\n");
		printf("0. Nothing to do. (This option will make time pass by half a day.)\n");
		printf("1. Show the time.\n");
		printf("2. Register.\n");
		printf("3. Withdraw an application.\n");
		printf("4. Withdraw an application and register again.\n");
		printf("5. Skip a week.(No new register)\n");
		printf("6. Skip this month.\n");
		scanf("%d",&op);
		if(op<0||op>7){
			printf("The operation is illegal, please type in again!\n");
			continue;
		}
		if(op==0){		//op=0 means pass half a day 	 	
			op0();
			continue;
		}
		if(op==1){		//register
			printf("Date(Month/Day/AM or PM): %d/%d ",month,day);
			if(!am)printf("am\n");
			else printf("pm\n\n");
			continue;
		}
		if(op==2){
			op2();
			continue;
		}
		if(op==3){		//withdraw 
			op3();
			continue;
		}  
		if(op==4){
			printf("Now you are going to withdraw an application and then register again, please enter your ID:\n");
			op3();
			printf("Your new ID is %d\n",len_N);
			tp_month=month,tp_day=day;
			tp_day+=14;//tp_day plus by 14 to pass two weeks 
			if(month==2){
				if(tp_day>=28){
					tp_day-=28;tp_month++;
				}
			}
			else if(month==4||month==6||month==9||month==11){
				if(tp_day>=30){
					tp_day-=30;tp_month++;
				}
			}
			else{
				if(tp_day>=31){
					tp_day-=31;tp_month++;
				}
			}
			tp_time=tp_month*1000+tp_day*10+am;
			strcpy(tp_state,"applied");
			printf("What's your phone number?\n");
			flag=scanf("%d",&tp_phone);
			while(flag!=1){
				printf("Error! Please enter number(8 digits)!\n");	
				flag=scanf("%d",&tp_phone);
				getchar();
	//				flushall();
	//				setbuff(stdin,NULL); 
			}
			printf("What's the number of your profession?(1~8)\n");
			flag=scanf("%d",&tp_prof);
			while(flag!=1){
				printf("Error! Please enter number(1~8)!\n");	
				flag=scanf("%d",&tp_prof);
				getchar();
			}
			printf("What's the risk status of you?\n");
			flag=scanf("%d",&tp_risk);
			while(flag!=1){
				printf("Error! Please enter number!\n");	
				flag=scanf("%d",&tp_risk);
				getchar();
			}
			N[len_N-1]=new patient(len_N,N[tp_id]->name,tp_prof,tp_time,tp_risk,tp_phone,N[tp_id]->birth,tp_state);
			N[len_N-1]->age_rank();
			printf("What's the closest hospital for you?\n");
			scanf("%d",&N[len_N-1]->closest);
			palist[N[len_N-1]->closest].pushback(N[len_N-1]);
			printf("Do you have ddl for treatment?(y/n))\n");
			scanf("%s",choice);
			if(choice[0]=='y'){
				printf("What's the deadline of you?(month day am(1)/pm(0)))\n");
				scanf("%d %d %d",&tp_month,&tp_day,&tp_am);
				N[len_N-1]->ddl=tp_month*1000+tp_day*10+tp_am;
			}
			else N[len_N-1]->ddl=0;
			printf("Register successfully! Your new ID is %d.\n",len_N-1);
			num_re++;
			continue;
		}
		if(op==5){
			for(int i=1;i<=14;i++)op0();
			continue;
		}
		if(op==6){
			int temp_mo=months[month]*2;
			for(int i=1;i<=temp_mo;i++)op0();
			continue;
		}
	}
	cout << endl << "Year 2021 has ended. Goodbye!" << endl;
	return 0;
}

