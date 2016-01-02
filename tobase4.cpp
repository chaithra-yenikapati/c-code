// tobase4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
char* tobase4(char *c);
struct test {
	char input[20];
	char output[20];
} testDB[6] = { 
	            {"NULL","NULL"},
		        {"10","2"},
				{"10101","111"},
                {"12345","12345"},
                {"1 0 0 1","1 0 0 1"},
                {"234^%$","234^%$"}
            };
void testCases()
{
	char *output=(char*)malloc(20*sizeof(char));
	for(int i=0; i<7; i++) {
		output=tobase4(testDB[i].input);
		printf("%s",output);
		if(strcmp(output,testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
char* tobase4(char *input)
{
	char *res=(char*)malloc(30*sizeof(char));
	int l=strlen(input),i,j=0;
	if(l%2==0)
	{
	     for(i=0;i<l;i++)
	     {
		     if(input[i]=='0'||input[i]=='1')
			 {
				 res[j]=(((toascii(input[i])-48)*2));
				 i++;
				 res[j]=(res[j]+(toascii(input[i])-48))+48;
				 j++;
		      }
			 else 
				 return input;
		 }
		 res[j]='\0';
		 return res;
	}
	else
	{
		res[j++]=48+(toascii(input[l-1])-48);
		for(i=1;i<l-1;i++)
		{
			if(input[i]=='0'||input[i]=='1')
			{
				 res[j]=(((toascii(input[i])-48)*2));
				 i++;
				 res[j]=(res[j]+(toascii(input[i])-48))+48;
				 j++;
			}
			 else 
				 return input;
		}
		res[j]='\0';
		return res;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

