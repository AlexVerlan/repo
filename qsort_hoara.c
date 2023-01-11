#include <stdio.h>
#include <stdlib.h>

void qsort_hoara(int* arr,int size){
	for(int i=0;i<size+1;++i){
		printf("arr[%d] = %d ",i,arr[i]);
	}
	printf("\n_______\n");
	if(size<1)return;
	int mid=arr[(size)/2];
	int l=0,r=size,buf=0;
	printf("mid=%d",mid);
	while(l<r){
		while(arr[l]<mid)++l;
		while(arr[r]>mid)--r;
		if(l<r){
			buf=arr[l];
			arr[l]=arr[r];
			arr[r]=buf;
			++l,--r;
		}
	}
	getchar();
	printf("l= %d r=%d",l,r);
	qsort_hoara(arr,r);
	qsort_hoara(arr+l,size);
	


}

int main(int* argc, char** argv){
	int arr[20];
	for(int i=0;i<20;++i){
		arr[i]=rand()%10;
	}
	for(int i=0;i<20;++i){
		printf("arr[%d] = %d ",i,arr[i]);
	}
	printf("\n_______\n");
	qsort_hoara((int*)arr,19);
	for(int i=0;i<20;++i){
		printf("arr[%d] = %d ",i,arr[i]);
	}
	return 0;
}


