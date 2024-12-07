#include <stdio.h>
#include <stdlib.h>

int *queue;
int size;
int front = -1, rear = -1;

void initializeQueue() {
    queue = (int *)malloc(size * sizeof(int));
}

void enqueue(int element) {
    if (front == (rear + 1) % size) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    queue[rear] = element;
}

int dequeue() {
    int element;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    element = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
    printf("%d dequeued from the queue\n", element);
    return element;
}

int searchElement(int element) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int current = front;
    int position = 1;
    do {
        if (queue[current] == element) {
            return position;
        }
        current = (current + 1) % size;
        position++;
    } while (current != (rear + 1) % size);
    return -1;
}

void displayQueue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int current = front;
    do {
        printf("%d ", queue[current]);
        current = (current + 1) % size;
    } while (current != (rear + 1) % size);
    printf("\n");
}

int main() {
    int choice, searchResult, element;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);
    initializeQueue();
    do {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                enqueue(element);
		displayQueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                searchResult = searchElement(element);
                if (searchResult != -1) {
                    printf("%d found at position %d\n", element, searchResult);
                } else {
                    printf("%d not found in the queue\n", element);
                }
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice...\n");
                break;
        }
    } while (choice != 5);
    free(queue);
    return 0;
}
