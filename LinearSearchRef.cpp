#include <iostream>
using namespace std;

int linear_search(int *arr, int size, int serEl)
{
    int c;
    for (c = 0; c < size; c++)
    {
        if (*(arr + c) == serEl)
        {
            return c;
        }
    }

    return -1;
}
// scanf("%d", &array[i]);
int main()
{
    int array[10], search, c, n, position;

    printf("Enter number to search : ");
    scanf("%d", &n);

    printf("Enter array elements : ");
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    printf("Input a number to search : ");
    cin >> search;

    position = linear_search(array, n, search);

    if (position == -1)
    {
        printf("%d is NOT present!", search);
    }
    else
    {
        printf("%d is present!", search);
    }

    return 0;
}