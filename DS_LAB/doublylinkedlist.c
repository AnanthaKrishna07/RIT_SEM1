#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

void ibeg(int val) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;

    printf("%d is inserted at the beginning\n", val);
}

void iend(int val) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("%d is inserted at the end\n", val);
}

void ipos(int val, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        ibeg(val);
        return;
    }

    struct node* temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds! Inserting at the end.\n");
        iend(val);
    } else {
        struct node* newnode = malloc(sizeof(struct node));
        newnode->data = val;

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;

        printf("%d is inserted at position %d\n", val, position);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = head;
    printf("Elements in the list:\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void dbeg() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        struct node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        printf("%d is deleted from the beginning of the list\n", temp->data);
        free(temp);
    }
}

void dend() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else if (head->next == NULL) {
        dbeg();
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->prev->next = NULL;

        printf("%d is deleted from the end of the list\n", temp->data);
        free(temp);
    }
}

void dpos(int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position == 1) {
        dbeg();
        return;
    }

    struct node* temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
    } else {
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        printf("%d is deleted from position %d\n", temp->data, position);
        free(temp);
    }
}

int main() {
    int val, position, choice;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a random position\n");
        printf("4. Deletion at beginning\n");
        printf("5. Deletion at end\n");
        printf("6. Deletion at any position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &val);
                ibeg(val);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &val);
                iend(val);
                break;
            case 3:
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                ipos(val, position);
                break;
            case 4:
                dbeg();
                break;
            case 5:
                dend();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                dpos(position);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
