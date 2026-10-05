#include <bits/stdc++.h>

using namespace std;

int main() {

    int x;
    cin >> x;

    // number to digits
    vector<int> digits;
    int digit;
    while(x > 0){
        digit = x % 10;
        digits.push_back(digit);
        x = x / 10;
    }

    return 0;
}