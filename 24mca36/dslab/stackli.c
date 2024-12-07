#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
}
*top=NULL;
int isEmpty()
{
	if(top==NULL)
		return 1;

	else
		return 0;
}
void push(int data)
{
	struct node*newnode;
	newnode=malloc(sizeof(newnode));
	if(newnode==NULL)
	{
		printf("Stack overflow");
	}
	newnode->data=data;
	newnode->link=NULL;
	newnode->link=top;
	top=newnode;
}
int pop()
{
	struct node*temp;
	int val;
	if(isEmpty())
	{
		printf("Stack underflow");
		return 1;
	}
	temp=top;
	val=temp->data;
	top=temp->link;
	free(temp);
	temp=NULL;
	return val;

}
void display()
{
	struct node*temp;
	temp=top;
	if(isEmpty())
	{
		printf("Stack underflow");
	
	}else{
	printf("Stack elements are:");
	while(temp)
	{
		printf("%d\t",temp->data);
		temp=temp->link;
	}
}}
int search(int data)
{
struct node*temp;
temp=top;
int f=0;
while(temp)
{
	if(temp->data==data)
	{f=1;
	printf("element found");
	}
temp=temp->link;

}
if(f==0)
printf("element not found");
}

int main()
{
	int choice,data;
	do{
	printf("\n1.PUSH\n");
	printf("2.POP\n");
	printf("3.DISPLAY\n");
	printf("4.Search\n");
	printf("5.EXIT\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the element to be pushed:");
			scanf("%d",&data);
			push(data);
			break;
		case 2:
			data=pop();
			printf("\nDeleted element is %d",data);
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Enter the element to be searched:");
			scanf("%d",&data);
			search(data);
			break;
		case 5:
			exit(1);
		default:
			printf("Invalid choice");
	}
}while(choice!=5);
	return 0;
}

