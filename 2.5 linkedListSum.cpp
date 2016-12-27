// LinkedListSum.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include "linkedList.cpp"
#include <stdio.h>



int convertToInteger(LinkedList * plist);

LinkedList* linkedListSum(LinkedList* plist1, LinkedList* plist2)
{

	if( plist1->isEmpty() == true || plist2->isEmpty() == true )
		return NULL;

	LinkedList* pResultLinkedList = new  LinkedList();

	int nNumer1 = convertToInteger(plist1);
	int nNumer2 = convertToInteger(plist2);

	char szResultBuf[100];
	memset(szResultBuf,0,100);

	sprintf(szResultBuf,"%d",nNumer1 + nNumer2);
	
	int nLenOfResult = strlen(szResultBuf);
	for(int i=0;i<nLenOfResult;i++)
	{
		pResultLinkedList->insertAtHead(szResultBuf[i]-'0');
	}

	return pResultLinkedList;
}

int convertToInteger(LinkedList * plist)
{
	int nResult = 0;

	if( plist->isEmpty() == false)
	{
		int nCipher = 1; //각 자릿수에 곱해지는 수 

		Node* pTravelNode = plist->getFirstNode();

		while(pTravelNode != NULL)
		{
			nResult += (pTravelNode->getData() * nCipher) ;
			pTravelNode = pTravelNode->getNextLink();
			nCipher *= 10;
		}
	}
	
	return  nResult;
}


int _tmain(int argc, _TCHAR* argv[])
{
	LinkedList list1;
	LinkedList list2;

	LinkedList list3;
	LinkedList list4;


	list1.insertAtTail(3);
	list1.insertAtTail(4);
	list1.insertAtTail(2);

	list2.insertAtTail(4);
	list2.insertAtTail(0);
	list2.insertAtTail(7);

	LinkedList* pResult  = linkedListSum(&list1,&list2);

	if(pResult)
	{
		pResult->printList();
		delete pResult;
	}
		
	list3.insertAtTail(3);
	list3.insertAtTail(4);
	list3.insertAtTail(7);

	list4.insertAtTail(4);
	list4.insertAtTail(7);
	list4.insertAtTail(7);

	pResult = linkedListSum(&list3,&list4);

	if(pResult)
	{
		pResult->printList();
		delete pResult;
	}




	return 0;
}

