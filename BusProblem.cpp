#include <iostream>
using namespace std;

#define MAX_CAP 5
int busQueue[MAX_CAP];
int front = -1, rear = -1;

void insertRear()
{
    int inputVal;

    cout << "\nEnter passenger you want to add : " << endl;
    cin >> inputVal;

    if (rear == MAX_CAP - 1)
    {
        cout << "☢️ No seats left!!! ☢️";
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    busQueue[rear] = inputVal;
}

void deleteFront()
{
    if (front == -1)
    {
        cout << "☢️ No seats occupied!!! ☢️";
    }
    cout << "\nPassenger exitting from front end is : " << busQueue[front] << endl;
    if (front == rear) //! If the element removed from ^ is the last element condition
    {
        front = -1;
        rear = -1;
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
    if (rear == -1)
    {
        cout << "☢️ No seats occupied!!! ☢️";
    }
    cout << "\nPassenger exitting from rear end is : " << busQueue[rear] << endl;
    if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        if (rear == 0)
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

    if (front <= rear)
    {
        while (front <= rear)
        {
            cout << busQueue[front] << endl;
            front++;
        }
    }
    else
    {
        while (front <= MAX_CAP - 1)
        {
            cout << busQueue[front] << endl;
            front++;
        }
        front = 0;
        while (front <= rear)
        {
            cout << busQueue[front] << endl;
            front++;
        }
    }
}

/**
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
 *
 * $ Data Structure used -> Input Restricted Dequeue
 *
 * $ Operations possible :-
 * - Insert Rear
 * - Delete from right
 * - Delete from left
 *
 */

int main()
{
    int choice;

    do
    {
        cout << "1. Insert Element\n2. Delete from Front\n3. Delete from rear\n4. Display" << endl;
        cin >> choice;

        switch (choice)
        {
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

    // insertRear();
    // insertRear();
    // insertRear();
    // insertRear();

    // deleteFront();
    // deleteRear();

    // displayBus();

    return 0;
}
