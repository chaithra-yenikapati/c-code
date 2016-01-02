// string_to_linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
struct node{
	int node_value;
	struct node *next_node;
};
struct node* head=NULL;

struct node* insert_in_to_linkedlist(char c,struct node* current)
{
	if(c<'0' || c>'9')
		return NULL;
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->node_value=c-'0';
	temp->next_node=NULL;
		if(head==NULL)
		{
			head=temp;
			current=head;
		}
		else
		{	
			current->next_node=temp;
			current=current->next_node;
		}
	return current;
}
void print_list()
{
	if (head==NULL)
	{
		printf("empty list\n");
	    return;
	}
	while(head!=NULL)
	{
		printf("%d\t",head->node_value);
		head=head->next_node;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char *input_str;
	struct node* current=head;
	int i;
	printf("enter the input string\n");
	input_str=(char *)malloc(sizeof(char)*10000);
	scanf("%s",input_str);
	if(input_str!="")
		for(i=0;input_str[i]!='\0';i++)
		{
			current=insert_in_to_linkedlist(input_str[i],current);
			if(current==NULL)
			{
				head=NULL;
				break;
			}
		}
	print_list();
	return 0;
}


	