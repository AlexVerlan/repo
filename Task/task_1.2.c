#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void NSD_radix_sort(int* arr, int size,int raz){

	int raz_buf=pow(10,raz);
	if (raz_buf%10){++raz_buf;}
	int arr_sort[10][size+1];
	
	for(int i=0;i<10;++i){
		for(int x=0;x<=size;++x)
			arr_sort[i][x]=0;
	}
	
	
	
	
	
		for(int i=0;i<size;++i){
			int count_raz=(arr[i])/raz_buf;
				
		
			int count_size=arr_sort[count_raz][size];
				
			arr_sort[count_raz][count_size]=((arr[i])%raz_buf);
				
			arr_sort[count_raz][size]+=1;
				
		}
	
	
	
	for(int i=0;i<10;++i){
		if((arr_sort[i][size]>1)&&raz>0)NSD_radix_sort(arr_sort[i],arr_sort[i][size],raz-1);
	}
	
	
      
	int idx=0;
	for(int i=0;i<10;++i){
		for(int x=0;x<arr_sort[i][size];++x){
			arr[idx]=0;
			arr[idx]=i*raz_buf;
			arr[idx]+=arr_sort[i][x];
			++idx;
		}
	}
			
}

void bucket_sort (int*arr,int size){
	int arr_buf[size];
	for(int i=0; i<size;++i){
		arr_buf[i]=0;
	}
	int i=0;
	for(int x=0;x<size;++x){
		if(!(arr[x]%2)){
			arr_buf[i]=arr[x];
			
			++i;
		}
	}
	for(int d=0;d<i;++d){
		printf("[%d]=%d ",d,arr_buf[d]);
	}
	printf("\n_______\n");
	
	NSD_radix_sort((int*)arr_buf,i,3);
	for(int d=0;d<i;++d){
		printf("[%d]=%d ",d,arr_buf[d]);
	}
	printf("\n_______\n");
	
	int x=0,y=0;
	while(x<size){
		if((arr[x]%2)){++x;}else{arr[x]=arr_buf[y];++x;++y;}
	}
	
}



int main(int* argc, char** argv){
	int arr[50];

	for(int i=0;i<50;++i){
		arr[i]=rand()%1000;
	}

	for(int i=0;i<50;++i){
		printf("[%d]=%d ",i,arr[i]);
	}
	
	

	printf("\n_______\n");

	bucket_sort((int*)arr,50);

	for(int i=0;i<50;++i){
		printf("[%d] = %d ",i,arr[i]);
	}
	
	return 0;
}