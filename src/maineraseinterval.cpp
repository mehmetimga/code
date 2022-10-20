#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(),[](auto p1,auto p2){return p1[1]<p2[1];});
        
        int end = intervals[0][1];
        int prev = 0;
        int count = 0;
        int length = intervals.size();
        for (int i = 1; i < length; i++) {
          if (intervals[prev][1] > intervals[i][0]) {
            if (intervals[prev][1] > intervals[i][1]) {
              prev = i;
            }
            count++;
          } else {
            prev = i;
          }
        }
        return count;
    }
};

int main()
{
    //vector<vector<int>> a={{1,2},{2,3},{3,4},{1,3}};


    vector<vector<int>> a={{-47397,9550},{2720,30659},{-23874,-14936},{-31855,18014},{31222,34030},{-13839,-4283},{-22000,17663},{46119,47768},{-5123,10900},{11410,31472},{43210,46846},{10347,46318},{-37970,9448},{-38500,-8858},{6451,18362},{-11875,16988},{-7651,36023},{20607,21165},{35854,40598},{32093,37885},{21732,40458},{4378,26744},{24895,35981},{3782,27773},{45646,48754},{-6825,-576},{-1356,38013},{-20483,-10761},{41785,44602},{-35607,20895},{24983,39497},{49344,49667},{3809,39757},{-21256,-916},{-24425,20174},{29860,40909},{-18701,-12461}};

    cout << "count=" << Solution().eraseOverlapIntervals(a);
    return 0;
}