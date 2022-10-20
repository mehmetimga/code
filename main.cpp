#include <iostream>

using namespace std;

bool sequence()
{
    int a[]{3,2,0,1,10,9,6,5,3,7,8};

    constexpr int length = size(a);
    int i{0};
    for (auto val:a)
    { 
        for (int j{0};j<length;j++)
        {
            if (val<0 || val>=length)
                return false;

            if (a[i]!=i)
                swap(a[i],a[a[i]]);
            else
                break;
        }
        i++;
    }
    for (int k=0;k<length;k++)
    {
        cout << ", " << a[k];
    }
    return true;
}

int main()
{
    bool result = sequence();
    if (result)
        cout << "Correct result " << endl;
}