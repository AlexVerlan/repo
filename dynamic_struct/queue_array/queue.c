#include <stdio.h>
#include <stdlib.h>

#define T int
#define SIZE 10
int start=0;
int end =-1;
int val=0;	


T queue[SIZE];

void enqueue(T a){
	if(++val>SIZE){
		--val;
		printf("\n|ERROR QUEUE OVERFLOW|\n");
	
	}else{
		++end;
		end=end%SIZE;
	
		queue[end]=a;
	}	
}

T dequeue(){
	if(val<=0){
		printf("\n|ERROR QUEUE IS EMPTY|\n");
	}else{
		T a=queue[start];
		start=(start+1)%SIZE;
		--val;
		return a;		
	}
}
int main(int*argc,char** argv){
	for(int i=0;i<9;++i){
		enqueue(rand()%100);	
	}
	for(int i=0;i<9;++i){
		printf("[%d]=%d  ",i,queue[i]);
	}
	printf("\n");
	for(int i=0;i<2;++i){
		enqueue(rand()%100);	
	}
	for(int i=0;i<10;++i){
		printf("[%d]=%d  ",i,queue[i]);
	}
	printf("\n");
	for(int i=0;i<5;++i){
		printf("%d ",dequeue());	
	}
	printf("\n");
	for(int i=0;i<5;++i){
		enqueue(rand()%100);	
	}
	for(int i=0;i<10;++i){
		printf("[%d]=%d  ",i,queue[i]);
	}
	
	return 0;	
}
