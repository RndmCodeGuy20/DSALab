#include <iostream>
using namespace std;

void insertElArr(int *arrPtr, int n, int choice, int insEl)
{
    int *arrPtrNew = (int *)realloc(arrPtr, (n + 1) * sizeof(int));

    int newSize = n + 1;
    choice = newSize - choice;

    for (int i = 0; i < choice; i++)
    {
        arrPtrNew[newSize - i] = arrPtrNew[newSize - i - 1];
    }

    arrPtrNew[newSize - choice] = insEl;

    for (int i = 0; i < newSize; i++)
    {
        printf("Element at %d is : %d\n", i, arrPtrNew[i]);
    }
}

int main()
{
    int *arrPtr;
    int Choice, insEl, n;

    cout << "Enter the size of the array : ";
    cin >> n;

    arrPtr = (int *)calloc(n, sizeof(int));

    cout << "Enter the elements of the array : ";
    for (int i = 0; i <= n - 2; i++)
    {
        cin >> arrPtr[i];
    }
    arrPtr[n - 1] = 999;

    for (int i = 0; i < n; i++)
    {
        printf("Element at %d is : %d\n", i, arrPtr[i]);
    }

    printf("Enter the element and the position where you want to insert : ");
    scanf("%d %d", &insEl, &Choice);

    insertElArr(arrPtr, n, Choice, insEl);

    return 0;
}