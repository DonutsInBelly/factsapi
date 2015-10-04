#include<stdio.h>
#include <string.h>
#include "FactTable.h"
#include <stdlib.h>

struct _FactNode {
	char* fact;
	char* category;
	struct FactNode* next;
};

struct _CategoryNode {
	char* category;
	int count;
	struct CategoryNode* next;
};

FactNode* hashtable[100];
CategoryNode * counts;

int _hash(char* category) {
	int hasher = 0;
	char* c = category;
	while (*c != '\0') {
		hasher += *c;
		c++;
	}
	hasher = hasher%100;
	return hasher;
}
void hashPut(FactNode * fact)
{
		int hasher = _hash(fact->category);
		fact->next = hashtable[hasher];
		hashtable[hasher]=fact;
		char * cat = fact->category;
		CategoryNode * curr = counts;
		while(1)
		{
			if(strcmp(curr->category,fact->category)==0)
			{
				curr->count=curr->count+1;
				return;
			}
			if(curr->next!=NULL)
				curr = curr->next;
			else
				break;
		}
		CategoryNode * node= malloc(sizeof(CategoryNode *));
		node->category=fact->category;
		node->count = 1;
		node->next = NULL;
		curr->next= node;
}
FactNode * hashGet(char * category)
{
	int numFacts = 0;
	CategoryNode * curr = counts;
	while(curr!=NULL)
	{
		if(strcmp(curr->category,category)==0)
			{
				numFacts = curr->count;
				break;
			}
			curr = curr->next;
	}
	if(numFacts==0)
	{
		printf("Error, category not found in arraylist CategoryCount\n");
		return NULL;
	}
	int rando = rand() % numFacts+1;
	int hasher = hash(category);
	FactNode * curren = hashtable[hasher];
	while(1)
	{
		if(strcmp(curren->category,category)==0)
			rando=rando-1;
		if(rando ==0)
			return curren;
		curren = curren->next;
	}
	return NULL;
}

main() {

	FactNode** hashtable = malloc(sizeof(FactNode **));
	CategoryNode * counts = malloc(sizeof(CategoryNode *));
	
}
