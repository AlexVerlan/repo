#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int value;
	struct Node* left;
	struct Node* right;	
}Node;

typedef struct{
	Node* root;	
}Tree;



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



int tree_depth(Node*a,int b){
	if(a->left==NULL&&a->right==NULL){
		return b;
	}
	int l=b;
	int r=b;
	if(a->left!=NULL){
		l=tree_depth(a->left,b+1);
	}
	if(a->right!=NULL){
		r=tree_depth(a->right,b+1);
	}
	if(l<=r){return r;}else{return l;}
	
}

void print_node(Node* a){
	if(a==NULL){
		printf("[]");
	}else{
		printf("[%d]",a->value);
	}	
}

void print_buf(Node* a,int** list_size,int* list_size_2,int depth,int depth_2){
	if(a==NULL){
		if(depth_2!=depth){
			list_size_2[depth_2]+=1;
			print_buf(NULL,list_size,list_size_2,depth,depth_2+1);
			print_buf(NULL,list_size,list_size_2,depth,depth_2+1);
			
		}else{
			list_size_2[depth_2]+=1;
		}
		
	}else{
		if(depth_2!=depth){
			*((*(list_size+depth_2))+list_size_2[depth_2])=a->value;
			list_size_2[depth_2]+=1;
			print_buf(a->left,list_size,list_size_2,depth,depth_2+1);
			print_buf(a->right,list_size,list_size_2,depth,depth_2+1);
		}else{
			*((*(list_size+depth_2))+list_size_2[depth_2])=a->value;
			list_size_2[depth_2]+=1;
		}
		
	}	



}

void print_tree(Tree*a){
	int depth;
	depth=tree_depth(a->root,0);
	printf("%d\n",depth);
	
	int*list_size=(int*)calloc(sizeof(int),depth+1);
	for(int i=0;i<=depth;++i){
		list_size[i]=pow(2,i);
	}
	for(int i=0;i<=depth;++i){
		printf("%d ",list_size[i]);
	}

	int*list_size_2=(int*)calloc(sizeof(int),depth+1);
	for(int i=0;i<=depth;++i){
		list_size_2[i]=0;
	}
	
	int** list=(int**)calloc(sizeof(int*),depth+1);
	

	for(int i=0;i<=depth;++i){
		*(list+i)=(int*)calloc(sizeof(int),list_size[i]);
	}
	printf("\n");
	for(int i=0;i<=depth;++i){
		//*(*(list+i))=list_size[i];
		
		for(int d=0;d<list_size[i];++d){
			
			*((*(list+i))+d)=-1;
		}
	}
	printf("_________\n");
	print_buf(a->root,list,list_size_2,depth,0);
	
	printf("_________\n");
	char asd='|';
	
	for(int i=0;i<=depth;++i){

		for(int d=0;d<pow(2,i);++d){
			if(d==0){
				for(int x=0;x<list_size[depth-i]-1;++x){
					printf("%3c",asd);
				}
			}
			printf("%3d",*((*(list+i))+d));
			
			if(d==pow(2,i)-1){
				for(int x=0;x<(list_size[depth-i])-1;++x){
					printf("%3c",asd);
				}
			}else{
				for(int x=0;x<list_size[depth-i]*2-1;++x){
					printf("%3c",asd);
				}
			}
		}
		printf("\n");
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
	print_tree(a);
	return 0;
	
}
	

