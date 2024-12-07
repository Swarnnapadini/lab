#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*head=NULL;
void insert_beg();
void insert_end();
void display();	
void delete_beg();
int main()
{
	int choice=0;
	do{
		printf("\n1.Insert at beginning\n2.Insert at end\n3.Delete at beginning\n4.Delete at end\n5.Display\n6.Search\n7.EXit ");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_beg();
				break;
			case 2:  
                                insert_end();
                                break;
			case 3:  
                                display();
				break;
			case 4:  
                                delete_beg();
				break;
			case 5:  
                                exit(0);
			default:
				printf("Invalid choice");


		}

	}while(choice!=9);
return 0;

}

void display()
{
	struct node*temp;
	temp=head;
	while(temp->next!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
}
}
			
void insert_beg()
{
	struct node*newnode;
	int item;
	newnode=malloc(sizeof(struct node));
	printf("Enter data to be inserted:");
	scanf("%d",&item);
	newnode->data=item;
	newnode->next=head;
	head=newnode;
	printf("Node inserted");
	display();
}
 void insert_end()
{
	struct node*newnode,*temp;
        int item;
        newnode=malloc(sizeof(struct node));
        printf("Enter data to be inserted:");
        scanf("%d",&item);
        newnode->data=item;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;}
	else{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		
		}
		temp->next=newnode;
		printf("Node inserted");
		display();
}
	
}
void delete_beg()
{
	struct node *temp;
	if(head==NULL)
		printf("List is empty");
	else{
		temp=head;
		head=temp->next;
		free(temp);
		display();
}
}

