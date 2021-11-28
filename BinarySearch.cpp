#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int searchEl)
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
            return binarySearch(arr, start, mid - 1, searchEl);
        }
        if (arr[mid] < searchEl)
        {
            return binarySearch(arr, mid + 1, end, searchEl);
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {4, 9, 12, 16, 21, 33, 37, 45, 49, 52, 56, 63, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num;

    cout << "Enter the number to search: \n";
    cin >> num;

    int index = binarySearch(arr, 0, n - 1, num);
    if (index == -1)
    {
        cout << num << " is not present in the array";
    }
    else
    {
        cout << num << " is present at index " << index << " in the array";
    }
    return 0;
}