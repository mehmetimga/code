#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end(), [](auto p1, auto p2)
             { return p1[0] < p2[0]; });

        for (auto p : intervals)
        {
            if (merged.size() == 0 || merged[merged.size() - 1][1] < p[0])
                merged.push_back(p);
            else
            {
                merged[merged.size() - 1][1] = max(merged[merged.size() - 1][1], p[1]);
            }
        }
        return merged;
    }
};

int main()
{
    //[[1,3],[2,6],[8,10],[15,18]]
    vector<vector<int>> a = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> b = Solution().merge(a);
    for (auto b1 : b)
    {
        cout << "{" << b1[0] << "," << b1[1] << "},";
    }
    return 0;
}