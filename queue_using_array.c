#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display();

int front, rear;
int SIZE, arr[20];

void main()
{
    int i;
    int choice;
    front = rear = -1;
    printf("Enter the size of the Queue\n");
    scanf("%d", &SIZE);
    while(1)
    {
        printf("\n1.Add Element to the Queue\n");
        printf("2.Delete Element from the Queue\n");
        printf("3.Display the Queue\n");
        printf("4.Exit the Program\n");
        printf("-----------------------------------\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            case 4: exit(0);
            default: printf("You have entered a wrong choice\n");
        }
    }
}

void enqueue()
{
    int elem;
    if(rear == SIZE - 1)
        printf("The Queue is already Full\n");
    else
    {
        if(front == -1)
            front = 0;
        printf("Enter the element to be inserted\n");
        scanf("%d", &elem);
        rear++;
        arr[rear] = elem;
    }
}

void dequeue()
{
    if(front == -1)
        printf("The Queue is Empty\n");
    else
    {
        printf("%d is removed from the queue\n", arr[front]);
        if(front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void display()
{
    int i;
    if(front == -1)
        printf("The Queue is Empty\n");
    else
    {
        printf("\nElements of the Queue Are:\n");
        for(i = front; i <= rear; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\nFront= %d, Rear= %d", front, rear);
    }
}
