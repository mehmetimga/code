#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include<array>
#include<functional>


using namespace std;

deque<char> getintarray(string input)
{
  stringstream ss(input);
  deque<char> d;
  string c;
  while(getline(ss,c, ','))
  {

    if (c=="-B" &&d.size()>0)
        d.pop_front();
    else if (c!="-B")
        d.push_front(c[0]);
    
  }
  return d;
}

string EquivalentKeypresses(string strArr[], int arrLength) {
  
  deque<char> s1= getintarray(strArr[0]);
  deque<char> s2= getintarray(strArr[1]);

  if (s1.size()!=s2.size())
    return "false";
  string result;

  while(!s1.empty())
  {
    char c1=s1.back();
    char c2=s2.back();
    s1.pop_back();
    s2.pop_back();
    if (c1!=c2)
        return "false";
    result+=c1;
  }

  return result;

}

// int main(void) { 
   
//   // keep this function call here
//   string A[]{"p,o,i,n,-B,t", "-B,p,o,i,t"};
//   int arrLength = sizeof(A) / sizeof(*A);
//   cout << EquivalentKeypresses(A, arrLength);
//   return 0;
    
// }
int main()
{
    array<int, 10> arr = { 1,2,3,4,5,6,7,8,9 };

    sort(begin(arr), 
         end(arr), 
         [](int a, int b) {return a > b; });

    for (auto item : arr)
      cout << item << " ";

    return 0;
}