#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
	struct Node*second;
}Node;

typedef struct {
	Node* head;
	int size;
}List;

List* init(){
	List* a=(List*)calloc(sizeof(List),1);
	a->head=NULL;
	a->size=0;
	return a;
}

void push(List* a,int val){
	Node* buf=(Node*)calloc(sizeof(Node),1);
	buf->value=val;
	buf->second=NULL;
	if(a->head==NULL){
		a->head=buf;
		return;
	}
	Node*con=a->head;
	
	while((con->second)!=NULL){
		con=con->second;
	}
	con->second=buf;
	a->size+=1;	
}

void pop(List* a){
	if(a->head==NULL){return;}
	
	Node* buf=a->head;
	if(buf->second==NULL){
		a->head=NULL;
		a->size=0;
		return;
	}
	Node* buf_second=buf->second;
	while((buf_second->second)!=NULL){
		buf=buf_second;
		buf_second=buf_second->second;
	}
	buf->second=NULL;
	a->size-=1;
	return;
}

void copy(List*a,List*b){
 	Node* head_buf=a->head;
	while(head_buf!=NULL){
		push(b,head_buf->value);
		head_buf=head_buf->second;
	}	
}

void print_Node(Node*a){
	if(a==NULL){printf("[] ");}else{
		printf("[%d] ",a->value);
	}	
}

void print_List(List *a){
	if(a->head==NULL){
		printf("\n|is empty|\n");
		return;
	}
	Node*buf=a->head;
	while(buf!=NULL){
		print_Node(buf);
		buf=buf->second;
	}	
	printf("\n");
}

void sort(List*a){
	if(a->head==NULL){printf("sort");return;}
	Node* buf=a->head;
	Node* buf_second=buf->second;
	
	while(buf_second!=NULL){
		if((buf->value)>(buf_second->value)){
			printf("Not sort");
			return;
		
		}
		buf=buf_second;
		buf_second=buf->second;
	}
	printf("sort");
	
}

int main(int * argc,char* argv){
	List* a=init();
	List* b=init();
	
	for(int i=0;i<10;++i){
		push(a,i);
	}
	
	print_List(a);
	print_List(b);
	printf("\n__________________\n");
	copy(a,b);
	print_List(a);
	print_List(b);
	printf("\n__________________\n");
	for(int i=0;i<5;++i){
		pop(a);
	}
	print_List(a);
	print_List(b);
	
	push(a,1);
	print_List(a);
	sort(a);
	printf("\n__________________\n");
	for(int i=0;i<5;++i){
		pop(a);
	}
	print_List(a);
	sort(a);
	printf("\n__________________\n");	
	push(a,1);
	print_List(a);
	sort(a);
	
	printf("\n1__________________\n");	
	pop(a);
	
	pop(a);

	print_List(a);
	sort(a);
		
}


