#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

typedef struct strr
{
    int data;
    struct strr * left;
  struct strr * right;
  struct strr * parent;
}
strr;

typedef struct derev
{
    struct strr * root;
  int count;
}
derev;

void init(derev* t)
{
    struct derev * new_derev = malloc(sizeof new_derev);
	new_derev->root = NULL;
    new_derev->count = 0;
    t = new_derev;
}

int find(derev* t, int value, strr* n)
{
  struct strr * b;
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

int insert(derev* t, int value)
{
  struct strr * n, ** b, * last_strr = NULL;
struct strr * en;
en = malloc(sizeof * en);
    
int error = find(t, value, en);
  if (error == 0)
  {
    return 1;
  }
  b = &t->root;
  n = t->root;
  while (1)
  {
    if (n == NULL) 
	{
      n = * b = malloc(sizeof * n);
      if (n != NULL)
	  {
        n->data = value;
        n->left = NULL;
        n->right = NULL;
        n->parent = last_strr;
        t->count++;
        return 0;
      } 
	  else 
	  {
        return 2; 
      }
    }
    last_strr = n;  
    if (value > n->data)
	{
      b = &n->right;
      n = n->right;
    }
	else
	{
      b = &n->left;
      n = n->left;
    }
  }
  return 0;
}

int deepness(struct strr * n, int deep)
{
  if (n == NULL)
  {
    return deep;
  }
    
int d1 = deepness(n->left, deep + 1);
int d2 = deepness(n->right, deep + 1);
return (d1 > d2) ? d1 : d2;
}

void printstrr(struct strr * n, int flow, int deep, int perv)
{
  if (flow == deep)
  {
      if (perv > 0)
	  {
        printf(" ");
      } 
    if (n == NULL)
	{
      printf("_");
    }
	else
	{
      printf("%d", n->data);
    } 
  } 
  else if (n != NULL)
  {
    printstrr(n->left, flow + 1, deep, perv);
printstrr(n->right, flow + 1, deep, perv + 1);
  }
  else
	{
    printstrr(n, flow + 1, deep, perv);
	printstrr(n, flow + 1, deep, perv + 1);
	}
}

void print(struct strr * n)
{
  int m = deepness(n, 0);
  for (int i = 1; i <= m; i++)
  {
  printstrr(n, 1, i, 0);
  printf("\n");
  }
}
   
void printderev(struct derev * t)
{
    print(t->root);
}

void print_obh1(struct strr * n)
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
	{
        xex++;
    }
    printstrr(n, 1, i, 0);
  }
}   

void print_obh2(struct derev * t)
{
    strr* a[15];
int ab = 0;
strr* write[15];
int wb = 0;
strr* n = t->root;
    while (wb<t->count)
	{ 
        while (n != NULL)
		{
            wb++;
            if (n->right != NULL)
			{
                ab++;
                a[ab] = n->right;
            }
            write[wb] = n;
            n = n->left;
        }
        n = a[ab];
        ab -= 1;    
    }  
    int xex = 0;
    
    for (int i = 1; i <= wb; i++)
	{
        if (xex > 0)
		{
            printf(" ");
        } else {
            xex++;
        }
        printf("%d", write[i]->data);
    } 
  printf("\n");
}   

void print_obh3(struct strr * n, int xex)
{
    if (n->left != NULL)
	{
        print_obh3(n->left, xex + 1);
    } 
    if (n->right != NULL)
	{
        print_obh3(n->right, xex + 1);
    }
    printf("%d", n->data);
    if (xex > 0)
	{
        printf(" ");
    }   
}   

int main()
{
  struct derev * t = malloc(sizeof t);
init(t);
  for (int i = 0; i< 7; i++)
  {
    int a;
scanf("%d", &a);
insert(t, a);
  }
  print_obh3(t->root, 0);
printf("\n");
  return 0;
}
