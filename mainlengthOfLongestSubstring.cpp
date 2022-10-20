#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int maxlen=0;
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            auto it=m.find(s[i]);
            if(it!=m.end() && len>=i-it->second)
            {
                len=i-it->second;
                maxlen=max(maxlen,len);
                m[s[i]]=i;

            }else{
                m[s[i]]=i;
                len++;
                maxlen=max(maxlen,len);

            }
        }
        maxlen=max(maxlen,len);
        return maxlen;
    }
};

int main()
{
    cout << "length="<<Solution().lengthOfLongestSubstring("cdd")<< endl;

    return 0;
}

