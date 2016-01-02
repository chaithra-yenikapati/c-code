// stringpalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include <cstdlib>
bool ispalindrome(char*);
struct test
{
	char input[20];
	bool output;
}testDB[6]={
	{"madam",true},
	{"1 0 1 0 1",true},
	{"chaithra",false},
	{"!@#$",false},
	{"   ",true},
	{"",true}
};
void testcases()
{
	int i;
	bool flag;
	for(i=0;i<6;i++)
	{
		flag=ispalindrome(testDB[i].input);
		if(flag==testDB[i].output)
			printf("PASSED\n");
		else
			printf("FAILED\n");
	}
}
bool ispalindrome(char* str)
{
   int i,j,flag=true;
   for(i=0,j=(strlen(str)-1);i<=j;i++,j--)
   {
     if(str[i]!=str[j]) 
     {
         flag =false; 
     }
   }
   return flag;
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
    system("PAUSE");
	return 0;
}

