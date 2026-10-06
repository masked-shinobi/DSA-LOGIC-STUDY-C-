
void palipart(string s, vector<string>& partition, vector<vector<string>>& ans){
    if(s.length() == 0){
        ans.push_back(partition);
        return;
    }
    // main case 
    for( int i = 0; i < s.size(); i++){
        string part = s.substr(0, i+1);
        if(isPallindrome(part)){
            partition.push_back(part);
            palipart(s.substr(i+1), partition, ans); // for the remaining part
            partition.pop_back(); // backtracking
        }
    }
}
