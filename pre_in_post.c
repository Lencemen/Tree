#include<stdio.h>
#include<stdlib.h>
typedef struct treetype
{
	struct treetype *left;
	int info;
	struct treetype *right;
}bst;
void insertNode(bst **root,int item)
{
	bst *ptr,*nodeptr,*par;
	ptr=(bst*)malloc(sizeof(bst));
	ptr->left=ptr->right=NULL;
	ptr->info=item;
	if(*root == NULL)
	{
		*root=ptr;
	}
	else{
		par=NULL;
		nodeptr=*root;
		while(nodeptr != NULL){
			par=nodeptr;
			if(item < nodeptr->info)
				nodeptr=nodeptr->left;
			else
			nodeptr=nodeptr->right;
			
		}
		if(item < par->info)
			par->left=ptr;
		else
			par->right=ptr;
	}
}
void preorder(bst *root)
{
	bst *stack[25],*ptr;
    int top=-1;
    top=top+1;
    stack[top]=NULL;
    ptr=root;
    while (ptr!=NULL)
    {
        printf("\t%d",ptr->info);
        if(ptr->right!=NULL){
            stack[++top]=ptr->right;
        }
        if(ptr->left!=NULL){
            ptr=ptr->left;
        }
        else{
            ptr=stack[top--];
        }
	}
}
void inorder(bst *root)
{
	if (root != NULL) {
    inorder(root->left);
    printf("%d\t", root->info);
    inorder(root->right);
  }
}
void postorder(bst *root)
{
	if (root != NULL) {
	postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->info);
}
}
int main()
{
	int choice,item;
	bst *root;
	root=NULL;
	while(1)
	{
		printf("\n.....BST menu....\n");
		printf("\n 1 Insert an element");
		printf("\n 2 PREORDER");
		printf("\n 3 INORDER");
		printf("\n 4 POSTORDER");
		printf("\n 5 EXIT");
		printf("\n Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n Enter an item=");
			scanf("%d",&item);
			insertNode(&root,item);
			break;
			case 2:preorder(root);
			break;
			case 3:inorder(root);
			break;
			case 4:postorder(root);
			break;
			default:exit(1);
		}
	}
	return 0;
}
