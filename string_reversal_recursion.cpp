// string_reversal_recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"malloc.h"

void reverse(char* input,int strt,int middle,int end)
{
	if(strt>=middle||input==NULL||input=='')
		return;
	char temp;
	temp=input[strt];
	input[strt++]=input[end];
	input[end--]=temp;
	reverse(input,strt,middle,end);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n=0,m;
	char *input;
	printf("Enter the string size\n");
	scanf("%d",&n);
	m=n/2;
	input=(char*)malloc(n*sizeof(char));
	printf("Enter a string\n");
	scanf("%s",input);
	reverse(input,0,m,n-1);
	printf("The reversed string is: %s",input);
	return 0;
}
