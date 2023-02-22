#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
	int* arr;
	int size;
	int last_elem;
}Heap;

void insert_heap(Heap* a, int buf){
	if(!(a->last_elem)){
		*(a->arr)=buf;
		a->last_elem+=1;
		return;
	}
	if((a->last_elem)==a->size){
		printf("heap overflow");
		return;
	}
	*((a->arr)+a->last_elem)=buf;
	int i=a->last_elem;
	int g;
	while(i>0){
		if(i%2){
			g=(i-1)/2;	
		}else{
			g=(i-2)/2;
		}
		if( *((a->arr)+i) <=  *((a->arr)+g)){
			i=0;
		}else{
			*((a->arr)+i)=*((a->arr)+g);
			*((a->arr)+g)=buf;
			i=g;
		}
	}
	a->last_elem+=1;
}

Heap* init(int size){
	Heap* a=(Heap*)calloc(sizeof(Heap),1);
	a->arr=(int*)calloc(sizeof(int),size);
	a->size=size;
	a->last_elem=0;	
	return a;
}

void print_heap(Heap* a){
	if(a->last_elem==0){
		printf("heap is empty\n");
		return;
	}
	for(int i=0;i<a->last_elem;++i){
		printf("[%d] ",*((a->arr)+i));
	}	
	printf("\n");
}
void print_heap2(Heap*a){
	if(a->last_elem==0){
		printf("heap is empty\n");
		return;
	}
	int i=0;
	int b=0;
	int x=0;
	do{
		i=pow(2,b);
		for(int d=0;d<i&&x<a->last_elem;++d){
			printf("[%d] ",*((a->arr)+x) );
			++x;
		}
		printf("\n");
		++b;	
	}while(i<a->last_elem&&x<a->last_elem);
	
}

int pop(Heap* a){
	int buf=*(a->arr);
	int ggg;
	*(a->arr)=*((a->arr)+(a->last_elem)-1);
	a->last_elem-=1;
	int i=0;
	int l;
	int r;
	while(i<a->last_elem){
		l=i*2+1;
		r=i*2+2;
		
		if(l>=a->last_elem||r>=a->last_elem){
			return buf;
		}
		if( *((a->arr)+i) < *((a->arr)+l) &&  *((a->arr)+i) < *((a->arr)+r) ){
			if(*((a->arr)+l)>=*((a->arr)+r)){
				ggg=*((a->arr)+l);
				*((a->arr)+l)=*((a->arr)+i);
				*((a->arr)+i)=ggg;
				i=l;
			}else{
				ggg=*((a->arr)+r);
				*((a->arr)+r)=*((a->arr)+i);
				*((a->arr)+i)=ggg;
				i=r;
			}
		}else{
			if(*((a->arr)+l)>*((a->arr)+i)){
				ggg=*((a->arr)+l);
				*((a->arr)+l)=*((a->arr)+i);
				*((a->arr)+i)=ggg;
				i=l;
			}else{
				if(*((a->arr)+r)>*((a->arr)+i)){
					ggg=*((a->arr)+r);
					*((a->arr)+r)=*((a->arr)+i);
					*((a->arr)+i)=ggg;
					i=r;
				}else{
					return buf;
				}
			}
			
		}
	}
	
}

int main(int* argc,char** argv){
	Heap* a=init(40);
	print_heap2(a);
	int* buf=(int*)calloc(sizeof(int),40);
	for(int i=0;i<40;++i){
		buf[i]=rand()%100;
	}
	printf("buf=");
	for(int i=0;i<40;++i){
		printf("[%d] ",buf[i]);
	}
	printf("\n");
	printf("\n");
	for(int i=0;i<40;++i){
		insert_heap(a,buf[i]);
	}
	print_heap(a);
	printf("\n");
	print_heap2(a);
	
	for(int i=0;i<40;++i){
		buf[i]=pop(a);
	}
		printf("\n");
	printf("buf=");
	for(int i=0;i<40;++i){
		printf("[%d] ",buf[i]);
	}
	printf("\n");
	
}



