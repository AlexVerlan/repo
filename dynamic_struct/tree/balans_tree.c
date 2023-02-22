#include <stdio.h>
#include <stdlib.h>
#include "print_tree.h"

/*typedef struct{
	int value;
	struct Node* left;
	struct Node* right;	
}Node;

typedef struct{
	Node* root;	
}Tree;*/

Tree* init(){
	Tree* a=(Tree*)calloc(sizeof(Tree),1);
	a->root==NULL;
	return a;	
}

void bin_tree(FILE* file,int n,Node** a){
	if(n<=0){
		return;
	}else{	
		int asd;
		*a=(Node*)calloc(sizeof(Node),1);
		fscanf(file,"%d",&asd);
		
		(*a)->value=asd;
		
		int l=n/2;
		int r=n-l-1;
		bin_tree(file,l,&((*a)->left));
		bin_tree(file,r,&((*a)->right));	
	}
}

int main(int* argc,char** argv){
	FILE*file;
	file=fopen("balance.txt","r");
	if(file==NULL){
		printf("can not openned file\n");
		return 1;
	}else{
		int i=15;
		Tree* a=init();
		
		bin_tree(file,15,&(a->root));
		Node*asd=a->root;
		
	
		
		fclose(file);
		print_tree(a);
		
	}	


	return 0;	
}
