/**
    Problem: LCM of 2 numbers.

    Product of 2 numbers = GCD * LCM
    Hence LCM = Product of 2 numbers / GCD

    @author salroid
    www.salroid.me
*/

#include <iostream>

using namespace std;

int gcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return gcd(num2, num1 % num2);
}


int main () {
    int num1, num2;
    cin >> num1 >> num2;
    cout << (num1 * num2) / gcd(num1, num2) << endl;
    return 0;
}