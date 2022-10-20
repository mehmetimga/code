#include <iostream>

using namespace std;

void merge(int* arr, int left, int right)
{
    int temp[100];
    int i=left;
    int k=left;
    int mid=(left+right)/2;
    int j=mid+1;

    while(i<=mid && j<=right)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
        temp[k++]=arr[i++];

    while(j<=right)
        temp[k++]=arr[j++];

    for(int n=left;n<=right;n++)
        arr[n]=temp[n];

}

void mergesort(int* arr, int left,int right)
{
    if (left>=right)
        return;

    int mid=(left+right)/2;

    //conquer
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);

    merge(arr,left,right);
}

int main()
{
    int arr[]={3,1,6,7,2,9,11,20,5};
    int length=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,length-1);
    for(int i=0;i<length;i++)
        cout << " " << arr[i];
    return 0;

}