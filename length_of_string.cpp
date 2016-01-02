// length_of_string.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include<malloc.h>
int length(char *);
struct teststub
{
	char *input;
	int length;
	int returnlength;
}test[8]={
	      {"abcd",4},//the string contains only letters
		  {"hello  hi",9}, //the string contains spaces
          {"1234",4}, //the string contains numbers
          {"@#$%",4}, //the string contains spaecial characters
          {"",0}, //if is a null string
          {"',.",3},//if the string contains double quotes and single quotes
		  {NULL,NULL},
		  {"",0}
         }; 
int _tmain(int argc, _TCHAR* argv[])
{
    for(int i=0;i<8;i++)
	{
		test[i].returnlength=length(test[i].input);
		if(test[i].returnlength==test[i].length)
			printf("passed\n");
		else
			printf("failed\n");
	}
	return 0;
}
int length(char *input)
{
	int i,length=0;
	if(input==NULL)
		return NULL;
	for(i=0;input[i]!='\0';i++)
		length++;
	return length;
}



