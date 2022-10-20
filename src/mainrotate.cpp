#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int > a(nums.size());
        for (int j = 0; j < nums.size(); ++j)
        {
            a[(j+k)%nums.size()]=nums[j];
        }
        nums=a;
    }
};

int main()
{
    vector<int> a;
    a.push_back(-4);
    a.push_back(-1);
    a.push_back(0);
    a.push_back(3);
    a.push_back(10);

    Solution().rotate(a, 3);
    for (auto i : a)
        cout << i << "," << endl;
    return 0;
}