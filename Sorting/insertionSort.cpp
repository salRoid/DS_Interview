#include <iostream>

using namespace std;

int main() {
	int i ,j, n,key, arr[10];
	cin >> n;
	for(i = 0;i < n; i++)
		cin >> arr[i];
	for(j = 0; j < n; j++) {
		key = arr[j];
		i = j - 1;
		while(i >= 0 && arr[i] > key) {
			arr[i+1] = arr[i];
			i = i - 1;
			arr[i + 1] = key;
		}
	}
	for(i = 0; i < n; i++){
		cout << arr[i] << " ";

	}
}
