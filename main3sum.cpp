#include <iostream>

using namespace std;

int main()
{
    int a[]{1,2,4,9,6,3,5};
    int n=size(a);
    int target = 9;

    sort(a,a+n);

    for(int i=0;i<n-1;i++)
    {
        int left=i+1;
        int right=n-1;
        while (left<right)
        {
            int val=(a[i]+a[left]+a[right]);
            if (val==target)
            {
                cout << a[i] << " " << a[left]<<" " << a[right] << endl;
                left++;
                right--;
            }
            else if (val < target)
                left++;
            else    
                right--;

        }

    }

}