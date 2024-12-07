#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *rep;
    struct node *next;
    int data;
} *heads[50], *tails[50];

static int countRoot = 0;

// Function to create a new set with a single element
void makeSet(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->rep = new;  // A node is its own representative initially
    new->next = NULL;
    new->data = x;
    heads[countRoot] = new;  // Store the head of the set
    tails[countRoot] = new;  // Store the tail of the set
    countRoot++;
}

// Function to find the representative of an element
struct node* find(int a) {
    int i;
    struct node *tmp;
    for (i = 0; i < countRoot; i++) {
        tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == a)
                return tmp->rep;  // Return the representative of the element
            tmp = tmp->next;
        }
    }
    return NULL;
}

// Function to perform union of two sets containing elements a and b
void unionSets(int a, int b) {
    int i, j, pos, flag = 0;
    struct node *tail2;
    struct node *rep1 = find(a);
    struct node *rep2 = find(b);
    
    if (rep1 == NULL || rep2 == NULL) {
        printf("\nElement(s) not present in the DS\n");
        return;
    }
    
    if (rep1 != rep2) {
        // Find the position of rep2 and remove it from the list
        for (j = 0; j < countRoot; j++) {
            if (heads[j] == rep2) {
                pos = j;
                flag = 1;
                countRoot -= 1;  // Decrease the root count
                tail2 = tails[j];
                for (i = pos; i < countRoot; i++) {
                    heads[i] = heads[i+1];
                    tails[i] = tails[i+1];
                }
                break;
            }
        }
        
        // Merge the sets by connecting the tail of rep1's set to rep2's set
        for (j = 0; j < countRoot; j++) {
            if (heads[j] == rep1) {
                tails[j]->next = rep2;
                tails[j] = tail2;
                break;
            }
        }
        
        // Update the representative for all elements in rep2's set
        while (rep2 != NULL) {
            rep2->rep = rep1;  // Set rep1 as the new representative
            rep2 = rep2->next;
        }
    }
}

// Function to search if an element is present in any set
int search(int x) {
    int i;
    struct node *tmp;
    for (i = 0; i < countRoot; i++) {
        tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == x)
                return 1;  // Element found
            tmp = tmp->next;
        }
    }
    return 0;  // Element not found
}

// Function to display the representatives of all sets
void displayRepresentatives() {
    printf("\nSet Representatives: ");
    for (int i = 0; i < countRoot; i++) {
        printf("%d ", heads[i]->data);
    }
    printf("\n");
}

// Function to display all elements in each disjoint set
void displaySets() {
    int i, j;
    struct node *temp;
    
    printf("\nDisjoint Sets:\n");
    for (i = 0; i < countRoot; i++) {
        temp = heads[i];
        printf("{ ");
        int first = 1;
        while (temp != NULL) {
            if (!first) printf(", ");
            printf("%d", temp->data);
            first = 0;
            temp = temp->next;
        }
        printf(" }\n");
    }
}

// Main function
int main() {
    int choice, x, y, setSize;

    // Ask for initial set size
    printf("Enter the size of the set (max 50): ");
    scanf("%d", &setSize);

    // Input validation for set size
    while (setSize <= 0 || setSize > 50) {
        printf("Invalid set size. Please enter a size between 1 and 50: ");
        scanf("%d", &setSize);
    }

    // Input elements for the initial set
    printf("\nEnter %d unique elements to the set:\n", setSize);
    for (int i = 0; i < setSize; ) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        

        if (search(x)) {
            printf("Element %d already exists in the set. Please enter a unique element.\n", x);
        } else {
            makeSet(x);
            i++;
        }
    }


    do {
        printf("\n1. View the set representatives");
        printf("\n2. Union of the set");
        printf("\n3. Find Set");
        printf("\n4. Display all sets");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayRepresentatives();
                break;
                
            case 2:
                printf("\nEnter first element: ");
                scanf("%d", &x);
                printf("Enter second element: ");
                scanf("%d", &y);
                unionSets(x, y);
                break;
                
            case 3:
                printf("\nEnter the element to find: ");
                scanf("%d", &x);
                struct node *rep = find(x);
                if (rep == NULL) {
                    printf("\nElement not present in the DS\n");
                } else {
                    printf("\nThe representative of %d is %d\n", x, rep->data);
                }
                break;
                
            case 4:
                displaySets();
                break;
                
            case 5:
                printf("\nExiting......\n");
                exit(0);
                
            default:
                printf("\nInvalid choice\n");
                break;
        }
    } while (1);

    return 0;
}
