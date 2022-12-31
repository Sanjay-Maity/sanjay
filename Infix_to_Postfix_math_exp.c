#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};
struct Node *head;
// head = NULL;

int IsEmpty(struct Node *t_head)
{
    if (t_head == NULL)
    {
        return 1;
    }
    return 0;
}

int Is_Operator(char love)
{
    if (love == '*' || love == '-' || love == '+' || love == '/' || love == '%' || love == '^')
    {
        return 1;
    }
    return 0;
}

int Is_Start_Parentheses(char joker)
{
    if (joker == '(' || joker == '{' || joker == '[')
    {
        return 1;
    }
    return 0;
}

int Is_End_Parentheses(char joker)
{
    if (joker == ')' || joker == '}' || joker == ']')
    {
        return 1;
    }
    return 0;
}

int parentheses_precedence(char love)
{
    if (love == '(' || love == ')')
    {
        return 2;
    }
    if (love == '{' || love == '}')
    {
        return 1;
    }
}

int Operator_precedence(char love)
{
    if (love == '^')
    {
        return 6;
    }
    if (love == '*' || love == '/' || love == '%')
    {
        return 5;
    }
    if (love == '+' || love == '-')
    {
        return 4;
    }
}

void push(char data)
{
    struct Node *purba = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    purba->data = data;
    purba->next = NULL;
    if (head == NULL)
    {
        head = purba;
    }
    else
    {
        purba->next = head;

        head = purba;
    }
    // return t_head;
}

void display(struct Node *purba)
{
    printf("\n **** Your Stack Element : ----\n");
    while (purba != NULL)
    {
        printf("%c\t", purba->data);
        purba = purba->next;
    }
}

char pop()
{
    if (!IsEmpty(head))
    {
        struct Node *temp;
        temp = head;
        char ch = temp->data;
        head = head->next;
        free(temp);
        return ch;
    }
    return 0;
}
char stack_TopElement()
{
    return head->data;
}

void Infix_to_Postfix(char Infix[])
{
    int i = 0, j = 0;
    while (Infix[i] != '\0')
    {
        if (Is_Operator(Infix[i]) || Is_Start_Parentheses(Infix[i]) || Is_End_Parentheses(Infix[i]))
        {
            if (Is_Operator(Infix[i]) || Is_Start_Parentheses(Infix[i]))
            {
                if (IsEmpty(head))
                {
                    if (Is_Start_Parentheses(Infix[i]))
                    {
                        if (Infix[i] == '(')
                        {
                            push(')');
                            i++;
                        }
                        if (Infix[i] == '{')
                        {
                            push('}');
                            i++;
                        }
                    }
                    else
                    {
                        push(Infix[i]);
                        i++;
                    }
                }
                else
                {
                    if (Is_Start_Parentheses(Infix[i]) || Is_End_Parentheses(stack_TopElement()) || Operator_precedence(stack_TopElement()) < Operator_precedence(Infix[i]))
                    {
                        if (Is_Start_Parentheses(Infix[i]))
                        {
                            if (Infix[i] == '(')
                            {
                                push(')');
                                i++;
                            }
                            if (Infix[i] == '{')
                            {
                                push('}');
                                i++;
                            }
                        }
                        else
                        {
                            push(Infix[i]);
                            i++;
                        }
                    }

                    else
                    {
                        printf("%c", pop());
                        // j++;
                    }
                }
            }
            else
            {
                while (stack_TopElement() != Infix[i])
                {
                    j++;
                    char ch = pop();
                    if (!Is_Start_Parentheses(ch))
                    {
                        printf("%c", ch);
                    }
                }
                pop();
                i++;
            }
        }
        else
        {
            printf("%c", Infix[i]);
            // j++;
            i++;
        }
    }

    while (!IsEmpty(head))
    {
        printf("%c", pop());
    }
}

void main()
{
    // struct Node *head;
    head = NULL;
    int size;
    printf("Enter the total element no of your Infix Equeation : ");
    scanf("%d", &size);
    // char *Infix = (char *)malloc(size * sizeof(char));
    // char *Postfix = (char *)malloc((size + 1) * sizeof(char));
    char Infix[size];
    printf("Enter your Infix Equeation : ");
    scanf("%s", Infix);
    // printf("\n %s", Infix);
    Infix_to_Postfix(Infix);

    // printf("\n %c", Postfix[0]);
}