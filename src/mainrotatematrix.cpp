#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left=0;
        int right=matrix.size()-1;
        int top=0;
        int down=matrix[0].size()-1;
        while(left<=right && top<=down)
        {
            int temp=0;
            int temp2=0;
            for(int i=0;i<(right-left);i++)
            {
                temp=matrix[top+i][right];
                matrix[top+i][right]=matrix[top][left+i]; 
                temp2=matrix[down][right-i];
                matrix[down][right-i]=temp;

                temp=matrix[down-i][left];
                matrix[down-i][left]=temp2;
                matrix[top][left+i]=temp;
            }

            left++;
            right--;
            top++;
            down--;

        }


    }
};

int main()
{
    vector < vector <int > > a =
        {{1,2,3},
        {4,5,6},
        {7,8,9}};
    Solution().rotate(a);
        return 0;
}