#include <iostream>
using namespace std;

//`REVIEW: Function to sort the array and to find the Minimum and Maximum terms.
void sortMinMaxArr(int *arrPtr, int size, char Choice)
{
    int temp;
    //- Selection Sort to sort the array.

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arrPtr[i] > arrPtr[j])
            {
                temp = arrPtr[i];
                arrPtr[i] = arrPtr[j];
                arrPtr[j] = temp;
            }
        }
    }

    switch (Choice)
    {
    case 'M':
        cout << "\nMaximum Element : " << arrPtr[size - 1];
        break;

    case 'm':
        cout << "\nMinimum Element : " << arrPtr[0];
        break;

    case 'O':
        cout << "\nSorted Array : " << endl;
        for (int i = 0; i < size; i++)
        {
            printf("Element at %d is : %d\n", i, arrPtr[i]);
        }
        break;

    default:
        break;
    }
}

//`REVIEW: Function to insert an element in the array.
void insertElArr(int *arrPtr, int n, int choice, int insEl)
{
    int *arrPtrNew = (int *)realloc(arrPtr, (n + 1) * sizeof(int));

    int newSize = n + 1;
    choice = newSize - choice;
    
    for (int i = 0; i < newSize - choice; i++)
    {
        arrPtrNew[newSize - i] = arrPtrNew[newSize - i - 1];
    }

    arrPtrNew[newSize - choice] = insEl;

    for (int i = 0; i < newSize; i++)
    {
        printf("Element at %d is : %d\n", i, arrPtrNew[i]);
    }
}

//`REVIEW: Function to merge two arrays.
void mergeArr(int *arrPtr, int n1, int n2)
{
    int *arr2Ptr;
    arr2Ptr = (int *)calloc(n2, sizeof(int));

    cout << "\nEnter the elements of the array : ";
    for (int i = 0; i <= n2 - 2; i++)
    {
        cin >> arr2Ptr[i];
    }
    arr2Ptr[n2 - 1] = 999;

    for (int i = 0; i < n2; i++)
    {
        printf("Element at %d is : %d\n", i, arr2Ptr[i]);
    }

    int *mergedArr;
    mergedArr = (int *)calloc(n1 + n2, sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        mergedArr[i] = arrPtr[i];
    }

    for (int i = n1, j = 0; i < n1 + n2 && j < n2; i++, j++)
    {
        mergedArr[i] = arr2Ptr[j];
    }

    cout << "\n\n";

    for (int i = 0; i < n1 + n2; i++)
    {
        printf("Element at %d is : %d\n", i, mergedArr[i]);
    }
}

//`REVIEW: Function to search an element in the array using binary search.
int searchElArrBin(int arr[], int start, int end, int searchEl)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == searchEl)
        {
            return mid;
        }
        if (arr[mid] > searchEl)
        {
            return searchElArrBin(arr, start, mid - 1, searchEl);
        }
        if (arr[mid] < searchEl)
        {
            return searchElArrBin(arr, mid + 1, end, searchEl);
        }
    }
    return -1;
}

//`REVIEW: Function to search an element in an array using linear search.
void searchElArrLin(int *arr, int size, int serEl)
{
    int c, flag = 1;
    for (c = 0; c < size; c++)
    {
        if (*(arr + c) == 999)
        {
            break;
        }

        if (*(arr + c) == serEl)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        printf("\n%d is NOT present!\n", serEl);
    }
    else if (flag == 0)
    {
        printf("\n%d is present!\n", serEl);
    }
}

//`REVIEW: Function to delete an element in the array.
void arrDelEl(int *arr, int size, int pos)
{
    // array() = {1,2,3,4,5,6,7,999}

    for (int i = pos; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 999;

    for (int i = 0; i < size; i++)
    {
        printf("Element at %d is : %d\n", i, arr[i]);
    }

    return;
}

//`REVIEW: Function to initialise an array.
void arrInitOps(int n)
{
    int *arrPtr;
    int pos, search;
    char InnerChoice;

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

    cout << "\n\n👋👋👾👾🦖🦖🤖🤖\tArray Operations Program - Main Menu\t👋👋👾👾🦖🦖🤖🤖\n";
    cout << "⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡";

    while (true)
    {

        cout << "\n\nWhat operation do you want perform? : ";
        cout << "\nD -> Delete an element from the existing array 💀";
        cout << "\nS -> Search an element in the existing array 🔍";
        cout << "\nE -> To merge an array with the existing one ➕";
        cout << "\nI -> Insert an element into the existing array 📲";
        cout << "\nM -> To find the maximum number in the array ⬆️";
        cout << "\nm -> To find the minimum number in the array ⬇️";
        cout << "\nO -> To sort the array 🧙‍♂️";
        cout << "\nX -> Exit the program! ❗❌";
        cout << "\nEnter your choice : ";
        cin >> InnerChoice;

        switch (InnerChoice)
        {
        case 'D':
            // delete element function
            cout << "Enter the element position you want to delete : ";
            cin >> pos;

            arrDelEl(arrPtr, n, pos);
            break;

        case 'S':
            // search element using both lin and bin
            cout << "Enter the element you want to search : (Linear Search)";
            cin >> search;

            searchElArrLin(arrPtr, n, search);

            cout << "Enter the element you want to search : (Binary Search)";
            cin >> search;

            int index;
            index = searchElArrBin(arrPtr, 0, n - 1, search);

            if (index == -1)
            {
                cout << search << " is not present in the array\n";
            }
            else
            {
                cout << search << " is present at index " << index << " in the array\n";
            }
            break;

        case 'E':
            // merge array function
            int n2;

            cout << "Enter the size of the second array : ";
            cin >> n2;

            mergeArr(arrPtr, n, n2);
            break;

        case 'I':
            // insert element function
            int Choice, insEl;

            printf("Enter the element and the position where you want to insert : ");
            scanf("%d %d", &insEl, &Choice);

            insertElArr(arrPtr, n, Choice, insEl);
            break;

        case 'M':
        case 'm':
        case 'O':
            // sort, min and max element function
            sortMinMaxArr(arrPtr, n, InnerChoice);
            break;

        case 'X':
            cout << "Exiting the program!❗🦖👋";
            break;

        default:
            cout << "Wrong Choice, ending the program";
            break;
        }
    }
}

//`IMPORTANT: Main Function
int main()
{
    int n;
    char Choice;

    cout << "\n\n👋👋👾👾🦖🦖🤖🤖\tArray Operations Program - Shantanu Mane - E - 63\t👋👋👾👾🦖🦖🤖🤖\n";
    cout << "⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡";

    cout << "\n\nWhat operation do you want perform? (I -> Initialise the array ✅| X -> Exit the program❗❌) : ";
    cin >> Choice;

    switch (Choice)
    {
    case 'I':
        cout << "\n\nEnter the size of the array : ";
        cin >> n;
        arrInitOps(n);
        break;

    case 'X':
        cout << "Exiting the program!❗🦖👋";
        break;

    default:
        cout << "Wrong Choice, exiting the program!";
        break;
    }

    return 0;
}
