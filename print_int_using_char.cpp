// print_int_using_char.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void printc(int);

int _tmain(int argc, _TCHAR* argv[])
{
	
	int int_input;
	char* char_output;
	printf("enter a value\n");
	scanf("%d",&int_input);
	printc(int_input);
	return 0;
}
void printc(int input)
{
	char c[10];
	int i=0;
	if(input>9)
	{
		while(input>0)
		{
			c[i]=(input%10)+48;
			input=input/10;
			i++;
		}
		for(i=i-1;i>=0;i--)
			printf("%c",c[i]);
	}
	else
	{
		c[0]=input+48;
		printf("%c",c[0]);
	}
}


