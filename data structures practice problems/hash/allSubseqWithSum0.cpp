// Print all subsquence that has sum 0
// O(N) to find number of such subsequences
// O(N.k) to find range i.e print start and end index of subsequence instead of the numbers in it
// O(N^2.k) to print all subsequence
// where k is max number of sequences starting the same number 
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

unordered_map<int, map<int, int> > indexBook;

void printArr(int* arr, int arrSize){
  for(int i=0; i<arrSize; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void allSubseqWithSum0(int* arr, int arrSize){
  int* sumArr = (int*)malloc((arrSize+1)*sizeof(int));
  sumArr[0] = 0;
  indexBook[0].insert(make_pair(1, 1));
  for(int i=1; i<=arrSize; i++){
    sumArr[i] = sumArr[i-1] + arr[i-1];
    indexBook[sumArr[i]].insert(make_pair(i+1, i+1));
  }
  
  int strt, end;
  for(pair<int, map<int, int> > ptr1 : indexBook){
    strt = ptr1.second.begin()->first-1;
    for(map<int, int>::iterator ptr2 = ++ptr1.second.begin(); ptr2 != ptr1.second.end(); ptr2++){
      end = ptr2->first-2;
      cout << "Subseq at index : " << strt << " to " << end << endl;
      printArr(arr+strt, end-strt+1);
    }
  }  
}

int main(){
  
  int arrSize = 8;
  int arr[] = {1, -1, 0, 2, 3, 4, 5, -9};

/*
  int *arr;

  cout << "Array size : ";
  cin >> arrSize;
  arr = (int*)malloc(arrSize*sizeof(int));

  int val;
  for(int i=0; i<arrSize; i++){
    cout << "Enter number : ";
    cin >> arr[i];
  }
*/
  allSubseqWithSum0(arr, arrSize);
  
  cout << endl;
  return 0;
}
