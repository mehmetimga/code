#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

     int firstnum=INT_MAX;
     int secondnum=INT_MAX;

     for (int i=0;i<nums.size();++i)
     {
        if (firstnum>=nums[i]){
            firstnum=nums[i];
        }
        else if (secondnum>=nums[i]){
            secondnum=nums[i];
        }
        else{
            return true;
        }
     }   
     return false;
    }
};

int main()
{
    vector<int> a={10,20,3,2,1,3,2,0,4};
    cout << "found:" << Solution().increasingTriplet(a);
    return 0;
}