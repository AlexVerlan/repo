#include <stdio.h>
#include <stdlib.h>

struct stack{
	
	int number;
	int arr[100];
};
void  push(struct stack* a,int b){
	a->number=(a->number)+1;
	if(a->number>=100){
		--(a->number);
		printf("\n|ERROR STACK ODERFLOW|\n");
	}else{
		a->arr[a->number]=b;
	}
	
}

int pop(struct stack *a){
	--(a->number);
	if(a->number<-1){
		++(a->number);
		printf("\n|ERROR STACK IS EMPTY|\n");
	}else{
		return(a->arr[a->number+1]);
	}	
	
}

int peek(struct stack* a){
	if(a->number<=-1){
		printf("\n|ERROR STACK IS EMPTY|\n");
	}else{
		return (a->arr[a->number]);
	}

}

int main (int* argc,char**argv){
	struct stack a;
	a.number=-1;

	printf("pop(a)=%d\n",pop(&a));

	printf("peek(a)=%d\n",peek(&a));

	for(int i=0; i<10;++i){
		push(&a,(rand()%100));
	}

	for(int i=0;i<10;++i){
		printf("[%d]=%d ",i,a.arr[i]);
	}	
	printf("\n");

	printf("pop(a)=%d\n",pop(&a));

	printf("peek(a)=%d\n",peek(&a));

	for(int i=0;i<10;++i){
		printf("%d pop(a)=%d\n",i,pop(&a));
	}
	
}
