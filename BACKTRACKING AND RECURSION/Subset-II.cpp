#include <bits/stdc++.h>

using namespace std;

void subset(vector<int>& elements, vector<int>& ans, vector<vector<int>>& arr, int i){
    // base case
    if(i == elements.size()){
        arr.push_back(ans);
        return;
    }

    // inclusion 
    ans.push_back(elements[i]);
    subset(elements, ans, arr, i+1);

    int idx = i+1;

    // duplicates skipper step
    while(idx < elements.size() && elements[idx] == elements[idx-1]){
        idx++;
    }

    // exclusion
    ans.pop_back();
    subset(elements, ans, arr, idx);

    // do the same as before that is we need to pass i with everything else
    // now for base case if i is arr.size then push ans to something and return 
    // inclusion - push arr of i to ans
    // call function with i+1
    // initialise idx with i+1
     
    // now special step : while( idx < arr.size and arr[idx] == arr[idx-1]) then idx++;
    // pop back from the ans
    // call function again with idx instead of i+1
}

int main() {

    // duplicates also present in this array
    vector<vector<int>> arr; // answer present
    vector<int> ans;         // works as temporary variable
    vector<int> elements;    // works as a element input

    sort(elements.begin(), elements.end());

    subset(elements, ans, arr, 0);

    return 0;
}