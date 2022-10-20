#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        m = m - 1;
        n = n - 1;
        int k = m + n + 1;

        while (k >= 0)
        {
            cout << " numbers=" << nums1[m] << " " << nums2[n] << endl;

            if ((n>-1)&& (nums1[m] < nums2[n])|| m<0)
            {
                nums1[k--] = nums2[n];
                n--;
            }
            else
            {
                nums1[k--] = nums1[m];
                m--;
            }
        }
    }
};

int main()
{

    //vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    //vector<int> nums2 = {2, 5, 6};
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m = 0;
    int n = 1;
    Solution().merge(nums1, m, nums2, n);
    cout << "After merge: " ;

    for (auto i : nums1)
        cout << " " << i ;
    cout << endl;

    return 0;
}