#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
	struct node* second_point;
}node;

typedef struct {
	int size;
	node* head;
}list;

list* init(){
	list* ls=(list*)calloc(sizeof(list),1);
	ls->size=0;
	ls->head=NULL;	
	return ls;
}

void push(list* a,int b){
	node* new=(node*)calloc(sizeof(node),1);
	new->value=b;
	new->second_point=a->head;
	a->head=new;
	for(int i=0;i<a->size;++i){
		new=new->second_point;
	}
	new->second_point=a->head;
	a->size+=1;
}

void print_node(node*a){
	if(a==NULL){
		printf(" [] ");
	}else{
		printf(" [%d] ",a->value);
	}	
	
}

void print_list(list* ls,int a){
	node*buf=ls->head;
	for(int i=0;i<(ls->size)*a;++i){
		print_node(buf);
		buf=buf->second_point;
	}
}

int main(int* argc,char** argv){
	list* a;
	a=init();
	push(a,10);
	print_list(a,3);
	printf("\n");
	push(a,20);
	print_list(a,3);
	printf("\n");
	push(a,30);
	print_list(a,3);
	printf("\n");
		
	
}
	



