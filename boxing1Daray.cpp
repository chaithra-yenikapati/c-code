// 1dary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"
struct test {
	int input[20];
	int size_of_array;
} testDB[6] = { {NULL,0},
				{{1,2,3,4},4},
				{{0,0,0,0,0,0,0,0,0,0},10},
				{{},0},
				{{1},1},
				{{1,2,3,4,5},5}
};
char ** boxing1DArray(int *,int);

bool checkBoxing1DArray(char **box1Darray,int *input,int size_of_input_array)
{
	int box_array_size = (size_of_input_array * 4)+1,index=0;
	for(int i=0;i<3;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<box_array_size;j++)
			{
				if(box1Darray[i][j]!='-')
					return false;
			}
		}
		else
		{
			for(int j=0;j<box_array_size;j++)
			{
				if(j%4 == 0)
				{
					if(box1Darray[i][j] != '|')
						return false;
				}
				else if(j%2!=0)
				{
					if(box1Darray[i][j] != ' ')
						return false;
				}
				else
				{
					if(box1Darray[i][j] != input[index++]+'0')
						return false;
				}
			}
		}
	}
	return true;
}

void testCases()
{
	char **output;
	for(int i=0; i<6; i++) {
		output = boxing1DArray(testDB[i].input,testDB[i].size_of_array);
		if(testDB[i].input == NULL)
		{
			if(output == NULL)
				printf("PASSED");
			else
				printf("FAILED");
			continue;
		}
		if(checkBoxing1DArray(output,testDB[i].input,testDB[i].size_of_array)) printf("PASSED\n"); else printf("FAILED\n");
	}
}
char ** boxing1DArray(int *input,int size_of_array)
{
	//code for boxing the given 1d array
	char **res;
	int i,j,cols=(size_of_array * 4)+1,index=0;
	res = (char**)malloc(sizeof(char)*3);
    for(i=0;i<3;i++)
       res[i] = (char *)malloc(sizeof(char)*cols);
	
 for(i=0;i<3;i++)
 {
		 if(i%2==0)
		 {
			for(j=0;j<cols;j++)
			{
			   res[i][j]='-';
			}
		}
		else
		{
	         for(j=0;j<cols;j++)
			 {
			    if(j%4==0)
				   res[i][j]='|';
				else if((j%2)!=0)
				   res[i][j]=' ';
				else
				   res[i][j]=input[index++]+'0';
			 }
		}
   }
    return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}