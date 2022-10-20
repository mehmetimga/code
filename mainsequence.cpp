#include <iostream>
#include <algorithm>

using namespace std;

bool sequence1()
{
    int a[]{3,2,0,1,10,9,6,5,3,7,8};

    int length = sizeof(a)/sizeof(a[0]);
    for (int i=0;i<length;i++)
    { 
        for (int j=0;j<length;j++)
        {
            if (a[i]<0 || a[i]>=length)
                return false;

            if (a[i]!=i)
                swap(a[i],a[a[i]]);
            else
                break;
        }
    }
    for (int k=0;k<length;k++)
    {
        cout << ", " << a[k];
    }
    return true;
}

bool sequence()
{
    int a[]{3,0,2,1};
    int length =  sizeof (a)/sizeof(a[0]);
    for (int i=0;i<length;i++)
    {
        if (a[i]<0 || a[i]>=length)
            return false;

        if (i!=a[i])
            swap(a[i],a[a[i]]);
    }
    return true;

}

bool sequence3()
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

            if (val!=i)
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
    bool s = sequence();
    return 0;
}