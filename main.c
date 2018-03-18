/*
 * main.c
 * Author: giorgio
 */

#include<stdio.h>
#include<stdlib.h>

typedef unsigned short int Boolean;

#define TRUE 1
#define FALSE 0

struct record {
	float key;
	float value;
};

struct list {
	int value;
	struct list *next_ptr;
};

void init(struct list **ptrptr);
void funzione(struct record *V, struct list **ptrptr, float target, int N);
void pre_insert(struct list**ptrptr, int value);
void visit(struct list *ptr);
void suf_insert(struct list ** ptrptr, int value);

int main() {
	int N, i;
	float target;
	struct record *V;
	struct list *ptrptr;

	printf("Inserire dimensione vettore \n");
	scanf("%d", &N);

	V = (struct record*) malloc(N * sizeof(struct record));

	for (i = 0; i < N; i++) {
		printf("Inserire valore in posizione %d nella lista \n", i+1);
		scanf("%f", &V[i].value);
	};

	printf("Inserire valore da ricercare \n");
	scanf("%f", &target);

	init(&ptrptr);

	funzione(V, &ptrptr, target, N);

	visit(ptrptr);

	return 0;
}

void init(struct list **ptrptr) {
	*ptrptr = NULL;
}

void funzione(struct record *V, struct list **ptrptr, float target, int N) {
	int i;

	for (i = 0; i < N; i++) {
		if (V[i].value == target) {									
			printf("Valore uguali in posizione %d\n", i + 1);
			suf_insert(ptrptr, i + 1);								
		} else {
			printf("Valore diverso in posizione %d \n", i + 1);
		}
	}

}

void pre_insert(struct list ** ptrptr, int value)					
{
	struct list * tmp_ptr;

	tmp_ptr = *ptrptr;
	*ptrptr = (struct list *) malloc(sizeof(struct list));
	(*ptrptr)->value = value;
	(*ptrptr)->next_ptr = tmp_ptr;
}

void visit(struct list *ptr)										
{

	while (ptr != NULL) {
		printf("%d ", ptr->value);
		ptr = ptr->next_ptr;
	}
}
void suf_insert(struct list ** ptrptr, int value)					

{
	while (*ptrptr != NULL) {
		ptrptr = &((*ptrptr)->next_ptr);
	}
	pre_insert(ptrptr, value);
}
