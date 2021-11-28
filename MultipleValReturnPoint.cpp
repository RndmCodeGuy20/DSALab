#include <iostream>
using namespace std;

void sum_diff(int x, int y, int *Sum, int *Diff)
{
    *Sum = x + y;
    *Diff = x - y;
}

int main()
{
    int a, b, sum, diff;

    a = 10;
    b = 20;

    sum_diff(a, b, &sum, &diff);

    printf("Sum of %d and %d is : %d\n", a, b, sum);
    printf("Difference of %d and %d is : %d", a, b, diff);

    return 0;
}