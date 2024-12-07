#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
    struct node* prev;  
};

struct node* head = NULL;  


void display(){
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
	printf("%d->", temp->data);
        temp = temp->next;
    }
printf("NULL");
}

void ins_beg(int item){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = head;
    newnode->prev = NULL;  
    
    if (head != NULL)
        head->prev = newnode;  
    
    head = newnode; 
display();
}
void ins_end(int item){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;  
    newnode->prev = NULL;  

    if (head == NULL) {
        head = newnode;  
        return;
    }
	struct node* temp = head;
    	while (temp->next != NULL) {
        	temp = temp->next;  
    }
    
    temp->next = newnode;  
    newnode->prev = temp;
    display();
}
void ins_pos(int item, int pos){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;

    if (pos == 1) {
        ins_beg(item);
        return;
    }

    struct node* temp = head;
    int i = 1;

    
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
}

    if (temp == NULL) {
	printf("\nPosition not found\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;  
    newnode->prev = temp;        

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;  
    display();
}

void del_beg(){
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
}

    struct node* temp = head;
    printf("%d is deleted\n", temp->data);

 head = temp->next;  

    if (head != NULL)
        head->prev = NULL;  

    free(temp);  
    display();
}
void del_end(){
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp = head;
 if (temp->next == NULL) {  
        printf("%d is deleted\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

   
    while (temp->next != NULL) {
        temp = temp->next;
 }

    printf("%d is deleted\n", temp->data);
    temp->prev->next = NULL;
    free(temp);  
    display();
}
void del_pos(int pos) {
    if (head == NULL) {
        printf("\nList is empty\n");
	return;
    }

    if (pos == 1) {
        del_beg();
        return;
    }

    struct node* temp = head;
    int i = 1;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {

	printf("\nPosition not found\n");
	return;
    }

    printf("%d is deleted\n", temp->data);

    if (temp->next != NULL)  
        temp->next->prev = temp->prev;

    if (temp->prev != NULL) 
        temp->prev->next = temp->next;

    free(temp);  
    display();
}
void search(int data)
{
        struct node*temp=head;
        int pos=1;
        while(temp!=NULL)
        {
                if(temp->data==data)
                {
                        printf("Element %d found at position %d\n",data,pos);
                        return;
                }
                temp=temp->next;
                pos++;
        }
        printf("Element not found...");
        }


 int main()
{
	int ch, data;
    while (1) {
	printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at random location");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from end");
        printf("\n6. Delete from random location");
        printf("\n7. Display");
        printf("\n8. Search");
        printf("\n9. Exit");
        
	printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                int item;
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                ins_beg(item);
                break;
}
            case 2: {
                int item2;
                printf("\nEnter the element to be inserted: ");
		scanf("%d", &item2);
                ins_end(item2);
                break;
            }
            case 3:
	 {
                int item3, pos2;
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item3);
                printf("\nEnter the position of element to be inserted: ");
                scanf("%d", &pos2);
                ins_pos(item3, pos2);
                break;
            }
            case 4:
                del_beg();
                break;

            case 5:
                del_end();
                break;
	    case 6: {
                int pos;
		printf("\nEnter the position of element to be deleted: ");
                scanf("%d", &pos);
                del_pos(pos);
                break;
            }
            case 7:
                display();
                break;
	     case 8:
                printf("Enter the data to be searched:: ");
                scanf("%d", &data);
                search(data);
                break;
            case 9:
                printf("\nExiting....");
                exit(0);
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
}
