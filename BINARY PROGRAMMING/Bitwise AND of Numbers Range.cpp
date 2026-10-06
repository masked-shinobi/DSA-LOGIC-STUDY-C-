#include <iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;

    while (left != right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}

int main() {
    cout << rangeBitwiseAnd(5, 7) << "\n";  // 4
    return 0;
}