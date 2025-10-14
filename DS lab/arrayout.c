#include <stdio.h>
#include <stdlib.h>

int array[100];
int num;

void insertion();
void deletion();
void searching();
void sorting();
void display();

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    printf("Enter the elements:\n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Searching\n");
        printf("4. Sorting\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            searching();
            break;
        case 4:
            sorting();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}

void insertion()
{
    int number;
    printf("Enter the number to be inserted: ");
    scanf("%d", &number);

    if (num >= 100)
    {
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }

    array[num] = number;
    num++;

    printf("Element inserted successfully.\n");
    display();
}

void deletion()
{
    int ind;
    if (num <= 0)
    {
        printf("Array is empty! Nothing to delete.\n");
        return;
    }

    printf("Enter the index of element to delete (0 to %d): ", num - 1);
    scanf("%d", &ind);

    if (ind < 0 || ind >= num)
    {
        printf("Invalid index!\n");
        return;
    }

    for (int j = ind; j < num - 1; j++)
    {
        array[j] = array[j + 1];
    }

    num--;
    printf("Element deleted successfully.\n");
    display();
}

void searching()
{
    int tosearch;
    int found = 0;

    printf("Enter element to search: ");
    scanf("%d", &tosearch);

    for (int i = 0; i < num; i++)
    {
        if (array[i] == tosearch)
        {
            printf("%d found at position %d (index %d)\n", tosearch, i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("%d is not found in the array\n", tosearch);
    }
}

void sorting()
{
    int i, j, temp;

    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("Array sorted in ascending order.\n");
    display();
}

void display()
{
    if (num == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements are:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

