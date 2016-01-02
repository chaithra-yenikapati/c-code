// product.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

struct test{
	int input[10];
	int len;
	int output[10];
}testDB[5]={
	{{1,2,3,4,5},5,{120,60,40,30,24}},//all positive numbers in input
	{{0,1,2,3,4},5,{24,0,0,0,0}},//input with one zero
	{{-1,-2,3,4,5},5,{-120,-60,40,30,24}},//negative numbers as input
	{{2,2,2},3,{4,4,4}},//all same numbers in the array
	{{1,2,0,3,0},5,{0,0,0,0,0}}//more than one zero in input
};

int* product_except_itself(int* input,int len)
{
	int i,temp=1;
	int * mul=(int*)malloc(len*sizeof(int));
	for(i=0;i<len;i++)
	{	
		mul[i]=temp;
		temp*=input[i];
	}
	temp=1;
	for(i=len-1;i>=0;i--)
	{
		mul[i]*=temp;
		temp*=input[i];
	}
	return mul;
}

void testcases()
{
	int *output,flag=0;
	for(int i=0;i<5;i++)
	{
		output=product_except_itself(testDB[i].input,testDB[i].len);
		for(int j=0;j<testDB[i].len;j++)
			if(output[j]!=testDB[i].output[j])
				flag=1;
		if(flag==1)
			printf("\ntest failed");
		else
			printf("\ntest passed");
	}

}
int main()
{
	testcases();
	return 0;
}

