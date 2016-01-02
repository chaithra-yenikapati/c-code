// 2-D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h>
#include<stdlib.h>
void readinput(char **,int,int);
void modifyinput(char **,char**,int,int);
void printres(char**,int,int);


int _tmain(int argc, _TCHAR* argv[])
{
 char **a,**res;
 int i,j,r,c,rows,cols;
 printf("enter the no of rows,columns\n");
 scanf("%d %d",&r,&c);
  a= (char**)malloc(sizeof(char)*r);
for(i=0;i<r;i++)
 a[i] = (char *)malloc(sizeof(char)*c);
 readinput(a,r,c);
 rows=2*r+1;
 cols=4*c+1;
 res = (char**)malloc(sizeof(char)*rows);
for(i=0;i<rows;i++)
 res[i] = (char *)malloc(sizeof(char)*cols+1);
 
 modifyinput(a,res,rows,cols);
 printres(res,rows,cols);
 return 0;
 }
void readinput(char **a,int r,int c)
{
	int i,j;
	printf("enter array values\n");
  fflush(stdin);
 for(i=0;i<r;i++)
 {
	 fflush(stdin);
	 for(j=0;j<c;j++)
	 {
	     scanf("%c",&a[i][j]);
	 }
 }
}
void modifyinput(char **a,char** res,int rows,int cols)
{
	int i,j;
	for(i=0;i<rows;i++)
 {
		 if(i%2==1)
		 {
			 for(j=0;j<cols-1;j++)
			 {
				 res[i][j]='|';
				 j++;
				 res[i][j]=' ';
				 j++;
				 res[i][j]=a[(i-1)/2][(j/2-1)/2];
				 j++;
				 res[i][j]=' ';
			 }
			 res[i][j++]='|';
			 res[i][j]='\0';
		 }
		 else
		 {
			 for(j=0;j<cols;j++)
			 {
				 res[i][j]='-';
			 }
			 res[i][++j]='\0';
		 }
 }
}
void printres(char** res,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%c",res[i][j]);
		printf("\n");
	}
}



