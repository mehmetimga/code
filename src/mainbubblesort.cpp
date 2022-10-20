#include <iostream>
#include <algorithm>

using namespace std;

void mergesort(int b[], int length)
{
}

void    quicksort(int b[], int length)
{
}

void bublesort(int b[], int length)
{
    if (length == 1)    
        return;

    for (int i = 0; i < length-1; ++i)
    {
        if (b[i] > b[i + 1])
            swap(b[i], b[i + 1]);
    }
    bublesort(b, length - 1);
}
void bublesort2(int b[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length - 1; ++j)
        {
            if (b[j] > b[j + 1])
            {
                swap(b[j], b[j + 1]);
            }
        }
    }
}

int main()
{
    int a[] = {4, 2, 4, 56, 71, 99, 5};
    int length = sizeof(a) / sizeof(a[0]);

    bublesort(a, length);

    for (int k = 0; k < length; k++)
    {
        if (k == 0)
            cout << a[k];
        else
            cout << "," << a[k];
    }
    cout << endl;
    return 0;
}