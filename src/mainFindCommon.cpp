#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> getintarray(string input)
{
  stringstream ss(input);
  vector<int> arr;
  string num;
  while(getline(ss,num, ','))
  {
    if(num.at(0)==' '){
      num.erase(0,1);
    }
    int val=stoi(num);
    arr.push_back(val);
  }
  return arr;
}

string FindIntersection(string strArr[], int arrLength) {
  
  int i{0};
  int j{0};

  string result;
  vector<int> arr1=getintarray(strArr[0]);
  vector<int> arr2=getintarray(strArr[1]);

  while(i<arr1.size() && j<arr2.size())
  {
    if (arr1[i]==arr2[j])
    {
      if (result.length()>0)
        result+=',';
      result+=to_string(arr1[i]);
      j++;
      i++;
    }
    else if (arr1[i]>arr2[j])
      j++;
    else 
      i++;
  }
  if (result.length()==0)
    return "false";

  return result;

}

int main(void) { 
   
  // keep this function call here
  string A[]{"1, 3, 9, 10, 17, 18", "1, 4, 9, 10"};

  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;
    
}