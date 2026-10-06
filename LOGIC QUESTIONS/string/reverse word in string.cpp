#include <bits/stdc++.h>

using namespace std;

int main(){

    string str = "Sanjay is the student with aura.";
    // split words
    stringstream ss(str);
    string capture;
    vector<string> words;

    while(ss>>capture){
        words.push_back(capture);
    }

    for(string s : words){
        reverse(s.begin(), s.end());
        for(char x : s){
            cout << x << " ";
        }
    }

    return 0;
}