#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int res = n;

    for (int i = 0; i < n; i++) {
        res ^= i ^ nums[i];
    }
    return res;
}

int main() {
    vector<int> nums = {3, 0, 1};
    cout << missingNumber(nums) << "\n";  // 2
    return 0;
}