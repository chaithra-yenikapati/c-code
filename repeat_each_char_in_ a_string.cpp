// repeat_each_char_in_ a_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
struct test {
	char input[20];
	int n;
	char output[20];
} testDB[7] = { 
	{"abc",3,"aaabbbccc"},
	{"a b c",2,"aa  bb  cc"},
	{"!@ a12",2,"!!@@  aa1122"},
	{"xyz",1,"xyz"},
	{"abc",-1,"abc"},
	{"",4,""},
	{NULL,5,NULL}
};

void repeat_each_char(char* input,int n)
{
	int len=strlen(input),i,j=len-1,flag=0;
	if(input==NULL||input=="")
		return;
	for(i=len*n-1;i>0&&j>=0;i--)
	{
		if(n<2)
			break;
		input[i]=input[j];
		flag++;
		if(flag==n)
		{
			flag=0;
			j--;
		}
	}
	input[len*n]='\0';
}
void testcases()
{
	for(int i=0;i<7;i++)
	{
		repeat_each_char(testDB[i].input,testDB[i].n);
		if(strcmp(testDB[i].input,testDB[i].output)==0)
			printf("test %d passed\n",i+1);
		else
			printf("test %d failed\n",i+1);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}

