#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isrow = false;
        bool iscol = false;

        for (int i = 0; i < n; ++i)
        {

            if (matrix[0][i] == 0)
            {
                isrow = true;
            }
        }
        if (matrix[0][0] == 0)
        {
            iscol = true;
        }
        for (int i = 1; i < m; ++i)
        {

            if (matrix[i][0] == 0)
            {
                iscol = true;
            }

            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 0)
                for (int j = 0; j < m; j++)
                    matrix[j][i] = 0;
        }
        if (iscol)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[j][0] = 0;
            }
        }
        if (isrow)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix{
        {-4, -2147483648, 6, -7, 0},
        {-8, 6, -8, -6, 0},
        {2147483647, 2, -9, -6, -10}};
    Solution().setZeroes(matrix);
    return 0;
}