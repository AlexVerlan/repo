#include <stdio.h>
#include <stdlib.h>

void swap(int* i,int*b){
	int buf;
	buf=*i;
	*i=*b;
	*b=buf;
	}
void insert_sort(int* arr,int size){
	int buf;
	for(int i=0;i<size;++i){
		buf=arr[i];
		for(int x=0;x<i;++x){
			if(arr[x]>buf){
				for(int d=i;d>x;--d){
					swap(arr+d,arr+d-1);
				}
				break;
			}
		}
	}
}

void q_sort(int* arr, int size){
	int l=0;
	int r=size-1;
	int mid=arr[size/2];
	do{
		while(arr[l]<mid){++l;}
		while(arr[r]>mid){--r;}
		
		if(l<=r){
			swap(arr+l,arr+r);
			++l,--r;
		}
	}while(l<=r);
	if(r>0){
		if(r>10){q_sort(arr,r+1);
		}else{
			insert_sort(arr,r+1);	
		}
	}
	if(l<size-1){
		if(size-1-l>10){q_sort(arr+l,size-l);
		}else{
			insert_sort(arr+l,size-l);	
		}
	}
	
	
}

int main(int* argc, char** argv){
	int arr[50];

	for(int i=0;i<50;++i){
		arr[i]=rand()%20;
	}

	for(int i=0;i<50;++i){
		printf("[%d]=%d ",i,arr[i]);
	}
	
		int asd[20];

		for(int i=0;i<20;++i){
			asd[i]=0;
		}

		for(int i=0;i<50;++i){
			++(asd[arr[i]]);
		}
	
		printf("\n");
		printf("\n_______\n");
 		for(int i=0;i<20;++i){
			printf("[%d] = %d ",i,asd[i]);
		}
	

	printf("\n_______\n");

	q_sort((int*)arr,50);

	for(int i=0;i<50;++i){
		printf("[%d] = %d ",i,arr[i]);
	}
	
	return 0;
}