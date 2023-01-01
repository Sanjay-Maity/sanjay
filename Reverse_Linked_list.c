#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void display()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
}

void reverse()
{
    struct Node *current, *prev;
    current = NULL;
    prev = NULL;
    while (head != NULL)
    {
        current = head->next;
        head->next = prev;
        prev = head;
        head = current;
    }
    head = prev;
}
void main()
{
    head = NULL;
    struct Node *p1, *p2, *p3, *p4, *p5, *p6;
    p1 = (struct Node *)malloc(sizeof(struct Node));
    p2 = (struct Node *)malloc(sizeof(struct Node));
    p3 = (struct Node *)malloc(sizeof(struct Node));
    p4 = (struct Node *)malloc(sizeof(struct Node));
    p5 = (struct Node *)malloc(sizeof(struct Node));
    p6 = (struct Node *)malloc(sizeof(struct Node));
    p1->data = 1;
    p1->next = p2;
    p2->data = 2;
    p2->next = p3;
    p3->data = 3;
    p3->next = p4;
    p4->data = 4;
    p4->next = p5;
    p5->data = 5;
    p5->next = p6;
    p6->data = 6;
    p6->next = NULL;
    head = p1;
    printf("\n");
    display();
    reverse();
    printf("\n");
    display();
}