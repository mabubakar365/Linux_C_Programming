#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void InsertElementToList(int data);
void PrintLinkedList();

void InsertElementToList(int data)
{
    Node * node = malloc(sizeof(Node));

    if(node == NULL)
    {
        printf("Unable to allocate memory for Node\n");
        return;
    }

    node->data = data;
    node->next = NULL;

    if(head == NULL)
    {
        head = node;
    }

    else
    {
        Node *temp;
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = node;
    }
}

void PrintLinkedList()
{
    Node *temp;
    temp = head;

    printf("head==>");

    while(temp != NULL)
    {
        printf("%d==>", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void FreeList()
{
    Node *temp;
    temp = head;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void main()
{
    PrintLinkedList();
    for(int i = 0; i < 20; i++)
    {
        InsertElementToList(i);
        PrintLinkedList();
    }
    PrintLinkedList();
    FreeList();
    PrintLinkedList();
}