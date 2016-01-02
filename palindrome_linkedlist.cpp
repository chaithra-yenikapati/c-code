// palindrome_linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
struct node
{
    int node_value;
	node *link;
};
struct node *f=NULL;
struct node *reverse_head=NULL;
struct node * insert(int n,struct node* current)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->node_value=n;
	temp->link=NULL;
	if(f==NULL)
	{
		f=temp;
		current=f;
	}
	else
	{
		current->link=temp;
		current=current->link;
	}
	return current;
}

void print_values(struct node *p)
{
	if(p==NULL)
		printf("list is empty\n");
	else
	{
		while(p->link!=NULL)
		{
			printf("%d ->",p->node_value);
			p=p->link;
		}
		printf("%d\n",p->node_value);
	}
}
 void reversal()
{
   struct node* temp=f,*p;
   while(temp)
   {
	   p=(struct node*)malloc(sizeof(struct node));
	   p->link=NULL;
	   p->node_value=temp->node_value;
	   if(!reverse_head)
			reverse_head=p;
	   else
	   {
		   p->link=reverse_head;
		   reverse_head=p;
	   }
	   temp=temp->link;
   }
}

 void compare(struct node *p1,struct node *p2)
 {
	 while(p1!=NULL&&p2!=NULL)
	 {
		 if(p1->node_value==p2->node_value)
		 {
		 p1=p1->link;
		 p2=p2->link;
	     }
		 else 
		 {
			 printf("given linked list is not a pallindrome\n");
			 return;
		 }
	 }
	 printf("given linked list is a pallindrome\n");
 }


int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,node_value,choice;
	struct node *current=f;
	printf("enter the no of values\n");
	scanf("%d",&n);
	printf("enter the values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&node_value);
		current=insert(node_value,current);
	}
    reversal();
	compare(f,reverse_head);
	return 0;
}
