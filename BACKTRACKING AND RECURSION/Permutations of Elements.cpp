#include <bits/stdc++.h>

using namespace std;

// get the permutations of the objects
// method without any extra space 

void permutations(vector<int>&elements, int idx, vector<vector<int>>&  combinations){
    if(idx == elements.size()){
        combinations.push_back(elements);
        return;
    }

    for(int i = idx; i < elements.size(); i++){
        swap(elements[idx], elements[i]);
        permutations(elements, idx+1, combinations);
        swap(elements[idx], elements[i]);
    }
}

int main(){

    // introduce parameter idx to the function
    // check base : if idx == arr size then add the combination to something  and then return ;
    // for loop run till i goes from idx to full size
        // swap element at idx and element that is at i 
        // call the function with idx+1
        // swap elements again same as before
        
    vector<int> elements;
    int idx = 0;
    vector<vector<int>> combinations;

    permutations(elements, idx, combinations);

    return 0;
}