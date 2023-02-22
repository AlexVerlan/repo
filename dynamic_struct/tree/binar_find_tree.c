#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "print_tree.h"



void push_node(Node* a,int b){
	if(b<=a->value){
		if(a->left!=NULL){
			push_node((a->left),b);
		}else{
			Node* buf=(Node*)calloc(sizeof(Node),1);
			buf->left=NULL;
			buf->right=NULL;
			buf->value=b;
			a->left=buf;
		}
		
	}else{
		if(a->right!=NULL){
			push_node(a->right,b);
		}else{
			Node* buf=(Node*)calloc(sizeof(Node),1);
			buf->left=NULL;
			buf->right=NULL;
			buf->value=b;
			a->right=buf;
		}	
	}
}

void push(Tree* a, int b){
	if(a->root==NULL){
		Node* buf=(Node*)calloc(sizeof(Node),1);
		buf->left=NULL;
		buf->right=NULL;
		buf->value=b;
		a->root=buf;
	}else{
		push_node(a->root,b);
	}
}






Tree* init(){
	Tree*a=(Tree*)calloc(sizeof(Tree),1);
	a->root=NULL;
	return a;	
}


int main(int* argv, char** argc){
	Tree* a=init();
	for(int i=0;i<10;++i){
		push(a,rand()%30);
	}
	printf("____\n");
	print_tree(a);
	return 0;
	
}
	

