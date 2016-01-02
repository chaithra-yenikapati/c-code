// phone_mapping.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
struct test{
	char input[30];
	char output[30];
}testDB[5]={
	{"adgjmptw","23456789"},
	{"a b c","2 2 2"},
	{"a!@d","2!@3"},
	{"",""},
	{NULL,NULL}
};

void phone_mapping(char* input)
{
	for(int i=0;input[i]!='\0';i++)
	{
		switch(input[i])
		{
		case 'a':case 'b':case'c':
			input[i]='2';
			break;
		case 'd':case 'e': case 'f':
			input[i]='3';
			break;
		case 'g':case 'h': case 'i':
			input[i]='4';
			break;
		case 'j':case 'k':case'l':
			input[i]='5';
			break;
		case 'm':case 'n':case'o':
			input[i]='6';
			break;
		case 'p':case 'q':case'r':case's':
			input[i]='7';
			break;
		case 't':case 'u':case'v':
			input[i]='8';
			break;
		case 'w':case 'x':case'y':case 'z':
			input[i]='9';
			break;
		default:
			break;
		}
	}
}

void testcases()
{
	for(int i=0;i<5;i++)
	{
		phone_mapping(testDB[i].input);
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

