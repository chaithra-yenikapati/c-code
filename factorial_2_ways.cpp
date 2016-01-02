// factorial_2_ways.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
struct test
{
	int input;
	int output1; //one way recursion.
	int output2;//two way recursion.
}testDB[4]={
	{1,1,1},   //base case of 1
	{5,120,120},//positive number
	{-10,-10,-10},//if negative number is given as input, the same is returned by the function.
	{0,1,1}//base case of 0
};

int fact1way(int input)
{
	if(input>0)
	   return input*fact1way(input-1);
	else if(input==0)
		return 1;
	else
		return input;
}
int fact2way(int low,int high)
{
	if(high==0||high==1)
		return 1;
	else if(high==low||high<0)
		return high;
	else
	 {
			 int mid;
		     mid=(low+high)/2;
		        return fact2way(low,mid)*fact2way(mid+1,high);
	 }
}


void testcases()
{
	int i,fact1,fact2,low=1;
	for(i=0;i<4;i++)
	{
		fact1=fact1way(testDB[i].input);//1 way
		fact2=fact2way(low,testDB[i].input);// 2 way
		if(fact1==testDB[i].output1 && fact2==testDB[i].output2) printf("PASSED\n"); else printf("FAILED\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}

