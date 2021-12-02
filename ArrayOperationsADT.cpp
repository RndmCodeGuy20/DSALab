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

int main()
{
    struct structArr strArr;
    int aS, tS;

    cout << "Enter the total size : ";
    cin >> tS;

    cout << "Enter the actual size : ";
    cin >> aS;

    createArr(&strArr, tS, aS);
    setValue(&strArr);
    showArr(&strArr);

    return 0;
}