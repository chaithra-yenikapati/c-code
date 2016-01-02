// nsum.cpp : Defines the entry point for the console application.
//code to find sum of natural numbers up to given number 
//specifications:  the functions take any kind of integer ie +ve or -ve as input and handles the input accordingly.

#include "stdafx.h"
int sum(int );
int sum(int,int);
struct test
{
	int input;
	int output1; //output of one way recursion.
	int output2;//output of two way recursion.
}testDB[4]={
	{1,1,1},   //if a positive integer is passed, then the function returns sum of natural no's up to that integer as output.
	{4,10,10},
	{-2,-2,-2},//if negative numbers are given as input, te same are returned by the function.
	{0,0,0}//if 0 is given as input same is returned.
};


void testsumupton()
{
	int i,sum1,sum2;
	for(i=0;i<4;i++)
	{
		sum1=sum(testDB[i].input);//calling one way recursive code with only one argument
		sum2=sum(1,testDB[i].input);// calling two way recursive code with two arguments.
		if(sum1==testDB[i].output1&&sum2==testDB[i].output2) printf("PASSED\n"); else printf("FAILED\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testsumupton();
	return 0;
}
//one way recursive code
int sum(int n)
{       
	if(n==1)
		return 1;
	else if(n>1)
		return n+sum(n-1);
	else return n;

}

//two way recursive code
int sum(int low,int high)
{
	if(high-low>1)
	{
	 int m=(low+high)/2,s1,s2;
	 return m+sum(low,m-1)+sum(m+1,high);
	}
	if(low==high)
		return low;
	if(high-low==1)
		return low+high;
	else return high;
}
	 
