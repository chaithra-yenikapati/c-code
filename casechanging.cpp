// casechanging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ctype.h"
#include "string.h"
struct test {
	char input[20];
	char output[20];
} testDB[11] = {
	            {"ABC","abc"},//string with only uppercase
				{"abc","ABC"},//string with only lowercase
                {"AbC","aBc"},//string with a mixture of uppercase and lowercase letters
                {"123","123"},//string with digits
                {"",""},//empty string
                {"a1B2c","A1b2C"},//string having combination of digits and characters
                {"a B c","A b C"},//string with spaces
                {"!@#$","!@#$"},//string with only special characters
                {"A!@b","a!@B"},//string with both specialcharacters and alphabet
                {"    ","    "},//string having only spaces
                {NULL,NULL},//null string

              };
//function to find if character is lowercase	
int islowerCase(char c)
{
	if(c>='a' && c<='z')
		return 1;
	return 0;
}
//function to find whether string is uppercase
int isupperCase(char c)
{
	if(c>='A' && c<='Z')
		return 1;
	return 0;
}
//function to change the case of a given character
void changeCase(char* input)
{
	int i;
	if(input==NULL)
		return;//NULL case
	for(i=0;input[i]!='\0';i++)
	{
		if(islowerCase(input[i]))//lowercase condition
			input[i]=toascii(input[i])-32;//conversion to uppercase
			
		else 
		{
			if(isupperCase(input[i]))//uppercase condition
				input[i]=toascii(input[i])+32;//conversion to lower case
		}
	}
}
void testCases()
{
	for(int i=0; i<11; i++) {
		changeCase(testDB[i].input);//calling changeCase function with input as argument
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();//calling the testcases function
	return 0;
}


