#include <stdio.h>
#include <stdlib.h>

void qsort_hoara(int* arr,int size){
	int l=0,r=size;
	int mid=arr[size/2];
	int buf;
	do{
		while(arr[l]<mid)++l;
		while(arr[r]>mid)--r;
		if(l<=r){
			buf=arr[l];
			arr[l]=arr[r];
			arr[r]=buf;
			--r;
			++l;
		}
	}while(l<=r);
	if(r>0)qsort_hoara(arr,r);
	if(l<size)qsort_hoara(arr+l,size-l);
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
	qsort_hoara((int*)arr,19);
	for(int i=0;i<20;++i){
		printf("arr[%d] = %d ",i,arr[i]);
	}
	return 0;
}


