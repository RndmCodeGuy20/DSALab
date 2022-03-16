#include <iostream>
using namespace std;

struct node
{
    int priority;
    int data;
    struct node *link;
};

void enQ(struct node *ptr, int priority, int data)
{
    struct node *newNode;
    struct node *trail = ptr;
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->priority = priority;
    newNode->link = NULL;

    if (ptr == NULL)
    {
        ptr = newNode;
    }

    if (ptr != NULL)
    {
        if (ptr->priority > newNode->priority)
        {
            newNode->link = ptr;
            ptr = newNode;
        }

        while (ptr)
        {
            ptr = ptr->link;

            if (ptr->priority > newNode->priority)
            {
                trail->link = newNode;
                newNode->link = ptr;
            }

            trail = ptr;
        }
    }
}

void dispList(struct node *ptr)
{
    while (ptr)
    {
        printf("\t|  %d   |   %d   |   🔗 \t", ptr->data, ptr->priority);
        ptr = ptr->link;
    }
}

int main()
{
    struct node *head = NULL;

    enQ(head, 3, 392);
    enQ(head, 2, 39);
    enQ(head, 4, 2);
    enQ(head, 1, 92);

    dispList(head);

    return 0;
}