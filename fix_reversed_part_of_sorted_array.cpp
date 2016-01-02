// fix_reversed_part_of_sorted_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct test {
	int input[20];
	int len;
	int output[20];
} testDB[4] = {
	{{6,5,4,7,8,9},6,{4,5,6,7,8,9}},
	{{1,2,3,6,5,4,7,8,9},9,{1,2,3,4,5,6,7,8,9}},
	{{1,2,3,4,5},5,{1,2,3,4,5}},
	{{1,2,3,6,5,4},6,{1,2,3,4,5,6}}
};
void fix_reversed_part(int* input,int strt,int end)
{
	int m=(strt+end)/2,temp;
	while(strt<=m)
	{
		temp=input[strt];
		input[strt++]=input[end];
		input[end--]=temp;
	}
}

void fix_array(int* input,int len)
{
	int i,strt=0,end=0,flag=0;
	for(i=0;i<len-1;i++)
	{
		if(input[i]>input[i+1])
		{
			flag++;
			if(flag==1)
			{
				strt=i;
				end=i+1;
			}
			else
				end++;
		}
	}
	fix_reversed_part(input,strt,end);
}
void testcases()
{
	for(int i=0; i<4; i++) 
	{
		fix_array(testDB[i].input,testDB[i].len);
		int flag=1;
		for(int j=0;j<testDB[i].len;j++)
     		{
				if(testDB[i].input[j]==testDB[i].output[j])
				flag=0;
			else flag=1;}
		if(flag==0)
			printf("test %d passed\n",i+1);
		else
			printf("test %d failed\n",i+1);
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}

