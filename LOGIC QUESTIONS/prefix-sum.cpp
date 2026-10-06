#include <bits/stdc++.h>

using namespace std;

int prefixcount(vector<int> nums, int k){
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0;
    int prefix = 0;
    for( int num : nums ){
        prefix += num;
        if(mp.count(prefix - k)){
            count += mp[prefix - k];
        }
        mp[prefix]++;
    }

    return count;
}

int main() {

    return 0;
}