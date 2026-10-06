#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;

    for (int x : nums) {
        res ^= x;
    }
    return res;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << "\n";  // 4
    return 0;
}