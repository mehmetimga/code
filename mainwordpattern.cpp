#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char, int> mchar;
        unordered_map<string, int> mword;
        istringstream in(s);
        int i = 0, n = pattern.size();
        
        for (string word; in >> word; ++i) {
        
            if (i==n || mchar[pattern[i]] != mword[word])
                return false;
            
            mchar[pattern[i]] = mword[word] = i+1;
        
        }
        
        return i==n;
    }
};


int main()
{

    cout << " result:" << Solution().wordPattern("abba","dog cat cat dog");

    // string input = "abc def ghi";
    // istringstream ss(input);

    // int i = 0;
    // for (string word; ss >> word; ++i)
    // {

    //     cout << word << endl;
    // }

    // string str = "abc def ghi";
    // stringstream ss(str);

    // string token;
    // vector<string> v;
    // while (ss >> token)
    // {
    //     v.push_back(token);
    //     //printf("%s\n", token.c_str());
    // }
    // auto it{v.begin()};
    // while(it!=v.end())
    // {
    //     cout<<*it<<endl;
    //     it++;
    // }
}