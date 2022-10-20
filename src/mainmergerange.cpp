#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > merged;
        sort(intervals.begin(),intervals.end(),[](auto a,auto b){
            return a[0]<b[0];
        });
      for (auto c:intervals)
      {
        if (merged.size()==0 || merged.at(merged.size()-1)[1]<c[0])
        {
          merged.push_back(c);
        }else {
          merged.at(merged.size()-1)[1]=max(merged.at(merged.size()-1)[1],c[1]);
        }
      }
      return merged;
    }
};
int main()
{
    //[[1,3],[2,6],[8,10],[15,18]]
    vector< vector<int> > a={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int> > b = Solution().merge(a);
    for (auto b1:b)
    {
        cout <<"{"<< b1[0] <<","<< b1[1] <<"},";
    }
    return 0;

}
