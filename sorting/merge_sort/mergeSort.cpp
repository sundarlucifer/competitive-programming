// Merge sort implementation
#include <iostream>
using namespace std;

void merge(int* arr, int low,int mid, int high){
  int sortedArrSize = high-low+1;
  int sortedArr[sortedArrSize];
  int i = 0;        // sorted arr ind
  int ptr1 = low;   // 1st half ind
  int ptr2 = mid+1; // 2nd half ind
  while(ptr1<=mid && ptr2<=high){
    if(arr[ptr1]<arr[ptr2])
      sortedArr[i++] = arr[ptr1++];
    else
      sortedArr[i++] = arr[ptr2++];
  }
  while(ptr1<=mid)
    sortedArr[i++] = arr[ptr1++];
  while(ptr2<=high)
    sortedArr[i++] = arr[ptr2++];
  for(int i=low; i<=high; i++)
    arr[i] = sortedArr[i-low];
}

void mergeSort(int* arr, int low, int high){
  if(low>=high)
    return;
  int mid = (low+high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);
  merge(arr, low, mid, high);
}

void printArr(int* arr, int size){
  for(int i=0; i<size; i++)
    cout << arr[i] << " ";
  cout << endl;
}
 
int main(){
  int arr[] = {5, 1, -2, 4, 3, 6, -1};
  int arrSize = 7;

  printArr(arr, arrSize);

  mergeSort(arr, 0, arrSize-1);

  printArr(arr, arrSize);  

  return 0;
}
