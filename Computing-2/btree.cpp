//copy from https://www.programiz.com/dsa/b-tree
//at first the key of B tree is int, I change it to the contact of the patient
#include "BPlusTree.h"
#include <cstdio>
#include "stdlib.h"
#include <fstream>
#include <iostream>
using namespace std;

class TreeNode {  //here is the definition of TreeNode
  public:
  patient **keys; //here is the array of the address of the patient
  int t;
  TreeNode **C;
  int n;
  bool leaf;


  TreeNode(int temp, bool bool_leaf);
  TreeNode() {};
  void insertNonFull(patient* k);
  void splitChild(int i, TreeNode *y);
  void traverse();


  TreeNode *search(int k);

  friend class BTree;
};

class BTree { //here is the definition of BTree
  TreeNode *root;
  int t;

   public:
  BTree(int temp) { 
    root = NULL;
    t = temp;
  }

  void traverse() {     //here is the function for the B tree to show all the elements 
    if (root != NULL)
      root->traverse();
  }

  TreeNode *search(int k) {   //here is the function for the B tree to search through contact
    return (root == NULL) ? NULL : root->search(k);
  }

  void insert(patient* k);
};

TreeNode::TreeNode(int t1, bool leaf1) {  //here is constructed function for TreeNode
  t = t1;
  leaf = leaf1;

  keys = new patient*[2 * t - 1];
  C = new TreeNode *[2 * t];

  n = 0;
}

void TreeNode::traverse() {   //here is the function for print all the elements
  int i;
  for (i = 0; i < n; i++) {
    if (leaf == false)
      C[i]->traverse();
    cout << " " << keys[i]->contact;
  }

  if (leaf == false)
    C[i]->traverse();
}

TreeNode *TreeNode::search(int k) {   //here is the search function
  int i = 0;
 
  while (i < n-1 && k > keys[i]->contact){
    i++;
    }
 
  int a=keys[i]->contact;

  if (a == k){
    return this;
  }

  if (leaf == true){
    return NULL;}
  if(k > keys[i]->contact){
    return C[i+1]->search(k);
  }else{
    return C[i]->search(k);
  }
}

void BTree::insert(patient* k) {    //here is the insert function
  if (root == NULL) {
    root = new TreeNode(t, true);
    root->keys[0] = k;
    root->n = 1;
  } else {
    if (root->n == 2 * t - 1) {
      TreeNode *s = new TreeNode(t, false);

      s->C[0] = root;

      s->splitChild(0, root);

      int i = 0;
      if (s->keys[0]->contact < k->contact)
        i++;
      s->C[i]->insertNonFull(k);

      root = s;
    } else
      root->insertNonFull(k);
  }
}

void TreeNode::insertNonFull(patient* k) {  //here is another insert function
  int i = n - 1;

  if (leaf == true) {
    while (i >= 0 && keys[i]->contact > k->contact) {
      keys[i + 1] = keys[i];
      i--;
    }

    keys[i + 1] = k;
    n = n + 1;
  } else {
    while (i >= 0 && keys[i]->contact > k->contact)
      i--;

    if (C[i + 1]->n == 2 * t - 1) {
      splitChild(i + 1, C[i + 1]);

      if (keys[i + 1]->contact < k->contact)
        i++;
    }
    C[i + 1]->insertNonFull(k);
  }
}

void TreeNode::splitChild(int i, TreeNode *y) {   //here is the function for splitchild
  TreeNode *z = new TreeNode(y->t, y->leaf);
  z->n = t - 1;

  for (int j = 0; j < t - 1; j++)
    z->keys[j] = y->keys[j + t];

  if (y->leaf == false) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j + t];
  }

  y->n = t - 1;
  for (int j = n; j >= i + 1; j--)
    C[j + 1] = C[j];

  C[i + 1] = z;

  for (int j = n - 1; j >= i; j--)
    keys[j + 1] = keys[j];

  keys[i] = y->keys[t - 1];
  n = n + 1;
}





/*int main() {
  patient* p1=new patient();
patient* p2=new patient();
patient* p3=new patient();
patient* p4=new patient();
patient* p5=new patient();
patient* p6=new patient();
patient* p7=new patient();
patient* p8=new patient();

p1->contact=1;
p2->contact=2;
p3->contact=30;
p4->contact=4;
p5->contact=5;
p6->contact=6;
p7->contact=7;
p8->contact=8;
  BTree t(3);
  t.insert(p1);
  t.insert(p2);
  t.insert(p3);
  t.insert(p4);
  t.insert(p5);
  t.insert(p6);
  t.insert(p7);
  t.insert(p8);


  cout << "The B-tree is: ";
  t.traverse();

  int k = 12;
  (t.search(k) != NULL) ? cout << endl
                 << k << " is found"
              : cout << endl
                 << k << " is not Found";

  k = p3->contact;
  (t.search(k) != NULL) ? cout << endl
                 << k << " is found"
              : cout << endl
                 << k << " is not Found\n";
}*/