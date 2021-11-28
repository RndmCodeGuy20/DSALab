#include <iostream>
using namespace std;

void arrEdit(int array[])
{
    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    array[3] = 40;
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};

    arrEdit(array);

    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << endl;
    }

    return 0;
}