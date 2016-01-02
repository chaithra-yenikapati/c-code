// string3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<malloc.h>
#include<string.h>
void testcase();
void replace(char *,char *,int );
struct tests
{
	char input1[20];  //input string 1
	char input2[10]; //input string 2
	int index;  //index from where string2 to be inserted in string1
	char output[20]; //result
	
}test[13]={{"hello","hii hi",2,"hehii hi"},  //s1.length<s2.length+pos
{"how r u","hello",6,"how r hello"},//s1.length=pos
{"hello","hii",0,"hiilo"}, //s1.length>s2.length+pos
{"hello","hiii",-1,"hello"},  //pos<0
{"hello","hiii",6,"hello"},  //pos>s1.length
{"1234","567",2,"12567"},  //string contains integer input
{"1*%^@","!##*",0,"!##*@"},  //string contain special characters
{NULL,NULL,0,NULL},  //s1 and s2 are null
{"hellosir","hii",5,"hellohii"}, //s1.length=s2.length+pos
{"hello","hiiii",0,"hiiii"},//s1.length=s2.length
{"","hiii",1,""}}; //s1 is empty
void replace(char *s1,char* s2,int x)
{
	int i,j;
	if(x<0||x>strlen(s1))
		return;
	for(i=x,j=0;s2[j]!='\0';i++,j++)
	{
		s1[i]=s2[j];
	}
}
void testcase()
{
	for(int i=0;i<13;i++)
	{
		replace(test[i].input1,test[i].input2,test[i].index);//calling function which replaces the string
		if(strcmp(test[i].input1,test[i].output)==0)
			printf("passed\n");
		else
			printf("failed\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testcase();
	return 0;
}
