// remove_duplicate_chars.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

bool *state_array=(bool*)malloc(26*sizeof(bool));

bool is_lower(char x)
{
	if(x>=97&&x<=122)
		return true;
	return false;
}

bool is_upper(char x)
{
	if(x>=65&&x<=90)
		return true;
	return false;
}

void remove_dups(char* input)
{
	for(int i=0;i<26;i++)
		state_array[i]=false;
	int read,write,value;
	for(read=0,write=0;input[read]!='\0';read++)
	{
		if(is_lower(input[read]))
			value=97;
		else if(is_upper(input[read]))
			value=65;
		else
		{
			value=-1;
			break;
		}
		if(state_array[input[read]-value]==false)
		{
			input[write++]=input[read];
			state_array[input[read]-value]=true;
		}
	}
	if(value!=-1)
		input[write]='\0';
	else
	{
		printf("\nInvalid input");
		exit(0);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char* input=(char*)malloc(30*sizeof(char));
	printf("Enter a string:");
	scanf("%s",input);
	remove_dups(input);
	printf("\nThe modified input after removing the duplicates is: %s",input);
	return 0;
}

