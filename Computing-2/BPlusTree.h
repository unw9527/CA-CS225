#ifndef BPlusTree_h
#define BPlusTree_h

#define LEAF_ORDER 3
#define ORDER 4
#define MAX_NUM 5

#include <string>
using namespace std;
#include "ex1ex2.cpp"

struct InternalNodeData{

    int m_Keys[ORDER];
    void * m_Pointers[MAX_NUM];
};

struct LeafNodeData{
    int m_Keys[LEAF_ORDER];
    patient* m_number[LEAF_ORDER];
    void* m_next;
};

class Node{
public:
    int m_nKeyNum;
    bool m_bLeaf;
    Node *m_pParent{};
    Node()
    {
        m_nKeyNum = 0;
        m_bLeaf = false;
    }
};

class InternalNode:public Node{
public:
    InternalNodeData* internalNodeData;
    InternalNode(){
        internalNodeData = new InternalNodeData;
        for(int & m_Key : internalNodeData->m_Keys){
            m_Key=0;
        }
        for(int i=0;i<LEAF_ORDER;i++){
            internalNodeData->m_Pointers[i]=nullptr;
        }
    };
};

class LeafNode:public Node{
public:
    LeafNodeData* leafNodeData;
    LeafNode(){
        leafNodeData = new LeafNodeData;
        for(int i=0;i<ORDER;i++){
            leafNodeData->m_Keys[i]=0;
        }
        for(int i=0;i<MAX_NUM;i++){
            leafNodeData->m_number[i] = nullptr;
        }
        leafNodeData->m_next = nullptr;
    };
};
class BPlusTree
{
public:
	BPlusTree();
	~BPlusTree();
private:
	Node * m_pRoot;
	Node * m_pFirst;
	Node * m_pLast;
public:
	bool Insert(int nKey, patient* number);
	bool Remove(int nKey);
	bool InsertKeyAndPointer(Node * pParent, Node * pOld, int nKey, Node * pNew);
	void PrintLeaves();
	patient* search(int nKey);
    void PrintLayerTree();
    void printInfo(int nKey);
};

#endif