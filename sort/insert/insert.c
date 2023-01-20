#include <stdio.h>
#include <stdlib.h>

void insert(int* arr, int size){
	int buf;
	for(int i=1; i<size;++i){
		buf=arr[i];
		int x=i-1;
		while(arr[x]>buf&&x>=0){
			int sw=arr[x];
			arr[x]=arr[x+1];
			arr[x+1]=sw;
			--x;
		}
	}		
}

int main(int* argc, char** argv){
	int arr[20];
	for(int i=0;i<20;++i){
		arr[i]=rand()%10;
	}
	for(int i=0;i<20;++i){
		printf("[%d]=%d ",i,arr[i]);
	}
	printf("\n_______\n");
	insert((int*)arr,20);
	for(int i=0;i<20;++i){
		printf("arr[%d] = %d ",i,arr[i]);
	}
	return 0;
}