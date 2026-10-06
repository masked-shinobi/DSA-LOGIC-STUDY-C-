#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;

    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;

        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        res.push_back(subset);
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};

    for (auto& s : subsets(nums)) {
        cout << "[ ";
        for (int x : s) cout << x << " ";
        cout << "]\n";
    }
    // [ ] [ 1 ] [ 2 ] [ 1 2 ] [ 3 ] [ 1 3 ] [ 2 3 ] [ 1 2 3 ]
    return 0;
}