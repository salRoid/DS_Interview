#include <iostream>

using namespace std;

void printDivisors(int n) {
    int i;
    for (i = 1; i * i < n; i++) {
        if (n % i  == 0) {
            cout << i << " " ;
        }
    }

    for ( ; i >= 1 ; i--) {
        if (n % i  == 0) {
            cout << (n / i) << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    printDivisors(n);
    return 0;
}