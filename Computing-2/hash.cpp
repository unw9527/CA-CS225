#include "ex1ex2.h"
#include<string>
#include <iostream>
#include <fstream>
#include<vector>
struct node{
	patient* pt;
	int age;
	int id;
	bool flag; 
};
vector<node>hash_tb[55];	//Hash table.
void put_in_hash(int ag,int id,patient* pat){	//This function is used to put one patient into the hash table.
	hash_tb[ag%55].push_back({pat,ag,id,0});
}
void del_hash(patient* pat){			//This function is used to delete one patient from the hash table.
	int ag=2021-pat->birth,id=pat->id;
	for (std::vector<node>::iterator it = hash_tb[ag%55].begin(); it != hash_tb[ag%55].end(); ++it){
		if((*it).age==ag&&(*it).id==id){
			(*it).flag=1;//Flag==1 means this person has been deleted.
			break;
		}
	}
}
void find_age(int ag){		//This function is used to find the people of this age.
	char filename[30] = {0};
    sprintf(filename,"People-with-age-of-%d.txt",ag);
    ofstream outfile(filename,ios::out);
    if(!outfile){
        cout << "Open the file failure...\n";
        exit(0);
    }
    cout << endl << "Information of people with "<<ag<<" produced to People-with-age-of-"<<ag<< ".txt" << endl << endl;
    outfile << "People with age of " << ag << endl;
    outfile << "ID,NAME,PROF,AGE,CONTACT,RISK,REGISTRATION,STATUS,TREATMENT\n";
	for (std::vector<node>::iterator it = hash_tb[ag%55].begin(); it != hash_tb[ag%55].end(); ++it){
		int tp_id=(*it).id;
		if((*it).age==ag&&(*it).flag==0){
			outfile << tp_id << ',' << N[tp_id]->name <<','<<  N[tp_id]->prof << ',' <<2021-N[tp_id]->birth<<','
			<< N[tp_id]->contact <<','<<N[tp_id]->risk<<','<<N[tp_id]->time<<','<<N[tp_id]->status<<',';
			if(N[tp_id]->treatment==1)outfile<<"Surgery"<<endl;
			else if (N[tp_id]->treatment==2)outfile<<"Vaccination"<<endl;
			else outfile<<"Medical advice"<<endl;
		}	
	}
	outfile.close();
}
