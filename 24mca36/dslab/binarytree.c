#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	struct node *right;
	int data;
};
struct node* insert(struct node* root, int value) {
  if (root == NULL) {
	 struct node *newnode = malloc(sizeof(struct node));
       	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
  } else if (value == root->data) {
    printf("Same data can't be stored\n");
  } else if (value > root->data) {
    root->right = insert(root->right, value);
  } else {
    root->left = insert(root->left, value);
  }
  return root;
}


void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d -> ", root->data);                                                                                                                                                                                                                                                                                                                                   
  inorderTraversal(root->right);
}

void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d -> ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d -> ", root->data);
}

struct node* search(struct node* root, int key) { 
  if (root == NULL) {
    printf("Node not found\n"); 
    return NULL;
  } else if (root->data == key) {
    printf("Node found\n");
    return root;
  } else if (root->data < key) {
    return search(root->right, key); 
  } else {
    return search(root->left, key);
  }
}

struct node* minValueNode(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int key){
    if (root == NULL)
        return root;
 
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void display(struct node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    inorderTraversal(root);
    printf("\n");
}

int main(){
	struct node *root = NULL;
	int opt, value, searchv, key;
	do {
		printf("\n1.INSERT NODE\n2.INORDER TRAVERSAL\n3.PREORDER TRAVERSAL\n4.POSTORDER TRAVERSAL\n5.DISPLAY\n6.SEARCH\n7.DELETE\n8.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Enter the number: ");
				scanf("%d", &value);
				root = insert(root, value);
				break;
			case 2:
				printf("Inorder Traversal: ");
                                inorderTraversal(root);
                                printf("\n");
                                break;

			case 3:
				printf("Preorder Traversal: ");
                                preorderTraversal(root);
                                printf("\n");
                                break;

			case 4:
				printf("Postorder Traversal: ");
                                postorderTraversal(root);
                                printf("\n");
                                break;
			case 5:
	
				printf("Display\n");
                                display(root);
                                break;

			case 6:
				printf("Enter the number to search: ");
                                scanf("%d", &searchv);
                                search(root, searchv);
                                break;
			case 7:
				printf("Enter the number to delete: ");
                                scanf("%d", &key);
                                root = deleteNode(root, key);
                                break;
			case 8:
				printf("Exit\n");
				break;
			default:
				printf("Invalid option!\n");
		}
	} while(opt != 8);
	return 0;
}
