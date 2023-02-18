#include <stdio.h>
#include <stdlib.h>
//form_factor ( - 1, [ - 2, { - 3
//_____________________________________________
typedef struct{
	int form_factor;	
	struct Bracket* prev;
	
}Bracket;

typedef struct{
	Bracket* head;		
}Stack;
//_____________________________________________

Stack* init(){
	Stack* a=(Stack*)calloc(sizeof(Stack),1);	
	a->head=NULL;
	return a;
}


void push(Stack* a,int form_factor_buf){
	Bracket* buf=(Bracket*)calloc(sizeof(Bracket),1);
	buf->form_factor=form_factor_buf;
	buf->prev=a->head;
	a->head=buf;
}

void pop(Stack* a,int form_factor_buf,int* curs){
	if(a->head==NULL){
		*curs=0;
		return;
	}
	Bracket* buf=a->head;
	if(buf->form_factor!=form_factor_buf){
		*curs=0;
		return;
	}
	a->head=buf->prev;	
	
}


void test (char* arr, int size){
	Stack*a=init();
	
	int curs=1;
		
	
	
	
	for(int i=0;i<size;++i){
		printf("[%d] %c\n",i,arr[i]);
		
		switch(arr[i]){
			case '(':
				push(a,1);
				break;
			case '[':
				push(a,2);
				break;
			case '{':
				push(a,3);
				break;
			case ')':
				pop(a,1,&curs);
				break;
			case ']':
				pop(a,2,&curs);
				break;
			case '}':
				pop(a,3,&curs);
		}



		if(curs==0){
			printf("\n|ERROR|\n");
			return;
		}
	
	}
	if(a->head!=NULL){
		printf("\n|ERROR|\n");
		return;
	}
	printf("\n|OK|\n");
	return;
}


int main(int* argc, int** argv){
	char a[20]="([{}])";
	test((char*)a,14);	
	return 0;
	
}


















