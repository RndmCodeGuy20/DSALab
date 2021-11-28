#include <iostream>
using namespace std;

void mergeArr(int n2)
{
    int *arrPtr;

    arrPtr = (int *)calloc(n2, sizeof(int));

    cout << "Enter the elements of the array : ";
    for (int i = 0; i <= n2 - 2; i++)
    {
        cin >> arrPtr[i];
    }
    arrPtr[n2 - 1] = 99;
}

int searchElArr(int *arr, int size, int serEl)
{
    int c, flag;
    for (c = 0; c < size; c++)
    {
        if (*(arr + c) == serEl)
        {
            flag = 0;
        }
    }

    flag = 1;

    if (flag == 1)
    {
        printf("%d is NOT present!", serEl);
    }
    else if (flag == 0)
    {
        printf("%d is present!", serEl);
    }
}

void arrDelEl(int *arr, int size, int pos)
{
    // array() = {1,2,3,4,5,6,7,99}

    for (int i = pos; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 99;

    for (int i = 0; i < size; i++)
    {
        printf("Element at %d is : %d\n", i, arr[i]);
    }

    return;
}

void arrInit(int n)
{
    int *arrPtr;
    int pos, search;

    arrPtr = (int *)calloc(n, sizeof(int));

    cout << "Enter the elements of the array : ";
    for (int i = 0; i <= n - 2; i++)
    {
        cin >> arrPtr[i];
    }
    arrPtr[n - 1] = 99;

    for (int i = 0; i < n; i++)
    {
        printf("Element at %d is : %d\n", i, arrPtr[i]);
    }

    cout << "Enter the element position you want to delete : ";
    cin >> pos;

    arrDelEl(arrPtr, n, pos);

    cout << "Enter the element you want to search : ";
    cin >> search;

    pos = searchElArr(arrPtr, n, search);

    int n2;

    cout << "Enter the size of the second array : ";
    cin >> n2;

    mergeArr(n2);
}

//`IMPORTANT: Main Function
int main()
{
    int n;

    cout << "Enter the size of the array : ";
    cin >> n;

    arrInit(n);

    return 0;
}
