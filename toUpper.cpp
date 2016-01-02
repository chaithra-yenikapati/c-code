// toUpper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

struct test {
	char input[20];
	char output[20];
} testDB[7] = { {"",""},
                {NULL,NULL},
				{"hEllO123","HELLO123"},
				{"HellO!@#","HELLO!@#"},
				{"HELLO","HELLO"},
				{"hello","HELLO"},
				{"Hello w  orld","HELLO W  ORLD"}
            };

void toUpper(char* input)
{
	int i;
	for(i=0;input[i]!='\0';i++)
	    if(input[i]>='a'&&input[i]<='z')
			input[i]=input[i]-32;
}


void testCases()
{
	for(int i=0; i<7; i++) {
		toUpper(testDB[i].input);
		if(strcmp((testDB[i].input), testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}






