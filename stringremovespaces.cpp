// stringremovespaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"string.h"
#include"stdlib.h"
struct test
{
	char inputstr[30];
	char outputstr[30];
}testDB[8]={//testDB is an array of structures consisting of all possible test cases for removing spaces in the given string
	{"hello hi world        :)","hellohiworld:)"},//spaces in between characters at more than one locations
	{"    ",""},//string having all spaces
	{"    hello","hello"},//spaces before characters
	{"hello   ","hello"},//spaces after characters
	{"hello      hi","hellohi"},//spaces between characters
	{NULL,NULL},//null string
	{"1 2 3 @ # $","123@#$"},//spaces between numeric and special symbols
	{"",""},//empty string
};


//function takes a string and removes spaces present in the string
void removespaces(char *str)
{
	int i,read=0,write=0;//i:index ptr;read:read variable; write: write variable
    for(i=0;str[i]!='\0';i++)
	{
		if(str[read]==' ')
		  read++;		
		else 
		{
			str[write]=str[read];
			read++;
			write++;
		}
	}
	  str[write]='\0';
}
void testremovespaces()
{
	int i;
	for(i=0;i<8;i++)
	{
	   removespaces(testDB[i].inputstr);//calling the removespaces function with the inputstr argument
	   if(strcmp(testDB[i].inputstr,testDB[i].outputstr)==0)printf("\npassed");else printf("\nfailed");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testremovespaces();//calling the test removespaces function
    return 0;
}
