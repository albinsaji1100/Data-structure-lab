#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int q[SIZE];
int front = 0, rear = 0;

void insertq(int item) {
    int nextRear = (rear + 1) % SIZE;
    if (nextRear == front) {
        printf("Queue is full\n");
    } else {
        rear = nextRear;
        q[rear] = item;
    }
}

int deleteq1(int *status) {
    if (front == rear) {
        *status = 0;
        printf("Queue is empty\n");
        return -1;
    } else {
        front = (front + 1) % SIZE;
        *status = 1;
        return q[front];
    }
}

int searching(int item) {
    if (front == rear) {
        // Queue empty
        return -1;
    }
    int i = (front + 1) % SIZE;
    while (i != (rear + 1) % SIZE) {
        if (q[i] == item)
            return i;
        i = (i + 1) % SIZE;
    }
    return -1;
}

int main() {
    int opt, item, status, ans;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter the option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &item);
                insertq(item);
                break;

            case 2:
                item = deleteq1(&status);
                if (status == 1)
                    printf("Deleted item = %d\n", item);
                break;

            case 3:
                printf("Enter the number to search: ");
                scanf("%d", &item);
                ans = searching(item);
                if (ans == -1)
                    printf("Item not found\n");
                else
                    printf("Item found at position %d\n", ans);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}

