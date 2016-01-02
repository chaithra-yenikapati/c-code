// left_shift,right_shift.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
void reverse(int *input,int strt,int end)
{
	int m=(strt+end)/2,temp;
	for(;strt<=m;strt++,end--)
	{
		temp=input[strt];
		input[strt]=input[end];
		input[end]=temp;
	}
}
void left_shift(int *input,int size)
{
	int n;
	printf("enter the no of positions to be shifted\n");
	scanf("%d",&n);
	if(n>size||n<0)
	{
		printf("invalid position\n");
		return;
	}
	else
	{
		reverse(input,0,n-1);
		reverse(input,n,size-1);
		reverse(input,0,size-1);
	}
	printf("\nafter left shift,the array is:\n");
	for(int i=0;i<size;i++)
		printf("%d\t",input[i]);
}
void right_shift(int* input,int size)
{
	int n;
	printf("enter the no of positions to be shifted\n");
	scanf("%d",&n);
	if(n>size||n<0)
	{
		printf("invalid position\n");
		return;
	}
	else
	{
		reverse(input,0,size-n-1);
		reverse(input,size-n,size-1);
		reverse(input,0,size-1);
	}
	printf("\nafter right shift,the array is:\n");
	for(int i=0;i<size;i++)
		printf("%d\t",input[i]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int *input,choice,size,n;
	printf("enter your choice\n1.Left shift\n2.Right shift\n");
	scanf("%d",&choice);
	printf("enter the array size\n");
	scanf("%d",&size);
	input=(int*)malloc(size*sizeof(int));
	printf("enter the array values\n");
	for(int i=0;i<size;i++)
		scanf("%d",&input[i]);
	if(choice==1)
		left_shift(input,size);
	if(choice==2)
		right_shift(input,size);
	return 0;
}

