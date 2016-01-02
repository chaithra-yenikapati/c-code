// fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int fibonacci_1_way(int,int,int );
int fibonacci_2_way(int );

int _tmain(int argc, _TCHAR* argv[])
{
	int n,i;
	printf("enter the limit\n");
	scanf("%d",&n);
	//calling one way code
	printf("Oneway recursive result is:\n");
	i=fibonacci_1_way(n,0,1);
	printf("\nTwo way result is:\n");
	//calling two way code
	for(i=1;i<=n;i++)
		printf("%d\t",fibonacci_2_way(i));
	return 0;
}
//code for one way recursion
int fibonacci_1_way(int n,int i,int j)
{
	if(n>0)
		{
			printf("%d\t",i);
	        return fibonacci_1_way(n-1,j,i+j);
	    }
	else return 1;
}
//code for two way recursion
int fibonacci_2_way(int n)
{
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else if(n>2)
		return fibonacci_2_way(n-1)+fibonacci_2_way(n-2);
}