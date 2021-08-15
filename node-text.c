#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int date;
	struct node *pNext;
};

struct node *Creat_Node(int);
void Ergodic(struct node *);
void insert_tail(struct node *const pH,struct node *new);
void insert_head(struct node *const pH,struct node *new);
//main函数------------------------------------------------
int main(){
	struct node *const pHeader=Creat_Node(0);
	
	pHeader->pNext=Creat_Node(11);
	pHeader->pNext->pNext=Creat_Node(22);
	pHeader->pNext->pNext->pNext=Creat_Node(33);
	insert_tail(pHeader,Creat_Node(44));
	insert_head(pHeader,Creat_Node(55));
	insert_head(pHeader,Creat_Node(58));
	Ergodic(pHeader);
	return 0;
}
//函数的定义------------------------------------------------
struct node *Creat_Node(int n){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	if(NULL==p){
		printf("malloc error\n");
		return NULL;
	}
	bzero(p,sizeof(struct node));
	p->date=n;
	p->pNext=NULL;	
	return p;
}

void Ergodic(struct node *pH){
	struct node *pFind=pH;
	int cnt=1;
	while(NULL!=pFind->pNext){
		pFind=pFind->pNext;
		printf("node %d:	    %d\n",cnt,pFind->date);
		cnt++;
	}
	pH->date=cnt-1;
	printf("total node: %d\n",pH->date);
}

void insert_tail(struct node * const pH,struct node *new){
	struct node *pFind=pH;
	while(NULL!=pFind->pNext){
		pFind=pFind->pNext;
	}
	pFind->pNext=new;
}

void insert_head(struct node *const pH,struct node *new){
	new->pNext=pH->pNext;
	pH->pNext=new;
}