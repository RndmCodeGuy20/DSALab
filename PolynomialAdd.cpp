/**
 * @file PolynomialAdd.cpp
 * @author Shantanu Mane (@RndmCodeGuy20) (shantanu.mane.200@outlook.com)
 * @brief Program to add two polynomials using Linked List.
 * @version  1.0.3
 * @date 2022-01-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
using namespace std;

struct node
{
    int coeff, deg;
    struct node *next;
};

struct node *createNode(struct node *head, int co, int de)
{
    struct node *ptr, *newNode;
    ptr = (struct node *)malloc(sizeof(struct node));
    newNode = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        newNode->coeff = co;
        newNode->deg = de;
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        newNode->coeff = co;
        newNode->deg = de;
        newNode->next = NULL;

        ptr->next = newNode;
    }

    return head;
}

struct node *addPoly(struct node *P, struct node *Q, struct node *sum)
{
    struct node *p1 = P, *p2 = Q, *rez;

    if (p1 != NULL && p2 == NULL)
    {
        sum = p1;
        return sum;
    }
    else if (p1 == NULL && p2 != NULL)
    {
        sum = p2;
        return sum;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (sum == NULL)
        {
            sum = (struct node *)malloc(sizeof(struct node));
            rez = sum;
        }
        else
        {
            rez->next = (struct node *)malloc(sizeof(struct node));
            rez = rez->next;
        }

        if (p1->deg > p2->deg)
        {
            rez->coeff = p1->coeff;
            rez->deg = p1->deg;
            p1 = p1->next;
        }
        else if (p2->deg > p1->deg)
        {
            rez->coeff = p2->coeff;
            rez->deg = p2->deg;
            p2 = p2->next;
        }
        else if (p1->deg == p2->deg)
        {
            rez->coeff = p1->coeff + p2->coeff;
            rez->deg = p1->deg;
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        rez->next = (struct node *)malloc(sizeof(struct node));
        rez = rez->next;

        rez->coeff = p1->coeff;
        rez->deg = p1->deg;
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        rez->next = (struct node *)malloc(sizeof(struct node));
        rez = rez->next;

        rez->coeff = p2->coeff;
        rez->deg = p2->deg;
        p2 = p2->next;
    }

    rez->next = NULL;

    return sum;
}

void dispPoly(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->coeff << "x^" << ptr->deg << " + ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    struct node *P = NULL, *Q = NULL, *sum = NULL;
    int coeff, deg;

    P = createNode(P, 10, 0);
    P = createNode(P, 30, 3);
    P = createNode(P, 15, 2);

    dispPoly(P);

    Q = createNode(Q, 20, 2);
    Q = createNode(Q, 10, 1);
    Q = createNode(Q, 9, 0);

    dispPoly(Q);

    sum = addPoly(P, Q, sum);
    dispPoly(sum);

    return 0;
}