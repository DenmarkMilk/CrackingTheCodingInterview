// RotateBitmap.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>



class BrMatrix
{
private:	
	int m_nRows;
	int m_nCols;
	int* m_data;

public:
	BrMatrix(int nRows,int nCols)
	{
		m_nCols = nCols;
		m_nRows = nRows;

		m_data = (int*)malloc( sizeof(int) * nRows * nCols );
	}

	int getRows()
	{
		return m_nRows	;
	}

	int getCols()
	{
		return m_nCols	;
	}

	void setValue(int row, int col, int value)
	{
		if(m_nCols < col || m_nRows < row)
		{
			return ;
		}

		m_data[ row * m_nCols + col] = value;
	}

	void setValueInOneRowAtTheSameTime(int row,int* values)
	{

		if( m_nRows < row )
			return ;
		
		
		memcpy(&m_data[row * m_nCols],values,sizeof(int) * m_nCols );		
	}

	int getValue(int row, int col)
	{
		if(m_nCols < col || m_nRows < row)
		{
			return m_data[0];
		}

		return m_data[ row * m_nRows + col];

	}

	int* getValuePointer(int row, int col)
	{
		if(m_nCols < col || m_nRows < row)
		{
			return NULL;
		}

		return &(m_data[ row * m_nRows + col]);
	}

	void print()
	{
		for(int i=0;i<m_nRows;i++)
		{
			for(int j=0;j<m_nCols;j++)
			{
				printf("%d	",getValue(i,j));
			}

			printf("\n");
		}

		printf("\n\n");
	}

	void rotate90()
	{
		int colMax = m_nCols;

		for(int i=0; i<colMax/2; i++)
		{
			for(int j=0; j<(colMax+1)/2; j++)
			{
				fourNumberRotate( 
							getValuePointer(i,j),
							getValuePointer(colMax-1-j,i), 
							getValuePointer(colMax-1-i,colMax-1-j),
							getValuePointer(j,colMax-i) );
			}
		}

	}

private:
	void fourNumberRotate(int *a, int *b, int *c, int *d)
	{
		//printf("%d,%d,%d,%d\n",*a,*b,*c,*d);
		int temp = *a;
		*a = *b;
		*b = *c;
		*c = *d;
		*d = temp;
	}

};




int _tmain(int argc, _TCHAR* argv[])
{
	BrMatrix matrix2(2,2);
	BrMatrix matrix3(3,3);
	BrMatrix matrix4(4,4);
	
	int nIncreaingNumber = 1;
	for(int i=0;i<matrix2.getRows();i++)
	{
		for(int j=0;j<matrix2.getCols();j++)
		{
			matrix2.setValue(i,j,nIncreaingNumber);
			nIncreaingNumber++;
		}
	}
	matrix2.print();
	matrix2.rotate90();
	matrix2.print();

	nIncreaingNumber = 1;
	for(int i=0;i<matrix3.getRows();i++)
	{
		for(int j=0;j<matrix3.getCols();j++)
		{
			matrix3.setValue(i,j,nIncreaingNumber);
			nIncreaingNumber++;
		}
	}
	matrix3.print();
	matrix3.rotate90();
	matrix3.print();

	nIncreaingNumber = 1;
	for(int i=0;i<matrix4.getRows();i++)
	{
		for(int j=0;j<matrix4.getCols();j++)
		{
			matrix4.setValue(i,j,nIncreaingNumber);
			nIncreaingNumber++;
		}
	}
	matrix4.print();
	matrix4.rotate90();
	matrix4.print();


	return 0;
}

