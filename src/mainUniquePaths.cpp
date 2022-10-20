#include <iostream>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int a[m][n];
        //memset(a, 1, sizeof(a));
        memset(a,1,m*n*sizeof (int));

        for (int j = 0; j < m; j++)
        {

            for (int i = 0; i < n; i++)
            {
                a[j][i] = 1;
            }

        }
        for (int j = 1; j < m; j++)
        {

            for (int i = 1; i < n; i++)
            {
                a[j][i] = a[j][i - 1] + a[j - 1][i];
            }

        }
        return a[m-1][n-1];
    }
};

int main()
{
    cout << "result=" << Solution().uniquePaths(5, 5) << endl;
    return 0;
}