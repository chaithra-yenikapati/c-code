// string_length_recursion.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "malloc.h"

int str_len(char* input,int len)
{
	if(input==""||input==NULL)
		return 0;
	if(input[len]=='\0')
		return len;
	len+=1;
	str_len(input,len);
}
int main()
{
	int l;
	char* input=(char*)malloc(100*sizeof(char));
	printf("Enter a string\n");
	scanf("%s",input);
	l=str_len(input,0);
	printf("Length of the given string is: %d",l);
	return 0;
}

