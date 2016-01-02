// reverseintarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
void reverse(int *,int);
int _tmain(int argc, _TCHAR* argv[])
{
	int length,i,*input;
	printf("enter the array length\n");
	scanf("%d",&length);
	printf("enter the array values\n");
	input=(int*)calloc(length,sizeof(int));
	for(i=0;i<length;i++)
	   scanf("%d",&input[i]);
	reverse(input,length);
	printf("the reversed array is:\n");
	for(i=0;i<length;i++)
		printf("%d\t",input[i]);
	free(input);
	return 0;
}
void reverse(int *input,int length)
{
	int i,temp;
	for(i=0;i<length/2;i++)
	{
		temp=input[i];
		input[i]=input[length-i-1];
		input[length-i-1]=temp;
	}
}
