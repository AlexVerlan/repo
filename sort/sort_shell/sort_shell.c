#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int*b){
		int buf;
		buf=*a;
		*a=*b;
		*b=buf;
	}

void sort_shell (int* arr,int size){
		int buf=size/2;
		while(buf>=1){
			for(int i=0;i<buf;++i){
				for(int x=(i+buf);x<size;x+=buf){
					if(arr[x]<arr[x-buf]){
						swap(arr+x,arr+(x-buf));
					}
				}
				
			}
			buf/=2;			
			
		}
	
	}

int main(int* argc, char** argv){
	int arr[20];
	for(int i=0;i<20;++i){
		arr[i]=rand()%30;
	}
	for(int i=0;i<20;++i){
		printf("[%d]=%d ",i,arr[i]);
	}
	printf("\n_______\n");
	sort_shell((int*)arr,20);
	for(int i=0;i<20;++i){
		printf("arr[%d] = %d ",i,arr[i]);
	}
	return 0;
}