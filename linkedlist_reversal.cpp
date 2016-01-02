// linkedlist_reversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
void print_values(struct node*);
node* reversal(node *,node *);
struct node
{
    int node_value;
	node *link;
};
struct node *f=NULL;
struct node* insert(int n,struct node* current)
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
int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,node_value;
	struct node* current=f;
	printf("enter the no of values\n");
	scanf("%d",&n);
	printf("enter the values\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&node_value);
		current=insert(node_value,current);
	}
	printf("the given values are\n");
	print_values(f);
    f=reversal(f,NULL);
	printf("the reversed list is:\n");
	print_values(f);
	return 0;
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
 node *reversal(node *p, node *q)
{
    node *current;

    if (p == NULL)
        return q;

    current = p;
    p = p->link;
    current->link = q;

    reversal(p, current);
}
