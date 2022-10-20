#include <iostream>
#include <list>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

int main()
{

    string line;
    list<string> userlist;
    vector<string> cache;

    cin >> line;
    while (line != "0")
    {

        if (line == "redo")
        {
            line = cache.back();
            cache.pop_back();
            userlist.push_back(line);
        }
        else if (line == "undo")
        {
            line = userlist.back();
            userlist.pop_back();
            cache.push_back(line);
        }
        else
        {
            userlist.push_back(line);
        }

        cout << "Your values:";
        

        for (auto item :userlist)
            cout << item ;

        cout << endl ;
                 
        cin >> line;
    }
}
