#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b==0)
        return a;
    else   
        return gcd(b,a%b);
}

string gcdOfStrings(string str1, string str2){
    int len1 = str1.size();
    int len2 = str2.size();
    
    if (len1 < len2) 
        return gcdOfStrings(str2, str1);
    
    for (int i = 0; i < len2; i++)
        if (str1[i] != str2[i]) 
            return "";
    
    if (len1 == len2) 
        return str1;
    
    return gcdOfStrings(str1.substr(len2), str2);
}

int main()
{
    cout << "gcd="<< gcdOfStrings("AAAAAA","AAA")<<endl; 
    cout << "gcdn="<< gcd(56,21)<<endl; 
}