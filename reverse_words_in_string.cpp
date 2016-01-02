// reverse_words_in_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
void reverse_string(char*input,int strt,int end)
{
	int m=(strt+end)/2;
	char temp;
	for(strt;strt<=m;strt++,end--)
	{
		temp=input[strt];
		input[strt]=input[end];
		input[end]=temp;
	}
}
void reverse_words_order(char *input_str)
{
	int i=0,strt=i,end=0,flag=0;
     for(i=0;input_str[i]!='\0';i++)
	 {
		if(input_str[i]!=' ')
			end=i;
		else
		{
			reverse_string(input_str,strt,end);
			strt=i+1;
			flag=1;
		}
	
	 }
	 if(flag>0)
	 {
		 reverse_string(input_str,strt,i-1);
		reverse_string(input_str,0,i-1);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char *input_str=(char*)malloc(sizeof(char)*50);
	printf("enter the string:\n");
	gets(input_str);
	reverse_words_order(input_str);
	printf("the reverse order of the words in the given string is:  %s",input_str);
	return 0;
}

