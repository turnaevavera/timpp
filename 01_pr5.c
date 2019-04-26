#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

typedef struct node 
{
    int data;
    struct node * left;
struct node * right;
struct node * parent;
}
node;

typedef struct tree{
    struct node * root;
    
int count;
}
tree;

void init(tree* t)
{
    struct tree * new_t = malloc(sizeof new_t);
new_t->root = NULL;
new_t->count = 0;
t = new_t;
}

int find(tree* t, int value, node* n)
{
struct node * b;
b = t->root;
if (t->root == NULL)
{
    return 1;
}
    
while (1)
	{
if (b == NULL) 
	{
    return 1;
	} 
else if (b->data == value)
	{
    n->data = b->data;
    n->left = b->left;
    n->right = b->right;
    n->parent = b->parent;
    return 0;
	} 
  else if (value > b->data)
	{
    b = b->right;
	} 
    else 
		{
	b = b->left;
		}
	}
return 1;
}

int insert(tree* t, int value)
{
struct node * n, ** bb, * pr_str = NULL;
struct node * e_n;
e_n = malloc(sizeof * e_n);
int error_tree = find(t, value, e_n);
if (error_tree == 0)
	{
    return 1;
	}
bb = &t->root;
n = t->root;
while (1)
	{	
    if (n == NULL) 
		{
        n = * bb = malloc(sizeof * n);
		if (n != NULL)
			{
        n->data = value;
        n->left = NULL;
        n->right = NULL;
        n->parent = pr_str;
        t->count++;
        return 0;
			} 
	else
				{
				return 2;
				}	
		}
    
pr_str = n;
if (value > n->data)
	{
    bb = &n->right;
    n = n->right;
	}
else 
		{
    bb = &n->left;
    n = n->left;
		}
    }
    return 0;
}

int deepness(struct node * n, int deep)
{
if (n == NULL)
	{
    return deep;
	}
int d1 = deepness(n->left, deep + 1);
int d2 = deepness(n->right, deep + 1);
return (d1 > d2) ? d1 : d2;
}

void printNode(struct node * n, int flow, int deep, int first)
{
if (flow == deep)
	{
    if (first > 0)
		{
        printf(" ");
        }
if (n == NULL)
	{
    printf(" ");
	} 
else
{
printf("%d", n->data);
}
	} 
	else if (n != NULL)
	{
    printNode(n->left, flow + 1, deep, first);
    printNode(n->right, flow + 1, deep, first + 1);
	} 
	else
		{
printNode(n, flow + 1, deep, first);
printNode(n, flow + 1, deep, first + 1);
		}
}

void print(struct node * n)
{
    
int m = deepness(n, 0);
for (int i = 1; i <= m; i++)
	{
    printNode(n, 1, i, 0);
    printf("\n");
    }
}

void printTree(struct tree * t)
{
print(t->root);
}

void print_obh1(struct node * n)
{
int m = deepness(n, 0);
int xex = 0;
for (int i = 1; i <= m; i++)
	{
if (xex > 0)
		{
		printf(" ");
		} 
	else
	{xex++;}
printNode(n, 1, i, 0);
	}
}

int main()
{
struct tree * t = malloc(sizeof t);
init(t);
for (int i = 0; i< 7; i++)
	{
    int a;
    scanf("%d", &a);
    insert(t, a);
    }
print_obh1(t->root);
printf("\n");
return 0;
}
