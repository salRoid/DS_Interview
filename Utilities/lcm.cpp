/**
    Problem: LCM of more than 2 numbers.

    As we know :
    Product of 2 numbers = GCD * LCM
    LCM = Product of 2 numbers / GCD

    Since this formula won't work in this approach.
    We iterate through the numbers and store ans (LCM) on each iteration.

    ans = LCM(ans, arr[i])
    
    @author salroid
    www.salroid.me
*/

#include <iostream>
#include <vector>

using namespace std;

int gcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return gcd(num2, num1 % num2);
}

int main () {
    int num; 
    cin >> num;
    vector <int> arr(num);
    for (int i = 0; i < num; i++) 
        cin >> arr[i];
    int ans = arr[0];
    for (int i = 1; i < num; i++) {
        ans = (ans * arr[i]) / gcd (ans, arr[i]);
    }
    cout << ans << endl;
    return 0;
}