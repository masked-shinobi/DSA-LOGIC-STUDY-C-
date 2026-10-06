#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}

int main() {
    for (int x : countBits(5)) cout << x << " ";  // 0 1 1 2 1 2
    cout << "\n";
    return 0;
}