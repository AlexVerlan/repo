#include <stdio.h>
#include  <stdlib.h>

#define WHITE 1
#define BLACK 0

typedef struct{
	int color;
	
	int value;
	
	struct Node* left;
	struct Node* right;
}Node;

typedef struct{
	Node* root;

}Tree;

Tree* init_tree(){
	Tree* a=(Tree*)calloc(sizeof(Tree*),1);
	a->root=NULL;
	return a;		
}

Node* init_node(int x){
	Node* a=(Node*)calloc(sizeof(Node),1);
	a->left=NULL;
	a->right=NULL;
	a->color=BLACK;
	a->value=x;
	return a;
}

void push_node(Node* a,int x){
	if(a->value<x){
		int buf=x;
		x=a->value;
		a->value=buf;
	}
	
	if(a->left==NULL){
	
		a->left=init_node(x);

	}else{
		Node* buf_Node=a->left;
		if(buf_Node->color==WHITE){

			push_node(a->left,x);

		}else{

			if( a->right==NULL ){

				a->right=init_node(x);
				a->color=BLACK;

			}else{
				Node* buf_Node=a->right;

				if( buf_Node->color==WHITE ){

					push_node(a->right,x);
					Node* buf_Node_2=a->left;
					if( buf_Node_2->color==BLACK && buf_Node->color==BLACK ){

						a->color=BLACK;

					}
				}
			}
		}
	}
}

void tree_recolor(Node* a){
	if(a==NULL){
		return;
	}
	a->color=WHITE;
	tree_recolor(a->left);
	tree_recolor(a->right);
}

void push_tree(Tree* a,int x){
	if(a->root==NULL){
		a->root=init_node(x);
	}else{
		if( (a->root)->color==BLACK ){
			tree_recolor(a->root);
		}
		push_node(a->root,x);
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
	if(!a->root){
		printf("tree is empty\n");
		return;
	}
	//определение высоты (мне легче воспринимать как глубину) дерева
	int depth;
	depth=tree_depth(a->root,0);	
		
	//кол-во элементов в каждом уровне дерева
	int*list_size=(int*)calloc(sizeof(int),depth+1);
	for(int i=0;i<=depth;++i){
		list_size[i]=pow(2,i);
	}
	
	//?
	int*list_size_2=(int*)calloc(sizeof(int),depth+1);
	for(int i=0;i<=depth;++i){
		list_size_2[i]=0;
	}
	
	//выделение памяти для вектора массивов с поуровневым занесением всего дерева
	int** list=(int**)calloc(sizeof(int*),depth+1);
	for(int i=0;i<=depth;++i){
		*(list+i)=(int*)calloc(sizeof(int),list_size[i]);
	}
	
	//все участки памяти делаем со значением -1
	for(int i=0;i<=depth;++i){
		for(int d=0;d<list_size[i];++d){	
			*((*(list+i))+d)=-1;
		}
	}

	//считывание дерева в вектор list
	print_buf(a->root,list,list_size_2,depth,0);
	
	//поуровненвый и визуализированный вывод дерева в коммандную строку
	for(int i=0;i<=depth;++i){
		for(int d=0;d<pow(2,i);++d){
			if(d==0){
				for(int x=0;x<list_size[depth-i]-1;++x){
					printf("  |");
				}
			}
			if(*((*(list+i))+d)!=-1){
				printf("%3d",*((*(list+i))+d));
			}else{
				printf("  -");
			}
			
			
			if(d==pow(2,i)-1){
				for(int x=0;x<(list_size[depth-i])-1;++x){
					printf("  |");
				}
			}else{
				for(int x=0;x<list_size[depth-i]*2-1;++x){
				printf("  |");
				}
			}
		}
		printf("\n");
	}
	

}


int main(int* argc,char** argv){
	Tree*a=init_tree();
	print_tree(a);
	
	for(int i=0;i<30;++i){
		push_tree(a,i);
		print_tree(a);
		printf("\n");
	}	
	return 0;	


}





















