#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
}*front,*back,*temp,*first;

int top();
void push(int data);
void pop();
void empty();
void display();
void size();
int count = 0;

void main()
{
    int no, option, first_element;
    front = back = NULL;

    do
    {
        system("cls");
        printf("\n 1 - push");
        printf("\n 2 - pop");
        printf("\n 3 - Top");
        printf("\n 4 - Empty");
        printf("\n 5 - Display");
        printf("\n 6 - size");
        printf("\n 7 - Exit");
        printf("\n Enter choice : ");
        scanf("%d", &option);
        if( option == 1)
        {
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
        }
        else if(option == 2)
        {
            pop();
        }
        else if (option == 3)
        {
            first_element = top();
            if (first_element != 0)
                printf("Top element is: %d", first_element);
            else
                printf("\n There's no top element as queue is empty. ");
            getchar();
            printf("\n\nPress Enter to Continue\n");
            getchar();
        }
        else if (option == 4)
        {
            empty();
            getchar();
            printf("\n\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 5)
        {
            display();
            getchar();
            printf("\n\nPress Enter to Continue\n");
            getchar();
        }
        else if( option == 6)
        {
            size();
            getchar();
            printf("\n\nPress Enter to Continue\n");
            getchar();
        }
        else if (option == 7)
        {
            exit(0);
        }
        else
        {
            printf("Invalid Option!");
            getchar();
            printf("\n\nPress Enter to Continue\n");
            getchar();
        }
    }
    while(option != 7);
}




/* Inserting elements in the queue */
void push(int data)
{
    if (back == NULL)
    {
        back = (struct node *)malloc(sizeof(struct node));
        back->next = NULL;
        back->value = data;
        front = back;
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        back->next = temp;
        temp->value = data;
        temp->next = NULL;

        back = temp;
    }
    count++;
}

/* Displaying the queue elements */
void display()
{
    first = front;

    if ((first == NULL) && (back == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (first != back)
    {
        printf("%d ", first->value);
        first = first->next;
    }
    if (first == back)
        printf("%d", first->value);
}

/* Deleting value from the queue */
void pop()
{
    first = front;

    if (first == NULL)
    {
        printf("\n No elements, empty queue");
        return;
    }
    else if (first->next != NULL)
    {
        first = first->next;
        printf("\n Deleted value : %d", front->value);
        free(front);
        front = first;
    }
    else
    {
        printf("\n Deleted value : %d", front->value);
        free(front);
        front = NULL;
        back = NULL;
    }
    count--;
    getchar();
    printf("\n\nPress Enter to Continue\n");
    getchar();
}

/* Top element of queue */
int top()
{
    if ((front != NULL) && (back != NULL))
        return(front->value);
    else
        return 0;
    getchar();
    printf("\n\nPress Enter to Continue\n");
    getchar();
}

/* Checking if the queue empty or not */
void empty()
{
    if ((front == NULL) && (back == NULL))
        printf("\n Queue is empty");
    else
        printf("Queue isn't empty");

}
/*Checking queue size */
void size()
{
    printf("\n Queue size : %d", count);
}
