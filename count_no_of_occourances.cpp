// count_no_of_occourances.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
int* count_no_of_occurances(char* input)
{
	int* count_array=(int*)malloc(26*sizeof(int));
	for(int i=0;i<26;i++)
		count_array[i]=0;
	for(int i=0;input[i]!='\0';i++)
	{
		if(input[i]>=97&&input[i]<=122)
			count_array[input[i]-'a']+=1;
		else if(input[i]>=65&&input[i]<=90)
			count_array[input[i]-'A']+=1;
		else
			return NULL;
		
	}
    return count_array;
}

void print_result(int* count_array)
{
	char output_string[50];
	int i,j=0;
	for(i=0;i<26;i++)
	{
		if(count_array[i]>0)
		{
			output_string[j++]='a'+i;
		    if(count_array[i]<9)
				output_string[j++]='0'+count_array[i];
			else
			{
				int value=count_array[i],k=0;
				char num[4];
				while(value>0)
				{
					num[k++]=value%10+'0';
					value=value/10;
				}
				while(k>0)
				{
					output_string[j++]=num[--k];
				}
			}
		}
	}
	output_string[j]='\0';
	printf("The resultant string is:  %s",output_string);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* input_string=(char*)malloc(50*sizeof(char));
	char *output;
	int *count_array_ptr;
	printf("enter the input string:\n");
	scanf("%s",input_string);
	count_array_ptr=count_no_of_occurances(input_string);
	if(count_array_ptr==NULL)
	{
		printf("invalid string\n");
		return 0;
	}
	print_result(count_array_ptr);
	return 0;
}

