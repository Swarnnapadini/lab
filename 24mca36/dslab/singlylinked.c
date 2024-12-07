#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node*next;
        };
struct node*head=NULL;
void display(){
        struct node*temp=head;
        if(head==NULL){
        printf("empty list");
        return;
        }
while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
        }
        }
void insert_beg(int data){
struct node*newnode=(struct node*)malloc(sizeof (struct node));
newnode->data=data;
newnode->next=head;
head=newnode;
display();
        }
void insert_end(int data){
struct node*newnode=(struct node*)malloc(sizeof (struct node));

        newnode->data=data;
        newnode->next=  NULL;
        if(head==NULL){
                head=newnode;
                }
        else{
        struct node*temp=head;
        while(temp->next!=NULL){
                temp=temp->next;}
                temp->next=newnode;}
        display();
}
void insert_pos(int data,int pos){
        struct node*newnode=(struct node*)malloc(sizeof (struct node));
        struct node*temp=head;
        newnode->data=data;
        if(pos==1){
                newnode->next=head;
                head=newnode;
                display();
                return;
                }
        for(int i=1;i<pos-1 && temp!=NULL;i++){
                temp=temp->next;
                        }
while(temp==NULL){
        printf("invalid");
        return;}
newnode->next=temp->next;
temp->next=newnode;
display();
}
void del_beg()
{
	struct node*temp;
	if(head==NULL)
		printf("List is empty");
	else{
		temp=head;
		head=temp->next;
		free(temp);
		display();
}
}
void del_end()
{
	struct node *temp,*temp1;
	if(head==NULL)
		printf("List is empty");
	else
	{
		temp=head;
		while(temp->next!=NULL){
temp1=temp;			
temp=temp->next;
		}
		temp1->next=temp->next;
		free(temp);
	display();
}
}

int main(){
int choice,data,pos;
while(1){
printf("\n 1.Insert at begining \n");
printf(" 2.Insert at end \n");
printf(" 3.Insert at position \n");
printf(" 4.display the list \n");
printf(" 5.delete from beginning \n");
printf(" 6.exit \n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice){
        case 1:
        printf("Enter data to insert at beginning: ");
        scanf("%d",&data);
        insert_beg(data);
        break;
case 2:
        printf("Enter data to insert at end :");
        scanf("%d",&data);
        insert_end(data);
        break;
        case 3:
        printf("Enter data to be insert at random position: ");
        scanf("%d",&data);
        printf("Enter position be inserted:");
        scanf("%d",&pos);
        insert_pos(data,pos);
        break;
        case 4:
        display();
        break;
	case 5:
	del_beg();
	break;
        case 6:
        exit(0);
        default:
        printf("Invalid choice \n");

}
}
return 0;
}
