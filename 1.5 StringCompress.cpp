// StringCompress.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TEMP_BUF_SIZE 10000



bool appendCompressedOneChar(char* pBuf, char compressedChar, int nDuplicatedCnt, int nBufMaxSize)
{

	char szOneCharCompressedStr[100];
	sprintf(szOneCharCompressedStr,"%c%d",compressedChar,nDuplicatedCnt);

	if( strlen(szOneCharCompressedStr) + strlen(pBuf) >= nBufMaxSize)
	{
		return false;
	}

	sprintf(pBuf,"%s%s",pBuf,szOneCharCompressedStr);

	return true;
}

char* compressString(const char* szString )
{
	int nStrLen = strlen(szString);
	char* pCompressedStr = NULL;

	if(nStrLen <=0 )
	{
		pCompressedStr = (char*)malloc( sizeof(char) * 1 );
		pCompressedStr[0] = 0;
		return pCompressedStr;
	}

	int nCompressedLen = 0;
	bool bSucess = true;
	int nDuplicatedCnt = 0;
	char prevChar = szString[0];
	pCompressedStr = (char*)malloc( sizeof(char) * (nStrLen + 1) );
	memset(pCompressedStr,0, sizeof(char) * (nStrLen + 1) );

	for(int i=0 ; i< nStrLen ; i++ )
	{
		if( prevChar == szString[i] )
		{
			nDuplicatedCnt ++;
		}
		else
		{
			bool appendSuccess = appendCompressedOneChar(pCompressedStr,prevChar,nDuplicatedCnt,nStrLen);

			if( appendSuccess == false )
			{
				bSucess = false;
				break;
			}

			nDuplicatedCnt = 1;			
		}

		if( i == nStrLen-1 )
		{
			bool appendSuccess = appendCompressedOneChar(pCompressedStr,szString[i],nDuplicatedCnt,nStrLen);

			if( appendSuccess == false )
			{
				bSucess = false;
				break;

			}
		}

		prevChar = szString[i];

	}


	if( bSucess == false )
	{
		memcpy(pCompressedStr,szString,strlen(szString)+1);
	}


	return pCompressedStr;
}

int _tmain(int argc, _TCHAR* argv[])
{

	char *szProblemStr[] = {"", "aaaaaaaaaaa", "aaabbbb", "abc", "abccccd", "aabc","aaaaabaaaaa"};
	char *szAnswerStr[] = {"", "a11", "a3b4", "abc"/*a1b1c1*/,  "abccccd"/*"a1b1c4d1"*/, "aabc"/*a2b1c1*/,"a5b1a5" };


	char szTemp[TEMP_BUF_SIZE] ;
	char* szTestSuccess = "fail";
	for (int i = 0 ; i < sizeof(szProblemStr)/sizeof(szProblemStr[0]); i++) 
	{
		memset(szTemp,0,TEMP_BUF_SIZE);
		strcpy (szTemp, szProblemStr[i]);
		char* pCompressedStr = compressString(szTemp);
		szTestSuccess =  strcmp(pCompressedStr,szAnswerStr[i]) == 0 ? "success":"fail";
		printf ("%s : \"%s\" >> \"%s\"  \n", szTestSuccess, szProblemStr[i], pCompressedStr);
		free(pCompressedStr);
	}




	return 0;
}

