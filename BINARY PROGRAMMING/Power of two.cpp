#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    cout << isPowerOfTwo(16) << "\n";  // 1
    cout << isPowerOfTwo(18) << "\n";  // 0
    return 0;
}