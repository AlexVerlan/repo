#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int value;
	struct Node*second_p;
}Node;

typedef struct{
	Node** arr;
	int size;
}Hesh;



void hesh_init(Hesh**a,int size_f){
	
	*a=(Hesh*)calloc(1,sizeof(Hesh));
	
	(*a)->size=size_f;
	(*a)->arr=(Node**)calloc(size_f,sizeof(Node*));
	for(int i=0;i<size_f;++i){
		*((*a)->arr+i)=NULL;
	}
}

void node_print(Node*a,int d){
	if(a==NULL){
	return;}
	else{
		printf("%d-%d ",d,a->value);
		node_print(a->second_p,d+1);
	}
}

void hesh_print(Hesh*a){
	printf("size-%d\n",a->size);
	for(int i=0;i<a->size;++i){
		printf("[%d] - ",i);
		node_print( *(a->arr+i),0 );
		printf("\n");
	}
}

void hesh_push(Hesh*a,int value_f){
	
	Node*buf=*(a->arr+value_f%a->size);
	if(buf==NULL){
		*(a->arr+value_f%a->size)=(Node*)calloc(1,sizeof(Node));
		(*(a->arr+value_f%a->size))->value=value_f;
		(*(a->arr+value_f%a->size))->second_p=NULL;
		return;
	}
	node_print(buf,0);
	
	while((buf->second_p)!=NULL){
		buf=buf->second_p;
	}
	

	buf->second_p=(Node*)calloc(1,sizeof(Node));
	buf=buf->second_p;
	buf->value=value_f;
	buf->second_p=NULL;
	printf("\n\n");
	node_print(buf,0);
	printf("\n\n");
}

int main(int* argc,char** argv){
	Hesh**a=(Hesh**)calloc(1,sizeof(Hesh*));
	
	hesh_init(a,10);
	
	
	for(int i=0;i<20;++i){hesh_push(*a,rand()%30);}
	hesh_print(*a);
	return 0;
}






















