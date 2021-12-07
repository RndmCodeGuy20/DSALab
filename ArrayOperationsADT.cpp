#include <iostream>
using namespace std;

struct structArr
{
    int *arrPtr;
    int actualSize;
    int totalSize;
};

void createArr(struct structArr *strArr, int tSize, int acSize)
{
    strArr->totalSize = tSize;
    strArr->actualSize = acSize;
    strArr->arrPtr = (int *)calloc(tSize, sizeof(int));
}

void setValue(struct structArr *Arr)
{
    cout << "Enter the elements in the array : ";
    for (int i = 0; i < Arr->actualSize; i++)
    {
        scanf("%d", &(Arr->arrPtr)[i]);
    }
}

void showArr(struct structArr *Arr)
{
    for (int i = 0; i < Arr->actualSize; i++)
    {
        printf("Element at %d is : %d\n", i, Arr->arrPtr[i]);
    }
}

void insertElArr(struct structArr *Arr, int choice, int insEl)
{
    Arr->actualSize++;
    choice = Arr->actualSize - choice;

    for (int i = 0; i < choice; i++)
    {
        Arr->arrPtr[Arr->actualSize - i] = Arr->arrPtr[Arr->actualSize - i - 1];
    }

    Arr->arrPtr[Arr->actualSize - choice] = insEl;

    for (int i = 0; i < Arr->actualSize; i++)
    {
        printf("Element at %d is : %d\n", i, Arr->arrPtr[i]);
    }
}

void insertElArrEnd(struct structArr *Arr, int insEl)
{
    Arr->actualSize++;
    Arr->arrPtr[Arr->actualSize - 1] = insEl;

    for (int i = 0; i < Arr->actualSize; i++)
    {
        printf("Element at %d is : %d\n", i, Arr->arrPtr[i]);
    }
}

void arrDelEl(struct structArr *Arr, int pos)
{
    // array() = {1,2,3,4,5,6,7,999}

    for (int i = pos; i < Arr->actualSize; i++)
    {
        Arr->arrPtr[i] = Arr->arrPtr[i + 1];
    }
    Arr->arrPtr[Arr->actualSize - 1] = 999;

    for (int i = 0; i < Arr->actualSize; i++)
    {
        if (Arr->arrPtr[i] == 999)
        {
            break;
        }

        printf("Element at %d is : %d\n", i, Arr->arrPtr[i]);
    }

    return;
}

void sortMinMaxArr(struct structArr *Arr, char Choice)
{
    int temp;
    //- Selection Sort to sort the array.

    for (int i = 0; i < Arr->actualSize; ++i)
    {
        for (int j = i + 1; j < Arr->actualSize; ++j)
        {
            if (Arr->arrPtr[i] > Arr->arrPtr[j])
            {
                temp = Arr->arrPtr[i];
                Arr->arrPtr[i] = Arr->arrPtr[j];
                Arr->arrPtr[j] = temp;
            }
        }
    }

    switch (Choice)
    {
    case 'M':
        cout << "\nMaximum Element : " << Arr->arrPtr[Arr->actualSize - 1];
        break;

    case 'm':
        cout << "\nMinimum Element : " << Arr->arrPtr[0];
        break;

    case 'O':
        cout << "\nSorted Array : " << endl;
        for (int i = 0; i < Arr->actualSize; i++)
        {
            printf("Element at %d is : %d\n", i, Arr->arrPtr[i]);
        }
        break;

    default:
        break;
    }
}

int searchElArrBin(struct structArr *Arr, int start, int end, int searchEl)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;

        if (Arr->arrPtr[mid] == searchEl)
        {
            return mid;
        }
        if (Arr->arrPtr[mid] > searchEl)
        {
            return searchElArrBin(Arr, start, mid - 1, searchEl);
        }
        if (Arr->arrPtr[mid] < searchEl)
        {
            return searchElArrBin(Arr, mid + 1, end, searchEl);
        }
    }
    return -1;
}

void searchElArrLin(struct structArr *Arr, int serEl)
{
    int c, flag = 1;
    for (c = 0; c < Arr->actualSize; c++)
    {
        if (*(Arr->arrPtr + c) == 999)
        {
            break;
        }

        if (*(Arr->arrPtr + c) == serEl)
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

void sumAndAvg(struct structArr *Arr)
{
    int temp;
    //- Selection Sort to sort the array.

    for (int i = 0; i < Arr->actualSize; ++i)
    {
        for (int j = i + 1; j < Arr->actualSize; ++j)
        {
            if (Arr->arrPtr[i] > Arr->arrPtr[j])
            {
                temp = Arr->arrPtr[i];
                Arr->arrPtr[i] = Arr->arrPtr[j];
                Arr->arrPtr[j] = temp;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < Arr->actualSize; i++)
    {
        if (Arr->arrPtr[i] == 999)
        {
            break;
        }

        sum += Arr->arrPtr[i];
    }
    printf("Sum : %d\n", sum);

    double Avg = (double)(sum) / (double)(Arr->actualSize);
    printf("\nAverage : %d\n", Avg);
}

void mergeArr(struct structArr *Arr)
{
    int n2;
    printf("Enter number of elements in array 2 : ");
    scanf("%d", &n2);

    int *Arr2 = (int *)calloc(n2, sizeof(int));

    cout << "\nEnter the elements of the array : ";

    for (int i = 0; i <= n2 - 1; i++)
    {
        cin >> Arr2[i];
    }

    cout << "\nMerged Array : " << endl;

    int *mergedArr;
    mergedArr = (int *)calloc(Arr->actualSize + n2, sizeof(int));

    for (int i = 0; i < Arr->actualSize; i++)
    {
        mergedArr[i] = Arr->arrPtr[i];
    }

    for (int i = Arr->actualSize, j = 0; i < Arr->actualSize + n2 && j < n2; i++, j++)
    {
        mergedArr[i] = Arr2[j];
    }

    for (int i = 0; i < Arr->actualSize + n2; i++)
    {
        printf("Element at %d is : %d\n", i, mergedArr[i]);
    }
}

void intersection(struct structArr *Arr)
{
    int n2;
    printf("Enter number of elements in array 2 : ");
    scanf("%d", &n2);

    int *Arr2 = (int *)calloc(n2, sizeof(int));

    cout << "\nEnter the elements of the array : ";

    for (int i = 0; i <= n2 - 1; i++)
    {
        cin >> Arr2[i];
    }

    printf("\nIntersection ⬇️ : \n");

    for (int i = 0; i < n2; i++)
    {
        int index = searchElArrBin(Arr, 0, Arr->actualSize, Arr2[i]);

        if (index != -1)
        {
            printf("\n%d", Arr2[i]);
        }
    }
    cout << endl;
}

void isSorted(struct structArr *Arr)
{
    int flag = 1;

    for (int i = 0; i < Arr->actualSize - 1; i++)
    {
        if (Arr->arrPtr[i] > Arr->arrPtr[i + 1])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "Array is sorted!\n";
    }
    else
    {
        cout << "Array is NOT sorted\n";
    }
}

void revNew(struct structArr *Arr)
{
    int *tempArr;

    tempArr = (int *)calloc(Arr->totalSize, sizeof(int));

    for (int i = Arr->actualSize - 1, j = 0; i >= 0; i--, j++)
    {
        tempArr[j] = Arr->arrPtr[i];
    }

    free(Arr->arrPtr);
    Arr->arrPtr = tempArr;

    for (int i = 0; i < Arr->actualSize; i++)
    {
        printf("Element at %d is : %d\n", i, Arr->arrPtr[i]);
    }
}

void revSame(struct structArr *Arr)
{
    int size = Arr->actualSize, temp = 0;

    for (int i = 0; i < size / 2; i++)
    {
        temp = Arr->arrPtr[i];
        Arr->arrPtr[i] = Arr->arrPtr[size - i - 1];
        Arr->arrPtr[size - i - 1] = temp;
    }
}

int main()
{

    char Choice;
    struct structArr strArr;
    int aS, tS;

    cout << "\n\n👋👋👾👾🦖🦖🤖🤖\tArray Operations Program Using ADT - Shantanu Mane - E - 63\t👋👋👾👾🦖🦖🤖🤖\n";
    cout << "⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡";

    cout << "\n\nWhat operation do you want perform? (I -> Initialise the array ✅| X -> Exit the program❗❌) : ";
    cin >> Choice;

    switch (Choice)
    {
    case 'I':

        cout << "Enter the total size : ";
        cin >> tS;

        cout << "Enter the actual size : ";
        cin >> aS;

        createArr(&strArr, tS, aS);
        setValue(&strArr);
        break;

    case 'X':
        cout << "Exiting the program!❗🦖👋";
        break;

    default:
        cout << "Wrong Choice, exiting the program!";
        break;
    }

    char InnerChoice;

    while (true)
    {
        cout << "\n\nWhat operation do you want perform? : ";
        cout << "\nN -> Show the newly created array 👀";
        cout << "\nI -> Insert an element into the existing array 📲";
        cout << "\ni -> Insert an element in the end into the existing array 📲";
        cout << "\nD -> Delete an element from the existing array 💀";
        cout << "\nS -> Search an element in the existing array 🔍";
        cout << "\nT -> Intersection of two arrays 🧩";
        cout << "\nE -> To merge an array with the existing one ➕";
        cout << "\nM -> To find the maximum number in the array ⬆️";
        cout << "\nm -> To find the minimum number in the array ⬇️";
        cout << "\nO -> To sort the array 🧙‍♂️";
        cout << "\nU -> Sum of the elements in the array 🦖";
        cout << "\nA -> Average of the elements in the array 🦍";
        cout << "\nr -> Reverse the array into a new array 🔀";
        cout << "\nR -> Reverse the elements of the array 🔀";
        cout << "\nY -> Check if the array is sorted or not 🧙‍♂️";
        cout << "\nX -> Exit the program! ❗❌";
        cout << "\nEnter your choice : ";
        cin >> InnerChoice;

        switch (InnerChoice)
        {
        //* Show Array Function
        case 'N':
            showArr(&strArr);

        //* Delete Element Function
        case 'D':
            // delete element function
            int pos;
            cout << "Enter the element position you want to delete : ";
            cin >> pos;

            arrDelEl(&strArr, pos);
            break;

        //* Search Element Function(s)
        case 'S':
            // search element using both lin and bin
            int search;
            cout << "Enter the element you want to search : (Linear Search) : ";
            cin >> search;

            searchElArrLin(&strArr, search);

            cout << "Enter the element you want to search : (Binary Search) : ";
            cin >> search;

            int index;
            index = searchElArrBin(&strArr, 0, strArr.actualSize, search);

            if (index == -1)
            {
                cout << search << " is not present in the array\n";
            }
            else
            {
                cout << search << " is present at index " << index << " in the array\n";
            }
            break;

        //* Merge Array Function
        case 'E':
            // merge array function
            mergeArr(&strArr);
            break;

        //* Insert Element Function
        case 'I':
            // insert element function
            int Choice, insEl;

            printf("Enter the element and the position where you want to insert : ");
            scanf("%d %d", &insEl, &Choice);

            insertElArr(&strArr, Choice, insEl);
            break;

        //* Insert Element in End Function
        case 'i':
            printf("Enter the element you want to add in the end : ");
            cin >> insEl;

            insertElArrEnd(&strArr, insEl);

        //* Sort, Minimum and Maximum Element Function
        case 'M':
        case 'm':
        case 'O':
            // sort, min and max element function
            sortMinMaxArr(&strArr, InnerChoice);
            break;

        //* Intersection of Two Arrays Function
        case 'T':
            intersection(&strArr);

        //* Is Sorted or Not Function
        case 'Y':
            isSorted(&strArr);

        //* Sum and Average Function
        case 'U':
        case 'A':
            sumAndAvg(&strArr);

        //* Reverse Array in New Array
        case 'r':
            revNew(&strArr);

        //* Reverse Array in Same Array
        case 'R':
            revSame(&strArr);

        //* Exit Program
        case 'X':
            cout << "Exiting the program!❗🦖👋";
            break;

        default:
            cout << "Wrong Choice, ending the program";
            break;
        }
    }
    return 0;
}