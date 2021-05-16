#include "BPlusTree.h"
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;


BPlusTree::BPlusTree()
{
	m_pRoot = nullptr;
	m_pFirst = nullptr;
	m_pLast = nullptr;
}


BPlusTree::~BPlusTree()
= default;

bool BPlusTree::Insert(int nKey, patient* number)
{
	int i = 0;
	int m = 0;

	if (m_pRoot==nullptr)
	{
        auto * pNew = new LeafNode();
        pNew->m_bLeaf = true;
		pNew->m_nKeyNum = 1;
        pNew->m_pParent = nullptr;
		pNew->leafNodeData->m_Keys[0]=nKey;
        pNew->leafNodeData->m_number[0]=number;
        m_pRoot = pNew;
		m_pFirst = pNew;
		return true;
	}

	Node * pTmp = m_pRoot;

	while (!pTmp->m_bLeaf)
	{
		for (i = 0; i < pTmp->m_nKeyNum; i++)
		{

			if (nKey <  ((InternalNode*)pTmp)->internalNodeData->m_Keys[i])
				break;
		}
		if (i == 0)
			pTmp = (Node *) (((InternalNode*)pTmp)->internalNodeData->m_Pointers[0]);
		else
			pTmp = (Node *)(((InternalNode*)pTmp)->internalNodeData->m_Pointers[i]);
	}

	for (i = 0; i < ((LeafNode *)pTmp)->m_nKeyNum; i++)
	{
		if (nKey == ((LeafNode *)pTmp)->leafNodeData->m_Keys[i])
		{
			return false;
		}
	}

	if (((LeafNode *)pTmp)->m_nKeyNum < LEAF_ORDER)
	{
		for (i = 0; i < ((LeafNode *)pTmp)->m_nKeyNum; i++)
		{
			if (nKey < ((LeafNode *)pTmp)->leafNodeData->m_Keys[i])
            {
                break;
            }
		}

		for (m = ((LeafNode *)pTmp)->m_nKeyNum - 1; m >= i; m--)
		{
            ((LeafNode *)pTmp)->leafNodeData->m_Keys[m + 1] = ((LeafNode *)pTmp)->leafNodeData->m_Keys[m];
            ((LeafNode *)pTmp)->leafNodeData->m_number[m + 1] = ((LeafNode *)pTmp)->leafNodeData->m_number[m];
		}
        ((LeafNode *)pTmp)->leafNodeData->m_Keys[i] = nKey;
        ((LeafNode *)pTmp)->leafNodeData->m_number[i] = number;
        patient* x1 = ((LeafNode *)pTmp)->leafNodeData->m_number[i];
        ((LeafNode *)pTmp)->m_nKeyNum++;
		return true;
	}

	int nMid = (LEAF_ORDER + 1) / 2;

	int * pTmpKeys = new int[LEAF_ORDER + 1];
	auto * pTmpnumbers = new patient*[LEAF_ORDER + 1];


	for (i = 0; i < pTmp->m_nKeyNum; i++)
	{
		if (((LeafNode *)pTmp)->leafNodeData->m_Keys[i] > nKey)
			break;
	}

	for (m = pTmp->m_nKeyNum - 1; m >= i; m--)
	{
		pTmpKeys[m + 1] = ((LeafNode *)pTmp)->leafNodeData->m_Keys[m];
        pTmpnumbers[m + 1] = ((LeafNode *)pTmp)->leafNodeData->m_number[m];
	}

	for (m = 0; m < i; m++)
	{
		pTmpKeys[m] = ((LeafNode *)pTmp)->leafNodeData->m_Keys[m];
        pTmpnumbers[m] = ((LeafNode *)pTmp)->leafNodeData->m_number[m];
        patient* x = ((LeafNode *)pTmp)->leafNodeData->m_number[m];
        patient* y = pTmpnumbers[m];
	}
	pTmpKeys[i] = nKey;
    pTmpnumbers[i] = number;

    auto * pNew = new LeafNode;

	for (m = 0, i = nMid; i < LEAF_ORDER + 1; i++,m++)
	{
		pNew->leafNodeData->m_Keys[m] =pTmpKeys[i];
		pNew->leafNodeData->m_number[m] = pTmpnumbers[i];
		pNew->m_nKeyNum++;
	}
    pNew->m_pParent = pTmp->m_pParent;

	pNew->m_bLeaf = pTmp->m_bLeaf;

	for (i = 0; i < pTmp->m_nKeyNum; i++)
	{
        ((LeafNode*)pTmp)->leafNodeData->m_Keys[i] = 0;
        ((LeafNode*)pTmp)->leafNodeData->m_number[i] = nullptr;
	}

	pTmp->m_nKeyNum = 0;

	for (i = 0; i < nMid; i++)
	{
        ((LeafNode*)pTmp)->leafNodeData->m_Keys[i] = pTmpKeys[i];
        ((LeafNode*)pTmp)->leafNodeData->m_number[i] = pTmpnumbers[i];
		pTmp->m_nKeyNum++;
	}
	pNew->leafNodeData->m_next = ((LeafNode*)pTmp)->leafNodeData->m_next;
    ((LeafNode*)pTmp)->leafNodeData->m_next= pNew;


	if (!InsertKeyAndPointer(pTmp->m_pParent, pTmp, pTmpKeys[nMid], pNew))
	{
		return false;
	}
	return true;
}

void BPlusTree::PrintLeaves()
{
	int i = 0;
	if (!m_pFirst)
		return;
	LeafNode * pCur =(LeafNode*)m_pFirst;
	printf("------print leaves-------\n");
	while(1){
        for(int i=0;i<pCur->m_nKeyNum;i++){
            printf("<key:%d, number:%s>\n", pCur->leafNodeData->m_Keys[i], pCur->leafNodeData->m_number[i]->name);
        }
        if(pCur->leafNodeData->m_next==NULL){
            break;
        }else{
            pCur = static_cast<LeafNode *>(pCur->leafNodeData->m_next);
        }
        printf("\n------------------------------------------------------\n");
	}
}

bool BPlusTree::InsertKeyAndPointer(Node * pParent, Node * pOld, int nKey, Node * pNew)
{
	if (!pOld)
		return false;

	if (!pNew)
		return false;

	int i = 0;

	int m = 0;

	int k = 0;

	if (pParent == nullptr)
	{
		auto * pNewRoot = new InternalNode;
        pNewRoot->m_bLeaf = false;
		pNewRoot->internalNodeData->m_Keys[0] = nKey;
		pNewRoot->m_nKeyNum = 1;
        pNewRoot->internalNodeData->m_Pointers[0] = pOld;
        pNewRoot->internalNodeData->m_Pointers[1] = pNew;
		pNewRoot->m_pParent = nullptr;
		pOld->m_pParent = pNewRoot;
        pNew->m_pParent = pNewRoot;
		m_pRoot = pNewRoot;
		return true;
	}

	for (i = 0; i < pParent->m_nKeyNum; i++)
	{
		if (nKey == ((InternalNode*)pParent)->internalNodeData->m_Keys[i])
			return false;
		if (nKey < ((InternalNode*)pParent)->internalNodeData->m_Keys[i])
			break;
	}

	if (pParent->m_nKeyNum < ORDER)
	{
		for (m = pParent->m_nKeyNum - 1; m >= i; m--)
		{
            ((InternalNode*)pParent)->internalNodeData->m_Keys[m + 1] = ((InternalNode*)pParent)->internalNodeData->m_Keys[m];
		}

		for (m = pParent->m_nKeyNum; m > i; m--)
		{
            ((InternalNode*)pParent)->internalNodeData->m_Pointers[m + 1] = ((InternalNode*)pParent)->internalNodeData->m_Pointers[m];
		}

        ((InternalNode*)pParent)->internalNodeData->m_Keys[i] = nKey;
        ((InternalNode*)pParent)->internalNodeData->m_Pointers[i + 1] = pNew;
		pParent->m_nKeyNum++;

		pNew->m_pParent = pParent;
		return true;
	}

	int * pTmpKeys = new int[ORDER + 1];

	void ** pTmpPointers = new void *[ORDER + 2];

	for (i = 0; i < pParent->m_nKeyNum; i++)
	{
		if (nKey < ((InternalNode*)pParent)->internalNodeData->m_Keys[i])
			break;
	}

	for (m = 0; m < i; m++)
	{
		pTmpKeys[m] = ((InternalNode*)pParent)->internalNodeData->m_Keys[m];
	}

	pTmpKeys[m] = nKey;
	m++;

	for (k = i; k < pParent->m_nKeyNum; k++,m++)
	{
		pTmpKeys[m] = ((InternalNode*)pParent)->internalNodeData->m_Keys[k];
	}

	for (m = 0; m <= i; m++)
	{
		pTmpPointers[m] = ((InternalNode*)pParent)->internalNodeData->m_Pointers[m];
	}

	pTmpPointers[m] = pNew;
	m++;

	for (k = i + 1; k <= pParent->m_nKeyNum; k++,m++)
	{
		pTmpPointers[m] = ((InternalNode*)pParent)->internalNodeData->m_Pointers[k];
	}

	Node * pNewSplit = new InternalNode;

	pNewSplit->m_bLeaf = pParent->m_bLeaf;

	pNewSplit->m_pParent = pParent->m_pParent;

	int nMid = (ORDER + 1) / 2;

	int nMidKey = pTmpKeys[nMid];

	for (m = 0, i = nMid + 1; i < ORDER + 1; i++, m++)
	{
        ((InternalNode*)pNewSplit)->internalNodeData->m_Keys[m] = pTmpKeys[i];
        ((InternalNode*)pNewSplit)->internalNodeData->m_Pointers[m] = pTmpPointers[i];
		if (!pNewSplit->m_bLeaf)
		{
			Node * pCur = static_cast<Node *>(((InternalNode*)pNewSplit)->internalNodeData->m_Pointers[m]);
			if (pCur)
			{
				pCur->m_pParent = pNewSplit;
			}
		}
		pNewSplit->m_nKeyNum++;
	}

    ((InternalNode*)pNewSplit)->internalNodeData->m_Pointers[m] = pTmpPointers[i];

	if (!pNewSplit->m_bLeaf)
	{
		Node * pCur = static_cast<Node *>(((InternalNode*)pNewSplit)->internalNodeData->m_Pointers[m]);
		if (pCur)
		{
			pCur->m_pParent = pNewSplit;
		}
	}

	pParent->m_nKeyNum = 0;

	for (i = 0; i < nMid; i++)
	{
        ((InternalNode*)pParent)->internalNodeData->m_Keys[i] = pTmpKeys[i];
        ((InternalNode*)pParent)->m_nKeyNum++;
	}

	for (i = 0; i <= nMid; i++)
	{
        ((InternalNode*)pParent)->internalNodeData->m_Pointers[i] = pTmpPointers[i];
	}

    delete[] pTmpKeys;

    delete[] pTmpPointers;

	return InsertKeyAndPointer(pParent->m_pParent, pParent, nMidKey, pNewSplit);
}

patient* BPlusTree::search(int nKey){

    int i=0;
    if (!m_pRoot)
        return nullptr;

    Node * pTmp = m_pRoot;
    while (!pTmp->m_bLeaf)
    {
        for (i = 0; i < pTmp->m_nKeyNum; i++)
        {
            if (nKey < ((InternalNode*)pTmp)->internalNodeData->m_Keys[i])
            {
                break;
            }
        }

        pTmp = (Node*)(((InternalNode*)pTmp)->internalNodeData->m_Pointers[i]);
    }

    auto* leafNode = (LeafNode *)pTmp;
    for(int i=0;i<leafNode->m_nKeyNum;i++){
        if(nKey == leafNode->leafNodeData->m_Keys[i]){
            return leafNode->leafNodeData->m_number[i];
        }
    }
    return nullptr;
}


void BPlusTree::PrintLayerTree()
{
    int i = 0;

    queue<Node *> q;

    if (m_pRoot == NULL)
    {
        printf("b+tree is null.\n");
        return;
    }

    Node* node;

    node = m_pRoot;
    q.push(node);

    while (q.empty() == false)
    {
        Node * nodeTmp = q.front();

        if (nodeTmp->m_bLeaf == false)
        {
            for (i = 0; i < nodeTmp->m_nKeyNum; i++)
            {
                printf("%d",((InternalNode*)nodeTmp) ->internalNodeData->m_Keys[i]);
                q.push((Node*)((InternalNode*)nodeTmp) ->internalNodeData->m_Pointers[i]);
                printf(" ");
            }
            q.push((Node*)((InternalNode*)nodeTmp) ->internalNodeData->m_Pointers[i]);
        }
        else
        {
            for (i = 0; i < nodeTmp->m_nKeyNum; i++)
            {
                printf("%d", ((LeafNode*)nodeTmp)->leafNodeData->m_Keys[i]);
                printf(" ");
            }
        }

        printf("\n");

        printf("-------------------------------------------------\n");

        q.pop();
    }

    return;
}

bool BPlusTree::Remove(int nKey)
{
	if (!m_pRoot)
		return false;

	int i = 0;

	int j=-1;

	int m = 0;

	Node * pTmp = m_pRoot;

	while (!pTmp->m_bLeaf)
	{
	    bool flag=false;
		for (i = 0; i < pTmp->m_nKeyNum; i++)
		{
            if (nKey < ((InternalNode*)pTmp)->internalNodeData->m_Keys[i])
            {
                flag = true;
                j=i;
                break;
            }
		}
		if(flag==false){
		    j = pTmp->m_nKeyNum;
		}

        pTmp = (Node*)(((InternalNode*)pTmp)->internalNodeData->m_Pointers[i]);
	}

	for (i = 0; i < pTmp->m_nKeyNum; i++)
	{
		if (nKey == ((LeafNode*)pTmp)->leafNodeData->m_Keys[i]) {
            break;
        }
	}

	if (i == pTmp->m_nKeyNum) {
	    printf("Wrong! %d node not exists",nKey);
        return false;
    }

	auto * pCur = (LeafNode *)pTmp;

	for (m = i + 1; m < pTmp->m_nKeyNum; m++)
	{
        pCur->leafNodeData->m_Keys[m-1] = pCur->leafNodeData->m_Keys[m];
        pCur->leafNodeData->m_number[m-1] = pCur->leafNodeData->m_number[m];
	}

	pTmp->m_nKeyNum--;

	int nLowNum = (LEAF_ORDER+1)  / 2;

	if (pTmp->m_nKeyNum >= nLowNum)
	{
		return true;
	}

	Node * pParent = pTmp->m_pParent;
	if (!pParent) {
        if (pTmp->m_nKeyNum < 1) {
            m_pRoot = NULL;
            delete pTmp;
            m_pFirst = m_pLast = NULL;
        }
        return true;
    }

	Node * pNeighbor = NULL;
	int nNeighbor = -1;
	int nIndex = -1;
	if (j == 0)
	{
		pNeighbor = (Node*)(((InternalNode *)pParent)->internalNodeData->m_Pointers[1]);
		nNeighbor = 1;
		nIndex = 0;
	}
	else
	{
        pNeighbor = (Node*)(((InternalNode *)pParent)->internalNodeData->m_Pointers[j-1]);
		nNeighbor = j - 1;
		nIndex = j;
	}

	if (pNeighbor->m_nKeyNum > nLowNum)
	{
		if (nNeighbor < nIndex)
		{
            ((InternalNode*)pParent)->internalNodeData->m_Keys[nNeighbor] = ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[pNeighbor->m_nKeyNum - 1];
			for (i = pTmp->m_nKeyNum - 1; i >= 0; i--)
			{
                ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[i + 1] = ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[i];
                ((LeafNode*)pNeighbor)->leafNodeData->m_number[i + 1] = ((LeafNode*)pNeighbor)->leafNodeData->m_number[i];
			}
            ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[i + 1] = ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[pNeighbor->m_nKeyNum - 1];
            ((LeafNode*)pNeighbor)->leafNodeData->m_number[0] = ((LeafNode*)pNeighbor)->leafNodeData->m_number[pNeighbor->m_nKeyNum - 1];
			pTmp->m_nKeyNum++;
			pNeighbor->m_nKeyNum--;
		}
		else
		{
            ((InternalNode*)pParent)->internalNodeData->m_Keys[nIndex] = ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[1];
            ((LeafNode*)pTmp)->leafNodeData->m_Keys[pTmp->m_nKeyNum] = ((LeafNode*)pTmp)->leafNodeData->m_Keys[0];
            ((LeafNode*)pTmp)->leafNodeData->m_number[pTmp->m_nKeyNum] = ((LeafNode*)pTmp)->leafNodeData->m_number[0];
			pTmp->m_nKeyNum++;
			for (i = 1; i <= pNeighbor->m_nKeyNum - 1; i++)
			{
                ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[i - 1] = ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[i];
                ((LeafNode*)pNeighbor)->leafNodeData->m_number[i - 1] = ((LeafNode*)pNeighbor)->leafNodeData->m_number[i];
			}
			pNeighbor->m_nKeyNum--;
		}
		return true;
	}

	else
	{
		if (nNeighbor < nIndex)
            {
			for (i = 0; i < pTmp->m_nKeyNum; i++)
			{
                ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[pNeighbor->m_nKeyNum] = ((LeafNode*)pTmp)->leafNodeData->m_Keys[i];
                ((LeafNode*)pNeighbor)->leafNodeData->m_number[pNeighbor->m_nKeyNum] = ((LeafNode*)pTmp)->leafNodeData->m_number[i];
				pNeighbor->m_nKeyNum++;
			}

			for (i = nIndex; i < pParent->m_nKeyNum; i++)
			{
                ((InternalNode*)pParent)->internalNodeData->m_Keys[i - 1] = ((InternalNode*)pParent)->internalNodeData->m_Keys[i];
			}

			for (i = nIndex + 1; i <= pParent->m_nKeyNum; i++)
			{
                ((InternalNode*)pParent)->internalNodeData->m_Pointers[i - 1] = ((InternalNode*)pParent)->internalNodeData->m_Pointers[i];
			}

			pParent->m_nKeyNum--;

            ((LeafNode*)pNeighbor)->leafNodeData->m_next = ((LeafNode*)pTmp)->leafNodeData->m_next;

			delete pTmp;

		}
		else
		{
			for (i = 0; i < pNeighbor->m_nKeyNum; i++)
			{
                ((LeafNode*)pTmp)->leafNodeData->m_Keys[pTmp->m_nKeyNum] = ((LeafNode*)pNeighbor)->leafNodeData->m_Keys[i];
                ((LeafNode*)pTmp)->leafNodeData->m_number[pTmp->m_nKeyNum] = ((LeafNode*)pNeighbor)->leafNodeData->m_number[i];
				pTmp->m_nKeyNum++;
			}

			for (i = nNeighbor; i < pParent->m_nKeyNum; i++)
			{
                ((InternalNode*)pParent)->internalNodeData->m_Keys[i - 1] = ((InternalNode*)pParent)->internalNodeData->m_Keys[i];
			}
			for (i = nNeighbor + 1; i <= pParent->m_nKeyNum; i++)
			{
                ((InternalNode*)pParent)->internalNodeData->m_Pointers[i - 1] = ((InternalNode*)pParent)->internalNodeData->m_Pointers[i];
			}

			pParent->m_nKeyNum--;
            ((LeafNode*)pTmp)->leafNodeData->m_next = ((LeafNode*)pNeighbor)->leafNodeData->m_next;
			delete pNeighbor;
		}

		Node * pCurTmp = pParent;
		int nInternalLowNum = (ORDER + 1) / 2;

		while (pCurTmp)
		{
			if (pCurTmp->m_nKeyNum >= nInternalLowNum)
			{
				break;
			}

			Node * pCurParent = pCurTmp->m_pParent;

			Node * pCurNeighbor = NULL;

			int nCurIndex = 0;

			int nNeighborIndex = 0;

			int nTmp = 0;

			if (!pCurParent)
			{
				if (pCurTmp->m_nKeyNum < 1)
				{
                    ((Node*)(((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[0]))->m_pParent= NULL;
					m_pRoot = (Node *)(((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[0]);
					delete pCurTmp;
				}
				break;
			}
			else
			{
				for (i = 0; i <= pCurParent->m_nKeyNum; i++)
				{
					if (pCurTmp == ((InternalNode*)pCurParent)->internalNodeData->m_Pointers[i])
					{
						break;
					}
				}

				if (i == 0)
				{
					pCurNeighbor = (Node *)((InternalNode*)pCurParent)->internalNodeData->m_Pointers[1];
					nCurIndex = 0;
					nNeighborIndex = 1;
				}
				else
				{
					pCurNeighbor = (Node *)((InternalNode*)pCurParent)->internalNodeData->m_Pointers[i-1];
					nCurIndex = i;
					nNeighborIndex = i-1;
				}

				if (pCurNeighbor->m_nKeyNum > nInternalLowNum)
				{
					if (nNeighborIndex < nCurIndex)
					{
						nTmp = ((InternalNode*)pCurParent)->internalNodeData->m_Keys[nNeighborIndex];
                        ((InternalNode*)pCurParent)->internalNodeData->m_Keys[nNeighborIndex] = ((InternalNode*)pCurNeighbor)->internalNodeData->m_Keys[pCurNeighbor->m_nKeyNum - 1];
						for (i = pCurTmp->m_nKeyNum - 1; i >= 0; i--)
						{
                            ((InternalNode*)pCurTmp)->internalNodeData->m_Keys[i + 1] = ((InternalNode*)pCurTmp)->internalNodeData->m_Keys[i];
						}
						for (i = pCurTmp->m_nKeyNum; i >= 0; i--)
						{
						    ((InternalNode *) pCurTmp)->internalNodeData->m_Pointers[i + 1] = ((InternalNode *) pCurTmp)->internalNodeData->m_Pointers[i];
						}
                        ((InternalNode*)pCurTmp)->internalNodeData->m_Keys[0] = nTmp;
						if (((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[pCurNeighbor->m_nKeyNum])
						{

                            static_cast<Node *>(((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[pCurNeighbor->m_nKeyNum])->m_pParent = pCurTmp;
						}
                        ((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[0] = ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[pCurNeighbor->m_nKeyNum];
						pCurTmp->m_nKeyNum++;
						pCurNeighbor->m_nKeyNum--;
					}
					else
					{
						nTmp =  ((InternalNode*)pCurParent)->internalNodeData->m_Keys[nCurIndex];
                        ((InternalNode*)pCurParent)->internalNodeData->m_Keys[nCurIndex] = ((InternalNode*)pCurNeighbor)->internalNodeData->m_Keys[0];
                        ((InternalNode*)pCurTmp)->internalNodeData->m_Keys[pCurTmp->m_nKeyNum] = nTmp;

						if (((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[0])
						{
							static_cast<Node *>(((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[0])->m_pParent = pCurTmp;
						}

                        ((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[pCurTmp->m_nKeyNum + 1] = ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[0];
						pCurTmp->m_nKeyNum++;

						for (i = 1; i < pCurNeighbor->m_nKeyNum; i++)
						{
                            ((InternalNode*)pCurNeighbor)->internalNodeData->m_Keys[i - 1] = ((InternalNode*)pCurNeighbor)->internalNodeData->m_Keys[i];
						}
						for (i = 1; i <= pCurNeighbor->m_nKeyNum; i++)
						{
                            ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[i-1] = ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[i];
						}

						pCurNeighbor->m_nKeyNum--;
					}
					break;
				}
				else
				{
					if (nNeighborIndex < nCurIndex)
					{
                        ((InternalNode*)pCurNeighbor)->internalNodeData->m_Keys[pCurNeighbor->m_nKeyNum] = ((InternalNode*)pCurParent)->internalNodeData->m_Keys[nNeighborIndex];
						pCurNeighbor->m_nKeyNum++;
						for (i = 0; i < pCurTmp->m_nKeyNum; i++)
						{
                            ((InternalNode*)pCurNeighbor)->internalNodeData->m_Keys[pCurNeighbor->m_nKeyNum] = ((InternalNode*)pCurTmp)->internalNodeData->m_Keys[i];
                            ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[pCurNeighbor->m_nKeyNum] = ((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[i];
							Node * pChild = (Node *)((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[pCurNeighbor->m_nKeyNum];
							if (pChild)
								pChild->m_pParent = pCurNeighbor;
							pCurNeighbor->m_nKeyNum++;
						}

                        ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[pCurNeighbor->m_nKeyNum] = ((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[i];

						if ( ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[pCurNeighbor->m_nKeyNum])
						{
							static_cast<Node *>( ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[pCurNeighbor->m_nKeyNum])->m_pParent = pCurNeighbor;
						}
						for (i = nNeighborIndex + 1; i < pCurParent->m_nKeyNum; i++)
						{
                            ((InternalNode*)pCurParent)->internalNodeData->m_Keys[i - 1] = ((InternalNode*)pCurParent)->internalNodeData->m_Keys[i];
						}

						for (i = nCurIndex + 1; i <= pCurParent->m_nKeyNum; i++)
						{
                            ((InternalNode*)pCurParent)->internalNodeData->m_Pointers[i - 1] = ((InternalNode*)pCurParent)->internalNodeData->m_Pointers[i];
						}

						pCurParent->m_nKeyNum--;

						delete pCurTmp;
					}
					else
					{
                        ((InternalNode*)pCurTmp)->internalNodeData->m_Keys[pCurTmp->m_nKeyNum] = ((InternalNode*)pCurParent)->internalNodeData->m_Keys[nCurIndex];
						pCurTmp->m_nKeyNum++;

						for (i = 0; i < pCurNeighbor->m_nKeyNum; i++)
						{
                            ((InternalNode*)pCurTmp)->internalNodeData->m_Keys[pCurTmp->m_nKeyNum] = ((InternalNode*)pCurNeighbor)->internalNodeData->m_Keys[i];
                            ((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[pCurTmp->m_nKeyNum] = ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[i];
							Node * pChild = (Node *)(((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[pCurTmp->m_nKeyNum]);
							if (pChild)
								pChild->m_pParent = pCurTmp;
							pCurTmp->m_nKeyNum++;
						}

                        ((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[pCurTmp->m_nKeyNum] = ((InternalNode*)pCurNeighbor)->internalNodeData->m_Pointers[i];
						if (((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[pCurTmp->m_nKeyNum])
						{
							((Node *)(((InternalNode*)pCurTmp)->internalNodeData->m_Pointers[pCurTmp->m_nKeyNum]))->m_pParent = pCurTmp;
						}

						for (i = nCurIndex + 1; i < pCurParent->m_nKeyNum; i++)
						{
							((InternalNode*)pCurParent)->internalNodeData->m_Keys[i - 1] = ((InternalNode*)pCurParent)->internalNodeData->m_Keys[i];
						}

						for (i = nNeighborIndex + 1; i <= pCurParent->m_nKeyNum; i++)
						{
							((InternalNode*)pCurParent)->internalNodeData->m_Pointers[i - 1] = ((InternalNode*)pCurParent)->internalNodeData->m_Pointers[i];
						}

						pCurParent->m_nKeyNum--;

						delete pCurNeighbor;
					}

					pCurTmp = pCurParent;
				}
			}
		}

		return true;
	}
}

void BPlusTree::printInfo(int nKey){
	patient* tempIll = this->search(nKey);
	if (NULL == tempIll){
		printf("The id you want to search is not registered or has been treated already.\n\n");
		return;
	}
	char filename[30] = {0};
    sprintf(filename,"Record-with-ID-of-%d.txt",nKey);
    ofstream outfile(filename,ios::out);
    if(!outfile){
        cout << "Open the file failure...\n";
        exit(0);
    }
    cout << endl << "Information of people with ID "<<nKey<<" produced to Record-with-ID-of-"<<nKey<< ".txt" << endl << endl;
    outfile << "Record with ID of " << nKey << endl;
    outfile << "ID,NAME,PROF,AGE,CONTACT,RISK,REGISTRATION,MEDICAL_STATUS,TREATMENT\n";
	outfile << tempIll->id << ',' << tempIll->name << ',' << tempIll->prof << ',' << tempIll->aging << ',' << tempIll->contact\
	<< ',' << tempIll->risk << ',' << tempIll->time << ',' << tempIll->status << ',';
	if(tempIll->treatment==1)outfile<<"Surgery"<<endl;
			else if (tempIll->treatment==2)outfile<<"Vaccination"<<endl;
			else outfile<<"Medical advice"<<endl;
	outfile.close();
}