// stringencoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include"string.h"
#include<ctype.h>
char* stringencode(char *);
struct test
{
	char input[30];
	char output[50];
}testDB[8]=
{
	{"abc","123"},
	{"aAB","1AB"},
	{"z1b","2612"},
	{" A a @"," A 1 @"},
	{"    ","    "},
	{"",""},
	{NULL,NULL},
	{"abcdefghijklmnopqrstuvwxyz","1234567891011121314151617181920212223242526"}

};
//funtion to check if the character is a lower case
int isLowercase(char c)
{
	if(c>='a' && c<='z')
		return 1;
	return 0;

}

//encoding function
char* stringencode(char *str)
{
	char *output=(char*)calloc(50,sizeof(char));
	int i,j,temp;//loop variable

	for(i=0,j=0;str[i]!='\0';i++,j++)
	{
		if(isLowercase(str[i]))
		{
			if(toascii(str[i]>105))
			{
		    temp=toascii(str[i])-96;//logic for encoding in the form a=1,b=2... z=26.
		    output[j+1]=temp%10+48;
			output[j]=temp/10+48;
			j++;
			}
			else
			{
				output[j]=toascii(str[i])-48;
			}
        }
		else
			output[j]=str[i];
	}
	return output;
}

//test function
void teststringencode()
{
	int i;
	char *encodedoutput=(char*)calloc(30,sizeof(char));
	for(i=0;i<8;i++)
	{
		
		encodedoutput=stringencode(testDB[i].input);
		if(strcmp(encodedoutput,testDB[i].output)==0) 
			printf("PASSED\n");
		else
		    printf("FAILED\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	teststringencode();
	return 0;
}
	