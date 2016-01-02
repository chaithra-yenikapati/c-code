// swap.cpp : Defines the entry point for the console application.
//written by Y.Chaithra
//date:13th january 2013

#include "stdafx.h"
#include<stdio.h>
void swap1(int,int);//swap function without temporary variable
void swap2(int,int);//swap function with temporary variable
void swap3(int*,int*);
int _tmain(int argc, _TCHAR* argv[])
{
	int v1,v2;//values to be swapped
	printf("enter two values\n");
	scanf("%d%d",&v1,&v2);
	printf("first swap function:\n");
	swap1(v1,v2);//passing addresses of values to swap function
	printf("second swap function:\n");
	swap2(v1,v2);
	printf("third swap function:\n");
	//passing addresses of values to swap function.i called this function at last because this function swaps the values at the addresses
	swap3(&v1,&v2);
	return 0;
}

void swap1(int v1,int v2)
{
  v1=v1+v2;
  v2=v1-v2;
  v1=v1-v2;
  printf("the values after swapping are v1=%d,v2=%d\n",v1,v2);//printing the values after swapping
}
void swap2(int v1,int v2)
{
	int temp;//temporary variable
	temp=v1;
	v1=v2;
	v2=temp;
	printf("the values after swapping are v1=%d,v2=%d\n",v1,v2);//printing the values after swapping
}
void swap3(int *p1,int *p2)//p1,p2 pointers to the values v1&v2
{
	int temp;//temporary variable
	printf("%d %d",*p1,p1);
	temp=*p1;
	*p1=*p2;
	*p2=temp;
	printf("the values after swapping are v1=%d,v2=%d\n",*p1,*p2);//printing the values after swapping
}




	
