#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

typedef struct {
    pthread_t tid;
    struct Node *next;
} Node;

Node *head = NULL;

void InsertTreadsToList(int data);
void PrintThreadList();

void InsertTreadsToList(int data)
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
    
}