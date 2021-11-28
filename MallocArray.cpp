#include <iostream>
using namespace std;

int main()
{
    int *ptr;
    int n;

    cout << "Enter the size of array : " << endl;
    cin >> n;

    ptr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << endl;
    }

    return 0;
}