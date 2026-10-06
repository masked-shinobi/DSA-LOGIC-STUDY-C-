#include <bits/stdc++.h>

using namespace std;

bool isPermutation(string str1, string str2) {
    if(str1.length() != str2.length())
        return false;

    unordered_map<char, int> map1;

    for(char c : str1) {
        map1[c]++;
    }

    for(char c : str2) {
        map1[c]--;
    }

    for(auto x : map1) {
        if(x.second != 0)
            return false;
    }

    return true;
}