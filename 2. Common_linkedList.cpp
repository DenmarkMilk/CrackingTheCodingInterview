
#include <iostream>
using namespace std;

class Node    //자료형을 정의합니다.
{
private:
	int m_data;
	Node* m_pNext;

public:

	Node()
	{
		m_data = 0;
		m_pNext = NULL;
	}

	void setData(int nData)
	{
		m_data = nData;
	}

	int getData()
	{
		return 	m_data ;
	}

	void setNextLink(Node* pNext)
	{
		m_pNext = pNext;
	}

	Node* getNextLink()
	{
		return m_pNext;
	}


};

class LinkedList
{
private:
	Node* pHead;
	int m_nSize;
	//Node* pTail;

public:
	LinkedList(){
		pHead = NULL; // set head to NULL
		m_nSize = 0;
		//pHead = new Node();
	}

	~LinkedList()
	{
		//delete pHead;
	}

	int getSize()
	{
		return m_nSize;
	}

	bool isEmpty()
	{
		return pHead == NULL ;
	}

	void insertAfter(Node* pPrevNode, int nData)
	{
		bool bFined = existInList(pPrevNode);

		if(bFined == true)
		{
			Node* pNewNode = createNewNode(nData);
			Node* pTempNode = pPrevNode->getNextLink();
			pPrevNode->setNextLink( pNewNode ) ;
			pNewNode->setNextLink( pTempNode );
			m_nSize++;
		}
	}

	Node* createNewNode(int nData)
	{
		Node* pNode = new Node();
		pNode->setData(nData);
		pNode->setNextLink(NULL);

		return pNode;
	}

	bool existInList(Node* pNode)
	{
		if(isEmpty() == true)
			return NULL;

		bool bSuccess = false;

		Node* pTravelNode = pHead;

		while(pTravelNode != NULL)
		{
			if( pTravelNode == pNode )
			{
				bSuccess = true;
				break;
			}
				
			pTravelNode = pTravelNode->getNextLink();
		}

		return bSuccess;
	}

	void insertAtTail(int nData)
	{

		if( isEmpty() == true )
		{
			Node* pNewNode = createNewNode(nData);
			pHead = pNewNode;
		}
		else
		{
			Node* pNode = getLastNode();

			Node* pNewNode = createNewNode(nData);
			Node* pTempNode = pNode->getNextLink();
			pNode->setNextLink( pNewNode ) ;
			pNewNode->setNextLink( pTempNode );
		}
		m_nSize++;

	} 
	void insertAtHead(int nData)
	{
		if( isEmpty() == true )
		{
			Node* pNewNode = createNewNode(nData);
			pHead = pNewNode;
		}
		else
		{
			Node* pNode = getFirstNode();

			Node* pNewNode = createNewNode(nData);
			//Node* pTempNode = pNode->getNextLink();
			//pNode->setNextLink( pNewNode ) ;
			pNewNode->setNextLink( pNode );
			pHead = pNewNode;
		}
		m_nSize++;
	}


	Node* getFirstNode()
	{
		return pHead;
	}

	void setHeadNode(Node* pNode)
	{
		pHead = pNode;
	}

	Node* getLastNode()
	{
		Node* pTravelNode = pHead;

		while(pTravelNode->getNextLink() != NULL)
		{
			pTravelNode = pTravelNode->getNextLink();
		}

		return pTravelNode;
	}

	void printList()
	{

		if(isEmpty() == true)
		{
			printf("%p	",pHead);
		}
	
		Node* pTravelNode = pHead;

		while(pTravelNode != NULL)
		{
			printf("%d	",pTravelNode->getData());
			pTravelNode = pTravelNode->getNextLink();
		}

		printf("\n================\n");
	
	}

};
