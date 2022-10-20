#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int col=0;
        int row=matrix[0].size()-1;
        
        while(row>=0 && col<matrix.size())
        {
            if (matrix[col][row]>target)
                row--;
            else if (matrix[col][row]<target)
                col++;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> a={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=5;
    cout << "found:" <<Solution().searchMatrix(a,target)<< endl;
}