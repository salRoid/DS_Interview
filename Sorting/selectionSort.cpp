#include <iostream>
#include <vector>

using namespace std;

int main() {
  int arrSize;
  cin >> arrSize;
  vector <int> arr(arrSize);
  for (int i = 0; i < arrSize; i++) 
    cin >> arr[i];
  for (int i = 0; i < arrSize-1; i++) {
    int min = i;
    for (int j = i + 1; j < arrSize; j++) {
      if (arr[j] < arr[min])
        min = j;
    }
    if (min != i) {
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
  for (int i = 0; i < arrSize; i++)
    cout << arr[i] << " " ;
}