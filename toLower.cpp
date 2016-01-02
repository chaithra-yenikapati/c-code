#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

struct test {
	char input[15];
	char output[15];
} testDB[7] = { {"",""},
                {NULL,NULL},
				{"hEllO123","hello123"},
				{"HellO!@#","hello!@#"},
				{"HELLO","hello"},
				{"hello","hello"},
                {"Hello w  orld","hello w  orld"}
            };

void toLower(char* input)
{
	int i;
	for(i=0;input[i]!='\0';i++)
	     if(input[i]>='A'&&input[i]<='Z')
		     input[i]=input[i]+32;
	

}

void testCases()
{
	for(int i=0; i<7; i++) 
	{
		toLower(testDB[i].input);
		if(strcmp((testDB[i].input), testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}