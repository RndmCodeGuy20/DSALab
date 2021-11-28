#include <iostream>
using namespace std;

int *initialize()
{
    int *temparr = (int *)malloc(sizeof(int) * 3);

    *temparr = 10;
    *(temparr + 1) = 20;
    *(temparr + 2) = 30;

    return temparr;
}

int main()
{
    int a, b, c;

    int *arr = initialize();

    a = arr[0];
    b = arr[1];
    c = arr[2];

    cout << a << " " << b << " " << c << endl;

    return 0;
}