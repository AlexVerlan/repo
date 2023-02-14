//1. Описать очередь с приоритетным исключением
//2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
//Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main, а также функции, 
//необходимые для работы приоритетной очереди и перевода систем счисления

#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int value;
	int indx;
	struct queue* second_point;	
}queue;

void push (queue* a,int alfa_value,int alfa_indx){
	
	queue* buf=a;
	while(a->second_point!=NULL){
		a=a->second_point;
	}
	queue* beta=(queue*)calloc(sizeof(queue),1);
	a->second_point=beta;
	beta->value=alfa_value;
	beta->indx=alfa_indx;
	beta->second_point=NULL;	
}

int pop(queue*a){
	queue* buf_a=a;

	queue*buf_a_second_point;

	int buf=a->indx;
		
	while(a->second_point!=NULL){

		buf_a_second_point=a->second_point;
		if(buf<buf_a_second_point->indx){
			buf=buf_a_second_point->indx;
			buf_a=a;
		}
		a=buf_a_second_point;
	}
	
	buf_a_second_point=buf_a->second_point;
	buf=buf_a_second_point->value;
	
	buf_a->second_point=buf_a_second_point->second_point;
	return buf;	
	
}

int main(int* argc,char** argv){
	queue a;
	a.value=1;
	a.indx=1;
	a.second_point=NULL;
	push(&a,2,2);	
	push(&a,3,3);	
	push(&a,4,4);		
	push(&a,5,5);	
	push(&a,0,0);	
	queue*buf=&a;
	while(buf!=NULL){
		printf("value=%d indx=%d\n",buf->value,buf->indx);
		buf=buf->second_point;
	}
	printf("\n\n");
	pop(&a);
	buf=&a;
	while(buf!=NULL){
		printf("value=%d indx=%d\n",buf->value,buf->indx);
		buf=buf->second_point;
	}
	printf("\n\n");
	pop(&a);
	buf=&a;
	while(buf!=NULL){
		printf("value=%d indx=%d\n",buf->value,buf->indx);
		buf=buf->second_point;
	}
	
	return 0;
}