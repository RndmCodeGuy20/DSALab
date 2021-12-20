/**
 * @file StackArrayOperationsADT.cpp
 * @author Shantanu Mane (@RndmCodeGuy20) (shantanu.mane.200@outlook.com)
 * @brief Stack operations on an array using abstract data types (structs)
 * @version  1.0.2
 * @date 2021-12-08
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
using namespace std;

struct stackArray
{
    int *stackArrayPtr;
    int top = -1;
    int MAX_SIZE;
    int tempEl;
};

void createStack(struct stackArray *stackArray, int totalSize)
{
    stackArray->MAX_SIZE = totalSize;
    stackArray->stackArrayPtr = (int *)malloc(totalSize * sizeof(int));
}

int isEmpty(struct stackArray *stackArray)
{
    if (stackArray->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stackArray *stackArray)
{
    if (stackArray->top == stackArray->MAX_SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stackArray *stackArray, int data)
{
    if (!isFull(stackArray))
    {
        stackArray->top = stackArray->top + 1;
        stackArray->stackArrayPtr[stackArray->top] = data;
    }
    else
    {
        cout << "\nStack Overflow! No space available!💀\n";
    }
}

void pop(struct stackArray *stackArray)
{
    if (!isEmpty(stackArray))
    {
        cout << stackArray->stackArrayPtr[stackArray->top] << endl;
        stackArray->top = stackArray->top - 1;
    }
    else
    {
        cout << "\nStack is empty! Add some elements!💀\n";
    }
}

int main()
{
    struct stackArray stackArr;
    int Size;
    char choice;
    int pushNum, Empty, Full;

    cout << "Enter the size of the array : ";
    cin >> Size;

    createStack(&stackArr, Size);

    cout << "\n\n";

    while (choice != 'X')
    {
        cout << "E. Check if the stack is empty 📪 : \nF. Check if the stack is full 🌕 : \nU. Push items to the stack 📍 : \nO. Pop items from the stack 🍾 : \nX. To exit the program 💀 : " << endl;
        cout << "What operations do you want to perform on your stack : " << endl;
        cin >> choice;

        switch (choice)
        {
        case 'E':
            Empty = isEmpty(&stackArr);
            if (Empty == 1)
            {
                cout << "Stack is empty!!! Push items to the stack!!!\n"
                     << endl;
            }
            else
            {
                cout << "Stack has some elements, consider checking if the stack is full or not!!!\n"
                     << endl;
            }
            break;

        case 'F':
            Full = isFull(&stackArr);
            if (Full == 1)
            {
                cout << "Stack is Full!!! Pop items from the stack!!!\n"
                     << endl;
            }
            else
            {
                cout << "Stack has some elements, consider checking if the stack is empty or not!!!\n"
                     << endl;
            }
            break;

        case 'U':
            cout << "Enter the element you want to push into the stack : " << endl;
            cin >> pushNum;

            push(&stackArr, pushNum);
            break;

        case 'O':
            cout << "Popping item from the stack :" << endl;
            cout << "Popped element is : ";

            pop(&stackArr);
            cout << "\n\n";
            break;

        default:
            break;
        }
    }

    return 0;
}

//* wandilena@rknec.edu