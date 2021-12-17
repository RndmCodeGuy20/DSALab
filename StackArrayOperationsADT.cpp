/**
 * @file StackArrayOperationsADT.cpp
 * @author Shantanu Mane (@RndmCodeGuy20) (shantanu.mane.200@outlook.com)
 * @brief 
 * @version  420.69
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
        // stackArray->tempEl = stackArray[stackArray->top];
        cout << stackArray->stackArrayPtr[stackArray->top] << endl;
        stackArray->top = stackArray->top - 1;
        // return stackArray->tempEl;
    }
    else
    {
        cout << "\nStack is empty! Add some elements!💀";
        // return -1;
    }
}

int main()
{
    struct stackArray stackArr;
    int Size;

    cout << "Enter the size of the array : ";
    cin >> Size;

    createStack(&stackArr, Size);

    cout << "\n\n";

    for (int i = 0; i < Size; i++)
    {
        // cin >> stackArr.tempEl;
        // push(&stastackArr.tempEl);

        push(&stackArr, i + 10);
    }

    // for (int i = 0; i < Size; i++)
    // {
    //     cout << stackArr.stackArrayPtr[i] << endl;
    // }

    for (int i = 0; i < Size; i++)
    {
        pop(&stackArr);
    }

    return 0;
}

//* wandilena@rknec.edu