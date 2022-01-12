/**
 * @file BusProblem.cpp
 * @author Shantanu Mane (@RndmCodeGuy20) (shantanu.mane.200@outlook.com)
 * @brief
 *
 * `Capacity -> 30
 * ` 2 doors
 * ` 1 entry
 * ` 2 exits
 * ` passengers can occupy seats in rear
 * ` passengers can exit in first come first serve basis
 * ` once bus is full alarms goes off
 *
 * - Front |    |     |     |     |     |     | .... |    | Rear
 * -------------------------------------------------
 * -       | 0  |  1  |  2  |  3  |  4  |  5  | ....   29
 *
 * - Front |    |     |     |     |     |     | .... |    | Rear
 * -------------------------------------------------
 * -       | 12 | 13  | 14  |  15 |  16 |  17 | ....   29
 *                      👆 insert from middle
 *                      👆 midfront
 *                              👆 midRear
 *
 * $ Data Structure used -> Modified Queue
 *
 * $ Operations possible :-
 * - Insert from middle onto front part
 * - Insert from middle onto rear part
 * - Delete from right
 * - Delete from left
 *
 * @version  1.0.4
 * @date 2022-01-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;

#define MAX_CAP 30
int busQueue[MAX_CAP];
int front = -1, rear = MAX_CAP, midF = -1, midR = MAX_CAP;

void insertRear()
{
    int inputVal;

    cout << "\nEnter passenger you want to add : " << endl;
    cin >> inputVal;

    if (midR == MAX_CAP / 2 - 1)
    {
        cout << "☢️ No seats left in rear!!! ☢️";
    }
    else if (midR == MAX_CAP && rear == MAX_CAP)
    {
        midR = rear = MAX_CAP - 1;
    }
    else
    {
        midR--;
    }

    busQueue[midR] = inputVal;
}

void insertFront()
{
    int inputVal;

    cout << "\nEnter passenger you want to add : " << endl;
    cin >> inputVal;

    if (midF == MAX_CAP / 2 - 1)
    {
        cout << "☢️ No seats left in front!!! ☢️";
    }
    else if (midF == -1 && front == -1)
    {
        front = midF = 0;
    }
    else
    {
        midF++;
    }

    busQueue[midF] = inputVal;
}

void deleteFront()
{
    if (front == -1)
    {
        cout << "☢️ No seats occupied in front!!! ☢️";
    }
    cout << "\nPassenger exitting from front end is : " << busQueue[front] << endl;
    if (front == midF) //! If the element removed from ^ is the last element condition
    {
        front = -1;
        midF = -1;
    }
    else
    {
        if (front == MAX_CAP - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void deleteRear()
{
    if (midR == MAX_CAP)
    {
        cout << "☢️ No seats occupied!!! ☢️";
    }
    cout << "\nPassenger exitting from rear end is : " << busQueue[rear] << endl;
    if (rear == midR)
    {
        rear = MAX_CAP;
        midR = MAX_CAP;
    }
    else
    {
        if (rear == MAX_CAP / 2 - 1)
        {
            rear = MAX_CAP - 1;
        }
        else
        {
            rear--;
        }
    }
}

void displayBus()
{
    if (front == -1)
    {
        cout << "☢️ No seats occupied!!! ☢️" << endl;
    }

    cout << "\nOccupied seats are : " << endl;

    while (front <= midF)
    {
        cout << busQueue[front] << endl;
        front++;
    }

    while (rear >= MAX_CAP / 2 - 1)
    {
        cout << busQueue[rear] << endl;
        rear--;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n🚌🚎🚐🚎🚌 Welcome to Mane Travels 🚌🚎🚐🚎🚌\n"
             << endl;
        cout << "0. Insert Element in Front\n1. Insert Element in Rear\n2. Delete from Front\n3. Delete from rear\n4. Display\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            insertFront();
            break;

        case 1:
            insertRear();
            break;

        case 2:
            deleteFront();
            break;

        case 3:
            deleteRear();
            break;

        case 4:
            displayBus();
            break;

        default:
            break;
        }
    } while (choice != 5);

    return 0;
}
