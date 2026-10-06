void combisum(vector<int>& arr, vector<int>& combination, vector<vector<int>>&ans, int target, int i) {

    int n = arr.size();
    // base case
    if(i == n || target < 0){
        return;
    }
    if(target == 0){
        ans.push_back(combination);
        return;
    }

    combination.push_back(arr[i]);
    // inclusion single step
    combisum(arr, combination, ans, target - arr[i], i+1);
    // inclusion multi step
    combisum(arr, combination, ans, target - arr[i], i);
    // exclusion
    combination.pop_back(); // backtrack
    combisum(arr, combination, ans, target, i+1);

}