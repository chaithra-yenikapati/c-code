// reversing_array_of_structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
struct input_person{
	char name[20];
	int age;
};

void reverse_array_of_structures(struct input_person* test_input,int count)
{
	struct input_person temp;
	int i=0,j=count-1;
	for(i=0;i<j;i++,j--)
	{
		temp=test_input[i];
		test_input[i]=test_input[j];
		test_input[j]=temp;
	}
}
struct input_person* take_input(int n)
{
	struct input_person* person_array=(struct input_person*)malloc(n*sizeof(struct input_person));
	for(int i=0;i<n;i++)
	{
		printf("Enter the name of person %d (max length 20 characters):",i+1);
		scanf("%s",person_array[i].name);
		printf("Enter the age of person %d :",i+1);
		scanf("%d",&person_array[i].age);
		if(person_array[i].age<0||person_array[i].age>100)
		{
			printf("Re-enter valid age of the person %d :",i+1);
			scanf("%d",&person_array[i].age);	
		}
	}
	return person_array;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int number;
	printf("Enter the number of persons:");
	scanf("%d",&number);
	struct input_person* input = take_input(number);
	reverse_array_of_structures(input,number);
	printf("The reversed array of structures is:\n");
	printf("Name\t\t Age\n");
	for(int i=0;i<number;i++)
	{
		printf("%s\t\t %d\n\n",input[i].name,input[i].age);
	}
	return 0;
}

