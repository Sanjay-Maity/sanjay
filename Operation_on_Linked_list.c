#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void createLinkedlist()
{
    struct Node *temp, *plove;
    int ch, data;
    do
    {
        if (head == NULL)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter data to store : ");
            scanf("%d", &head->data);
            // head->data = data;
            head->next = NULL;
            temp = head;
        }
        else
        {
            plove = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter data to store : ");
            scanf("%d", &plove->data);
            // plove->data = data;
            plove->next = NULL;
            temp->next = plove;
            temp = plove;
        }
        printf("If you want to enter more data then Enter 1 else 0 : ");
        scanf("%d", &ch);
    } while (ch);
}

void insert_before_head(int data)
{
    struct Node *plove = (struct Node *)malloc(sizeof(struct Node));
    plove->data = data;
    plove->next = head;
    head = plove;
}
void insert_after_a_given_data_of_linked_list(int data, int item)
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            struct Node *plove = (struct Node *)malloc(sizeof(struct Node));
            plove->data = data;
            plove->next = temp->next;
            temp->next = plove;
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("%d data not added in linked list \n");
    }
}

void reverse_linkedList()
{
    struct Node *current, *plove;
    current = NULL;
    plove = NULL;
    while (head != NULL)
    {
        current = head->next;
        head->next = plove;
        plove = head;
        head = current;
    }
    head = plove;
}
void display()
{
    printf("your linked list element : \n");
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void search(int item)
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            printf("\nItem %d situated in the linked list \n", item);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nItem %d not found in linked list : \n", item);
    }
}

void delete_a_node(int item)
{
    struct Node *plove;
    plove = head;
    int flag = 0;
    if (plove->data == item)
    {
        head = plove->next;
        free(plove);
        printf("Delete success\n");
        return;
    }
    struct Node *temp;
    temp = head->next;
    while (temp != NULL)
    {

        if (temp->data == item)
        {
            plove->next = temp->next;
            free(temp);
            printf("Delete success\n");
            break;
        }
        temp = temp->next;
        plove = plove->next;
    }
    if (temp == NULL)
    {
        printf("%d item not in the linkedlist \n", item);
    }
}

void main()
{
    head = NULL;

    createLinkedlist();
    printf("\n");
    display();
    int item;
    // ***************Insert Element At FIrst******************
    // printf("\nEnter data to add at the first of linked list : ");
    // scanf("%d", &item);
    // insert_before_head(item);
    // printf("\n");
    // display();
    // *****************Insert Enlement Ater Any given data of linked list*****************
    printf("\n");
    int data;
    printf("Enter data to add after any data of linked list : ");
    scanf("%d", &data);
    printf("Enter the data of linked list after which you want to add the data : ");
    scanf("%d", &item);
    insert_after_a_given_data_of_linked_list(data, item);
    printf("\n");
    display();

    // ***************Reverse Linked list******************
    // reverse_linkedList();
    // printf("\n");
    // display();

    // *******************search Element****************
    // printf("\nEnter search Element : ");
    // scanf("%d", &item);
    // search(item);

    // ****************delete node from linked list*********************
    // printf("\nEnter the data of node which you want to delete : ");
    // scanf("%d", &item);
    // delete_a_node(item);
    // printf("\n");
    // display();
}
