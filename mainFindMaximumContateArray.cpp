#include <iostream>

using namespace std;

int main()
{
    int a[]{23,34,45,321};
    int n=size(a);
    sort(a,a+n,
    [](int a, int b){
        string as=to_string(a);
        string ab=to_string(b);
        if (as+ab<ab+as)
            return false;
     return  true;
    });

    for(int i=0;i<n;i++){
        cout << a[i]; 
    }
}