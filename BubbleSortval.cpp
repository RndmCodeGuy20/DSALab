#include <iostream>
using namespace std;

void bubbleSort(int *arrPtr, int size)
{
    
}

int main()
{
    int *arr;
    int n;
    cout << "Enter Size : ";
    cin >> n;

    arr = (int *)calloc(n, sizeof(int));

    bubbleSort(arr, n);

    return 0;
}
