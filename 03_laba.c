#include <stdio.h> 

#include <stdlib.h> 

#include <stdbool.h>

#include <string.h>

typedef struct node

{

	int data;

	struct node * lev;

	struct node * prav;

	struct node * rod;

} node;

typedef struct tree

{

	struct node * root;

	int count;

} tree;

void init(tree * t)

{

	struct tree * new_tree = malloc(sizeof new_tree);

	new_tree->root = NULL;

	new_tree->count = 0;

	t = new_tree;

}

int poisk(tree* t, int value, node* n)

{

	struct node * node2;

	node2 = t->root;

	if (t->root == NULL) {

		return 1;

	}

	while (1) {

		if (node2 == NULL) {

			return 1;

		}

		else if (node2->data == value) {

			n->data = node2->data;

			n->lev = node2->lev;

			n->prav = node2->prav;

			n->rod = node2->rod;

			return 0;

		}

		else if (value > node2->data) {

			node2 = node2->prav;

		}

		else {

			node2 = node2->lev;

		}

	}

	return 1;

}

int insert(tree* t, int value)

{

	struct node * n, ** nodenode, *last_node = NULL;

	struct node * en;

	en = malloc(sizeof * en);

	int error = poisk(t, value, en);

	if (error == 0) {

		return 1;

	}

	nodenode = &t->root;

	n = t->root;

	while (1) {

		if (n == NULL) {

			n = *nodenode = malloc(sizeof * n);

			if (n != NULL) {

				n->data = value;

				n->lev = NULL;

				n->prav = NULL;

				n->rod = last_node;

				t->count++;

				return 0;

			}

			else {

				return 2;

			}

		}

		last_node = n;

		if (value > n->data) {

			nodenode = &n->prav;

			n = n->prav;

		}

		else {

			nodenode = &n->lev;

			n = n->lev;

		}

	}

	return 0;

}

int depth(struct node * n, int deep) {

	if (n == NULL) {

		return deep;

	}

	int depth1 = depth(n->lev, deep + 1);

	int depth2 = depth(n->prav, deep + 1);

	return (depth1 > depth2) ? depth1 : depth2;

}

void printNode(struct node * n, int current, int deep, int first) {

	if (current == deep) {

		if (first > 0) {

			printf(" ");

		}

		if (n == NULL) {

			printf("_");

		}

		else {

			printf("%d", n->data);

		}

	}

	else if (n != NULL) {

		printNode(n->lev, current + 1, deep, first);

		printNode(n->prav, current + 1, deep, first + 1);

	}

	else {

		printNode(n, current + 1, deep, first);

		printNode(n, current + 1, deep, first + 1);

	}

}

void print(struct node * n)

{

	int m = depth(n, 0);

	for (int i = 1; i <= m; i++) {

		printNode(n, 1, i, 0);

		printf("\n");

	}

}

void printTree(struct tree * t)

{

	print(t->root);

}

void print1(struct node * n)

{

	int m = depth(n, 0);

	int flag_tree = 0;

	for (int i = 1; i <= m; i++) {

		if (flag_tree > 0) {

			printf(" ");

		}

		else {

			flag_tree++;

		}

		printNode(n, 1, i, 0);

	}

}

void print2(struct tree * t)

{

	node * a[15];

	int ab = 0;

	node * write[15];

	int wb = 0;

	node * n = t->root;

	while (wb < t->count) {

		while (n != NULL) {

			wb++;

			if (n->prav != NULL) {

				ab++;

				a[ab] = n->prav;

			}

			write[wb] = n;

			n = n->lev;

		}

		n = a[ab];

		ab -= 1;

	}

	int flag_tree = 0;

	for (int i = 1; i <= wb; i++) {

		if (flag_tree > 0) {

			printf(" ");

		}

		else {

			flag_tree++;

		}

		printf("%d", write[i]->data);

	}

	printf("\n");

}

void print3(struct node * n, int flag_tree)

{

	if (n->lev != NULL) {

		print3(n->lev, flag_tree + 1);

	}

	if (n->prav != NULL) {

		print3(n->prav, flag_tree + 1);

	}

	printf("%d", n->data);

	if (flag_tree > 0) {

		printf(" ");

	}

}

int main() {

	struct tree * t = malloc(sizeof t);

	init(t);

	for (int i = 0; i < 7; i++) {

		int a;

		scanf("%d", &a);

		insert(t, a);

	}

	print3(t->root, 0);

	printf("\n");

	return 0;

}
