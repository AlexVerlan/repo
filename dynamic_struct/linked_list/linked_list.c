#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
	struct node* next;
	struct node* prev;	
}node;

typedef struct {
	int size;
	node*head;
	node*tail;	
	
}list;

list* init(){
	list*a=(list*)calloc(sizeof(list),1);
	a->size=0;
	a->head=NULL;
	a->tail=NULL;
	return a;	
}

void push_front(list* a,int d){

	node* buf=(node*)calloc(sizeof(node),1);
	
	if(a->size==0){
		a->tail=buf;
	}
	node*aaa=a->head;
	if(aaa!=NULL){aaa->next=buf;}
	buf->prev=a->head;
	
	a->head=buf;

	buf->value=d;	
	buf->next=NULL;

	a->size+=1;
}

void push_back(list*a,int d){
	node* buf=(node*)calloc(sizeof(node),1);	

	if(a->size==0){
		a->head=buf;
	}
	node*aaa=a->tail;
	if(aaa!=NULL){aaa->prev=buf;}
	
	buf->next=a->tail;
	
	a->tail=buf;
	
	buf->value=d;	
	buf->prev=NULL;
	
	a->size+=1;
}

node* pop_front(list*a){
	node* buf;
	buf=a->head;
	if(buf!=NULL){
		node*aaa=buf->prev;
		aaa->next=NULL;
		a->head=buf->prev;
		a->size-=1;
		if(a->size==0){
			a->tail=NULL;
		}
		if(a->size==1){
			a->tail=buf;
		}
	}
	return buf;
}

node* pop_back(list*a){
	node*buf;
	buf=a->tail;
	if(buf!=NULL){
		node* aaa=buf->next;
		aaa->prev=NULL;
		a->tail=buf->next;
		a->size-=1;
		if(a->size==0){
			a->head=NULL;
		}
		if(a->size==1){
			a->head=buf;
		}
	}
	return buf;
}

void print_node(node*a){
	if(a==NULL){
		printf("[]");
		return;
	}
	printf("[%d]",a->value);	
}

void print_list(list* a){
	node*buf=a->tail;
	while(buf!=NULL){
		print_node(buf);
		printf(" ");
		buf=buf->next;
	}	
	printf("size=%d\n",a->size);
}

int main(int* argc,char**argv){
	list*ls;
	ls=init();
	print_list(ls);	

	push_front(ls,1);
	print_list(ls);	

	push_back(ls,10);
	print_list(ls);
	
	push_front(ls,20);
	print_list(ls);	
	
	push_back(ls,30);
	print_list(ls);

	pop_front(ls);
	pop_back(ls);
	print_list(ls);		
	
}




















