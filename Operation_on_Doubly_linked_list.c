#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next, *previous;
};
struct Node *head;

void create_linked_list()
{
    struct Node *temp;
    int ch;
    do
    {

        if (head == NULL)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter data to store : ");
            scanf("%d", &head->data);
            head->next = NULL;
            head->previous = NULL;
            temp = head;
        }
        else
        {
            struct Node *plove = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter data to store : ");
            scanf("%d", &plove->data);
            temp->next = plove;
            plove->next = NULL;
            plove->previous = temp;
            temp = plove;
        }
        printf("If you want to enter more data then Enter 1 else 0 : ");
        scanf("%d", &ch);
    } while (ch);
}
void insert_at_first(int data)
{
    struct Node *plove = (struct Node *)malloc(sizeof(struct Node));
    plove->data = data;
    plove->next = head;
    plove->previous = NULL;
    head->previous = plove;
    head = plove;
}

void insert_element_after_Agiven_data_of_linkedlist(int data, int item)
{
    struct Node *plove = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    plove->data = data;
    plove->next = NULL;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            if (temp->next == NULL)
            {
                plove->next = temp->next;
                plove->previous = temp;
                temp->next = plove;
            }
            else
            {
                plove->next = temp->next;
                (temp->next)->previous = plove;
                temp->next = plove;
                plove->previous = temp;
            }
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Item %d not added in the linked list \n");
    }
}

void delete_A_node(int item)
{
    struct Node *temp;
    temp = head;
    if (item == head->data)
    {
        head = temp->next;
        head->previous = NULL;
        free(temp);
        printf("\nDelete success");
        return;
    }
    struct Node *plove = head->next;
    while (plove != NULL)
    {
        if (plove->data == item)
        {
            if (plove->next == NULL)
            {
                temp->next = plove->next;
                free(plove);
                printf("\nDelete success");
                return;
            }
            else
            {
                temp->next = plove->next;
                (plove->next)->previous = temp;
                free(plove);
                printf("\nDelete success");
                return;
            }
        }
        plove = plove->next;
        temp = temp->next;
    }
}

void reverse_linked_list()
{
    struct Node *plove, *current;
    plove = NULL;
    current = NULL;
    while (head != NULL)
    {
        current = head->next;
        head->next = plove;
        plove = head;
        plove->previous = current;
        head = current;
    }
    head = plove;
}

void display()
{
    struct Node *temp;
    temp = head;
    printf("\nyour data in linked list :\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void main()
{
    head = NULL;

    create_linked_list();
    printf("\n");
    display();
    int data;
    int item;

    // ****************insert_at_first*******************
    // printf("\nEnter data to add at the first of the linked list : ");
    // scanf("%d", &data);
    // insert_at_first(data);
    // display();

    // **************insert_element_after_Agiven_data_of_linkedlist*****************
    // printf("\nEnter data to add after any given position : ");
    // scanf("%d", &data);
    // printf("Enter the data of linked list after which you want to add the data : ");
    // scanf("%d", &item);
    // insert_element_after_Agiven_data_of_linkedlist(data, item);
    // display();

    // ***************delete_A_node ********************
    // printf("\nEnter data of the node which you want to delete : ");
    // scanf("%d", &item);
    // delete_A_node(item);
    // display();
    // ***********reverse_linked_list *************
    reverse_linked_list();
    display();
}