#include <iostream>
#include <cstdlib>

using namespace std;

// Function to print duplicates

//using abs
void printRepeating1(int arr[], int size)
{
    for (int i=0; i<size ; i++)
    {
        if ( arr[abs(arr[i])]>0)
            arr[abs(arr[i])]=-arr[abs(arr[i])];
        else    
            cout << abs(arr[i]) << " ";
    }
}

//using mode 
void printRepeating(int arr[], int size)
{
    for (int i=0; i<size ; i++)
    {
        if ( arr[arr[i]%size] < size)
            arr[arr[i]%size] =arr[arr[i]%size]+size;
        else    
            cout << arr[i]%size << " ";
    }
} 
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 1, 3, 6, 6 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printRepeating(arr, arr_size);
    return 0;
}