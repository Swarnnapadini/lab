#include<stdio.h>
#include<stdlib.h>
struct{
	int data;
	struct node *left;
	struct node *right;
};
struct node *insert(struct node *root,int val)
{
	if(root==NULL){
		struct node *newnode=malloc(sizeof(struct newnode));
		newnode->data=val;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	else if(val==root->data){
		printf("NO duplicate values");
	}
	else if(val<root->data){
		root->left=insert(root->left,val);
	}
	else{
		root->right=insert(root->right,val);
	}
return root;

}

void inorder(struct node* root){
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d->",root->data);
	inorder(root->right);
}

void preorder(struct node* root){
	if(root==NULL)
		return;
	printf("%d->",root->data);
	preorder(root->left);
	preorder(roo->right);
}
 void postorder(struct node *root){
	if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	printf("%d->",root->data);
}

void display(struct node*root){
	if(root==NULL){
		printf("Empty");
		return;
	}
	inorder(root);
	printf("\n");

}
 int main()
{
	struct node*root=NULL;	
	int ch,val;
	do{
		printf("1.INSERT NODE\/2.INORDER TRAVERSAL\n3.PREORDER TRAVERSAL\n4.POSTORDER TRAVERSAL\n5.DISPLAY\n6.EXIT");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the number:");
				scanf("%d",&val);
				root=insert(root,val);
				break;
			case 2:
                                printf("\nInorder Traversal: ");
                                inorder(root);
                                printf("\n");
                                break;
                        case 3:
                                printf("\nPreorder Traversal: ");
                                preorder(root);
                                printf("\n");
                                break;
                        case 4:
                                printf("\nPostorder Traversal: ");
                                postorder(root);
                                printf("\n");
                                break;
			case 5:
                                printf("\nDisplay\n");
                                display(root);
                                break;
			case 6:
                                printf("Exiting...\n");
                                break;

			default:
                                printf("Invalid option!\n");
		}
	}while(ch!=6);
	return;
}
