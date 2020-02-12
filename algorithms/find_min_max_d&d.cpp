#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findMinMax(vector<int> arr, int low, int high){

    // cout << low << ", " << high << " -> " << *min << ", " << *max << endl ;

    int min, max;
    
    if(low == high){
        min = arr[low];
        max = arr[high];
    }
    else if(low+1 == high){
        min = arr[low] < arr[high] ? arr[low] : arr[high];
        max = arr[low] > arr[high] ? arr[low] : arr[high];
    }
    else{
        int mid = (low+high)/2;
        pair<int, int> minmax1, minmax2;
        minmax1 = findMinMax(arr, low, mid);
        minmax2 = findMinMax(arr, mid+1, high);
        
        min = minmax1.first < minmax2.first ? minmax1.first : minmax2.first;
        max = minmax1.second > minmax2.second ? minmax1.second : minmax2.second;
    }

    return make_pair(min, max);

}

int main(){

    vector<int> arr;

    arr.push_back(50);
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(70);
    arr.push_back(10);
    arr.push_back(30);

    pair<int, int> min_max;

    min_max = findMinMax(arr, 0, arr.size()-1);

    cout << "min : " << min_max.first << endl;
    cout << "max : " << min_max.second << endl;

}