// sortarray01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct test
{
	char input[20];
	char output[20];
}testDB[7]={
	{"000111","000111"},
	{"111100","001111"},
	{"10101","00111"},
	{"0000","0000"},
	{"1111","1111"},
	{NULL,NULL},
	{"",""}
};


void compute(char *a)
{
    int l,i=0,j;
    l=strlen(a);
    j=l-1;
    while(1)
    {
      while(a[i]=='0'&&i<l-1)
       i++;
      while(a[j]=='1')
       j--;
      if(i<j)
      {
       a[i]='0';
       a[j]='1';
      }
      else 
           break;
    }   
}
void testsortarray01()
{
	int i;
	for(i=0;i<7;i++)
	{
        compute(testDB[i].input);
		if(strcmp(testDB[i].input,testDB[i].output)==0)
			printf("PASSED\n");
		else
			printf("FAILED\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
  testsortarray01();
   return 0;
}


