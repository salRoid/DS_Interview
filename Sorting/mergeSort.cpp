#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
 
using namespace std;
 
void merge (vector<int> &arr, int l, int m, int r) {
  int leftArrSize = m - l + 1;
  int rightArrSize = r - m;
  // Temp Arrays
  vector <int> left(leftArrSize);
  vector <int> right(rightArrSize);
  for (int i = 0; i < leftArrSize; i++) 
    left[i] = arr[i + l];
  for (int i = 0; i < rightArrSize; i++)
    right[i] = arr[i + m + 1];
 
    int i = 0, j = 0; // Initial Index of left and right subArray 
    int k = l; // Iinitial Index of Merged Array
    // Merge the two arrays
    while (i < leftArrSize && j < rightArrSize) {
      if (left [i] <= right[j]) {
        arr[k] = left[i];
        i++;
      } else {
        arr[k] = right[j];
        j++;
      }
      k++;
    }
    // Insert remaning elements to the merged array
    while (i < leftArrSize) {
      arr[k] = left[i];
      i++;
      k++;
    }
    while (j < rightArrSize) {
      arr[k] = right[j];
      j++;
      k++;
    }
}
 
void mergeSort (vector<int> &arr, int l, int r) {
  if (l < r) {
      int mid = l + (r - l) / 2;
      mergeSort (arr, l, mid);
      mergeSort (arr, mid + 1, r);
      merge (arr, l, mid, r);
  }
}
 
int main () {
  int arrSize;
  cin >> arrSize;
  vector <int> arr(arrSize);
  for (int i = 0; i < arrSize; i++) {
    cin >> arr[i]; // input the Array Elements
  }
  mergeSort(arr, 0, arrSize-1);
 
  for (int i = 0; i < arrSize; i++) 
	cout << arr[i] << " ";
 
  return 0;
} 