#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int value =0;
        int fives=n;
        while(fives>0)
        {
            fives=fives/5;
            value+=fives;
        }
        return value;
    }
};

int main()
{
    cout << Solution().trailingZeroes(80);
}