#include<stdio.h>
#include "FactTable.h"

// LL for hash table
struct _FactNode {
	char* fact;
	char* category;
	struct FactNode* next;
};

// LL that holds num facts per category
struct _CategoryNode {
	char* category;
	int count;
	struct CategoryNode* next;
};

FactNode** hashtable;
CategoryNode** counts;

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

main() {
	
	printf("%d\n", _hash("a"));
}
