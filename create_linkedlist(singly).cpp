// create_linkedlist(singly).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
void print_values(struct node*);
void compute(int);
node* reversal(node *,node *);
struct node
{
    int node_value;
	node *link;
};
struct node *f=NULL;
void insert(int n)
{
	struct node *current,*p;
	current=(struct node*)malloc(sizeof(struct node));
	current->node_value=n;
	current->link=NULL;
	if(f==NULL)
	{
		f=current;
	}
	else
	{
		current->link=f;
		f=current;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	printf("enter the value\n");
	scanf("%d",&n);
	compute(n);
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

void compute(int n)
 {
  int x;
  while(n>0)
  {
   x=n%10;
   insert(x);
   n=n/10;
   }
   print_values(f);
  }