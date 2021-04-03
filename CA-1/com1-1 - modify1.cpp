#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "com1-1 - modify1.h"
using namespace std;



// Class Functions
void patient::age_rank(int year_now) {
	int diff = year_now - this->birth;
	if (diff <= 12) {this->aging = 12;}
	else if (diff <= 18) {this->aging = 18;}
	else if (diff <= 35) {this->aging = 35;}
	else if (diff <= 50) {this->aging = 50;}
	else if (diff <= 65) {this->aging = 65;}
	else if (diff <= 75) {this->aging = 75;}
	else if (diff > 75) {this->aging = 76;}  //年龄段我是采用了12,18,等分隔线；也可改用1,2,3等表示年龄段 
}


// Other Funtions
vector<patient*> build_list() {  // Build a list of patients in one txt file.
	vector<patient*> palist;
	ifstream pafile;
	pafile.open("data.csv",ios::in);  // Text name can be changed, or be set as a parameter.
	int item=0;  // Count for when to turn to next patient.
	if (!pafile.fail()) { 
		while (!pafile.eof()) {
			patient* ill = new patient();
			char buf[64];
			pafile.getline(buf,64,',');  // Read in and stop when meeting comma (but never read this comma).
			while (buf[0]=='\n'){
				strcpy(buf, buf+1);  // Delete the "\n"(s) at the front of buf.
			}
			item++;
			switch (item) {  // You can refer to the order in the sample csv.
				case 1:
					ill->id=strtol(buf,NULL,10);
					break;
				case 2:
					strcpy(ill->name,buf);
					break;
				case 3:
					ill->prof=strtol(buf,NULL,10);
					break;
				case 4:
					strcpy(ill->time,buf);
					break; 
				case 5:
					ill->risk=strtol(buf,NULL,10);
					break; 
				case 6:
					strcpy(ill->status,buf);
					break;
				case 7:
					ill->contact=strtol(buf,NULL,10);
					break;
				case 8:
					ill->birth=strtol(buf,NULL,10);
					item=0;
					break;
			}
			if (item==0) {
				ill->age_rank(2021);  // This number can be changed if initially the year number is not 2021.
				palist.push_back(ill);  // This pointer to this patient is stored to the vector palist.
				continue;
			}
		}
	} else {
		cout << "File open failure!\n";
	}
	pafile.close();
	return palist;
}


// Main program
int main() {
	cout << "如需更改类内的数据成员和成员函数，或更改build_list函数，可以与我微信联系。" << "\n";
	return 0;
}
