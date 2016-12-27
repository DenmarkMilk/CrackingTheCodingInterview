// DeleteNode.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


#include "linkedList.cpp"


void deleteNode(LinkedList* pLinkedList, int nData)
{

	if( pLinkedList->isEmpty() == true )
		return ;

	Node* pNode = pLinkedList->getFirstNode();
	Node* pPrevNode = NULL;


	//1. 맨 처음 노드가 사라지는 경우
	if(pNode->getData() == nData )
	{
		pLinkedList->setHeadNode( pNode->getNextLink() );
		delete pNode;
	}
	else
	{
		//2. 맨 처음이 아닌 노드가 사라지는 경우 
		while(pNode->getNextLink() != NULL)
		{
			if(pNode->getNextLink()->getData() == nData)
			{
				Node* pDeleteNode = pNode->getNextLink();
				pNode->setNextLink(pDeleteNode->getNextLink());
				delete pDeleteNode;
				break;

			}
			pNode = pNode->getNextLink() ;
		}
	}

	
}

int _tmain(int argc, _TCHAR* argv[])
{


	LinkedList linkedlist;

	linkedlist.insertAtTail(1);
	linkedlist.insertAtTail(2);
	linkedlist.insertAtTail(3);
	linkedlist.insertAtTail(4);
	linkedlist.insertAtTail(5);

	deleteNode(&linkedlist,6);
	linkedlist.printList();

	deleteNode(&linkedlist,1);
	linkedlist.printList();
	linkedlist.insertAtHead(10);
	linkedlist.printList();

	deleteNode(&linkedlist,3);
	linkedlist.printList();
	linkedlist.insertAtHead(20);
	linkedlist.printList();

	deleteNode(&linkedlist,5);
	linkedlist.printList();
	linkedlist.insertAtTail(30);
	linkedlist.printList();









	

	return 0;
}

