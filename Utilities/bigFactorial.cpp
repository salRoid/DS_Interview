#include <iostream>

using namespace std;

int multiply(int x, int res[], int resSize) {
    int carry = 0;
    for (int i = 0; i < resSize; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        int carry = prod / 10;
    }
    while (carry) {
        res[resSize] = carry % 10;
        carry = carry / 10;
        resSize++;
    }
    return resSize;
}

int main () {
    int n;
    cin >> n;
    int res[500];
    res[0] = 1;
    int resSize = 1;
    for (int i = 2; i <= n; i++) {
        resSize = multiply(i, res, resSize);
    }
    cout << "Factorial of given number is \n"; 
    for (int i = resSize - 1; i >= 0; i--) 
        cout << res[i]; 
}