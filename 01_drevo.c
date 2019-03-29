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

} node;

typedef struct tree

{

struct node * root; // указатель на корень дерева

int count; // количество узлов в дереве

} tree;

void init(tree * t)

{

struct tree * new_t = malloc(sizeof new_t);

new_t->root = NULL;

new_t->count = 0;

t = new_t;

}

int find(tree* t, int value, node* n)

{

struct node * a;

a = t->root;

if (t->root == NULL){

return 1;

}

while (1){

if (a == NULL) {

return 1;

} else if (a->data == value){

n->data = a->data;

n->left = a->left;

n->right = a->right;

n->parent = a->parent;

return 0;

} else if (value > a->data){

a = a->right;

} else {

a = a->left;

}

}

return 1;

}

int insert(tree* t, int value)

{

struct node * n, ** b, * last_n = NULL;

struct node * e_n;

e_n = malloc(sizeof * e_n);

int err = find(t, value, e_n);

if (err == 0){

return 1;

}

b = &t->root;

n = t->root;

while (1){

if (n == NULL) {

n = *b = malloc(sizeof * n);

if (n != NULL){

n->data = value;

n->left = NULL;

n->right = NULL;

n->parent = last_n;

t->count++;

return 0;

} else {

// no memory

return 2;

}

}

last_n = n;

if (value > n->data){

b = &n->right;

n = n->right;

} else {

b = &n->left;

n = n->left;

}

}

return 0;

}

int _remove(tree* t, int value){

node * n = t->root;

if (t->root == NULL){

return 1;

}

while (1){

if (n == NULL) {

break;

return 1;

} else if (n->data == value){

break;

} else if (value > n->data){

n = n->right;

} else {

n = n->left;

}

}

//n->data = 5;

if ((n->left == NULL) && (n->right == NULL)){

if (n->parent->right->data == n->data){

n->parent->right = NULL;

} else {

n->parent->left = NULL;

}

} else if (n->right == NULL){

*n = *n->left;

} else if (n->left == NULL){

*n = *n->right;

} else {

//int min = n->left;

//int max = n->right;

node * search = n->right;

int min_value;

node *min;

while (1){

if (search == NULL) {

break;

} else {

min = search;

min_value = search->data;

search = search->left;

}

}

n->data = min->data;

n = min;

if ((n->left == NULL) && (n->right == NULL)){

if (n->parent->right->data == n->data){

n->parent->right = NULL;

} else {

n->parent->left = NULL;

}

} else if (n->right == NULL){

*n = *n->left;

} else {

*n = *n->right;

}

}

t->count--;

//free(n);

return 0;

}

int deepness(struct node * n, int deep){

if (n == NULL){

return deep;

}

int d1 = deepness(n->left, deep + 1);

int d2 = deepness(n->right, deep + 1);

return (d1 > d2) ? d1 : d2;

}

void printNode(struct node * n, int flow, int deep, int perv){

//printf("flow: %d, deep: %d\n", flow, deep);

if (flow == deep){

if (perv > 0){

printf(" ");

}

if (n == NULL){

printf("_");

} else{

printf("%d", n->data);

}

} else if (n != NULL){

printNode(n->left, flow + 1, deep, perv);

printNode(n->right, flow + 1, deep, perv + 1);

} else {

printNode(n, flow + 1, deep, perv);

printNode(n, flow + 1, deep, perv + 1);

}

}

void print(struct node * n)

{

int m = deepness(n, 0);

for (int i = 1; i <= m; i++){

printNode(n, 1, i, 0);

printf("\n");

}

}

void printTree(struct tree * t)

{

print(t->root);

}

void dump(struct node * n){

if (n != NULL){

printf("%d ", n->data);

dump(n->left);

dump(n->right);

} else {

//printf("_ ");

}

}

int removeMin(node* n){

if (n->left == NULL){

n = n->right;

}

while(1){

if (n->left == NULL){

if ((n->left == NULL) && (n->right == NULL)){

if (n->parent->right->data == n->data){

n->parent->right = NULL;

} else {

n->parent->left = NULL;

}

} else if (n->right == NULL){

*n = *n->left;

} else {

*n = *n->right;

}

return n->data;

} else {

n = n->left;

}

}

}

int rotateRight(tree * t, node *x){

node * y = x->left;

if ((y != NULL) && (x != NULL)){

x->left = y->right; // step 2

if (y->right != NULL){

y->right->parent = x; // step 3

}

y->parent = x->parent; // step 4

if (x->parent != NULL){

if (x->parent->left == x){

x->parent->left = y;

} else {

x->parent->right = y;

} // step 5

}

t->root = y;

y->right = x;

x->parent = y; // step 6

return 0;

} else {

return 1;

}

}

int rotateLeft(tree * t, node *x){

node * y = x->right;

if ((y != NULL) && (x != NULL)){

x->right = y->left; // step 2

if (y->left != NULL){

y->left->parent = x; // step 3

}

y->parent = x->parent; // step 4

if (x->parent != NULL){

if (x->parent->right == x){

x->parent->right = y;

} else {

x->parent->left = y;

} // stetp 5

}

t->root = y;

y->left = x;

x->parent = y; // step 6

return 0;

} else {

return 1;

}

}

int main(){

struct tree * t = malloc(sizeof t);

init(t);

for (int i = 0; i < 4; i++){

int a;

scanf("%d", &a);

insert(t, a);

}

printTree(t);

for (int i = 0; i < 3; i++){

int a;

scanf("%d", &a);

insert(t, a);

}

printTree(t);

int m1;

scanf("%d", &m1);

struct node * n;

n = malloc(sizeof * n);

find(t, m1, n);

if (n->parent != NULL){

printf("%d ", n->parent->data);

} else {

printf("_ ");

}

if (n->left != NULL){

printf("%d ", n->left->data);

} else {

printf("_ ");

}

if (n->right != NULL){

printf("%d\n", n->right->data);

} else {

printf("_\n");

}

int m2;

scanf("%d", &m2);

struct node * a;

a = malloc(sizeof * a);

int err = find(t, m2, n);

if (err == 1){

printf("-\n");

} else {

if (a->parent != NULL){

printf("%d ", a->parent->data);

} else {

printf("_ ");

}

if (a->left != NULL){

printf("%d ", a->left->data);

} else {

printf("_ ");

}

if (a->right != NULL){

printf("%d\n", a->right->data);

} else {

printf("_\n");

}

}

int m3;

scanf("%d", &m3);

_remove(t, m3);

printTree(t);

while (rotateLeft(t, t->root) != 1);

printTree(t);

while (rotateRight(t, t->root) != 1);

printTree(t);

printf("%d\n", t->count);

printf("-\n");

return 0;

}
