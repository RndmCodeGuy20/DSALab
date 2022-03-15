/**
 * @file DoubleLinkedListOps.cpp
 * @author Shantanu Mane (@RndmCodeGuy20) (shantanu.mane.200@outlook.com)
 * @brief Operations on a doubly linked list.
 * @version  3.2.0
 * @date 2022-02-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createNodeList(struct node *head)
{
    struct node *newNode, *ptr;
    int num;

    printf("\nEnter data of the node : ");
    scanf("%d", &num);

    if (head == NULL)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->prev = NULL;
        newNode->data = num;
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        ptr = head;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newNode;
        newNode->prev = ptr;
        newNode->next = NULL;
    }

    return head;
}

struct node *dispList(struct node *head)
{
    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("->  |  %d  |  ", ptr->data);
        ptr = ptr->next;
    }

    return head;
}

struct node *insBegin(struct node *head)
{
    struct node *newNode;
    int num;

    printf("\nEnter the data : ");
    scanf("%d", &num);

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = num;
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;

    head = newNode;

    return head;
}

struct node *insEnd(struct node *head)
{
    struct node *ptr, *newNode;
    int num;

    printf("\n Enter the data : ");
    scanf("%d", &num);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = NULL;

    return head;
}

struct node *insSpec(struct node *head)
{
    struct node *ptr, *newNode;
    int num;

    newNode = (struct node *)malloc(sizeof(struct node));
    int loc;

    if (newNode == NULL)
    {
        printf("\n💀💀💀No NODES in the LIST!!!💀💀💀\n");
    }
    else
    {
        printf("\nEnter the location : ");
        scanf("%d", &loc);

        printf("\nEnter the data : ");
        scanf("%d", &num);

        ptr = head;

        for (int i = 0; i < loc; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("\nNo node left to connect!\n");
                return 0;
            }
        }

        newNode->data = num;
        newNode->next = ptr->next;
        newNode->prev = ptr;
        ptr->next = newNode;
        ptr->next->prev = newNode;
    }

    return head;
}

struct node *delBegin(struct node *head)
{
    struct node *ptr;
    ptr = head;

    head = head->next;
    head->prev = NULL;

    free(ptr);

    return head;
}

struct node *delEnd(struct node *head)
{
    struct node *ptr;
    ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;

    free(ptr);

    return head;
}

struct node *revList(struct node *head)
{
    struct node *ptr, *temp;

    if (head == NULL)
    {
        return 0;
    }

    while (ptr != NULL)
    {
        temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;
        ptr = temp;
    }

    head = ptr;

    return head;
}

int getLength(struct node *head)
{
    int count = 0;

    if (head == NULL)
    {
        return count;
    }

    struct node *ptr = head;

    while (ptr != NULL)
    {
        ++count;
        ptr = ptr->next;
    }

    return count;
}

void sortList(struct node *head)
{
    struct node *current = NULL, *ptr = NULL;
    int temp;
    if (head == NULL)
    {
        return;
    }
    else
    {
        for (current = head; current->next != NULL; current = current->next)
        {
            for (ptr = current->next; ptr != NULL; ptr = ptr->next)
            {
                if (current->data > ptr->data)
                {
                    temp = current->data;
                    current->data = ptr->data;
                    ptr->data = temp;
                }
            }
        }
    }
}

int main()
{
    struct node *head = NULL;

    char choice;
    int length;

    do
    {
        cout << "\n🔗🔗 Doubly Linked List Program 🔗🔗\n"
             << endl;
        cout << "N. Create a Node List\nA. Insert Element in Beginning\nB. Insert Element in End\nC. Delete from Beginning\nD. Delete from End\nE. Display\nF. Insert at Specific Position\nR. Reverse the List\nL. Get Length of List\nS. Sort the List\nEnter your choice : ";
        ;
        cin >> choice;

        switch (choice)
        {
        case 'N':
            head = createNodeList(head);
            break;

        case 'A':
            head = insBegin(head);
            break;

        case 'B':
            head = insEnd(head);
            break;

        case 'C':
            head = delBegin(head);
            break;

        case 'D':
            head = delEnd(head);
            break;

        case 'E':
            head = dispList(head);
            break;

        case 'F':
            head = insSpec(head);
            break;

        case 'R':
            head = revList(head);
            break;

        case 'L':
            length = getLength(head);
            printf("Length of Linked List : %d\n", length);
            break;

        case 'S':
            sortList(head);
            break;

        default:
            break;
        }

    } while (choice != 'X');

    return 0;
}