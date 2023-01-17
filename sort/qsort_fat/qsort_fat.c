#include <stdio.h>
#include <stdlib.h>

void qsort_fat(int* arr,int size){
		int mid = arr[size];
		int l=0,r=size-1;
		int l_rav=0,r_rav=size-1;
		int buf=0;
		do{
			while(arr[l]<mid)++l;
			while(arr[r]>mid)--r;
			
			if(l<=r){
				if(arr[l]==mid){
					buf=arr[l];
					arr[l]=arr[l_rav];
					arr[l_rav]=buf;
					++l,++l_rav;
					continue;
				}
					if(arr[r]==mid){
					buf=arr[r];
					arr[r]=arr[r_rav];
					arr[r_rav]=buf;
					--r,--r_rav;
					continue;
				}
				buf=arr[l];
				arr[l]=arr[r];
				arr[r]=buf;
				--r;
				++l;
			}
		}while(l<=r);
		while(l_rav>0){
			arr[l_rav-1]=arr[r];
			arr[r]=arr[size];
			--r,--l_rav;	
		}
		while(r_rav<size){
			buf=arr[r_rav+1];
			arr[r_rav+1]=arr[l];
			arr[l]=buf;
			++l,++r_rav;	
		}
		
		if(l<size){qsort_fat(arr+l,size-l);}
		if(r>0){qsort_fat(arr,r);}
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
	qsort_fat((int*)arr,19);
	for(int i=0;i<20;++i){
		printf("arr[%d] = %d ",i,arr[i]);
	}
	return 0;
}