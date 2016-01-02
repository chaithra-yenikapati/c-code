// string_swapping.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void swap_strings(char *string1,char *string2)
{
	int i=0,flag=0;
	char temp;
	while(1)
	{
		if(string1[i]=='\0'&&string2[i]=='\0')
			break;
		if(string1[i]!='\0'&&string2[i]!='\0')
		{
			temp=string1[i];
			string1[i]=string2[i];
			string2[i++]=temp;
		}
		else if(string2[i]=='\0')
		{
			if(flag!=2){
				flag=2;
				string2[i]=string1[i];
				string1[i++]='\0';
			}
			else
				string2[i]=string1[i++];
		}
		else if(string1[i]=='\0')
		{
			if(flag!=1)
			{
				flag=1;
				string1[i]=string2[i];
				string2[i++]='\0';
			}
			else
				string1[i]=string2[i++];
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int max_len,i;
	char *string1,*string2;
	printf("enter the max length of the two strings\n");
	scanf("%d",&max_len);
	string1=(char*)malloc(max_len*sizeof(char));
	string2=(char*)malloc(max_len*sizeof(char));
	printf("enter the two strings to be swapped\n");
	scanf("%s %s",string1,string2);
	swap_strings(string1,string2);
	printf("%s,%s",string1,string2);
	return 0;
}

