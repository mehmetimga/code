
#include <iostream>
using namespace std;
 
int maxSubArraySum(int a[], int size)
{
    int currentmax=a[0];
    int globalmax=a[0];

    for (int i=1;i<size;i++)
    {
        currentmax=max(a[i],currentmax+a[i]);
        globalmax=max(currentmax,globalmax);
    }
    return globalmax;
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   cout << "Maximum contiguous sum is " << max_sum;
   return 0;
}