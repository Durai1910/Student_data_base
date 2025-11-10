#include<stdio.h>
#include "header.h"
#include<string.h>
#include<stdlib.h>

extern struct st *hptr;
void remove_node()
{
	char op;
	printf("\n");
	printf("\t*         Choose one to search...          *\n");
	printf("\t*------------------------------------------*\n");
	printf("\t|   R/r   |   Remove by Roll_no...         |\n");
	printf("\t|---------|--------------------------------|\n");
	printf("\t|   N/n   |   Remove by Name...            |\n");
	printf("\t*------------------------------------------*\n");
	printf("\n\tEnter your choice...\t");
	scanf(" %c",&op);
	printf("\n");
	ST*ptr=hptr;
	if((op=='R')||(op=='r'))
	{
		int n;
		roll_no();
		printf("\tThe given Roll_no's Data is deleted...\n");
		return;
	}
	else if((op=='N')||(op=='n'))
	{
		char s[30];
		printf("\n\tEnter which Name's Data to remove...");
		scanf(" %s",s);
		printf("\n\n");
		while(ptr!=0)
		{
			if((strcmp(ptr->name,s))==0)
			{
				count++;
				temp=ptr;
			}
			ptr=ptr->next;
		}ptr=hptr;
		if(count>1)
		{
			printf("\n\tThe given name occurs more than once in the list...");
			while(ptr!=0)
			{
				if(strcmp(ptr->name,s)==0)
				{
					printf("\n\t%d\t%[^\n]\t%f",ptr->roll,ptr->name,ptr->mark);
				}
				ptr=ptr->next;
			}
			roll_no();
			printf("\tThe given Name's Data is deleted...\n");
			return;
		}
		else
		{
			if(ptr->prev==0)
					ptr->next->prev = ptr->prev;
				else if(ptr->next==0)
					ptr->prev->next = ptr->next;
				else
				{
					ptr->prev->next = ptr->next;
					ptr->next->prev = ptr->prev;
				}
				free(ptr);
				printf("\tThe given Name's Data is deleted...\n");
				return;
		}
	}
	else
	{
		printf("\tInvalid Operation...\n");
		return;
	}
	printf("\tThe given data is not in the list.....\n");
}
void roll_no()
{
	printf("\n\tEnter which Roll_no's Data to remove....");
	scanf(" %d",&n);
	printf("\n\n");
	while(ptr!=0)
	{
		if(ptr->roll==n)
		{
			if(ptr->prev==0)
				ptr->next->prev = ptr->prev;
			else if(ptr->next==0)
				ptr->prev->next = ptr->next;
			else
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			free(ptr);
			break;
		}
		else
			ptr=ptr->next;
	}
}
			



