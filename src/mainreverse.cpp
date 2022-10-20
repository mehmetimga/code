#include <iostream>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int k=0;
        for(int i=0;i<s.size()+1;i++)
        {
            if (i== s.size() || s[i]==' '){ //reverse string
                for (int j=0;j<(i-k)/2;j++)
                {
                    char c=s[k+j];
                    char t=s[i-j-1];
                    s[k+j]=t;
                    s[i-j-1]=c;
                }
                k=i+1;//last space location
            }
        }
        return s;
    }
};

int main()
{
    cout << Solution().reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}