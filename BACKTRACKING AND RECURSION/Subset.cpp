#include <bits/stdc++.h>

using namespace std;

void printsubsets(vector<vector<int>>& answer, vector<int>& ans, vector<int>& arr, int i){

    // base case
    if(i == arr.size()){
        answer.push_back(ans);
        return; // to break 
    }

    // inclusion 
    ans.push_back(arr[i]);
    printsubsets(answer, ans, arr, i+1);
    // exclusion
    ans.pop_back();
    printsubsets(answer, ans, arr, i+1);

}

int main() {

    // parameter i to be in the function
    // now add element of i
    // call with everything with just i+1 added
    // now pop the element that is added before
    // call again with i+1

    // now at the start , check the base case where i is arr size then the stuff crossed so we need push

    vector<int> arr;
    vector<vector<int>> answer;
    vector<int> ans;

    printsubsets(answer,ans, arr, 0);

    return 0;
}