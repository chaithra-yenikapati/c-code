 #include<stdio.h>
#include <stdlib.h>
struct list
{
int element;
struct list *next;
struct list *prev;
};
 struct list *f=NULL;
 struct list *l=NULL;
 void insert(int );              
 void display(void);
 void compute(int);
int main()
 {
  int n;
  printf("enter a number\n");
  scanf("%d",&n);
  compute(n);
  return 0;
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
   display();
  }
  void insert(int n)
  {
   struct list*p=(struct list *)malloc(sizeof(struct list));
   p->element=n;
   if(f==NULL)
   {
    f=l=p;
    p->next=NULL;
    p->prev=f->prev=l->prev=NULL;
    }
    else
    {
    l->next=p;
    p->next=NULL;
    p->prev=l;
    l=p;
    }
  }
  void display(void)
  {
   struct list *p;
   if(f==NULL)
   {
    printf("list is empty\n");
    return;
   }
   printf("list is:\n");
   if(f==l)
   {
    printf("%d\n",f->element);
    return;
   }
   for(p=l;p!=f;p=p->prev)
    printf("%d\t",p->element);

   printf("%d",f->element);
  }