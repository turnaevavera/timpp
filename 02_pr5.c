#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

typedef struct list
{
  int data;
  struct list * left;
  struct list * right;
  struct list * parent;
} 
list;

typedef struct tree
{
  struct list * root;   
  int count;            
} 
tree;

void init(tree * t)
{
    struct tree * new_t = malloc(sizeof new_t);
    new_t->root = NULL;
    new_t->count = 0;
    t = new_t;
}

int find(tree* t, int value, list* l)
{
  struct list * ll;
  ll = t->root;
  if (t->root == NULL)
  {
    return 1;
  }
  while (1)
  {
    if (ll == NULL) 
	{
      return 1;
    } else if (ll->data == value)
	{
      l->data = ll->data;
      l->left = ll->left;
      l->right = ll->right;
      l->parent = ll->parent;
      return 0;
    } else if (value > ll->data)
	{
      ll = ll->right;
    } else 
	{
      ll = ll->left;
    }
  }
  return 1;
}

int insert(tree* t, int value)
{
  struct list * l, ** ll, * lll = NULL;
  struct list * yes;
  yes = malloc(sizeof * yes);
  int error = find(t, value, yes);
  if (error == 0)
  {
    return 1;
  }
  ll = &t->root;
  l = t->root;
  while (1){
    if (l == NULL)
	{
      l = *ll = malloc(sizeof * l);
      if (l != NULL)
	  {
        l->data = value;
        l->left = NULL;
        l->right = NULL;
        l->parent = lll;
        t->count++;
        return 0;
      }
	  else 
	  {
        return 2; 
      }
    }
    lll = l;  
    if (value > l->data)
	{
      ll = &l->right;
      l = l->right;
    } 
	else
	{
      ll = &l->left;
      l = l->left;
    }
  }
  return 0;
}

int deepness(struct list * l, int deep)
{
  if (l == NULL)
  {
    return deep;
  }
  int d1 = deepness(l->left, deep + 1);
  int d2 = deepness(l->right, deep + 1);
  return (d1 > d2) ? d1 : d2;
}

void printList(struct list * l, int flow, int deep, int perv)
{
  if (flow == deep)
  {
      if (perv > 0)
	  {
        printf(" ");
      }
      
    if (l == NULL)
	{
      printf("_");
    } else{
      printf("%d", l->data);
    } 
  } 
  else if (l != NULL)
  {
    printList(l->left, flow + 1, deep, perv);
    printList(l->right, flow + 1, deep, perv + 1);
  } 
  else 
  {
    printList(l, flow + 1, deep, perv);
    printList(l, flow + 1, deep, perv + 1);
  }
}

void print(struct list * l)
{
  int m = deepness(l, 0);
  for (int i = 1; i <= m; i++){
    printList(l, 1, i, 0);
    printf("\n");
  }
}   

void printTree(struct tree * t)
{
    print(t->root);
}
 
void print_round3(struct tree * t)
{
    list * a[15];
    int var1 = 0;
    list * write[15];
    int var2 = 0;
    list * l = t->root;
    while (var2 < t->count)
	{ 
        while (l != NULL)
		{
            var2++;
            if (l->right != NULL)
			{
                var1++;
                a[var1] = l->right;
            }
            write[var2] = l;
            l = l->left; 
        }
        l = a[var1];
        var1 -= 1;   
    }
    int xex = 0;
    for (int i = 1; i <= var2; i++)
	{
        if (xex > 0)
		{
            printf(" ");
        } 
		else
		{
            xex++;
        }
        printf("%d", write[i]->data);
    }   
  printf("\n");
}   

int main()
{
  struct tree * t = malloc(sizeof t);
  init(t);
  for (int i = 0; i < 7; i++)
  {
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  print_round3(t);
  return 0;
}
