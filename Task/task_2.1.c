//1. Описать очередь с приоритетным исключением
//2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
//Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main,
//а также функции, необходимые для работы приоритетной очереди и перевода систем счисления

#include <stdio.h>

#define SIZE 1000
int end=-1;
int stack[SIZE];

void push(a){
	if (++end>=SIZE){
		printf("\n|ERROR STACK OVERFFLOW|\n");
		--end;
	}else{
		stack[end]=a;
	}
}

int pop(){
	if(end<0){
		printf("\n|ERROR STACK IS EMPTY|\n");
	}else{
		int a=stack[end];
		--end;
		return a;	
	}
}

void dvoich(int a){
	do{
		push(a%2);
		a/=2;
	}while(a>0);	
	while(end>=0){
		printf("%d",pop());
	}	
	
}

int main(int* argc,char** argv){
	int a=888;
	printf("a=%d\n",a);
	dvoich(a);
	
	return 0;	
}

