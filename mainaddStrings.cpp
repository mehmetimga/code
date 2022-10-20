#include <iostream>
#include <deque>
#include <sstream>  

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1=num1.size()-1;
        int p2=num2.size()-1;
        int carry=0;
        deque<char> d;
        string s;
        stringstream ss;
        while(p1>=0 || p2>=0)
        {
            int x1= p1>=0?num1[p1]-'0':0;
            int x2= p2>=0?num2[p2]-'0':0;
            int value=(x1+x2+carry)%10;
            carry=(x1+x2+carry)/10;
            ss << value;
            p1--;
            p2--;
            
        }
        if (carry>0)
            ss<< carry;
        string sr=ss.str();
        string reversed(sr.rbegin(), sr.rend());

        return reversed;
    }
};

int  main()
{
    cout << "result:" << Solution().addStrings("12","123");
}