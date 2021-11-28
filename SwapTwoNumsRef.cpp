#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    int a = 10, b = 20;

    printf("Before Swapping :\n");
    printf("Number 1 : %d\nNumber 2 : %d", a, b);

    swap(&a, &b);

    printf("\nAfter Swapping : \n");
    printf("Number 1 : %d\nNumber 2 : %d", a, b);

    return 0;
}