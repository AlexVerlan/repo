#include <stdio.h>
#include <stdlib.h>

void counting_sort(int* arr,int size, int buf){
	int arr_sort[buf];
	for(int i=0;i<buf;++i){
		arr_sort[i]=0;
	}
	for(int i=0;i<size;++i){
		arr_sort[arr[i]]+=1;
	}
	for(int i=0;i<buf;++i){
		printf("arr_sort[%d] = %d ",i,arr_sort[i]);
	}
	printf("\n_______\n");
	int y=0;
	for(int i=0;i<buf;++i){
		for(int x=0;x<arr_sort[i];++x){
		arr[y]=i;
		++y;}
	}
}
int main(int* argc, char** argv){
	int arr[20];
	for(int i=0;i<20;++i){
		arr[i]=rand()%5;
	}
	for(int i=0;i<20;++i){
		printf("[%d]=%d ",i,arr[i]);
	}
	printf("\n_______\n");
	counting_sort((int*)arr,20,5);
	for(int i=0;i<20;++i){
		printf("arr[%d] = %d ",i,arr[i]);
	}
	return 0;
}