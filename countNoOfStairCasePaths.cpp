// testNoOfStairCasePaths.cpp : Defines the entry point for the console application.
// purpose: to find the number of ways to climb the given number of steps

/* SPEC: if the number of steps is negative or 0, the output is 0 number of ways */
#include "stdafx.h"
#include "stdlib.h"
struct test {
	int no_of_steps;
	int no_of_paths;
} testDB[5] ={ {-1,0},   // the no_of_steps  is negative
				{0,0},   // the no_of_steps is 0
				{1,1},   // the no_of_steps is 1
				{2,2},   // the no_of_steps is 2
				{6,13}}; // the no_of_steps is greater than 2

int countPaths(int no_of_steps)
{
	if(no_of_steps<=0)
		return 0;
	if(no_of_steps==1)
		return 1;
	if(no_of_steps==2)
		return 2;
	else
		 return countPaths(no_of_steps-1)+countPaths(no_of_steps-2);
}
void testCases()
{
	for(int i=0; i<5; i++) {
		if(countPaths(testDB[i].no_of_steps)==testDB[i].no_of_paths) printf("%d  PASSED\n",i+1); else printf("%d  FAILED\n",i+1);
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}