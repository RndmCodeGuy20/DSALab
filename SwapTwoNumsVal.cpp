#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    printf("\nAfter Swapping : \n");
    printf("Number 1 : %d\nNumber 2 : %d", a, b);
}

int main()
{
    int a = 10, b = 20;

    printf("Before Swapping :\n");
    printf("Number 1 : %d\nNumber 2 : %d", a, b);

    swap(a, b);
    return 0;
}
