#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
void removeDigits(char *c);
struct test {
	char input[20];
	char output[20];
} testDB[12] = {  
	            {"ABC123","ABC"},
		        {"12a34b56c","abc"},
                {"1Ab C2","Ab C"},
                {"123",""},
                {"",""},
                {"a1B2c","aBc"},
                {"a b c","a b c"},
                {"!@#$","!@#$"},
                {"A!1@2b","A!@b"},
                {"    ","    "},
		{"1a2b345CDef&8(&*","abCDef&(&*"},
				{NULL,NULL}
            };
void testCases()
{
	for(int i=0; i<12; i++) 
	{
		removeDigits(testDB[i].input);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
void removeDigits(char *input_str)
{
	int i,read=0,write=0;//i:index ptr;read:read variable; write: write variable
    for(read=0;input_str[read]!='\0';)
	{
		if(input_str[read]>='0'&&input_str[read]<='9')
		  read++;		
		else 
		{
			input_str[write]=input_str[read];
			read++;
			write++;
		}
	}
	  input_str[write]='\0';
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}