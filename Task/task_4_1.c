#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "print_tree.h"


//void print_tree(Tree*a)

Tree* init(){
	Tree*a=(Tree*)calloc(sizeof(Tree),1);
	a->root=NULL;
	return a;	
}

void push_rand_buf(Node*a,int buf){
	int curse;
	curse=rand()%2;
	if(curse){
		if(a->left){
			push_rand_buf(a->left,buf);
		}else{
			Node* d=(Node*)calloc(sizeof(Node),1);
			d->left=NULL;
			d->right=NULL;
			d->value=buf;
			a->left=d;
		}
	}else{
		if(a->right){
			push_rand_buf(a->right,buf);
		}else{
			Node* d=(Node*)calloc(sizeof(Node),1);
			d->left=NULL;
			d->right=NULL;
			d->value=buf;
			a->right=d;
		}
	}		
}

void push_rand(Tree*a,int buf){
	if(!a->root){
		Node* d=(Node*)calloc(sizeof(Node),1);
		d->left=NULL;
		d->right=NULL;
		d->value=buf;
		a->root=d;
		return;
	}
	Node*curs=a->root;
	push_rand_buf(curs,buf);
}



int deps_2;
int deps_2_dif;

int deps_2_node(Node*a,int deps){
	if(a==NULL){	
		int g=deps_2-deps;
		if(g!=0){
			if(deps_2_dif==0){
				deps_2_dif=g;
				return 1;
			}else{
				if(g!=deps_2_dif){
					return 0;
				}
				return 1;
			}
		}
		return 1;
	}else{
		int l,r;
		l=deps_2_node(a->left,deps+1);
		r=deps_2_node(a->right,deps+1);
		if(l&&r){return 1;}else{return 0;}
	}	
	
	
}

int balans_tree(Tree*a){
	deps_2=0;
	Node* buf=a->root;
	while(buf!=NULL){
			
		buf=buf->left;
		++deps_2;
	}
	
	deps_2_dif=0;
	return deps_2_node(a->root,0);
}


int main(int* argc,char** argv){
	Tree**array=(Tree**)calloc(sizeof(Tree*),50);
	for(int i=0;i<50;++i){
		
		*(array+i)=init();
	}		
	for(int i=0;i<50;++i){
		printf("%d = ",i);
		print_tree(*(array+i));	
	}
	for(int i=0;i<50;++i){
		for(int d=0;d<10000;++d){
			push_rand(*(array+i),rand()%100);
		}
	}
	
	for(int i=0;i<50;++i){
		printf("\n%d_________________________________\n",i);
		print_tree(*(array+i));
	}
	printf("\n");
	for(int i=0;i<50;++i){
		
		printf("balanced [%d] - %d\n",i,balans_tree(*(array+i)));
	}
	

	return 0;
		
}
