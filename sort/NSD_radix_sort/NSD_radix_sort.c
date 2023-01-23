#include <stdio.h>
#include <stdlib.h>


void NSD_radix_sort(int* arr, int size,int raz){
	int arr_sort[10][size+1];
	for(int i=0;i<10;++i){
		arr_sort[i][size]=0;
	}
	for(int i=0;i<size;++i){
		int count_raz=arr[i];
		for(int x=0;x<raz;++x){
			count_raz/=10;
		}
		int count_size=arr_sort[count_raz][size];
			
		int asd=1;
		for(int i=1;i<=raz;++i){
			asd*=10;
		}
		
		arr_sort[count_raz][count_size]=(arr[i]%asd);
		++arr_sort[count_raz][size];
	}
      
	for(int i=0;i<10;++i){
		if(arr_sort[i][size]>1)NSD_radix_sort(arr_sort[i],arr_sort[i][size],raz-1);
	}
	
	int idx=0;
	for(int i=0;i<10;++i){
		for(int x=0;x<arr_sort[i][size];++x){
			arr[idx]=0;
			for(int buf=1;buf<=raz;++buf){
				if(arr[idx]==0){
					(arr[idx])=1;
				}
				(arr[idx])*=10;
			}
			
			arr[idx]*=i;
			arr[idx]+=arr_sort[i][x];
			++idx;
		}
	}
			
}
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
		arr[i]=rand();
	}
	int arr_copy[20];
	for(int i=0;i<20;++i){
		arr_copy[i]=arr[i];
	}
	for(int i=0;i<20;++i){
		printf("[%d]=%d ",i,arr[i]);
	}
	printf("\n_______\n");
	for(int i=0;i<20;++i){
		printf("c[%d]=%d ",i,arr_copy[i]);
	}
	printf("\n_______\n");
	NSD_radix_sort((int*)arr,20,9);

	insert((int*)arr_copy,20);
	for(int i=0;i<20;++i){
		printf("arr_copy[%d]=%d arr[%d]=%d\n",i,arr_copy[i],i,arr[i]);
	}
	return 0;
}