// prependchar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"stdlib.h"
#include <string.h>
void prepend(char a,char *s);


struct test
{
	char input[30];
	char a;
	char output[30];
}testDB[6]={
	        {"abc",'a',"aabc"},
            {"abc",'b',"babc"},
            {"abc",'\0',"\0"},
            {"",'a',"a"},
            {NULL,'a',NULL},
            {"",'\0',""}
           };


void testcases()
{
	int i;
	for(i=0;i<6;i++)
	{
		prepend(testDB[i].a,testDB[i].input);
	    if(strcmp(testDB[i].input,testDB[i].output)==0)printf("PASSED\n");else printf("FAILED\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}
void prepend(char a,char *input)
{
	char temp=input[0],flag;
	int i;
	for(i=0;input[i]!='\0';i++)
	{
		flag=input[i+1];
		input[i+1]=temp;
		temp=flag;
	}
	input[i+1]=temp;
	input[0]=a;
}
		