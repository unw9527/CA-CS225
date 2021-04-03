#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "ex1ed2.h"
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
	int passfirstline=0;  // Used to omit the title line.
	if (!pafile.fail()) { 
		while (!pafile.eof()) {
			if (passfirstline==0) {
				char passing[256];
				pafile.getline(passing,256);
				passfirstline++;
				continue;
			}
			item=0;  // Reset item every time we need a new object of the class patient. 
			patient* ill = new patient();
			while (item>=0) {  // This loop is particularly used to initialize all information about "ill".
				char buf[64];
				pafile.getline(buf,64,',');  // Read in and stop when meeting comma (but never read this comma).
				while (buf[0]=='\n'){
					strcpy(buf, buf+1);  // Delete the "\n"(s) at the front of buf.
				}
				item++;
				switch (item) {  // You can refer to the order in the sample csv.
					case 1:
						ill->id=(int)strtol(buf,NULL,10);
						break;
					case 2:
						strcpy(ill->name,buf);
						break;
					case 3:
						ill->prof=(int)strtol(buf,NULL,10);
						break;
					case 4:
						strcpy(ill->time,buf);
						break; 
					case 5:
						ill->risk=(int)strtol(buf,NULL,10);
						break; 
					case 8:
						strcpy(ill->status,buf);
						break;
					case 6:
						ill->contact=(int)strtol(buf,NULL,10);
						break;
					case 7:
						ill->birth=(int)strtol(buf,NULL,10);
						item=-1;
						break;
					default:
						cout << "Wrong with switch!\n";
				}
				if (item==-1) {  // Set to -1 in order to jump out of the while loop and set a new patient* ill.
					ill->age_rank(2021);  // This number can be changed if initially the year number is not 2021.
					palist.push_back(ill);  // This pointer to this patient is stored to the vector palist.
					continue;
				}
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
	vector<patient*> paslist=build_list();
	cout << paslist[0]->risk << ' ' << paslist[0]->prof << "\n";
	cout << paslist[1]->risk << ' ' << paslist[1]->prof << "\n";
	cout << paslist[2]->risk << ' ' << paslist[2]->prof << "\n";
	cout << paslist[3]->risk << ' ' << paslist[3]->prof << "\n";
	cout << paslist[4]->risk << ' ' << paslist[4]->prof << "\n";
	cout << "Contact when meeting problem." << "\n";
	return 0;
}
