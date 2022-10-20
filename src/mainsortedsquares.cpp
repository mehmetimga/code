#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> a(nums.size());
        if (nums.size()<2){
            return nums;
        }
        
        int left = 0;
        int right= nums.size()-1;
        int lefts=nums[left]*nums[left];
        int rights=nums[right]*nums[right];
        int index=nums.size()-1;
        while(left<=right)
        {
            if (lefts>rights)
            {
                a[index]=lefts;
                left++;
                lefts=nums[left]*nums[left];
            }
            else
            {
                a[index]=rights;
                right--;
                rights=nums[right]*nums[right];
            }
            index--;
        }
        return a;
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
    
    vector <int> b= Solution().sortedSquares(a);
    for( auto i:b)
        cout << i << ","<<endl;
    return 0;
}