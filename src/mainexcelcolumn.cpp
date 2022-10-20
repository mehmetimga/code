#include <iostream>
using namespace std;


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int returnvalue=0;
        int base=1;
        int length = columnTitle.size();
        for (int i=0;i<columnTitle.size();++i) 
        {
            char a = columnTitle[length -i -1];
            int charvalue=a-'A' +1;
            returnvalue+=charvalue*base;
            base=base*26;
        }
        return returnvalue;
    }
};

int main()
{
    int value=Solution().titleToNumber("FXSHRXW");
    cout << "value:" << value << endl;

}