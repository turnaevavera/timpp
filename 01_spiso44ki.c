#include <stdio.h>
#include<stdlib.h>

struct node { 
 	int value;
	struct node *next;
} node;

struct list{		
	struct node* first;	
} list;

int isEmpty(struct list* spis)
{
	return spis->first==NULL;
}

struct node* find(struct list* spis,int value)
{
	struct node *tmp=spis->first;
	while(tmp->value!=value){
		if(tmp->next!=NULL)
			tmp=tmp->next;
		else
			return 0;
	}
	return tmp;
}

void init(struct list* spis,int value)
{
	struct node* tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->value=value;
	tmp->next=NULL;
	spis->first = tmp;
}

int push_back(struct list* spis, int x)
{
	if(isEmpty(spis)==1)
		init (spis,x);
	else
	{
		struct node* tmp = (struct node*)malloc(sizeof(struct node));
		tmp->value=x;
		tmp->next=NULL;
		struct node* temp = spis->first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=tmp;
	}
	return 0;
}

int push_front(struct list* spis,int x) 
{
	if(isEmpty(spis)==1)
		init (spis,x);
	else
	{
		struct node *tmp = (struct node*)malloc(sizeof(struct node));
		tmp->value=x;
		tmp->next=spis->first;
		spis->first=tmp;
	}
	return 0;
}

int clear(struct list* spis)
{
	if(isEmpty(spis)==1)
	{
		struct node *tmp=spis->first;
		struct node *temp=NULL;
		while(tmp!=NULL)
		{
			temp=tmp->next;
			free(tmp);
			tmp=temp;
		}
		spis->first=NULL;
	}
}

void _remove(struct list* spis, struct node *tmp){
	if(tmp!=NULL){
		if (tmp==spis->first)
			spis->first=tmp->next;
		else
		{
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			temp=spis->first;
			while(temp->next!=tmp)
				temp=temp->next;
			temp->next = tmp->next;
		}
		free(tmp);
	}
}

int removeFirst(struct list* spis, int x)
{
	struct node* element = find(spis,x);
	if (element!=NULL){
		_remove(spis,element);
		return 0;
	}
	return -1;
}

int insertAfter	(struct list* spis,int num, int value)
{
	struct node *temp = malloc(sizeof(node));
	temp->value=value;

	struct node* tmp = spis->first;
	struct node* prev_tmp = spis->first;
	
	for (int i = 1;i<num+1;i++)
	{
		prev_tmp=tmp;
		tmp=tmp->next;
		if(tmp==NULL) 
			return -1;
	}
	prev_tmp->next=temp;
	temp->next=tmp;
	return 0;   
}

void print(struct list* spis)
{
	struct node* tmp=spis->first;
	while(tmp->next!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->next;
	}
	printf("%d\n", tmp->value);
}

int main()
{
	int n,a;
    struct list* list=(struct list*)malloc(sizeof(struct list));	
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(list,a);
	}
	print(list);
	
	int k[3];
        scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		if(find(list,k[i])!=NULL)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");

	int m;
	scanf("%d",&m);
	push_back(list,m);
	print(list);

	int t;
	scanf("%d",&t);
	push_front(list,t);
	print(list);

	int j,x;
	scanf("%d%d",&j,&x);
	insertAfter(list,j,x);
	print(list);

	int z;
	scanf("%d",&z);
	removeFirst(list,z);
	print(list);

	clear(list);
	return 0;
}
