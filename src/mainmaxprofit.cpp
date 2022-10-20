#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0;
        int minprice = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }

        return maxprofit;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int profit = Solution().maxProfit(prices);
    cout << "maxprofit:" << profit << endl;
}