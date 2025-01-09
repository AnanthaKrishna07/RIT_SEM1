#include <stdio.h>
#include <stdlib.h>

// Global variables
void display(int MAX);
int front = -1;
int rear = -1;
int *CQueue;

// Function to check if the queue is full
int isFull(int MAX) {
    return (rear + 1) % MAX == front;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to insert (enqueue) an element into the queue
void enque(int value, int MAX) {
    if (isFull(MAX)) {
        printf("Queue is Full!!\n");
    } else if (isEmpty()) { // First element insertion
        front = 0;
        rear = 0;
        CQueue[rear] = value;
    } else { // Normal insertion
        rear = (rear + 1) % MAX;
        CQueue[rear] = value;
    }
    display(MAX);
}

// Function to remove (dequeue) an element from the queue
void deque(int MAX) {
    if (isEmpty()) {
        printf("Queue is Empty!!\n");
    } else if (rear == front) { // Last element deletion
        printf("%d is Deleted!!\n", CQueue[front]);
        front = -1;
        rear = -1;
    } else { // Normal deletion
        printf("%d is Deleted!!\n", CQueue[front]);
        front = (front + 1) % MAX;
    }
}

// Function to display all elements of the queue
void display(int MAX) {
    if (isEmpty()) {
        printf("Queue is empty!!\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        do {
            printf("%d -> ", CQueue[i]);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        printf("\n");
    }
}

// Function to search for an element in the queue
void search(int value, int MAX) {
    if (isEmpty()) {
        printf("Queue is Empty!!\n");
    } else {
        int pos = 1;
        int i = front;
        do {
            if (CQueue[i] == value) {
                printf("%d found at %d th position!\n", value, pos);
                return;
            }
            i = (i + 1) % MAX;
            pos++;
        } while (i != (rear + 1) % MAX);
        printf("%d not found!!\n", value);
    }
}

// Main function
int main() {
    int ch, value, MAX;

    printf("Enter the size of Queue: ");
    scanf("%d", &MAX);

    if (MAX <= 0) {
        printf("Invalid size! Exiting...\n");
        return 1;
    }

    // Dynamically allocate memory for the circular queue
    CQueue = (int *)malloc(MAX * sizeof(int));
    if (CQueue == NULL) {
        printf("Memory allocation failed! Exiting...\n");
        return 1;
    }

    do {
        printf("\n 1. Enque \n 2. Deque \n 3. Display \n 4. Search \n 5. Exit \n Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value to be Inserted: ");
                scanf("%d", &value);
                enque(value, MAX);
                break;
            case 2:
                deque(MAX);
                break;
            case 3:
                display(MAX);
                break;
            case 4:
                printf("Enter the value to Search: ");
                scanf("%d", &value);
                search(value, MAX);
                break;
            case 5:
                printf("Exiting the program..!!\n");
                free(CQueue); // Free allocated memory
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);
}
