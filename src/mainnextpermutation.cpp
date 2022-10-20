#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int length = nums.size();
        int decrease = -1;
        for (int i = length - 1; i > 0; --i)
        {
            if (nums[i] > nums[i - 1])
            {
                decrease = i-1;
                break;
            }
        }
        if (decrease == -1)
        {
            for (int i = 0; i < length / 2; ++i)
                swap(nums[i], nums[length - i - 1]);
        }
        else
        {
            int increase=decrease+1;
            for (int i = decrease+1; i <length; ++i)
            {
                if (nums[decrease] < nums[i])
                {
                    increase = i;
                }else
                    break;
            }
            swap(nums[decrease], nums[increase]);
            int start=decrease+1;
            int end=start+(length-start)/2;
            for (int i=start;i<end;i++)
            {
                swap(nums[i],nums[length-(i-start)-1]);
            }
        }
    }
};

int main()
{
    //vector<int> a = {5,4,7,5,3,2};
vector<int> a = {3,1,2};
    
    Solution().nextPermutation(a);
    for (int i : a)
        cout << " " << i;
    cout << endl;
}