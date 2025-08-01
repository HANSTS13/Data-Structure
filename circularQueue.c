#include <stdio.h>
int array[20], front = -1, rear = -1;
void enqueue(int n, int size) {
    if ((rear + 1) % size == front) {
        printf("Overflow\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
       array[rear] = n;
    printf("Elements in the queue:\n");
    int i = front;
    while (1) {
        printf("%d\n", array[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    } else {
        rear = (rear + 1) % size;
      array[rear] = n;
    printf("Elements in the queue:\n");
    int i = front;
    while (1) {
        printf("%d\n", array[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    }
    
}
void dequeue(int size) {
    if (front == -1) {
        printf("Underflow\n");
    }
    else if (front == rear) {
       printf("Deleted element: %d\n", array[front]);
        front = rear = -1;
    } else {
      printf("Deleted element: %d\n", array[front]);
        front = (front + 1) % size;
        printf("Elements in the queue:\n");
        int i = front;
        while (1) {
            printf("%d\n", array[i]);
            if (i == rear) break;
            i = (i + 1) % size;
        }
    }
}
void main() {
    int size, decision = 1, choice, num;
    printf("Enter maximum size of circular queue: ");
    scanf("%d", &size);
    while (decision == 1) {
        printf("\nEnter 1 for Enqueue, 2 for Dequeue: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            enqueue(num, size);
        } else if (choice == 2) {
            dequeue(size);
        } else {
            printf("Invalid option.\n");
        }
        printf("\nDo you want to continue:Enter 1 for Yes and 2 for No ");
        scanf("%d", &decision);
    }
}
