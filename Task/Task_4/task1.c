#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int value;	
	struct Node** list;
	int size;
	int visited;
}Node;

typedef struct{
	Node**list;
	int size;
	int** matrix;
	

}Graf;



void node_init(Node*a,int value_f,int size_f,Node** list_f ){
	a->visited=0;
	a->size=size_f;
	a->value=value_f;
	(a->list)=calloc(size_f,sizeof*a->list);
	for(int i=0;i<size_f;++i){
		*(a->list+i)=*(list_f+i);
	}
}

Graf* graf_init(int* arr_f,int size_f,int** matrix_f){
	Graf* a=(Graf*)calloc(sizeof(Graf),1);

	a->size=size_f;

	a->matrix=(int**)calloc(sizeof(int*),size_f);
	for(int i =0;i<size_f;++i){
		*(a->matrix+i)=(int*)calloc(sizeof(int),size_f);
		for(int d=0;d<size_f;++d){
			*((*(a->matrix+i))+d)=*((*(matrix_f+i))+d);
		}
	}

	a->list=(Node**)calloc(sizeof(Node*),size_f);
	for(int i=0;i<size_f;++i){
		*(a->list+i)=(Node*)calloc(sizeof(Node),1);
	}

	for(int i=0;i<size_f;++i){
		*(a->list+i)=(Node*)calloc(sizeof(Node),1);
	}

	Node** buf;
	int sr;
	int sr_b;
	int* arr=(int*)calloc(sizeof(int),size_f);
	

	printf("\n");
	for(int i=0;i<size_f;++i){
		printf("[%d]-%p ",i,*(a->list+i));
	}
	printf("\n");

	for(int i=0;i<size_f;++i){
		
		sr=-1;
		sr_b=0;
		free(buf);
		for(int d=0;d<size_f;++d){
			*(arr+d)=0;
		}
		

		for(int d=0;d<size_f;++d){
			if( *( (*(matrix_f+i)) +d) ){
				++sr;
				*(arr+d)+=(1+d);
			}
		}
		
		buf=(Node**)calloc(sizeof(Node*),sr);
		
		for(int d=0;d<size_f;++d){
			if( *(arr+d) ){
				*(buf+sr_b)=*((a->list)+d);
				++sr_b;
			}
		}
	
		node_init(*(a->list+i),*(arr_f+i),sr+1,buf );

	}

	return a;
}
void node_print( Node* a){
	printf("p=%p v=%d size=%d\nlist- ",a,a->value,a->size);
	for(int i=0;i<a->size;++i){
		printf("%p ",*(a->list+i));	
	}
		
}

void graf_print(Graf* a){
	printf("size g=%d\nmatrix-\n",a->size);
	for(int i=0;i<a->size;++i){
		for(int d=0;d<a->size;++d){
			printf(" %d ", *((*(a->matrix+i))+d) );
		}
		printf("\n");
	}
	printf("list->\n");
	for(int i=0; i<a->size;++i){
		node_print(*(a->list+i));
		printf("\n");
		printf("\n");
	}
	
}
void graf_free(Graf* a){
	for(int i=0;i<a->size;++i){
		free((a->list+i));
		
	}
	free(a);	
}

void node_stack(Node*a){
	if (a->visited){
		return;
	}
	a->visited=1;
	for(int i=0;i<a->size;++i){
		node_stack(*(a->list+i));
	}
	printf("\n");
	node_print(a);

}

void graf_stack(Graf*a){
	for(int i=0;i<a->size;++i){
		node_stack(*(a->list+i));
		printf("\n");
	}	
}


int main(int* argc,char**argv){
	FILE* file=fopen("matrix.txt","r");
	int arr[14]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int** matrix=(int**)calloc(sizeof(int*),14);
	for(int i=0;i<14;++i){
		*(matrix+i)=(int*)calloc(sizeof(int),14);	
		for(int d=0;d<14;++d){
			fscanf(file,"%d",*(matrix+i)+d);
			printf("%d ", *(*(matrix+i)+d));
		}
		printf("\n");
	}	

	printf("\n\n");
	
	Graf*a=graf_init((int*)arr, 14, matrix);
	graf_print(a);
	printf("\n_________\n");
	for(int i=0;i<3;++i){
		printf("\n");
		node_print( *((*(a->list))->list+i) );
	}

	printf("\n stack-\n");
	graf_stack(a);


	
	graf_free(a);
	
	return 0;
}


















