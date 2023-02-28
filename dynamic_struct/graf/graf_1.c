#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int value;
	int visited;
}Node;

typedef struct{
	int size;
	Node** list;
	int** matrix;
}Graf;

Graf* init_graf(){
	Graf* a=(Graf*)calloc(sizeof(Graf),1);
	a->list=NULL;
	a->matrix=NULL;
	return a;
}

Node* init_node(int a){
	Node* x=(Node*)calloc(sizeof(Node),1);
	x->value=a;
	x->visited=0;
	return x;

}
void push_node(int* arr, int size_f, Graf* a,int **matrix_f){
	a->size=size_f;
	(a->list)=(Node**)calloc(sizeof(Node*),size_f);
	for(int i=0;i<size_f;++i){
		*((a->list)+i)=init_node( *(arr+i) );
	}	
	a->matrix=matrix_f;
}

void depth_travle_buf(Node* a,Graf *b,int curs){
	if(a->visited==1){
		return;
	}
	a->visited=1;
	printf("%d ",a->value);
	for(int i=0;i<b->size;++i){
		if( *((*(b->matrix+curs))+i) ){
			depth_travle_buf( *((b->list)+i),b,i );
		}
	}
}

void depth_travle(Graf* a){
	if(a->size==0){printf("graf empty \n");}
	for(int i=0;i<a->size;++i){
		depth_travle_buf(*((a->list)+i),a,i);
	}	
	printf("\n");
	
}

int main (int* argc, char** argv){
	int** arr=(int**)calloc(sizeof(int*),6);
	for(int i=0;i<6;++i){
		*(arr+i)=(int*)calloc(sizeof(int),6);
	}	
	for(int i=0;i<6;++i){
		for(int d=0;d<6;++d){
			scanf("%d",(*(arr+i))+d);
		}
	}
	for(int i=0;i<6;++i){
		printf("{");
		for(int d=0;d<6;++d){
			printf("%d, ",*((*(arr+i))+d));
		}
		printf("}\n");
	}
	Graf* graf=init_graf();
	int x[6]={0,1,2,3,4,5};
	push_node((int*)x, 6, graf,arr);
	depth_travle(graf);
	
	return 0;
}











