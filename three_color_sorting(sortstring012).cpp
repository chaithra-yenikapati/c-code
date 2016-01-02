// three_color_sorting(sortstring012).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct test{
	int input[30];
	int len;
	int output[30];
}testDB[5]={
	{{1,0,2,2,0,1,0,2,1,0},10,{0,0,0,0,1,1,1,2,2,2}},
	{{0,0,0,0,0},5,{0,0,0,0,0}},
	{{1,1,1},3,{1,1,1}},
	{{2,2,2,2},4,{2,2,2,2}},
	{{0,0,0,1,1,1,2,2},8,{0,0,0,1,1,1,2,2}},
};
void sort0_1_2(int* input,int len)
{
	int index1=len-1,index2=len-1,temp;
	while(index1>=0)
	{
		if(input[index1]==2)
		{
			temp=input[index1];
			input[index1--]=input[index2];
			input[index2--]=temp;
		}
		else
			index1--;
	}
	index1=index2=0;
	while(index1<len)
	{
		if(input[index1]==0)
		{
			temp=input[index1];
			input[index1++]=input[index2];
			input[index2++]=temp;
		}
		else
			index1++;
	}
}




void testcases()
{
	for(int i=0;i<5;i++)
	{
		sort0_1_2(testDB[i].input,testDB[i].len);
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

