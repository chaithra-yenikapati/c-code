// linked_to_5th_node.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdlib.h"
struct linked5{
	int value;
	linked5 * link1;
	linked5 * link2;
};
struct linked5* head=NULL; 

void link_to_5th_element()
{
	struct linked5* fifth_ptr=head;
	struct linked5* temp=head;
	int count=0;
	while(fifth_ptr!=NULL&&count<4)
	{
		if(fifth_ptr->link2!=NULL)
			fifth_ptr->link2=NULL;
		fifth_ptr=fifth_ptr->link1;
		count++;
	}
	if(count<4||fifth_ptr==NULL)
		return;
	while(fifth_ptr->link1!=NULL)
	{
		temp->link2 = fifth_ptr;
		temp=temp->link1;
		fifth_ptr=fifth_ptr->link1;
	}
	if(fifth_ptr->link1==NULL)
		temp->link2=fifth_ptr;
}

struct linked5* delete_list(int value)
{
	struct linked5* temp=head,*prev=head;
	while(temp!=NULL&&temp->value!=value)
	{
		prev=temp;
		temp=temp->link1;
	}
	if(temp!=NULL)
	{
		if(temp==head)
			head=head->link1;
		else
			prev->link1=temp->link1;
		link_to_5th_element();
		printf("\nValue deleted\n");
	}
	else
		printf("\nValue doesnt exist\n");
	return head;
}

void print_list()
{
	struct linked5 *temp=head;
	if(temp==NULL)
	{
		printf("list is empty");
		return;
	}
	printf("node_addr   node_value   node_link1   node_link2\n");
	while(temp!=NULL)
	{
		printf("\n%d\t\t%d",temp,temp->value);
		printf("\t\t%d\t\t%d\n",temp->link1,temp->link2);
		temp=temp->link1;
	}
	printf("\n");
}

void insert_into_sorted_list()
{
	struct linked5* temp=head,*new_node,*prev;
	int value;
			if(head==NULL)
			{
				new_node=(struct linked5*)malloc(sizeof(struct linked5));
				printf("Enter a value to be inserted:\n");
				scanf("%d",&new_node->value);
				new_node->link1=NULL;
				new_node->link2=NULL;
				head=prev=new_node;
			}
			else
			{
				printf("Enter a value to be inserted:\n");
				scanf("%d",&value);
				temp=head;
				new_node=(struct linked5*)malloc(sizeof(struct linked5));
				new_node->value=value;
				new_node->link1=NULL;
				new_node->link2=NULL;
				while(temp!=NULL&&value>temp->value)
				{
						prev=temp;
						temp=temp-> link1;
				}
				if(temp==head&&value<=temp->value)
				{
					new_node->link1=temp;
					head=new_node;
				}
				else
				{
					new_node->link1=prev->link1;
					prev->link1=new_node;
				}
}
}
void create_list()
{
	int count=0,check,value,flag=1;
	while(1)
	{
		printf("Enter your choice:\n1.Insert\n2.Delete\n3.Print the list\n\n 0.exit\n");
		scanf("%d",&check);
		switch(check)
		{
		case 1:
			insert_into_sorted_list();
			if(count>=4)
				link_to_5th_element();
			count++;
			break;
		case 2:
			if(head==NULL)
			{
				printf("List is empty\n");
				break;
			}
			else
			{
				printf("Enter a value to be deleted:");
				scanf("%d",&value);
				delete_list(value);
				break;
			}
		case 3:
			print_list();
			break;
		case 0:
			break;
		}
		if(check==0)
			break;
	}	
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	create_list();	
	exit(0);
}