#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int date;
	struct Node* second_point;
}Node;

typedef struct list{
	Node* head;
	int size;		
}list;

void init(list*a){
	a->head=NULL;
	a->size=0;
}

void push(list*a,int b){

	Node*buf=(Node*)calloc(sizeof(Node),1);
	buf->date=b;
	buf->second_point=NULL;

	Node* current=a->head;

	if(current==NULL){
		a->head=buf;
		a->size+=1;
	}else{
		while(current->second_point!=NULL){
			current=current->second_point;	
		}
		current->second_point=buf;
		a->size+=1; 
	}
}

Node* pop(list* alfa,int b){
	
	Node* second_point;
	Node* point=alfa->head;
	if(point==NULL){
		return NULL;
	}
	if(point->date==b){
		alfa->head=point->second_point;
		alfa->size-=1;
		return point;
	}else{
		while(point->second_point!=NULL){
			second_point=point->second_point;
			if(second_point->date==b){
				point->second_point=second_point->second_point;
				alfa->size-=1;
				return second_point;
			}
			point=second_point;
		}
		return NULL;	
	}
}

void print_node(Node*a){
	if(a==NULL){
		printf("[]");
		return;
	}
	printf("[%d]",a->date);	
}

void print_list(list* a){
	Node*buf=a->head;
	while(buf!=NULL){
		print_node(buf);
		printf(" ");
		buf=buf->second_point;
	}	
	printf("size=%d\n",a->size);
}

int main(int*argc,char**argv){
	list*ls=(list*)calloc(sizeof(list),1);
	init(ls);
	print_list(ls);	
	push(ls,1);
	print_list(ls);	
	push(ls,10);
	print_list(ls);	
	push(ls,20);
	print_list(ls);	
	if(pop(ls,20)==NULL){printf("\n|no|\n");}
	print_list(ls);	
	
}


