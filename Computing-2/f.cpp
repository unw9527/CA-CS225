//this is the functions for Fibonacci heap

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cstdlib>
#include "f-h.h"
#include "math.h"

using namespace std;

int time(patient* p1,patient* p2){	//it's a function to compare p1 and p2's time of registration
	int p1ti=p1->time;
	int p2ti=p2->time;
    if(p1->risk==2){	//when risk=2, time should be 1 month later
        p1ti+=1000;
    }
    if(p2->risk==2){
    	p2ti+=1000;
    }
    if(p1ti<p2ti){	//if p1's time is smaller, that means p1 has priority than p2, return 1; otherwise return 0
		return 1;
    }
    if(p1ti>p2ti){
    	return 0;
    }
    return 0;
}


/*
int compare(patient* p1,patient* p2){   //if p1 has priority than p2, return 1; otherwise return 0
	if (p1->treatment < p2->treatment) {
		return 1;   // Return 1 for p2 treatment higher.
	}
	if (p1->treatment > p2->treatment) {
		return 0;   // Return 0 for p1 treatment higher.
	}
	if (p1->treatment == 1) {
		if(p1->risk==3&&p2->risk!=3){   //if risk==3, then the other one priority is bigger
	        return 0;
	    }
	    if(p2->risk==3&&p1->risk!=3){
	        return 1;
	    }
	    if(p1->prof<p2->prof){ //if prof is smaller, then priority is bigger
	        return 0;
	    }
	    if(p2->prof<p1->prof){
	        return 1;
	    }
	    if(p1->aging>p2->aging){	//if aging is smaller, then priority is bigger
	        return 1;
	    }
	    if(p2->aging>p1->aging){
	        return 0;
	    }
	    return time(p1,p2);	//if all of above can't determine the priotiry, then we need the time function to help
	}
} */

int compare(patient* p1,patient* p2){   //if p1 has priority than p2, return 1; otherwise return 0
	if (p1->treatment < p2->treatment) {
		return 1;   // Return 1 for p2 treatment higher.
	}
	if (p1->treatment > p2->treatment) {
		return 0;   // Return 0 for p1 treatment higher.
	}
	if (p1->treatment == 1) {
		if(p1->risk > p2->risk){   //if risk is smaller, it has bigger priority.
	        return 0;
	    }
	    if(p2->risk > p1->risk){
	        return 1;
	    }
	    if(p1->prof < p2->prof){ //if prof is smaller, then priority is bigger.
	        return 0;
	    }
	    if(p2->prof < p1->prof){
	        return 1;
	    }
	    return time(p1,p2);	//if all of above can't determine the priotiry, then we need the time function to help
	}
	if (p1->treatment == 2) {
		if(p1->aging < p2->aging){	//if aging is smaller, then priority is bigger
	        return 0;
	    }
	    if(p2->aging < p1->aging){
	        return 1;
	    }
	    if(p1->risk > p2->risk){   //if risk is smaller, it has bigger priority.
	        return 0;
	    }
	    if(p2->risk > p1->risk){
	        return 1;
	    }
	    return time(p1,p2);
	}
	if (p1->treatment == 3) {
		if(p1->prof < p2->prof){ //if prof is smaller, then priority is bigger.
	        return 0;
	    }
	    if(p2->prof < p1->prof){
	        return 1;
	    }
	    if(p1->aging < p2->aging){	//if aging is smaller, then priority is bigger
	        return 0;
	    }
	    if(p2->aging < p1->aging){
	        return 1;
	    }
	    return time(p1,p2);
	}
    return 0;
}




void F_h::insert(patient* p){		//here is a function for us to insert a patient to the root node of the heap
    if(min==nullptr){	//if patient is the first node of the heap
        min=p;	//we set min to be p
        p->left=nullptr;
        p->right=nullptr;		//and p's left and right be null
    }else{	//if patient is not the first node
    	if(min->right!=nullptr){	//if min is the only patient in the heap
    		min->right->left=p;
    		p->right=min->right;
		}
        min->right=p;
        p->left=min;	//just set left and right for patient and min
        if(compare(p,min)==1){	//if p has priority than min, then let min be p
            min=p;
        }
    }
    n++;	//let the number of nodes in the heap increase by 1
}

void F_h::brother(patient* p1,patient* p2){	//it's a function for making two nodes be brother
	if(p1->right!=nullptr){	//if there is no node in the right side of p1, then we don't need to set
		p1->right->left=p2;
    	p2->right=p1->right;	
    	    p1->right=p2;	//it's the necessary setting for two nodes
    p2->left=p1;
    return;
	}else if(p1->left!=nullptr){
		p1->left->right=p2;
		p2->left=p1->left;
		    p1->left=p2;	//it's the necessary setting for two nodes
    p2->right=p1;
    return;
	}
	p1->right=p2;	//it's the necessary setting for two nodes
    p2->left=p1;
}

//actually, this is not used by us but this is the function of the Fibonacci heap


/*void F_h::delet(patient* p){
    patient* p3=p->parent;	//create a new patient
    if(p3!=nullptr){	//this means p is not the root node
        p->parent=nullptr;	//set p's parent to be null
        if(p->right==nullptr&&p->left==nullptr){	//here we try to find the child of p3
            p3->child=nullptr;	//if so, there is no child
        }else if(p->left!=nullptr){	
            p3->child=p->left;	//if so, set the left child 
        }else{
        	p3->child=p->right;	//if so, set the right child
		}
    	if(p->left!=nullptr){	
    		p->left->right=p->right;	
		}
		if(p->right!=nullptr){
			p->right->left=p->left;	
		}
        p->left=nullptr;
        p->right=nullptr;	//set p's left brother and right brother
        p3->degree--;	//decrease the degree of the parent 
        brother(min,p);	//let p be the brother of min root
        p->marked=0;	//set p's marked be 0
        cascading_cut(p);	//use cascading_cut to delete p
    }
    min=p;	//let p be min
    extract_min(); 	//and delete it
}*/

patient* F_h::extract_min(){
    patient* p3=min;	//let p3 be min
    if(p3!=nullptr){
    if(p3->child!=nullptr){	//if min has child
        patient* p=p3->child;
        patient* pointer;	//create two new pointers
        while(p!=nullptr){	//this is for loop for every child of min
            pointer=p->right;	//to find every child
            p->parent=nullptr;	//set every child be nullptr
			if(p->right!=nullptr){
				p->right->left=nullptr;	
			}
        	p->left=nullptr;
       		p->right=nullptr;  	//just set p's right brother and left brother
            brother(min,p);	//let p be one root node
            p=pointer;
        }
        p3->child=nullptr;	//let min's child be null
    }

    if(p3->left!=nullptr){	
    	p3->left->right=p3->right;	
	}
	if(p3->right!=nullptr){	
		p3->right->left=p3->left;	
	}	//set min's right brother and left brother
	
	patient* pl=p3->left;
	patient* pr=p3->right;
	p3->left=nullptr;
	p3->right=nullptr;

    if(pr==nullptr&&pl==nullptr){
        min=nullptr;
    }else if(pl!=nullptr) {
        min=pl;
        consolidate();
    }else{
    	min=pr;
    	consolidate();
	}//set new min and consolidate
    n--;	//let the number of node decrease
    }
    return p3;	//return p3
}

//actually, this is not used by us but this is the function of the Fibonacci heap

/*void F_h::cascading_cut(patient* p){
    patient* p3=p->parent;	//let p3 be p's parent
    if(p3!=nullptr){	//if p is not the root node
        if(p->marked!=1){ 
            p->marked=1;	//if so, set p's marked be 1
        }else{
            p->parent=nullptr;	//set p's parent be nullptr
        	if(p->right==nullptr&&p->left==nullptr){	//here we try to find the child of p3
           		 p3->child=nullptr;	//if so, there is no child
        	}else if(p->left!=nullptr){	
            	p3->child=p->left;	//if so, set the left child 
        	}else{
        		p3->child=p->right;	//if so, set the right child
			}
    		if(p->left!=nullptr){
    			p->left->right=p->right;	
			}
			if(p->right!=nullptr){
				p->right->left=p->left;	
			}
      		p->left=nullptr;
      		p->right=nullptr;	//set p's left and right
      	    p3->degree--;	//set degree
     	    brother(min,p);	//let p be one root node
     	    p->marked=0;	//set p's marked
     	    cascading_cut(p3);	//use iteration for p3
        }
    }
}*/


patient* F_h::parent_child(patient* p1,patient* p2){
    if(compare(p1,p2)==1){	//if so, p2 has priority than p1
    	if(p2->left!=nullptr){  //the other operations are similar to the operations below
    		p2->left->right=p2->right;	
		}
		if(p2->right!=nullptr){
			p2->right->left=p2->left;	
		}
        p2->left=nullptr;
        p2->right=nullptr; 
       // p2->marked=0;
        p2->parent=p1;
        p1->degree++;
        if(p1->child!=nullptr){
            brother(p1->child,p2);
        }else{
            p1->child=p2;
        }
        return p1;
    }else{
    	if(p1->left!=nullptr){
    		p1->left->right=p1->right;	
		}
		if(p1->right!=nullptr){
			p1->right->left=p1->left;	
		}
        p1->left=nullptr;
        p1->right=nullptr;  //set p1's left brother and right brother
      //  p1->marked=0;	//set p1's marked
        p1->parent=p2;	//let p2 be parent of p1
        p2->degree++;      	//increase p2's degree
        if(p2->child!=nullptr){	//if p2 has child
            brother(p2->child,p1);	//just let p1 be brother of p2's child
        }else{
            p2->child=p1;	//if not, let p2's child be p1
        }
        return p2;	//return p2
    }
}

//actually, this is not used by us but this is the function of the Fibonacci heap

/*void F_h::decrease_key(patient* p, int k, int cas){//when cas=1,we change the profession; when cas=2, we change the risk
    if(cas==1){	//change the profession
        if(p->prof<k){	//if so, we don't need to change
            cout<<"new key is greater than current key";
            return;
        }
        p->prof=k;	//if not, change the value
    }if(cas==2){	//change the risk
        if(p->risk<k){	//if so, we don't need to change
            cout<<"new key is greater than current key";
            return;
        }
        p->risk=k;	//if not, change the value
    }else{	//in this case, cas is neither 1 nor 2, it's wrong case
        cout<<"wrong case!";
    }
    patient* p3=p->parent; 	//let p3 be p's parent
    if(p3!=nullptr&&compare(p,p3)==1){	//in this case, we need to change the location of p and p3
        p->parent=nullptr;	//let p's parent be null
        if(p->right==nullptr&&p->left==nullptr){	//set new child for p3
            p3->child=nullptr;
        }else if(p->left!=nullptr){
            p3->child=p->left;
        }else{
        	p3->child=p->right;
		}
    	if(p->left!=nullptr){
    		p->left->right=p->right;	
		}
		if(p->right!=nullptr){
			p->right->left=p->left;	
		}
        p->left=nullptr;
        p->right=nullptr;	//set p's left brother and right brother
        p3->degree--;	//let p3's degree decrease
        brother(min,p);	//let p be one of root nodes
        p->marked=0;	//let p's marked be 0
        cascading_cut(p3);	//use cascading_cut for p3
    }
    if(compare(p,min)==1){
        min=p;	//if so, let min be p
    }
}*/



void F_h::consolidate(){
   int upper;
   int m=n;
    upper=log(m)/log((sqrt(5)+1)/2)+1000;	//it's the upper degree for heap
    patient* heap[upper];	//create a new array
    for(int i=0;i<upper;i++){	//use a for loop to initialize all the elements in heap
        heap[i]=nullptr;
    }
    patient* p3=min;	//let p3 be min
    while (p3->right!=nullptr){	//find the leftest one in the root node
        p3=p3->right;
    }
	patient* po=p3;
	patient* o;
    while(po!=nullptr){	//use while loop to go through all the root nodes
        o=po->left;
        patient* pc = po;
        int d =pc->degree;	//let d be the degree of pc
        while(heap[d]!=nullptr){	//use while loop
            patient* p4=heap[d];	//let p4 be heap[d]
            if(compare(p4,pc)==1){	//if p4 has priority than pc, exchange p4 and pc
                patient* p5=pc;
                pc=p4;
                p4=p5;
        }
        if(p4->left!=nullptr){
    		p4->left->right=p4->right;	
		}
		if(p4->right!=nullptr){
			p4->right->left=p4->left;	
		}
        p4->left=nullptr;
        p4->right=nullptr;

            parent_child(pc,p4);	//let pc be one of children of p4
            heap[d]=nullptr;	//let head[d] be null
            d++;	//let d increase
        } 
        heap[d]=pc;	//let head[d] be p
        po=o;	//let p3 be the right brother and then go through all the nodes 
    }
    min=nullptr;	//let min be null
    for(int i=0;i<upper;i++){	//use for loop to go through all the elements 
        if(heap[i]!=nullptr){	//if it is non-null
            if(min==nullptr){	//if min has not been set
                min=heap[i];	//t min and left, right brother
                min->left=nullptr;
        		min->right=nullptr;
            }else{
            if(min->right!=nullptr){	//if min has right brother, set like this
    			min->right->left=heap[i];
    			heap[i]->right=min->right;
    			min->right=heap[i];
        		heap[i]->left=min;
			}else{		//if min doesn't have right brother, set like this
				min->right=heap[i];
        		heap[i]->left=min;
        		heap[i]->right=nullptr;
			}
            if(compare(heap[i],min)==1){	//if heap[i] has priority than min, set min be heap[i]
                min=heap[i];
            }
            }
        }
    } 
}
