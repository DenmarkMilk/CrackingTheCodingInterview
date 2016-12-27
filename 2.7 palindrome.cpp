// palindrome.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "linkedList.cpp"


LinkedList* reverseList(Node* pStartNode)
{


	LinkedList* pReversedList = new LinkedList();


	while(pStartNode!=NULL)
	{
		pReversedList->insertAtHead( pStartNode->getData() );
		pStartNode = pStartNode->getNextLink();
	}
	
	return pReversedList;

}

bool check(LinkedList* pList)
{
	int nlen = pList->getSize();
	int nMid = 0;

	if(nlen % 2 == 0)
		nMid = nlen/2;
	else
		nMid = nlen/2+1;


	Node* midNode = pList->getFirstNode();
	for(int i=1;i<nMid;i++)
	{
		midNode = midNode->getNextLink();
	}

	LinkedList* pReversedList = reverseList(midNode);


	Node* pFrontTravel = pList->getFirstNode();
	Node* pBackTravel = pReversedList->getFirstNode();

	for(int i=0;i<nMid;i++)
	{

		if(pFrontTravel->getData() != pBackTravel->getData() ) return false;

		pFrontTravel = pFrontTravel->getNextLink();
		pBackTravel = pBackTravel->getNextLink();
	}

	delete pReversedList;

	return true;




}

int _tmain(int argc, _TCHAR* argv[])
{
	LinkedList list1;
	LinkedList list2;
	LinkedList list3;
	LinkedList list4;
	LinkedList list5;
	LinkedList list6;



	list1.insertAtTail(3);
	list1.insertAtTail(4);
	list1.insertAtTail(2);
	list1.insertAtTail(4);
	list1.insertAtTail(3);

	bool bResult = check(&list1);
	printf("%s\n",bResult == true ? "true":"false");


	list2.insertAtTail(3);
	list2.insertAtTail(4);
	list2.insertAtTail(4);
	list2.insertAtTail(3);

	bResult = check(&list2);
	printf("%s\n",bResult == true ? "true":"false");


	list3.insertAtTail(3);
	list3.insertAtTail(4);
	list3.insertAtTail(5);
	list3.insertAtTail(3);

	bResult = check(&list3);
	printf("%s\n",bResult == true ? "true":"false");


	list4.insertAtTail(3);
	list4.insertAtTail(4);
	list4.insertAtTail(5);
	list4.insertAtTail(3);
	list4.insertAtTail(3);

	bResult = check(&list4);
	printf("%s\n",bResult == true ? "true":"false");


	list5.insertAtTail(3);
	list5.insertAtTail(4);
	list5.insertAtTail(3);


	bResult = check(&list5);
	printf("%s\n",bResult == true ? "true":"false");


	list5.insertAtTail(3);
	list5.insertAtTail(4);
	list5.insertAtTail(3);


	bResult = check(&list5);
	printf("%s\n",bResult == true ? "true":"false");




	list6.insertAtTail(3);

	bResult = check(&list6);
	printf("%s\n",bResult == true ? "true":"false");



	return 0;
}

