#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head = NULL;



void display() 
{
    struct node* temp = head;
    if (head == NULL) 
        {
        printf("\nList is empty\n");
        return;
        }
    while (temp != NULL)
        {
		printf("%d->", temp->data);
        temp = temp->next;
        }
	printf("NULL");
}

void in_beg(int data) 
{
        struct node* newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        display();

}
void in_end(int data) 
{
        struct node* newnode = (struct node*) malloc(sizeof(struct node));
        struct node* temp = head;
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL)
        {
                head = newnode;
        } 
        else
        {
		while (temp->next != NULL)
                {
                        temp = temp->next;
                }
        temp->next = newnode;
    }

 display();
}

void in_pos(int data,int pos)
{
        struct node* newnode = (struct node*) malloc(sizeof(struct node));
        struct node* temp = head;
        newnode->data = data;
	if (pos == 1)
        {
                newnode->next = head;
                head = newnode;
		 display();
                return;
        }
        for(int i = 1; i < pos - 1 && temp != NULL; i++)
        {
                temp = temp->next;
        }
        if (temp == NULL) 
        {
                printf("Position out of range\n");
                return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        display();
}
void del_beg()
{
        if(head == NULL)
        {
		printf("List is empty (underflow)\n");
                return;
        }
        struct node* temp = head;
	head = head->next;
        free(temp);
        display();
}
void del_end()
{
        if (head == NULL)
        {
                printf("List is empty (underflow)\n");
                return;
        }
        struct node* temp = head;
        struct node* prev = NULL;
        if (head->next == NULL)
	{
                free(head);
                head = NULL;
        }
        else 
        {
                while (temp->next != NULL)
                {
                prev = temp;
                temp = temp->next;
                }
        prev->next = NULL;
        free(temp);
        }
        display();
}
void del_pos(int pos)
{
        if (head == NULL) 
        {
                printf("List is empty (underflow)\n");
                return;
        }
        struct node* temp = head;
        struct node* prev = NULL;
        if (pos == 1)
        {
                head = head->next;
                free(temp);
                display();
                return;
        }
        for (int i = 1; i < pos && temp != NULL; i++)

{
                prev = temp;
                temp = temp->next;
        }
        if (temp == NULL)
        {
                printf("Position out of range\n");
                return;
        }
        prev->next = temp->next;
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

int main() {
    int choice, data, pos;
 do {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
	printf("\n3. Insert at random location");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from end");
        printf("\n6. Delete from random location");
        printf("\n7. Display");
	printf("\n8. Search");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                in_beg(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
		in_end(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                in_pos(data,pos);
		break;
            case 4:
                del_beg();
                break;
            case 5:
                del_end();
		break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                del_pos(pos);
                break;
            case 7:
                display();
                break;
	    case 8:
		printf("Enter the data to be searched:: ");
                scanf("%d", &data);
                search(data);
                break;

            case 9:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
        while (choice != 9);
        return 0;
}

