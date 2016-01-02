// merge2sortedarrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
struct test{
	int array1[30];
	int array2[30];
	int size_of_array1;
	int size_of_array2;
	int output[30];
}testDB[11]={
			{NULL,NULL,0,0,NULL},
			{{1,2,3,4,5},{5,6,7,8,9},5,5,{1,2,3,4,5,5,6,7,8,9}},
			{{5,6,7,8,9},{1,2,3,4,5},5,5,{1,2,3,4,5,5,6,7,8,9}},
			{{},{5,6,7,8,9},0,5,{5,6,7,8,9}},
			{{1,2,3,4,5},{},5,0,{1,2,3,4,5}},
			{{-5,-4,-3,-2,-1},{-9,-8,-7,-6,-5},5,5,{-9,-8,-7,-6,-5,-5,-4,-3,-2,-1}},
			{{10,10,10},{20,20,20},3,3,{10,10,10,20,20,20}},
			{{20,20,20},{10,10,10},3,3,{10,10,10,20,20,20}},
			{{10,10,10},{10,10,10},3,3,{10,10,10,10,10,10}},
			{{-1},{-1},1,1,{-1,-1}},
			{{},{},0,0,{}}
};

bool compareArrays(int *programoutput,int *testoutput)
{
	if(programoutput!=NULL)
	{
		for(int i=0;i<30;i++)
		{
			if(programoutput[i] != testoutput[i])
				return false;
		}
		return true;
	}
	else
	{
		if(programoutput==NULL)
			return true;
		return false;
	}
}

void mergeAndSortSortedArrays(int *array1,int *array2,int size_of_array1,int size_of_array2)
{
	int i,j,k;
	if(array1==NULL||array2==NULL)
		array1=NULL;

	for(k=size_of_array1+size_of_array2-1,i=size_of_array1-1,j=size_of_array2-1;i>=0&&j>=0;k--)
	{
		if(array1[i]<array2[j])
		{
			array1[k]=array2[j];
			j--;
		}
		else if(array1[i]==array2[j])
		{
			array1[k]=array2[j];
			j--;
			k--;
			array1[k]=array1[i];
			i--;
		}
		else
		{
			array1[k]=array1[i];
			i--;
		}
	}
	if(i<0)
	{   while(j>=0)
	  {
		array1[k]=array2[j];
	    j--;
		k--;
	  }
	}
}
void testCases()
{
	for(int i=0; i<11; i++) {
		mergeAndSortSortedArrays(testDB[i].array1,testDB[i].array2,testDB[i].size_of_array1,testDB[i].size_of_array2);
		if(compareArrays(testDB[i].array1,testDB[i].output)) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}