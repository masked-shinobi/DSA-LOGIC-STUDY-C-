#include <bits/stdc++.h>

using namespace std;

vector<int> deque_mono(vector<int> arr, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {

        // Remove indices outside the window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Maintain increasing order of values
        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Window is complete
        if (i >= k - 1) {
            ans.push_back(arr[dq.front()]);
        }
    }

    return ans;
}

int main() {

    return 0;
}