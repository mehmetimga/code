#include <iostream>
#include <algorithm>
#include  <vector>
#include  <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> a{0,0};

        for(int i=0;i<nums.size();i++){
            int c=target-nums[i];
            
            if(m.find(c) != m.end())
            {

                a[0]=m[c];
                a[1]=i;
                return a;
            }
            m[nums[i]]=i;
        }
        return a;
    }
};

int main()
{
    vector<int> nums{2,7,11,15};
    auto a=Solution().twoSum(nums,9);
    cout << "result =" << a[0] << "-" << a[1] << endl;
    return 0;
}