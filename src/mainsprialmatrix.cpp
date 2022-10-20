

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > a;
        for(int i=0;i<n;i++){
            vector<int> temp(n);
            a.push_back(temp);
        }
        
        int left=0;
        int right=n;
        int down=n;
        int top=0;
        int index=1;
        while(left<right && top<down)
        {
            for (int i=left;i<right;i++)
                a[top][i]=index++;
            for (int i=top+1;i<down;i++)
                a[i][right-1]=index++;
            for (int i=right-2;i>=left;i--)
                a[down-1][i]=index++;
            for (int i=down-2;i>top;i--)
                a[i][left]=index++;
            
            left++;
            right--;
            top++;
            down--;
            
        }
        return a;
        
    }
};

int main()
{
    Solution().generateMatrix(3);
}