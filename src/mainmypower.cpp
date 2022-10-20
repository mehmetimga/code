#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        
        if (n < 0) {
            x = 1 / x;
        }
        double v=1;
        n=abs(n);
        double cp = x;
        for (long i = n; i > 0; i /= 2) {
            if ((i % 2) == 1) {
                v = v * cp;
            }
            cp = cp * cp;
        }
        return v;
    }
};

int main()
{

    cout << "Solution:" << Solution().myPow(4,5);

}