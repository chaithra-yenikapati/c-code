// str_binarytoint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "math.h"
int binarytoint(char *);
struct test
{
	char input[30];
	int output;
}testDB[6]={{"1000",8},
            {"",0},
            {NULL,0},
            {"0000",0},
            {"1111",15},
             {" &  ",-1}
           };
void testcases()
{
	int i,integer_value;
	for(i=0;i<6;i++)
	{
		integer_value=binarytoint(testDB[i].input);
		printf("%d",integer_value);
		if(testDB[i].output==integer_value)printf("PASSED\n");else printf("FAILED\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}
int binarytoint(char *input)
{
	int integer_value=0,i,l;
	l=strlen(input);
	for(i=l-1;i>=0;i--)
	{
	  if(input[i]=='1'||input[i]=='0')
	  {
		if(input[i]=='1')
			integer_value=integer_value+pow(2.0,l-i-1);
	  }
	  else 
		  return -1;
	}
	return integer_value;
}