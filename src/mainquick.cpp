#include <iostream>

using namespace std;

int findPartition(int *arr, int left, int right, int pivot)
{
  while (true)
  {
    while (arr[left] < pivot)
      left++;

    while (right > 0 && arr[right] > pivot)
      right--;

    if (left > right)
      break;
    else
      swap(arr[left], arr[right]);
  }
  return left;
}

void quicksort(int *arr, int left, int right)
{
  if (left >= right)
    return;

  int pivot = arr[right];
  int partition = findPartition(arr, left, right, pivot);
  quicksort(arr, left, partition - 1);
  quicksort(arr, partition + 1, right);
}

int main()
{
  int arr[7] = {4, 6, 3, 2, 1, 9, 7};
  int length = sizeof(arr) / sizeof(arr[0]);
  int left = 0;
  int right = length - 1;
  quicksort(arr, left, right);

  for (int i = 0; i < length; i++)
    cout << arr[i] << " ";

  return 0;
}
