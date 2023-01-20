#include <stdio.h>
#include <stdlib.h>
void merge(int* arr,int size){//size=20 при 20 элементах массива 
	
	if(size<=1)return;

	int l=size/2;
	int r=size-l;

	int* arr_l=(int*)calloc(sizeof(int),l);
 	int* arr_r=(int*)calloc(sizeof(int),r);

	int i=0;

	for(;i<l;++i){
		arr_l[i]=arr[i];
	}

	for(int x=0;i<size;++x,++i){
		arr_r[x]=arr[i];
	}

	merge(arr_l,l);
	merge(arr_r,r);
	//____________

	int x=0,y=0;

	while(x<l&&y<r){
		if(arr_l[x]<arr_r[y]){
			arr[x+y]=arr_l[x];
			++x;
		}else{
			arr[x+y]=arr_r[y];
			++y;
		}
	}
	while(x<l){
		
		arr[x+y]=arr_l[x];
		++x;
	}
	
	while(y<r){
		arr[x+y]=arr_r[y];
		++y;	
	}
	return;
	
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
	merge((int*)arr,20);
	for(int i=0;i<20;++i){
		printf("arr[%d] = %d ",i,arr[i]);
	}
	return 0;
}